/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ET4145_test1_private.h
 *
 * Code generated for Simulink model 'ET4145_test1'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Sep  6 11:28:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ET4145_test1_private_h_
#define RTW_HEADER_ET4145_test1_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

void InitAdc (void);
void config_ADC_SOC0 (void);
void config_ADC_SOC8 (void);
void config_ADC_SOC2 (void);
extern uint16_T MW_adcInitFlag;

#endif                                 /* RTW_HEADER_ET4145_test1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
