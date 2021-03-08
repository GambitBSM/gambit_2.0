//==========================================================================
// This file has been automatically generated for Pythia 8 by
// MadGraph5_aMC@NLO v. 2.8.3.2, 2021-02-02
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#include "Sigma_MDMSM_gg_xchixchig.h"
#include "HelAmps_MDMSM.h"

using namespace Pythia8_MDMSM; 

namespace Pythia8 
{

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: g g > ~chi ~chi g NP<=2 WEIGHTED<=3 @2

//--------------------------------------------------------------------------
// Initialize process.

void Sigma_MDMSM_gg_xchixchig::initProc() 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_MDMSM::getInstance(); 
  pars->setIndependentParameters(particleDataPtr, couplingsPtr, slhaPtr); 
  pars->setIndependentCouplings(); 
  // Set massive/massless matrix elements for c/b/mu/tau
  mcME = particleDataPtr->m0(4); 
  mbME = particleDataPtr->m0(5); 
  mmuME = particleDataPtr->m0(13); 
  mtauME = particleDataPtr->m0(15); 
  jamp2[0] = new double[2]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void Sigma_MDMSM_gg_xchixchig::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(particleDataPtr, couplingsPtr, slhaPtr, alpS); 
  pars->setDependentCouplings(); 
  // Reset color flows
  for(int i = 0; i < 2; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 32; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1}, {-1,
      -1, -1, -1, 1}, {-1, -1, -1, 1, -1}, {-1, -1, -1, 1, 1}, {-1, -1, 1, -1,
      -1}, {-1, -1, 1, -1, 1}, {-1, -1, 1, 1, -1}, {-1, -1, 1, 1, 1}, {-1, 1,
      -1, -1, -1}, {-1, 1, -1, -1, 1}, {-1, 1, -1, 1, -1}, {-1, 1, -1, 1, 1},
      {-1, 1, 1, -1, -1}, {-1, 1, 1, -1, 1}, {-1, 1, 1, 1, -1}, {-1, 1, 1, 1,
      1}, {1, -1, -1, -1, -1}, {1, -1, -1, -1, 1}, {1, -1, -1, 1, -1}, {1, -1,
      -1, 1, 1}, {1, -1, 1, -1, -1}, {1, -1, 1, -1, 1}, {1, -1, 1, 1, -1}, {1,
      -1, 1, 1, 1}, {1, 1, -1, -1, -1}, {1, 1, -1, -1, 1}, {1, 1, -1, 1, -1},
      {1, 1, -1, 1, 1}, {1, 1, 1, -1, -1}, {1, 1, 1, -1, 1}, {1, 1, 1, 1, -1},
      {1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {512}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
    t[i] = 0.; 
  }

  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  // For now, call setupForME() here
  id1 = 21; 
  id2 = 21; 
  if( !setupForME())
  {
    return; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]); 
        t[0] = matrix_2_gg_xchixchig(); 

        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
        {
          matrix_element[iproc] += t[iproc]; 
          tsum += t[iproc]; 
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true; 
          ngood++; 
          igood[ngood] = ihel; 
        }
      }
    }
    jhel = 0; 
    sum_hel = min(sum_hel, ngood); 
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions(perm, helicities[ihel]); 
      t[0] = matrix_2_gg_xchixchig(); 

      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double Sigma_MDMSM_gg_xchixchig::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 21 && id2 == 21)
  {
    // Add matrix elements for processes with beams (21, 21)
    return matrix_element[0]; 
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.; 
  }
}

//--------------------------------------------------------------------------
// Select identity, colour and anticolour.

void Sigma_MDMSM_gg_xchixchig::setIdColAcol() 
{
  if(id1 == 21 && id2 == 21)
  {
    // Pick one of the flavor combinations (52, 52, 21)
    int flavors[1][3] = {{52, 52, 21}}; 
    vector<double> probs; 
    double sum = matrix_element[0]; 
    probs.push_back(matrix_element[0]/sum); 
    int choice = rndmPtr->pick(probs); 
    id3 = flavors[choice][0]; 
    id4 = flavors[choice][1]; 
    id5 = flavors[choice][2]; 
  }
  setId(id1, id2, id3, id4, id5); 
  // Pick color flow
  int ncolor[1] = {2}; 
  if((id1 == 21 && id2 == 21 && id3 == 52 && id4 == 52 && id5 == 21))
  {
    vector<double> probs; 
    double sum = jamp2[0][0] + jamp2[0][1]; 
    for(int i = 0; i < ncolor[0]; i++ )
      probs.push_back(jamp2[0][i]/sum); 
    int ic = rndmPtr->pick(probs); 
    static int colors[2][10] = {{3, 1, 1, 2, 0, 0, 0, 0, 3, 2}, {2, 1, 3, 2, 0,
        0, 0, 0, 3, 1}};
    setColAcol(colors[ic][0], colors[ic][1], colors[ic][2], colors[ic][3],
        colors[ic][4], colors[ic][5], colors[ic][6], colors[ic][7],
        colors[ic][8], colors[ic][9]);
  }
}

//--------------------------------------------------------------------------
// Evaluate weight for angles of decay products in process

double Sigma_MDMSM_gg_xchixchig::weightDecay(Event& process, int iResBeg, int
    iResEnd)
{
  // Just use isotropic decay (default)
  return 1.; 
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void Sigma_MDMSM_gg_xchixchig::calculate_wavefunctions(const int perm[], const
    int hel[])
{
  // Calculate wavefunctions for all processes
  double p[nexternal][4]; 
  int i; 

  // Convert Pythia 4-vectors to double[]
  for(i = 0; i < nexternal; i++ )
  {
    p[i][0] = pME[i].e(); 
    p[i][1] = pME[i].px(); 
    p[i][2] = pME[i].py(); 
    p[i][3] = pME[i].pz(); 
  }

  // Calculate all wavefunctions
  vxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  vxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  vxxxxx(p[perm[4]], mME[4], hel[4], +1, w[4]); 
  VVV1P0_1(w[0], w[1], pars->GC_10, pars->ZERO, pars->ZERO, w[5]); 
  FFS1_3(w[2], w[3], pars->GC_13, pars->mdl_mY, pars->mdl_wY, w[6]); 
  VVV1P0_1(w[0], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[7]); 
  VVV1P0_1(w[1], w[4], pars->GC_10, pars->ZERO, pars->ZERO, w[8]); 
  VVVS1_4(w[0], w[1], w[4], pars->GC_15, pars->mdl_mY, pars->mdl_wY, w[9]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  VVS2_0(w[5], w[4], w[6], pars->GC_14, amp[0]); 
  VVS2_0(w[7], w[1], w[6], pars->GC_14, amp[1]); 
  VVS2_0(w[0], w[8], w[6], pars->GC_14, amp[2]); 
  FFS1_0(w[2], w[3], w[9], pars->GC_13, amp[3]); 


}
double Sigma_MDMSM_gg_xchixchig::matrix_2_gg_xchixchig() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 4; 
  const int ncolor = 2; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {3, 3}; 
  static const double cf[ncolor][ncolor] = {{7, -2}, {-2, 7}}; 

  // Calculate color flows
  jamp[0] = +2. * (-std::complex<double> (0, 1) * amp[0] + std::complex<double>
      (0, 1) * amp[1] - std::complex<double> (0, 1) * amp[2] -
      std::complex<double> (0, 1) * amp[3]);
  jamp[1] = +2. * (+std::complex<double> (0, 1) * amp[0] - std::complex<double>
      (0, 1) * amp[1] + std::complex<double> (0, 1) * amp[2] +
      std::complex<double> (0, 1) * amp[3]);

  // Sum and square the color flows to get the matrix element
  double matrix = 0; 
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.; 
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j]; 
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i]; 
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i])); 

  return matrix; 
}


}  // end namespace Pythia8
