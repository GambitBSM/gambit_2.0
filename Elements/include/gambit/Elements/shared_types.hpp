//   GAMBIT: Global and Modular BSM Inference Tool
//   *********************************************
///  \file
///
///  Types used internally, returned and/or read
///  in by more than one backend, model or module.
///
///  *********************************************
///
///  Authors (add name and date if you modify):
///
///  \author Pat Scott
///          (patscott@physics.mcgill.ca)
///  \date 2013 Apr, Oct
///  \date 2014 Mar, Sep, Nov
///  \date 2015 Jan, Mar
///
///  \author Abram Krislock
///          (abram.krislock@fysik.su.se)
///  \date 2013 Dec
//
///  \author Christoph Weniger
///          (c.weniger@uva.nl)
///  \date 2014 Mar
///
///  \author Anders Kvellestad
///          (anderkve@fys.uio.no)
///  \date 2014 Oct
///
///  \author Ben Farmer
///          (benjamin.farmer@fysik.su.su)
///  \date 2015 Apr
///
///  \author Sebastian Wild
///          (sebastian.wild@ph.tum.de)
///  \date 2016 Aug
///
///  *********************************************

#ifndef __shared_types_hpp__
#define __shared_types_hpp__

#include "gambit/Utils/util_types.hpp"                 // General utility types useful to have around
#include "gambit/Utils/model_parameters.hpp"           // Definitions required to understand model parameter objects
#include "gambit/Utils/numerical_constants.hpp"        // Centralised constants header

#include "gambit/Elements/sminputs.hpp"                // Struct carrying SMINPUTS block (SLHA2)
#include "gambit/Elements/spectrum.hpp"                // Carries BSM plus Standard Model spectrum info
#include "gambit/Elements/decay_table.hpp"             // Decay table class (carries particle decay info)
#include "gambit/Elements/higgs_couplings_table.hpp"   // Higgs couplings table class (carries couplings info for entire Higgs sector)
#include "gambit/Elements/slhaea_helpers.hpp"          // Contains SLHAea reader/writer class alias
#include "gambit/Elements/halo_types.hpp"              // data types for DM halo properties

#include "gambit/Backends/default_bossed_versions.hpp" // Default versions of backends to use when employing BOSSed types
#include "gambit/Backends/backend_types_rollcall.hpp"  // All backend types (header is auto-generated by backend harvester).


// Other types that don't belong in any of the existing includes.  As the number of such types grows, they
// should be progressively organised into new headers, and those headers included from here.
namespace Gambit
{
  /// Pointer to a function that takes an integer by reference and returns a double.
  /// Just used for example purposes in ExampleBit_A and ExampleBit_B.
  typedef double(*fptr)(int&);

  /// A double in, double out function pointer
  typedef double(*fptr_dd)(double&);
}


#endif //__shared_types_hpp__


