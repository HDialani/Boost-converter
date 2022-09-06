/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control_data.c
 *
 * Code generated for Simulink model 'Openloop_voltage_control'.
 *
 * Model version                  : 5.94
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Sep  6 12:02:25 2022
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
  /* Mask Parameter: DiscretePIDController1_InitialC
   * Referenced by: '<S45>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController2_InitialC
   * Referenced by: '<S93>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_LowerSat
   * Referenced by:
   *   '<S52>/Saturation'
   *   '<S38>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: DiscretePIDController1_UpperSat
   * Referenced by:
   *   '<S52>/Saturation'
   *   '<S38>/DeadZone'
   */
  150.0,

  /* Expression: 1.5
   * Referenced by: '<S9>/V_f1'
   */
  1.5,

  /* Expression: 45
   * Referenced by: '<S9>/V_in'
   */
  45.0,

  /* Expression: 1.5
   * Referenced by: '<S9>/V_f'
   */
  1.5,

  /* Expression: 1.5
   * Referenced by: '<S9>/V_f3'
   */
  1.5,

  /* Expression: 45
   * Referenced by: '<S9>/V_in1'
   */
  45.0,

  /* Expression: 1.5
   * Referenced by: '<S9>/V_f2'
   */
  1.5,

  /* Expression: 0
   * Referenced by: '<S36>/Constant1'
   */
  0.0,

  /* Expression: 3/4096
   * Referenced by: '<S7>/1//ADC_resolution'
   */
  0.000732421875,

  /* Expression: 170
   * Referenced by: '<S7>/Opamp_converter'
   */
  170.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S45>/Integrator'
   */
  0.001,

  /* Expression: 1/150
   * Referenced by: '<S7>/Gain'
   */
  0.0066666666666666671,

  /* Expression: 100
   * Referenced by: '<S7>/Gain1'
   */
  100.0,

  /* Expression: 60e6
   * Referenced by: '<S7>/CLK frequency'
   */
  6.0E+7,

  /* Expression: 60e6
   * Referenced by: '<S113>/CLK frequency1'
   */
  6.0E+7,

  /* Expression: 60e6
   * Referenced by: '<S9>/CLK frequency'
   */
  6.0E+7,

  /* Expression: 60e6
   * Referenced by: '<S113>/CLK frequency'
   */
  6.0E+7,

  /* Computed Parameter: Integrator_gainval_f
   * Referenced by: '<S93>/Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S36>/ZeroGain'
   */
  0.0,

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S1>/Gain1'
   */
  64000U,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S1>/Gain'
   */
  64000U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S2>/Switch'
   */
  0U,

  /* Computed Parameter: Constant13_Value
   * Referenced by: '<S4>/Constant13'
   */
  3350U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S4>/Constant8'
   */
  500U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S4>/Constant3'
   */
  500U,

  /* Computed Parameter: Constant14_Value
   * Referenced by: '<S4>/Constant14'
   */
  2500U,

  /* Computed Parameter: Switch1_Threshold
   * Referenced by: '<S2>/Switch1'
   */
  0U,

  /* Computed Parameter: _Y0
   * Referenced by: '<S111>/ '
   */
  0,

  /* Computed Parameter: _Y0_a
   * Referenced by: '<S112>/ '
   */
  0,

  /* Computed Parameter: RateTransition5_InitialConditio
   * Referenced by: '<Root>/Rate Transition5'
   */
  0,

  /* Computed Parameter: Constant16_Value
   * Referenced by: '<S4>/Constant16'
   */
  1,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S4>/Constant9'
   */
  0,

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S4>/Constant15'
   */
  1,

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
