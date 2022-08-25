/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control.h
 *
 * Code generated for Simulink model 'Openloop_voltage_control'.
 *
 * Model version                  : 5.14
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Aug 25 16:19:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Openloop_voltage_control_h_
#define RTW_HEADER_Openloop_voltage_control_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Openloop_voltage_control_COMMON_INCLUDES_
#define Openloop_voltage_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "F2802x_Gpio.h"
#include "IQmathLib.h"
#endif                           /* Openloop_voltage_control_COMMON_INCLUDES_ */

#include "Openloop_voltage_control_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWM_GPIO (void);

/* Block signals (default storage) */
typedef struct {
  uint16_T MOSFET_Enable;              /* '<Root>/ADC_MOSFET_ON' */
  uint16_T Volt_Protection;            /* '<Root>/VoltMeas' */
  uint16_T IGBT_Enable;                /* '<Root>/ADC_IGBT_ON' */
  boolean_T In;                        /* '<S4>/In' */
  boolean_T In_g;                      /* '<S3>/In' */
  boolean_T RedLED;                    /* '<S2>/NOT1' */
  boolean_T GreenLED;                  /* '<S2>/NOT2' */
  boolean_T BLUELED;                   /* '<S2>/NOT3' */
  boolean_T RateTransition5;           /* '<Root>/Rate Transition5' */
} B_Openloop_voltage_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile boolean_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
} DW_Openloop_voltage_control_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold2_Trig_ZCE;  /* '<S2>/Sample and Hold2' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S2>/Sample and Hold1' */
} PrevZCX_Openloop_voltage_cont_T;

/* Parameters (default storage) */
struct P_Openloop_voltage_control_T_ {
  real_T D_IGBT_CCM;                   /* Variable: D_IGBT_CCM
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T D_MOSFET_CCM;                 /* Variable: D_MOSFET_CCM
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Timer_period_MOSFET;          /* Variable: Timer_period_MOSFET
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T f_sw_IGBT;                    /* Variable: f_sw_IGBT
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint16_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S2>/Constant3'
                                        */
  uint16_T Constant14_Value;           /* Computed Parameter: Constant14_Value
                                        * Referenced by: '<S2>/Constant14'
                                        */
  uint16_T Constant13_Value;           /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<S2>/Constant13'
                                        */
  uint16_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S2>/Constant8'
                                        */
  boolean_T _Y0;                       /* Computed Parameter: _Y0
                                        * Referenced by: '<S3>/ '
                                        */
  boolean_T _Y0_a;                     /* Computed Parameter: _Y0_a
                                        * Referenced by: '<S4>/ '
                                        */
  boolean_T Constant9_Value;           /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S2>/Constant9'
                                        */
  boolean_T Constant15_Value;          /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S2>/Constant15'
                                        */
  boolean_T Constant16_Value;          /* Computed Parameter: Constant16_Value
                                        * Referenced by: '<S2>/Constant16'
                                        */
  boolean_T RateTransition5_InitialConditio;
                          /* Computed Parameter: RateTransition5_InitialConditio
                           * Referenced by: '<Root>/Rate Transition5'
                           */
  boolean_T Constant6_Value;           /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<Root>/Constant6'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Openloop_voltage_cont_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Openloop_voltage_control_T Openloop_voltage_control_P;

/* Block signals (default storage) */
extern B_Openloop_voltage_control_T Openloop_voltage_control_B;

/* Block states (default storage) */
extern DW_Openloop_voltage_control_T Openloop_voltage_control_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Openloop_voltage_cont_T Openloop_voltage_contro_PrevZCX;

/* External function called from main */
extern void Openloop_voltage_control_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Openloop_voltage_control_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Openloop_voltage_control_initialize(void);
extern void Openloop_voltage_control_step0(void);
extern void Openloop_voltage_control_step1(void);
extern void Openloop_voltage_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Openloop_voltage_con_T *const Openloop_voltage_control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition9' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Openloop_voltage_control'
 * '<S1>'   : 'Openloop_voltage_control/Duty Cycles'
 * '<S2>'   : 'Openloop_voltage_control/Subsystem'
 * '<S3>'   : 'Openloop_voltage_control/Subsystem/Sample and Hold1'
 * '<S4>'   : 'Openloop_voltage_control/Subsystem/Sample and Hold2'
 */
#endif                              /* RTW_HEADER_Openloop_voltage_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */