//==========================================================================
// This file has been automatically generated for Pythia 8
// MadGraph5_aMC@NLO v. 2.8.3.2, 2021-02-02
// By the MadGraph5_aMC@NLO Development Team
// Visit launchpad.net/madgraph5 and amcatnlo.web.cern.ch
//==========================================================================

#ifndef HelAmps_MDMSM_H
#define HelAmps_MDMSM_H

#include <cmath> 
#include <complex> 

using namespace std; 

namespace Pythia8_MDMSM 
{
void ixxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fi[6]);

void oxxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fo[6]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv, std::complex<double>
    v[6]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]); 

double Sgn(double e, double f); 

void txxxxx(double p[4], double tmass, int nhel, int nst, std::complex<double>
    fi[18]);

void VVVVS1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void VVVS1_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> S4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void FFV3_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFV4C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFV5C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFS3_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVS2P0_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void FFS4_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void FFV5_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFS5C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVVV5_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void VVVVS1P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void VVVV3P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVVS2P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void FFS1C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVVV3_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFV4C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFS2C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);
void FFS2_4C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);

void FFS4_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void SSSS1_2(std::complex<double> S1[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> S2[]);

void VVV1_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void VVS1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFS2_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);
void FFS2_4_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);

void FFV1C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVSS1P0_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVVS2P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void VSS1P0_1(std::complex<double> S2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void VVSS1_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> S4[]);

void FFV3C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void VVVVS2_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void FFS5_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFS4C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVV4P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void VVS2_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void FFV1_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void SSS1_3(std::complex<double> S1[], std::complex<double> S2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVVVS3_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void VVVV2_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void VVSS1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> S3[]);

void VVVV5P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VSS1_0(std::complex<double> V1[], std::complex<double> S2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFS3C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFV2_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);
void FFV2_5_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);
void FFV2_3_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);
void FFV2_4_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);

void VVVV1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void FFS1_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFV2C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);
void FFV2_5C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);
void FFV2_3C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);
void FFV2_4C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);

void FFS5_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVVV4P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVV4_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFV4_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVS1P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> S4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFV2P0_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFS4P0_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVV1P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void VVVVS1_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void VVVS1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void FFV3_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVV2_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVV3_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void FFS3_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFS3C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFV5_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFS1_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFS5C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVV5_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVV4P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void VVVV3P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFS1C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVVS1_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void VVVVS3P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void FFV3_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFV4C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVV3_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void FFS2C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);
void FFS2_4C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);

void VVVVS2_5(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, double M5, double W5, std::complex<double> S5[]);

void FFS4_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void SSSS1_1(std::complex<double> S2[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> S1[]);

void VVV1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVS1_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void FFS2_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);
void FFS2_4_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);

void FFS5C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFV1C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVS1P0_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void VVVV3P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVS1P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> S4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVV2_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void FFS2C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);
void FFS2_4C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> S3[]);

void FFV5C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVV1_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void VVVVS2_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    S5[], std::complex<double> COUP, std::complex<double> & vertex);

void VVV1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void VVS1_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> V2[]);

void FFS4C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void FFS2_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);
void FFS2_4_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);

void VVS2_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> V2[]);

void FFV1C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFV1_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVV3P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void SSS1_0(std::complex<double> S1[], std::complex<double> S2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVS1_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> S4[]);

void VVVVS3_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    S5[], std::complex<double> COUP, std::complex<double> & vertex);

void VVVV1P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void VVSS1_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void VSS1_1(std::complex<double> S2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void VVVS1P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void FFV2_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);
void FFV2_5_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);
void FFV2_3_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);
void FFV2_4_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);

void VVVV1_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVVS2_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void VVVVS1P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void FFV2C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);
void FFV2_5C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);
void FFV2_3C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);
void FFV2_4C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP1, std::complex<double>
    COUP2, std::complex<double> & vertex);

void FFS5_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVVV1P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void VVVV4_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void FFV4_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVS2_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void FFV2P0_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVV1P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> V2[]);

void VVVVS1_5(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, double M5, double W5, std::complex<double> S5[]);

void VVVS1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVVS1P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void VVVV2_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFV5C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVSS1_1(std::complex<double> V2[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void FFS3_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VSS1_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> S2[]);

void FFS3C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void FFV5_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVV1_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFS1_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVVS1P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void FFV2C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);
void FFV2_5C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);
void FFV2_3C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);
void FFV2_4C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> V3[]);

void VVVV5_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void VVVV4P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVV4_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void FFV4_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void VVVVS2P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void VVSS1P0_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> S4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFS1C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVV1P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> V1[]);

void VVVVS1_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void VVVVS3P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void FFV3_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void FFV4C1_3(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void VVVVS2_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void FFS3_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVS2P0_2(std::complex<double> V1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> V2[]);

void FFS4_2(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void SSSS1_0(std::complex<double> S1[], std::complex<double> S2[],
    std::complex<double> S3[], std::complex<double> S4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void FFS1_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVVVS3_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void FFS5C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVV5_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVVS2P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M3, double W3, std::complex<double> V3[]);

void VVVV3_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void FFV1P0_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFS1C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void VVVVS3P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M1, double W1, std::complex<double> V1[]);

void VVVV2P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void FFS2C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);
void FFS2_4C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);

void VVVV1P0_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void FFV3C1_1(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void SSSS1_3(std::complex<double> S1[], std::complex<double> S2[],
    std::complex<double> S4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> S3[]);

void VVVVS3_5(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, double M5, double W5, std::complex<double> S5[]);

void VVS1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void VVVVS1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    S5[], std::complex<double> COUP, std::complex<double> & vertex);

void FFS4C1_2(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFS2_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);
void FFS2_4_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M3, double
    W3, std::complex<double> S3[]);

void FFV1C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVV1_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> V2[]);

void FFV1_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void SSS1_1(std::complex<double> S2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> S1[]);

void VVVV1P0_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void VVVVS3P0_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void VVVV2P0_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void FFV2_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);
void FFV2_5_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);
void FFV2_3_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);
void FFV2_4_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M2, double
    W2, std::complex<double> F2[]);

void FFV3C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVVS2_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void FFS2P0_1(std::complex<double> F2[], std::complex<double> S3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void FFS5_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFS4C1_1(std::complex<double> F1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

void VVVVS3_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> S5[], std::complex<double>
    COUP, double M4, double W4, std::complex<double> V4[]);

void VVVV4_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> V4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void SSS1_2(std::complex<double> S1[], std::complex<double> S3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> S2[]);

void VVS2_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFV1_3(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> V3[]);

void FFV3C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFV5C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);

void VVVS1_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> S4[], std::complex<double> COUP, double M2, double W2,
    std::complex<double> V2[]);

void VVVVS3_2(std::complex<double> V1[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> S5[], std::complex<double>
    COUP, double M2, double W2, std::complex<double> V2[]);

void VVVV2_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVVV3_1(std::complex<double> V2[], std::complex<double> V3[],
    std::complex<double> V4[], std::complex<double> COUP, double M1, double W1,
    std::complex<double> V1[]);

void VVSS1_0(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> S3[], std::complex<double> S4[], std::complex<double>
    COUP, std::complex<double> & vertex);

void VSS1_3(std::complex<double> V1[], std::complex<double> S2[],
    std::complex<double> COUP, double M3, double W3, std::complex<double> S3[]);

void FFS3C1_0(std::complex<double> F2[], std::complex<double> F1[],
    std::complex<double> S3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFV5_0(std::complex<double> F1[], std::complex<double> F2[],
    std::complex<double> V3[], std::complex<double> COUP, std::complex<double>
    & vertex);

void FFV2_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);
void FFV2_5_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);
void FFV2_3_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);
void FFV2_4_1(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);

void VVVV1_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void SSSS1_4(std::complex<double> S1[], std::complex<double> S2[],
    std::complex<double> S3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> S4[]);

void FFV2C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP, double M1, double W1, std::complex<double> F1[]);
void FFV2_5C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);
void FFV2_3C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);
void FFV2_4C1_2(std::complex<double> F2[], std::complex<double> V3[],
    std::complex<double> COUP1, std::complex<double> COUP2, double M1, double
    W1, std::complex<double> F1[]);

void VVVV5_4(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V3[], std::complex<double> COUP, double M4, double W4,
    std::complex<double> V4[]);

void VVVV4_3(std::complex<double> V1[], std::complex<double> V2[],
    std::complex<double> V4[], std::complex<double> COUP, double M3, double W3,
    std::complex<double> V3[]);

void FFV4_2(std::complex<double> F1[], std::complex<double> V3[],
    std::complex<double> COUP, double M2, double W2, std::complex<double> F2[]);

}  // end namespace Pythia8_MDMSM

#endif  // HelAmps_MDMSM_H
