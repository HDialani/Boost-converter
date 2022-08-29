/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control_data.c
 *
 * Code generated for Simulink model 'Openloop_voltage_control'.
 *
 * Model version                  : 5.28
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Aug 29 14:11:39 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Openloop_voltage_control.h"
#include "Openloop_voltage_control_private.h"

/* Block parameters (default storage) */
P_Openloop_voltage_control_T Openloop_voltage_control_P = {
  /* Variable: D_IGBT_CCM
   * Referenced by: '<S5>/Constant2'
   */
  0.85074626865671643,

  /* Variable: D_MOSFET_CCM
   * Referenced by: '<S5>/Constant1'
   */
  0.70297029702970293,

  /* Variable: Timer_period_IGBT
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S10>/Constant1'
   */
  4000.0,

  /* Variable: Timer_period_MOSFET
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S10>/Constant'
   */
  750.0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S3>/Constant3'
   */
  500U,

  /* Computed Parameter: Constant14_Value
   * Referenced by: '<S3>/Constant14'
   */
  2500U,

  /* Computed Parameter: Constant13_Value
   * Referenced by: '<S3>/Constant13'
   */
  3350U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S3>/Constant8'
   */
  500U,

  /* Computed Parameter: _Y0
   * Referenced by: '<S7>/ '
   */
  0,

  /* Computed Parameter: _Y0_a
   * Referenced by: '<S8>/ '
   */
  0,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S3>/Constant9'
   */
  0,

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S3>/Constant15'
   */
  1,

  /* Computed Parameter: Constant16_Value
   * Referenced by: '<S3>/Constant16'
   */
  1,

  /* Computed Parameter: RateTransition5_InitialConditio
   * Referenced by: '<Root>/Rate Transition5'
   */
  0,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<Root>/Constant6'
   */
  1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
