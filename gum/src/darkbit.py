"""
Master module for all DarkBit related routines.
"""

import numpy as np
import shutil
from distutils.dir_util import copy_tree

from setup import *
from files import *
from backends import *

def sort_annihilations(dm, three_fields, four_fields):
    """
    Sorts BSM vertices, returns DM+DM -> X + Y
    """

    if not isinstance(dm, Particle):
        GumError("\n\nDM not passed over as an instance of class Particle.")

    dm_dm_to_x_y = []

    # Add all 4-pt vertices that are DM + DM -> X + Y
    for i in range(0, len(four_fields)):

        if dm.is_sc and four_fields[i].count(dm.PDG_code) == 2:
            products = [f for f in four_fields[i] if f not in {dm.PDG_code}]
            dm_dm_to_x_y.append(products)

        elif not dm.is_sc and four_fields[i].count(dm.PDG_code) == 1 and \
                four_fields[i].count(dm.Conjugate.PDG_code) == 1:
            products = [f for f in four_fields[i] if
                        f not in {dm.PDG_code, dm.Conjugate.PDG_code}]
            dm_dm_to_x_y.append(products)

    v_with_dm = []
    v_with_dmbar = []
    v_with_2dm = []
    v_with_dmdmbar = []
    s_channel_propagators = []

    # Separate all vertices
    for i in range(0, len(three_fields)):

        # Self conjugate DM.
        if dm.is_sc():

            if three_fields[i].count(dm.PDG_code) == 1:
                v_with_dm.append(three_fields[i])

            elif three_fields[i].count(dm.PDG_code) == 2:
                v_with_2dm.append(three_fields[i])
                # Add s-channel propagator: DM+DM -> prop
                product = [f for f in three_fields[i] if f != dm.PDG_code]
                s_channel_propagators.append(product[0])

        # Not self-conjugate DM.
        elif not dm.is_sc():

            if three_fields[i].count(dm.PDG_code) == 1:

                if three_fields[i].count(dm.Conjugate.PDG_code) == 0:
                    v_with_dm.append(three_fields[i])

                elif three_fields[i].count(dm.Conjugate.PDG_code) == 1:
                    v_with_dmdmbar.append(three_fields[i])
                    # Add s-channel propagator: DM+DMbar -> prop
                    product = [f for f in three_fields[i] if
                               abs(f) != dm.PDG_code]
                    s_channel_propagators.append(product[0])

            elif three_fields[i].count(dm.Conjugate.PDG_code) == 1:
                v_with_dmbar.append(three_fields[i])

    # s-channel: sticking together
    # DM + DMbar -> propagator & propagator -> stuff + otherstuff

    # See what each propagator can decay into.
    for i in range(0, len(s_channel_propagators)):

        propagator_pdg = s_channel_propagators[i]

        for j in range(0, len(three_fields)):

            curr_vertex = three_fields[j][:]

            if curr_vertex.count(propagator_pdg) >= 1:
                # Copy the vertex & remove one instance of the propagator.
                curr_vertex.remove(
                    curr_vertex[curr_vertex.index(propagator_pdg)])
                dm_dm_to_x_y.append(curr_vertex)

    # t/u-channel: sticking together
    # DM + stuff -> propagator & propagator -> DMbar + otherstuff

    t_channel_propagators = []
    t_channel_potential = []

    # self-conj:
    if dm.is_sc():

        dm_verts = v_with_dm + v_with_2dm
        verts = dm_verts[:]

        # Remove one instance of DM from each vertex -- the incoming DM.
        for i in range(0, len(verts)):
            verts[i].remove(verts[i][verts[i].index(dm.PDG_code)])
            t_channel_potential.append(verts[i])

        vertsbar = verts

    elif not dm.is_sc():

        verts = v_with_dm[:]
        vertsbar = v_with_dmbar[:]

        # Remove one instance of DM from each vertex -- the incoming DM.
        for i in range(0, len(verts)):
            verts[i].remove(verts[i][verts[i].index(dm.PDG_code)])
            t_channel_potential.append(verts[i])

        # Remove DMbar from each vertex too -- also incoming.
        for i in range(0, len(vertsbar)):
            vertsbar[i].remove(
                vertsbar[i][vertsbar[i].index(dm.Conjugate.PDG_code)])

    # Remove any duplicate t-channel props.
    t_channel_propagators = list(set(t_channel_propagators))

    for i in range(0, len(t_channel_potential)):

        for j in range(0, len(vertsbar)):

            curr_vertex = vertsbar[j][:]

            if dm.spinX2 != 1:
                for k in range(2):
                    # If the mediator shows up in the DMbar ->
                    # add the two products and the mediator to respective lists.
                    if t_channel_potential[i][k] in curr_vertex:
                        ind = curr_vertex.index(t_channel_potential[i][k])
                        dm_dm_to_x_y.append([t_channel_potential[i][k - 1],
                                             curr_vertex[ind - 1]])
                        t_channel_propagators.append(t_channel_potential[i][k])

            # If DM is fermionic -> also allowed fermionic t-channel prop
            # TODO -- this requires continuous fermion chain
            else:
                pass

    propagators = s_channel_propagators + t_channel_propagators
    propagators[:] = list(set(propagators))

    # Remove all duplicates within the list of annihilation products.
    ann_products = map(list,
                       sorted(set(map(tuple, dm_dm_to_x_y)), reverse=True))
    # Remove any DM-DM self-interactions
    if [dm.PDG_code, dm.Conjugate.PDG_code] in ann_products:
        ann_products.remove([dm.PDG_code, dm.Conjugate.PDG_code])
    return np.array(ann_products), propagators


def xsecs(dm, ann_products, gambit_pdg_dict, gambit_model_name,
          calchep_pdg_dict):
    """
    Writes all entries for <sigma v> within the Process Catalogue,
    utilising CalcHEP.
    """

    # DM mass parameter
    gb_id = pdg_to_particle(dm.PDG_code, gambit_pdg_dict)
    dm_mass = "m" + gb_id.replace("\"", "")

    # Arrays of final states (GAMBIT names)
    out1g = np.array([pdg_to_particle(x, gambit_pdg_dict) for x in ann_products[:,0]])
    out2g = np.array([pdg_to_particle(x, gambit_pdg_dict) for x in ann_products[:,1]])
    # DM (and conjugate) as known to CalcHEP
    dm_chep = pdg_to_particle(dm.PDG_code, calchep_pdg_dict)
    dm_chepc = pdg_to_particle(dm.Conjugate.PDG_code, calchep_pdg_dict)

    towrite_class = (
            "// Annihilation cross-section. sigmav is a pointer to a"
            " CalcHEP backend function.\n"
            "double sv(str channel, DecayTable& tbl, "
            "double (*sigmav)(str&, std::vector<str>&, std::vector<str>&, "
            "double&, double&, const DecayTable&), double v_rel)\n"
            "{{\n"
            "/// Returns sigma*v for a given channel.\n"
            "double GeV2tocm3s1 = gev2cm2*s2cm;\n\n"
            "/// Hard-coded for now -- CalcHEP frontend needs this removing anyway, it doesn't use it.\n"
            "double QCD_coupling = 1.0;\n\n"
            "// CalcHEP args\n"
            "str model = \"{0}\"; // CalcHEP model name\n"
            "std::vector<str> in = {{\"{1}\", \"{2}\"}}; // In states: DM+DMbar\n"
            "std::vector<str> out; // Out states\n"
    ).format(gambit_model_name, dm_chep, dm_chepc)

    # Add each channel individually for annihilation cross sections
    for i in np.arange(len(ann_products)):
        towrite_class += (
                "if (channel == \"{0}, {1}\") "
                "out = {{\"{0}\", \"{1}\"}};\n"
        ).format(out1g[i], out2g[i])

    towrite_class += (
            "\n"
            "// Check the channel has been filled\n"
            "if (out.size() > 1) return "
            "sigmav(model, in, out, QCD_coupling, v_rel, tbl)*GeV2tocm3s1;\n"
            "else return 0;\n"
            "}\n\n"
    )

    channels = ', '.join("\"{}, {}\"".format(*t) for t in zip(out1g, out2g))
    p1 = ', '.join("\"{}\"".format(*t) for t in zip(out1g))
    p2 = ', '.join("\"{}\"".format(*t) for t in zip(out2g))

    towrite_pc = (
            "// Instantiate new {0} object.\n"
            "auto pc = boost::make_shared<{0}>();\n"
            "\n"
            "// Populate annihilation channel list and add "
            "thresholds to threshold list.\n"
            "process_ann.resonances_thresholds.threshold_energy"
            ".push_back(2*{1});\n"
            "auto channels = \n"
            "  daFunk::vec<string>({2});\n"
            "auto p1 = \n"
            "  daFunk::vec<string>({3});\n"
            "auto p2 = \n"
            "  daFunk::vec<string>({4});\n"
            "\n"
            "for (unsigned int i = 0; i < channels.size(); ++i)\n"
            "{{\n"
            "double mtot_final = \n"
            "catalog.getParticleProperty(p1[i]).mass + \n"
            "catalog.getParticleProperty(p2[i]).mass;  \n"
            "if ({1}*2 > mtot_final*0.5)\n"
            "{{\n"
            "daFunk::Funk kinematicFunction = daFunk::funcM("
            "pc, &{0}::sv, channels[i], tbl, "
            "BEreq::CH_Sigma_V.pointer(), daFunk::var(\"v\"));\n"
            "TH_Channel new_channel("
            "daFunk::vec<string>(p1[i], p2[i]), kinematicFunction);\n"
            "process_ann.channelList.push_back(new_channel);\n"
            "}}\n"
            "if ({1}*2 > mtot_final)\n"
            "{{\n"
            "process_ann.resonances_thresholds.threshold_energy.\n"
            "push_back(mtot_final);\n"
            "}}\n"
            "}}\n"
            "\n"
    ).format(gambit_model_name, dm_mass, channels, p1, p2)

    return towrite_class, towrite_pc

def proc_cat(dm, sv, ann_products, propagators, gambit_pdg_dict,
             gambit_model_name, calchep_pdg_dict, model_specific_particles,
             exclude_decays):
    """
    Writes all entries for the Process Catalogue for DarkBit.
    """

    gb_id = pdg_to_particle(dm.PDG_code, gambit_pdg_dict)
    gb_conj = pdg_to_particle(dm.Conjugate.PDG_code, gambit_pdg_dict)

    towrite = (
            "class {0}\n"
            "{{\n"
            "public:\n"
            "/// Initialize {0} object (branching ratios etc)\n"
            "{0}() {{}};\n"
            "~{0}() {{}};\n\n"
    ).format(gambit_model_name)

    if sv:
        sv_class, sv_src = xsecs(dm, ann_products, gambit_pdg_dict,
                                 gambit_model_name, calchep_pdg_dict)
        towrite += sv_class

    towrite += (
            "\n"
            "}};\n\n"
            "void TH_ProcessCatalog_{0}(DarkBit::TH_ProcessCatalog &result)\n"
            "{{\n"
            "using namespace Pipes::TH_ProcessCatalog_{0};\n"
            "using std::vector;\n"
            "using std::string;\n\n"
            "// Initialize empty catalog, main annihilation process\n"
            "TH_ProcessCatalog catalog;\n"
            "TH_Process process_ann(\"{1}\", \"{2}\");"
            "\n"
    ).format(gambit_model_name, gb_id, gb_conj)

    # Add flag for (non-)self-conjugate DM to rescale spectra properly
    if not dm.is_sc():
        towrite += (
                "\n"
                "// Explicitly state that Dirac DM is not self-conjugate to add"
                " extra \n// factors of 1/2 where necessary\n"
                "process_ann.isSelfConj = false;\n\n"
        )
    else:
        towrite += (
                "\n"
                "// Explicitly state that DM is self-conjugate\n"
                "process_ann.isSelfConj = true;\n\n"
        )

    towrite += add_SM_macros(gambit_model_name)

    # Add the new BSM particles to the Process Catalog
    dm_mass = "m" + gb_id.replace("\"", "")

    towrite += (
            "// {0}-specific masses\n"
            "double {1} = spec.get(Par::Pole_Mass, \"{2}\");\n"
            "addParticle(\"{2}\", {1}, {3});\n"
    ).format(gambit_model_name, dm_mass, gb_id, dm.spinX2)

    for i in np.arange(len(model_specific_particles)):
        if model_specific_particles[i].PDG_code != dm.PDG_code:
          towrite += (
                  "addParticle(\"{0}\", spec.get(Par::Pole_Mass, \"{1}\"), {2});\n"
          ).format(pdg_to_particle(model_specific_particles[i].PDG_code, gambit_pdg_dict),
                   pdg_to_particle(model_specific_particles[i].PDG_code, gambit_pdg_dict),
                   str(model_specific_particles[i].spinX2))

    towrite += (
            "\n"
            "// Get rid of convenience macros\n"
            "#undef getSMmass\n"
            "#undef addParticle\n"
            "\n"
            "// Import decay table from DecayBit\n"
            "DecayTable tbl = *Dep::decay_rates;\n"
            "\n"
            "// Set of imported decays\n"
            "std::set<string> importedDecays;\n"
            "\n"
            "// Minimum branching ratio to include\n"
            "double minBranching = runOptions->getValueOrDef<double>(0.0,"
            " \"ProcessCatalog_MinBranching\");\n"
            "\n"
            "// Import relevant decays\n"
            "using DarkBit_utils::ImportDecays;\n"
            "\n"
            "//      *** TODO: excludeDecays?? ***\n"
            "//      *** And ImportDecays!! For all propagators? ***\n"
            "//      *** and all final states?? Which to exclude...?\n"
            "\n"
    )

    if sv:
        towrite += sv_src

    if propagators:

        for i in np.arange(len(propagators)):
            if abs(propagators[i]) != abs(dm.PDG_code):
                towrite += (
                        "if (spec.get(Par::Pole_Mass, \"{0}\") >= 2*{1}) "
                        "process_ann.resonances_thresholds.resonances.\n    "
                        "push_back(TH_Resonance(spec.get(Par::Pole_Mass, \"{0}\"), "
                        "tbl.at(\"{0}\").width_in_GeV));\n"
                ).format(pdg_to_particle(propagators[i], gambit_pdg_dict),
                     dm_mass)

    towrite += (
            "\n"
            "catalog.processList.push_back(process_ann);\n\n"
            "// Validate\n"
            "catalog.validate();\n\n"
            "result = catalog;\n"
            "} // function TH_ProcessCatalog\n"
    )

    return towrite


def write_darkbit_src(dm, pc, sv, dd, ann_products, propagators,
                      gambit_pdg_dict, gambit_model_name, calchep_pdg_dict,
                      model_specific_particles, exclude_decays = []):
    """
    Collects all source for DarkBit: process catalogue, direct detection...
    """

    gb_id = pdg_to_particle(dm.PDG_code, gambit_pdg_dict)
    gb_conj = pdg_to_particle(dm.Conjugate.PDG_code, gambit_pdg_dict)

    if not isinstance(dm, Particle):
        print("DM not passed over as an instance of class Particle.")
        exit()

    intro_message = (
            "///  Implementation of {0}\n"
            "///  DarkBit routines."
    ).format(gambit_model_name)

    towrite = blame_gum(intro_message)

    towrite += (
            "#include \"gambit/Elements/gambit_module_headers.hpp\"\n"
            "#include \"gambit/DarkBit/DarkBit_rollcall.hpp\"\n"
            "#include \"gambit/Utils/ascii_table_reader.hpp\"\n"
            "#include \"boost/make_shared.hpp\"\n"
            "#include \"gambit/DarkBit/DarkBit_utils.hpp\"\n"
            "\n"
            "namespace Gambit\n"
            "{\n"
            "namespace DarkBit\n"
            "{\n"
    )

    if pc:
        towrite += proc_cat(dm, sv, ann_products, propagators,
                            gambit_pdg_dict, gambit_model_name,
                            calchep_pdg_dict, model_specific_particles,
                            exclude_decays)

    if dd:
        towrite += write_direct_detection(gambit_model_name)

    towrite += write_dm_id(gambit_model_name, gb_id)

    towrite += (
            "} //namespace DarkBit\n\n"
            "} //namespace Gambit\n"
            "\n"
    )

    return indent(towrite)

def write_dm_id(model_name, dm_id):
    """
    Returns entry for DarkMatter_ID in DarkBit.
    """

    towrite = (
            "\n"
            "void DarkMatter_ID_{0}(std::string& result)"
            "{{ result = \"{1}\"; }}"
            "\n\n"
    ).format(model_name, dm_id)

    return towrite;

def add_SM_macros(gambit_model_name):
    """
    Adds Standard Model macros to the Process Catalogue.
    """

    towrite = (
            "\n"
            "// Import particle masses \n"
            "\n"
            "// Convenience macros\n"
            "#define getSMmass(Name, spinX2) "
            "catalog.particleProperties.insert(std::pair<string, "
            "TH_ParticleProperty> (Name, TH_ParticleProperty"
            "(SM.get(Par::Pole_Mass,Name), spinX2)));\n"
            "#define addParticle(Name, Mass, spinX2) "
            "catalog.particleProperties.insert(std::pair<string, "
            "TH_ParticleProperty> (Name, "
            "TH_ParticleProperty(Mass, spinX2)));\n"
            "\n"
            "// Import Spectrum objects\n"
            "const Spectrum& spec = *Dep::{0}_spectrum;\n"
            "const SubSpectrum& SM = spec.get_LE();\n"
            "const SMInputs& SMI   = spec.get_SMInputs();\n"
            "\n"
            "// Get SM pole masses\n"
            "getSMmass(\"e-_1\",     1)\n"
            "getSMmass(\"e+_1\",     1)\n"
            "getSMmass(\"e-_2\",     1)\n"
            "getSMmass(\"e+_2\",     1)\n"
            "getSMmass(\"e-_3\",     1)\n"
            "getSMmass(\"e+_3\",     1)\n"
            "getSMmass(\"Z0\",       2)\n"
            "getSMmass(\"W+\",       2)\n"
            "getSMmass(\"W-\",       2)\n"
            "getSMmass(\"g\",        2)\n"
            "getSMmass(\"gamma\",    2)\n"
            "getSMmass(\"u_3\",      1)\n"
            "getSMmass(\"ubar_3\",   1)\n"
            "getSMmass(\"d_3\",      1)\n"
            "getSMmass(\"dbar_3\",   1)\n"
            "\n"
            "// Pole masses not available for the light quarks.\n"
            "addParticle(\"u_1\"   , SMI.mU,  1) // mu(2 GeV)^MS-bar\n"
            "addParticle(\"ubar_1\", SMI.mU,  1) // mu(2 GeV)^MS-bar\n"
            "addParticle(\"d_1\"   , SMI.mD,  1) // md(2 GeV)^MS-bar\n"
            "addParticle(\"dbar_1\", SMI.mD,  1) // md(2 GeV)^MS-bar\n"
            "addParticle(\"u_2\"   , SMI.mCmC,1) // mc(mc)^MS-bar\n"
            "addParticle(\"ubar_2\", SMI.mCmC,1) // mc(mc)^MS-bar\n"
            "addParticle(\"d_2\"   , SMI.mS,  1) // ms(2 GeV)^MS-bar\n"
            "addParticle(\"dbar_2\", SMI.mS,  1) // ms(2 GeV)^MS-bar\n"
            "\n"
            "// Masses for neutrino flavour eigenstates. Set to zero.\n"
            "// (presently not required)\n"
            "addParticle(\"nu_e\",     0.0, 1)\n"
            "addParticle(\"nubar_e\",  0.0, 1)\n"
            "addParticle(\"nu_mu\",    0.0, 1)\n"
            "addParticle(\"nubar_mu\", 0.0, 1)\n"
            "addParticle(\"nu_tau\",   0.0, 1)\n"
            "addParticle(\"nubar_tau\",0.0, 1)\n"
            "\n"
            "// Meson masses\n"
            "addParticle(\"pi0\",   meson_masses.pi0,       0)\n"
            "addParticle(\"pi+\",   meson_masses.pi_plus,   0)\n"
            "addParticle(\"pi-\",   meson_masses.pi_minus,  0)\n"
            "addParticle(\"eta\",   meson_masses.eta,       0)\n"
            "addParticle(\"rho0\",  meson_masses.rho0,      1)\n"
            "addParticle(\"rho+\",  meson_masses.rho_plus,  1)\n"
            "addParticle(\"rho-\",  meson_masses.rho_minus, 1)\n"
            "addParticle(\"omega\", meson_masses.omega,     1)\n"
            "\n"
    ).format(gambit_model_name)

    return towrite

def write_direct_detection(model_name):
    """
    Writes direct detection bits in DarkBit... TODO
    """

    towrite = (
            "\n"
            "/// Direct detection couplings.\n"
            "void DD_couplings_{0}(DM_nucleon_couplings & result)\n"
            "{{\n"
            "using namespace Pipes::DD_couplings_{0};\n"
            "const Spectrum& spec = *Dep::{0}_spectrum;\n"
            "\n"
            "  *** TODO *** \n"
            "result.gps = ();\n"
            "result.gns = ();\n"
            "result.gpa = ();\n"
            "result.gna = ();\n"
            "\n"
            "logger() << LogTags::debug << '{0} DD couplings:' << std::endl;\n"
            "logger() << ' gps = ' << result.gps << std::endl;\n"
            "logger() << ' gns = ' << result.gns << std::endl;\n"
            "logger() << ' gpa = ' << result.gpa << std::endl;\n"
            "logger() << ' gna = ' << result.gna << EOM;\n"
            "\n"
            "}}\n"
            "\n"
    ).format(model_name)

    return towrite

def write_darkbit_rollcall(model_name, pc, dd):
    """
    Writes the rollcall header entries for new DarkBit entry.
    """

    if pc:
        pro_cat = dumb_indent(4, (
                "#define FUNCTION TH_ProcessCatalog_{0}\n"
                "  START_FUNCTION(DarkBit::TH_ProcessCatalog)\n"
                "  DEPENDENCY(decay_rates, DecayTable)\n"
                "  DEPENDENCY({0}_spectrum, Spectrum)\n"
                "  BACKEND_REQ(CH_Sigma_V, (), double, (str&, std::vector<str>&, "
                "std::vector<str>&, double&, double&, const DecayTable&))\n"
                "  ALLOW_MODELS({0})\n"
                "#undef FUNCTION\n"
        ).format(model_name))
    else:
        pro_cat = None

    if dd:
        dir_det = dumb_indent(4, (
                "#define FUNCTION DD_couplings_{0}\n"
                "START_FUNCTION(DM_nucleon_couplings)\n"
                "DEPENDENCY({0}_spectrum, Spectrum)\n"
                "*** TODO *** \n"
                "#undef FUNCTION\n"
        ).format(model_name))
    else:
        dir_det = None

    dm_id = dumb_indent(4, (
            "#define FUNCTION DarkMatter_ID_{0}\n"
            "START_FUNCTION(std::string)\n"
            "ALLOW_MODELS({0})\n"
            "#undef FUNCTION\n"
    ).format(model_name))

    return pro_cat, dir_det, dm_id



def write_micromegas_src(gambit_model_name, spectrum, mathpackage, params,
                         particles, gambit_pdg_codes, calchep_masses, 
                         calchep_widths):
    """
    Writes frontend source and header files for a new MicrOmegas model.

    Needs to know whether the source code is generated by FeynRules or SARAH
    since SM-ish things like quark masses, gauge couplings, etc are hard-coded.
    """

    ## Frontend source file
    intro_message = (
            "///  Frontend for MicrOmegas {0}\n"
            "///  3.6.9.2 backend."
    ).format(gambit_model_name)

    mo_src = blame_gum(intro_message)

    mo_src += (
            "#include \"gambit/Backends/frontend_macros.hpp\"\n"
            "#include \"gambit/Backends/frontends/MicrOmegas_{0}_3_6_9_2.hpp\"\n"
            "#include <unistd.h>\n"
            "\n"
            "// Convenience functions (definitions)\n"
            "BE_NAMESPACE\n"
            "{{\n"
            "double dNdE(double Ecm, double E, int inP, int outN)\n"
            "{{\n"
            "// outN 0-5: gamma, e+, p-, nu_e, nu_mu, nu_tau\n"
            "// inP:  0 - 6: glu, d, u, s, c, b, t\n"
            "//       7 - 9: e, m, l\n"
            "//       10 - 15: Z, ZT, ZL, W, WT, WL\n"
            "double tab[250];  // NZ = 250\n"
            "// readSpectra() moved to initialization function.\n"
            "// Must be inside critical block if used here!\n"
            "// readSpectra();\n"
            "mInterp(Ecm/2, inP, outN, tab);\n"
            "return zInterp(log(E/Ecm*2), tab);\n"
            "}}\n"
            "}}\n"
            "END_BE_NAMESPACE\n"
            "\n"
            "// Initialisation function (definition)\n"
            "BE_INI_FUNCTION\n"
            "{{\n"
            "int error;\n"
            "char cdmName[10];\n"
            "\n"
            "const Spectrum& spec = *Dep::{1};\n"
            "const SMInputs& sminputs = spec.get_SMInputs();\n"
            "\n"
            "// YAML options for 3-body final states\n"
            "int VZdecayOpt, VWdecayOpt; // 0=no 3 body final states\n"
            "                            // 1=3 body final states in annihlations\n"
            "                            // 2=3 body final states in co-annihilations\n"
            "VZdecayOpt = runOptions->getValueOrDef<int>(1, \"VZdecay\");\n"
            "VWdecayOpt = runOptions->getValueOrDef<int>(1, \"VWdecay\");\n"
            "*VZdecay = VZdecayOpt;\n"
            "*VWdecay = VWdecayOpt;\n"
            "\n"
            "logger() << LogTags::debug << \""
            "Initializing MicrOmegas {0} with \";\n"
            "logger() << \"VWdecay: \" << VWdecay << \" VZdecay: \" << VZdecay << EOM;\n"
            "\n"
            "// Uncomment below to force MicrOmegas to do calculations in unitary gauge\n"
            "*ForceUG=1;\n"
            "\n"
    ).format(gambit_model_name, spectrum)

    # Now we must assign the GAMBIT values for each parameter to MO for
    # computation. First define a little function to make this neater. 
    mo_src += (
            "/// Assigns gambit value to parameter, with error-checking.\n"
            "void Assign_Value(char *parameter, double value)\n"
            "{\n"
            "int error;\n"
            "error = assignVal(parameter, value);\n"
            "if (error != 0) backend_error().raise(LOCAL_INFO, \""
            "Unable to set \" + std::string(parameter) +\n"
            "    \" in MicrOmegas. MicrOmegas error code: \" + std::to_string(error)"
            "+ \". Please check your model files.\\n\");\n"
            "}\n\n"
            "// BSM parameters\n"
    )

    donotassign = ["vev", "sinW2", "Yu", "Ye", "Yd", "g1", "g2", "g3"]

    # Firstly assign all BSM model parameters
    for param in params:

        # Internally computed
        if param.name in donotassign: continue

        # Ignore the pole masses - do these separately
        if  param.tag == "Pole_Mass": continue

        # Scalar case
        if param.shape == "scalar":
            mo_src += (
                    "Assign_Value((char*)\"{0}\", spec.get(Par::{1}, \"{2}\"));\n"
            ).format(param.name, param.tag, param.alt_name)

        # Vector case
        if param.shape.startswith('v'):
            size = param.shape[1:]
            mo_src += (
                "for(int i=1; i<{0}; i++)\n{{\n"
                "std::string paramname = \"{2}\" + std::to_string(i);\n"
                "Assign_Value((char*)paramname, spec.get(Par::{3}, \"{4}\"));\n"
                "}}\n"
            ).format(i, j, param.name, param.tag, param.alt_name)

        # Matrix case
        if param.shape.startswith('m'):
            size = param.shape[1:]
            i,j = size.split('x')

            mo_src += (
                "for(int i=1; i<{0}; i++)\n{{\n"
                "for(int j=1; j<{1}; j++)\n{{\n"
                "std::string paramname = \"{2}\" + std::to_string(i) + std::to_string(j);\n"
                "Assign_Value((char*)paramname, spec.get(Par::{3}, \"{4}\"));\n"
                "}}\n}}\n"
            ).format(i, j, param.name, param.tag, param.alt_name)


    # Do pole masses now
    mo_src += "// Masses\n"
    for part in particles:

        chname = calchep_masses[part.PDG_code]
        gbname = pdg_to_particle(part.PDG_code, gambit_pdg_codes)

        mo_src += (
               "Assign_Value((char*)\"{0}\", spec.get(Par::Pole_Mass, \"{1}\"));\n"
        ).format(chname, gbname)

    # SMInputs
    mo_src += "\n// SMInputs\n"

    SMinputs = {1 : 'mD', 2 : 'mU', 3 : 'mS', 4 : 'mCmC', 5:'mBmB', 6:'mT',
                11: 'mE', 13: 'mMu', 15: 'mTau', 23: 'mZ'}

    for pdg, chmass in calchep_masses.iteritems():
        if pdg in SMinputs:
            mo_src += (
                "Assign_Value((char*)\"{0}\", sminputs.{1});\n"
            ).format(chmass, SMinputs[pdg])


    # TODO GF, aS, aEWinv
    # # These are handled slightly differently by SARAH and FeynRules
    # if mathpackage == 'sarah':
    #     print("MO SARAH support not implemented yet.")

        
    # elif mathpackage == 'feynrules':
    #     print("MO FeynRules support not implemented yet.")
    #     # Do a different thing

    # Widths
    mo_src += (
            "\n"
            "// Set particle widths in micrOmegas\n"
            "const DecayTable* tbl = &(*Dep::decay_rates);\n"
            "double width = 0.0;\n"
            "bool present = true;\n"
            "\n"
    )

    for pdg, chwidth in calchep_widths.iteritems():
        mo_src += (
               "try {{ width = tbl->at(\"{0}\").width_in_GeV; }}\n"
               " catch(std::std::exception& e) {{ present = false; }}\n"
               "if (present) Assign_Value((char*)\"{1}\", width);\n"
               "present = true;\n\n"
        ).format(pdg_to_particle(pdg, gambit_pdg_codes), chwidth)



    # Get MicrOmegas to do it's thing.
    mo_src += (
            "// Initialise micrOMEGAs mass spectrum\n"
            "error = sortOddParticles(byVal(cdmName));\n"
            "if (error != 0) backend_error().raise(LOCAL_INFO, \"MicrOmegas function \"\n"
            "        \"sortOddParticles returned error code: \" + std::to_string(error));\n"
            "\n"
            "}\n"
            "END_BE_INI_FUNCTION\n"
    )

    return indent(mo_src)

def write_micromegas_header(gambit_model_name, mathpackage, params):
    """
    Writes a header file for micromegas.
    """

    ## Frontend source file
    intro_message = (
            "///  Frontend for MicrOmegas {0}\n"
            "///  3.6.9.2 backend."
    ).format(gambit_model_name)

    # Frontend header file
    mo_head = blame_gum(intro_message)

    mo_head += (
            "\n"
            "#define BACKENDNAME MicrOmegas_{0}\n"
            "#define BACKENDLANG CC\n"
            "#define VERSION 3.6.9.2\n"
            "#define SAFE_VERSION 3_6_9_2\n"
            "\n"
            "LOAD_LIBRARY\n"
            "\n"
            "BE_ALLOW_MODELS({0})\n"
            "\n"
            "BE_FUNCTION(assignVal, int, (char*,double),\"assignVal\",\"assignVal\")\n"
            "BE_FUNCTION(vSigma, double, (double, double, int), \"vSigma\",\"vSigma\")\n"
            "BE_FUNCTION(darkOmega, double, (double*, int, double), \"darkOmega\", \"oh2\")\n"
            "BE_FUNCTION(sortOddParticles, int, (char*), \"sortOddParticles\",\"mass_spectrum\")\n"
            "BE_FUNCTION(cleanDecayTable, void, (), \"cleanDecayTable\", \"cleanDecayTable\")\n"
            "BE_FUNCTION(nucleonAmplitudes, int, (double(*)(double,double,double,double), double*, double*, double*, double*), \"nucleonAmplitudes\", \"nucleonAmplitudes\")\n"
            "BE_FUNCTION(FeScLoop, double, (double, double, double, double), \"FeScLoop\", \"FeScLoop\")\n"
            "BE_FUNCTION(calcScalarQuarkFF, void, (double, double, double, double), \"calcScalarQuarkFF\", \"calcScalarQuarkFF\")\n"
            "BE_FUNCTION(calcSpectrum, double, (int, double*, double*, double*, double*, double*, double*, int*), \"calcSpectrum\", \"calcSpectrum\")\n"
            "BE_FUNCTION(printChannels, double, (double, double, double, int, FILE*), \"printChannels\", \"momegas_print_channels\")\n"
            "BE_FUNCTION(oneChannel, double, (double,double,char*,char*,char*,char*), \"oneChannel\", \"get_oneChannel\")\n"
            "BE_FUNCTION(mInterp, int, (double,int,int,double*) , \"mInterp\", \"mInterp\")\n"
            "BE_FUNCTION(zInterp, double, (double,double*) , \"zInterp\", \"zInterp\")\n"
            "BE_FUNCTION(readSpectra, int, (), \"readSpectra\", \"readSpectra\")\n"
            "\n"
            "BE_VARIABLE(mocommon_, MicrOmegas::MOcommonSTR, \"mocommon_\", \"MOcommon\")\n"
            "BE_VARIABLE(vSigmaCh, MicrOmegas::aChannel*, \"vSigmaCh\", \"vSigmaCh\")\n"
            "BE_VARIABLE(ForceUG, int, \"ForceUG\", \"ForceUG\")\n"
            "BE_VARIABLE(VZdecay, int, \"VZdecay\", \"VZdecay\")\n"
            "BE_VARIABLE(VWdecay, int, \"VWdecay\", \"VWdecay\")\n"
            "\n"
            "BE_CONV_FUNCTION(dNdE, double, (double,double,int,int), \"dNdE\")\n"
            "\n"
            "BE_INI_DEPENDENCY({0}_spectrum, Spectrum)\n"
            "BE_INI_DEPENDENCY(decay_rates, DecayTable)\n"
            "\n"
            "#include \"gambit/Backends/backend_undefs.hpp\"\n"
    ).format(gambit_model_name)

    return indent(mo_head)


def copy_micromegas_files(model_name):
    """
    Creates a copy of micrOMEGAs files in $BACKENDS/patches
    """

    # The location of the cleaned (GAMBIT-friendly) CH files
    ch_location = "./../Backends/patches/calchep/3.6.27/Models/" + model_name

    # Move the CH files to patches to copy across
    gb_target = "./../Backends/patches/micromegas/3.6.9.2/" + model_name + "/mdlfiles"
    if not os.path.exists(gb_target):
        os.makedirs(gb_target)

    shutil.copyfile(ch_location + "/func1.mdl", gb_target + "/func1.mdl")
    shutil.copyfile(ch_location + "/vars1.mdl", gb_target + "/vars1.mdl")
    shutil.copyfile(ch_location + "/lgrng1.mdl", gb_target + "/lgrng1.mdl")
    shutil.copyfile(ch_location + "/prtcls1.mdl", gb_target + "/prtcls1.mdl")
    shutil.copyfile(ch_location + "/extlib1.mdl", gb_target + "/extlib1.mdl")

    print("micrOMEGAs files moved to backend dir.")

def patch_micromegas(model_name, reset_dict):
    """
    Patches micrOMEGAs' Makefile to make it usable as a
    shared library. This is generic for every new model.
    """

    towrite = (
        "--- {0}/Makefile    2014-04-03 15:29:30.000000000 +0100\n"
        "+++ {0}/Makefile_patched    2019-10-08 16:23:45.576576545 +0100\n"
        "@@ -45,6 +45,13 @@ libs:\n"
        "    $(MAKE) -C work\n"
        "    $(MAKE) -C lib\n"
        "\n"
        "+sharedlib: all\n"
        "+ifeq (,$(main)) \n"
        "+\t@echo Main program is not specified. Use gmake main='<code of main program>'\n"
        "+else  \n"
        "+\t$(CXX) -shared -fPIC -o libmicromegas.so $(main) $(SSS) $(lDL)\n"
        "+endif\n"
        "+\n"
        " clean: \n"
        "    $(MAKE) -C lib  clean\n"
        "    $(MAKE) -C work clean \n"
    ).format(model_name)

    filename = "micromegas/3.6.9.2/"+model_name+"/patch_micromegas_3.6.9.2_"+model_name+".dif"

    write_file(filename, "Backends", towrite, reset_dict)
    
    print("micrOMEGAs files patched.")

def add_micromegas_to_cmake(model_name, reset_dict):
    """
    Add a new entry to cmake/backends.cmake for micrOMEGAs_<NEWMODEL>
    """

    towrite = (
            "\n"
            "# MicrOmegas "+model_name+" model\n"
            "set(model \""+model_name+"\")\n"
            "set(patch \"${PROJECT_SOURCE_DIR}/Backends/patches/${name}/${ver}/"+model_name+"/patch_${name}_${ver}_${model}.dif\")\n"
            "set(patchdir \"${PROJECT_SOURCE_DIR}/Backends/patches/${name}/${ver}/"+model_name+"\")\n"
            "check_ditch_status(${name}_${model} ${ver} ${dir})\n"
            "if(NOT ditched_${name}_${model}_${ver})\n"
            "  ExternalProject_Add(${name}_${model}_${ver}\n"
            "    DOWNLOAD_COMMAND \"\"\n"
            "    SOURCE_DIR ${dir}\n"
            "    PATCH_COMMAND ./newProject ${model} && patch -p0 < ${patch}\n"
            "    CONFIGURE_COMMAND ${CMAKE_COMMAND} -E copy_directory ${patchdir}/mdlfiles ${dir}/${model}/work/models/\n"
            "    BUILD_IN_SOURCE 1\n"
            "    CONFIGURE_COMMAND \"\"\n"
            "    BUILD_COMMAND ${CMAKE_COMMAND} -E chdir ${model} ${CMAKE_MAKE_PROGRAM} sharedlib main=main.c\n"
            "    INSTALL_COMMAND \"\"\n"
            "  )\n"
            "  add_extra_targets(\"backend model\" ${name} ${ver} ${dir}/${model} ${model} \"yes | clean\")\n"
            "  set_as_default_version(\"backend model\" ${name}_${model} ${ver})\n"
            "endif()\n"
            "\n"
    )

    add_to_backends_cmake(towrite, reset_dict, string_to_find="# Pythia")

def add_micromegas_to_darkbit_rollcall(model_name, reset_dict):
    """
    Adds entries to the DarkBit rollcall for micrOMEGAs routines.
    - RD_oh2_Xf_MicrOmegas
        - new BACKEND_OPTION
        - adds to ALLOW_MODELS
    - DD_couplings_MicrOmegas
        - new BACKEND_OPTION
        - adds to ALLOW_MODEL_DEPENDENCE
        - adds to MODEL_GROUP(group2 (...))
    """

    rollcall = full_filename("DarkBit_rollcall.hpp", "DarkBit")

    

                # Function                  # Capability    # String to write above
    entries = [ ["RD_oh2_Xf_MicrOmegas",    "RD_oh2_Xf",    "ALLOW_MODELS"],
                ["DD_couplings_MicrOmegas", "DD_couplings", "FORCE_SAME_BACKEND"] ]

    # Add the backend options to each entry - relic density and direct detection
    for entry in entries:
        function = entry[0]
        capability = entry[1]
        pattern = entry[2]

        # Find the CAPABILITY + FUNCTIONfunction RD_oh2_Xf_MicrOmegas
        exists, line = find_function(function, capability, "DarkBit")

        if not exists:
            raise GumError(("Function {0} not found in DarkBit_rollcall.hpp. "
                            "It should be there!").format(function))
    
        # Now find the ALLOW_MODELS for the CAPABILITY
        linenum = 0
        with open(rollcall, 'r') as f:
            # Start from the beginning of the FUNCTION
            for i in xrange(line):
                f.next()
            for num, line in enumerate(f, line):
                if pattern in line: 
                    linenum = num
                    break

        # What we want to write    
        towrite = "      BACKEND_OPTION((MicrOmegas_{}),(gimmemicro))\n".format(model_name)

        if linenum != 0:
            amend_file("DarkBit_rollcall.hpp", "DarkBit", towrite, linenum, reset_dict)
        else:
            raise GumError(("Could not find the string ALLOW_MODELS in DarkBit_rollcall, " 
                            "which is very weird."))

    # Add the model to the function arguments
    file = "DarkBit_rollcall.hpp"
    module = "DarkBit"
    add_new_model_to_function(file, module, "RD_oh2_Xf", 
                              "RD_oh2_Xf_MicrOmegas", model_name, reset_dict, 
                              pattern="ALLOW_MODELS")    
    add_new_model_to_function(file, module, "DD_couplings", 
                              "DD_couplings_MicrOmegas", model_name, 
                              reset_dict, pattern="ALLOW_MODEL_DEPENDENCE")   
    add_new_model_to_function(file, module, "DD_couplings", 
                              "DD_couplings_MicrOmegas", model_name, 
                              reset_dict, pattern="MODEL_GROUP(group2")

    """
    Direct detection 
    """
    # # find the CAPABILITY DD_couplings, function DD_couplings_MicrOmegas
    # exists, line = find_function("DD_couplings_MicrOmegas", "DD_couplings", "DarkBit")

    # if not exists:
    #     raise GumError(("Function DD_couplings_MicrOmegas not found in DarkBit_rollcall.hpp. "
    #                     "It should be there!"))

    # # Now find the ALLOW_MODELS for the CAPABILITY
    # linenum = 0
    # with open(rollcall, 'r') as f:
    #     # Start from the beginning of the FUNCTION
    #     for i in xrange(line):
    #         f.next()
    #     for num, line in enumerate(f, line):
    #         if 'ALLOW_MODELS' in line: 
    #             linenum = num
    #             break

    # # What we want to write    
    # towrite = "      BACKEND_OPTION((MicrOmegas_{}),(gimmemicro))\n".format(model_name)

    # if linenum != 0:
    #     amend_file("DarkBit_rollcall.hpp", "DarkBit", towrite, linenum, reset_dict)
    # else:
    #     raise GumError(("Could not find the string ALLOW_MODELS in DarkBit_rollcall, " 
    #                     "which is very weird."))