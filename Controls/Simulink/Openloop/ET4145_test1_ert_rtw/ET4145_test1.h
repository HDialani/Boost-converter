/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ET4145_test1.h
 *
 * Code generated for Simulink model 'ET4145_test1'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Aug 29 14:14:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ET4145_test1_h_
#define RTW_HEADER_ET4145_test1_h_
#include <string.h>
#include <stddef.h>
#ifndef ET4145_test1_COMMON_INCLUDES_
#define ET4145_test1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "F2802x_Gpio.h"
#include "IQmathLib.h"
#endif                                 /* ET4145_test1_COMMON_INCLUDES_ */

#include "ET4145_test1_types.h"
#include "MW_target_hardware_resources.h"

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
  uint16_T ADC_MOSFET_ON;              /* '<Root>/ADC_MOSFET_ON' */
  uint16_T VoltMeas;                   /* '<Root>/VoltMeas' */
  uint16_T ADC_IGBT_ON;                /* '<Root>/ADC_IGBT_ON' */
  boolean_T In;                        /* '<S2>/In' */
  boolean_T In_g;                      /* '<S1>/In' */
  boolean_T NOT1;                      /* '<Root>/NOT1' */
  boolean_T NOT2;                      /* '<Root>/NOT2' */
  boolean_T NOT3;                      /* '<Root>/NOT3' */
  boolean_T RateTransition5;           /* '<Root>/Rate Transition5' */
} B_ET4145_test1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile boolean_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
} DW_ET4145_test1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold2_Trig_ZCE;  /* '<Root>/Sample and Hold2' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<Root>/Sample and Hold1' */
} PrevZCX_ET4145_test1_T;

/* Parameters (default storage) */
struct P_ET4145_test1_T_ {
  real_T Constant_Value;               /* Expression: 525
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant7_Value;              /* Expression: 3400
                                        * Referenced by: '<Root>/Constant7'
                                        */
  uint16_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  uint16_T Constant14_Value;           /* Computed Parameter: Constant14_Value
                                        * Referenced by: '<Root>/Constant14'
                                        */
  uint16_T Constant13_Value;           /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<Root>/Constant13'
                                        */
  uint16_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<Root>/Constant8'
                                        */
  boolean_T _Y0;                       /* Computed Parameter: _Y0
                                        * Referenced by: '<S1>/ '
                                        */
  boolean_T _Y0_a;                     /* Computed Parameter: _Y0_a
                                        * Referenced by: '<S2>/ '
                                        */
  boolean_T Constant9_Value;           /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<Root>/Constant9'
                                        */
  boolean_T Constant15_Value;          /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<Root>/Constant15'
                                        */
  boolean_T Constant16_Value;          /* Computed Parameter: Constant16_Value
                                        * Referenced by: '<Root>/Constant16'
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
struct tag_RTM_ET4145_test1_T {
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
extern P_ET4145_test1_T ET4145_test1_P;

/* Block signals (default storage) */
extern B_ET4145_test1_T ET4145_test1_B;

/* Block states (default storage) */
extern DW_ET4145_test1_T ET4145_test1_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_ET4145_test1_T ET4145_test1_PrevZCX;

/* External function called from main */
extern void ET4145_test1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ET4145_test1_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ET4145_test1_initialize(void);
extern void ET4145_test1_step0(void);
extern void ET4145_test1_step1(void);
extern void ET4145_test1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ET4145_test1_T *const ET4145_test1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'ET4145_test1'
 * '<S1>'   : 'ET4145_test1/Sample and Hold1'
 * '<S2>'   : 'ET4145_test1/Sample and Hold2'
 */
#endif                                 /* RTW_HEADER_ET4145_test1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
