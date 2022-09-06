/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control.h
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
#include "F2802x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "f2802x_examples.h"
#include "IQmathLib.h"
#endif                           /* Openloop_voltage_control_COMMON_INCLUDES_ */

#include "Openloop_voltage_control_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
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

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);

/* Block signals (default storage) */
typedef struct {
  uint16_T SCIReceive[10];             /* '<S1>/SCI Receive' */
  uint16_T Volt_Protection;            /* '<S3>/VoltMeas' */
  uint16_T MOSFET_Enable;              /* '<S3>/ADC_MOSFET_ON' */
  uint16_T IGBT_Enable;                /* '<S3>/ADC_IGBT_ON' */
  uint16_T TmpSignalConversionAtSCITransmi[3];
  boolean_T In;                        /* '<S112>/In' */
  boolean_T In_g;                      /* '<S111>/In' */
  boolean_T RateTransition5;           /* '<Root>/Rate Transition5' */
  boolean_T RedLED;                    /* '<S4>/NOT1' */
  boolean_T GreenLED;                  /* '<S4>/NOT2' */
  boolean_T BLUELED;                   /* '<S4>/NOT3' */
} B_Openloop_voltage_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S45>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S93>/Integrator' */
  volatile boolean_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
} DW_Openloop_voltage_control_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold2_Trig_ZCE;  /* '<S4>/Sample and Hold2' */
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<S4>/Sample and Hold1' */
} PrevZCX_Openloop_voltage_cont_T;

/* Parameters (default storage) */
struct P_Openloop_voltage_control_T_ {
  real_T DiscretePIDController1_InitialC;
                              /* Mask Parameter: DiscretePIDController1_InitialC
                               * Referenced by: '<S45>/Integrator'
                               */
  real_T DiscretePIDController2_InitialC;
                              /* Mask Parameter: DiscretePIDController2_InitialC
                               * Referenced by: '<S93>/Integrator'
                               */
  real_T DiscretePIDController1_LowerSat;
                              /* Mask Parameter: DiscretePIDController1_LowerSat
                               * Referenced by:
                               *   '<S52>/Saturation'
                               *   '<S38>/DeadZone'
                               */
  real_T DiscretePIDController1_UpperSat;
                              /* Mask Parameter: DiscretePIDController1_UpperSat
                               * Referenced by:
                               *   '<S52>/Saturation'
                               *   '<S38>/DeadZone'
                               */
  real_T V_f1_Value;                   /* Expression: 1.5
                                        * Referenced by: '<S9>/V_f1'
                                        */
  real_T V_in_Value;                   /* Expression: 45
                                        * Referenced by: '<S9>/V_in'
                                        */
  real_T V_f_Value;                    /* Expression: 1.5
                                        * Referenced by: '<S9>/V_f'
                                        */
  real_T V_f3_Value;                   /* Expression: 1.5
                                        * Referenced by: '<S9>/V_f3'
                                        */
  real_T V_in1_Value;                  /* Expression: 45
                                        * Referenced by: '<S9>/V_in1'
                                        */
  real_T V_f2_Value;                   /* Expression: 1.5
                                        * Referenced by: '<S9>/V_f2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T uADC_resolution_Gain;         /* Expression: 3/4096
                                        * Referenced by: '<S7>/1//ADC_resolution'
                                        */
  real_T Opamp_converter_Gain;         /* Expression: 170
                                        * Referenced by: '<S7>/Opamp_converter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S45>/Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/150
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T CLKfrequency_Value;           /* Expression: 60e6
                                        * Referenced by: '<S7>/CLK frequency'
                                        */
  real_T CLKfrequency1_Value;          /* Expression: 60e6
                                        * Referenced by: '<S113>/CLK frequency1'
                                        */
  real_T CLKfrequency_Value_e;         /* Expression: 60e6
                                        * Referenced by: '<S9>/CLK frequency'
                                        */
  real_T CLKfrequency_Value_ei;        /* Expression: 60e6
                                        * Referenced by: '<S113>/CLK frequency'
                                        */
  real_T Integrator_gainval_f;       /* Computed Parameter: Integrator_gainval_f
                                      * Referenced by: '<S93>/Integrator'
                                      */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S36>/ZeroGain'
                                        */
  uint16_T Gain1_Gain_f;               /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S1>/Gain1'
                                        */
  uint16_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S2>/Switch'
                                        */
  uint16_T Constant13_Value;           /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<S4>/Constant13'
                                        */
  uint16_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S4>/Constant8'
                                        */
  uint16_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S4>/Constant3'
                                        */
  uint16_T Constant14_Value;           /* Computed Parameter: Constant14_Value
                                        * Referenced by: '<S4>/Constant14'
                                        */
  uint16_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S2>/Switch1'
                                        */
  boolean_T _Y0;                       /* Computed Parameter: _Y0
                                        * Referenced by: '<S111>/ '
                                        */
  boolean_T _Y0_a;                     /* Computed Parameter: _Y0_a
                                        * Referenced by: '<S112>/ '
                                        */
  boolean_T RateTransition5_InitialConditio;
                          /* Computed Parameter: RateTransition5_InitialConditio
                           * Referenced by: '<Root>/Rate Transition5'
                           */
  boolean_T Constant16_Value;          /* Computed Parameter: Constant16_Value
                                        * Referenced by: '<S4>/Constant16'
                                        */
  boolean_T Constant9_Value;           /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S4>/Constant9'
                                        */
  boolean_T Constant15_Value;          /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S4>/Constant15'
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
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S8>/Gain1' : Unused code path elimination
 * Block '<S114>/Constant' : Unused code path elimination
 * Block '<S114>/Constant1' : Unused code path elimination
 * Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition9' : Eliminated since input and output rates are identical
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
 * '<S1>'   : 'Openloop_voltage_control/Dashboard receiver block'
 * '<S2>'   : 'Openloop_voltage_control/Duty Cycles'
 * '<S3>'   : 'Openloop_voltage_control/Input hardware'
 * '<S4>'   : 'Openloop_voltage_control/Logic circuit'
 * '<S5>'   : 'Openloop_voltage_control/Output'
 * '<S6>'   : 'Openloop_voltage_control/Timer'
 * '<S7>'   : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx'
 * '<S8>'   : 'Openloop_voltage_control/Duty Cycles/Open loop control using parameter.m'
 * '<S9>'   : 'Openloop_voltage_control/Duty Cycles/Open loop using dashboard.slx'
 * '<S10>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1'
 * '<S11>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2'
 * '<S12>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Anti-windup'
 * '<S13>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/D Gain'
 * '<S14>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Filter'
 * '<S15>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Filter ICs'
 * '<S16>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/I Gain'
 * '<S17>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Ideal P Gain'
 * '<S18>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S19>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Integrator'
 * '<S20>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Integrator ICs'
 * '<S21>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/N Copy'
 * '<S22>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/N Gain'
 * '<S23>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/P Copy'
 * '<S24>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Parallel P Gain'
 * '<S25>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Reset Signal'
 * '<S26>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Saturation'
 * '<S27>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Saturation Fdbk'
 * '<S28>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Sum'
 * '<S29>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Sum Fdbk'
 * '<S30>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tracking Mode'
 * '<S31>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tracking Mode Sum'
 * '<S32>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tsamp - Integral'
 * '<S33>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tsamp - Ngain'
 * '<S34>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/postSat Signal'
 * '<S35>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/preSat Signal'
 * '<S36>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S37>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S38>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S39>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/D Gain/Disabled'
 * '<S40>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Filter/Disabled'
 * '<S41>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S42>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/I Gain/External Parameters'
 * '<S43>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S44>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Integrator/Discrete'
 * '<S46>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S47>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S48>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/N Gain/Disabled'
 * '<S49>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/P Copy/Disabled'
 * '<S50>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S51>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S52>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Saturation/Enabled'
 * '<S53>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S54>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Sum/Sum_PI'
 * '<S55>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S56>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S57>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S59>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S61>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S62>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Anti-windup'
 * '<S63>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/D Gain'
 * '<S64>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Filter'
 * '<S65>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Filter ICs'
 * '<S66>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/I Gain'
 * '<S67>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Ideal P Gain'
 * '<S68>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S69>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Integrator'
 * '<S70>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Integrator ICs'
 * '<S71>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/N Copy'
 * '<S72>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/N Gain'
 * '<S73>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/P Copy'
 * '<S74>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Parallel P Gain'
 * '<S75>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Reset Signal'
 * '<S76>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Saturation'
 * '<S77>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Saturation Fdbk'
 * '<S78>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Sum'
 * '<S79>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Sum Fdbk'
 * '<S80>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tracking Mode'
 * '<S81>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tracking Mode Sum'
 * '<S82>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tsamp - Integral'
 * '<S83>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tsamp - Ngain'
 * '<S84>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/postSat Signal'
 * '<S85>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/preSat Signal'
 * '<S86>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Anti-windup/Passthrough'
 * '<S87>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/D Gain/Disabled'
 * '<S88>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Filter/Disabled'
 * '<S89>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Filter ICs/Disabled'
 * '<S90>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/I Gain/External Parameters'
 * '<S91>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S92>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S93>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Integrator/Discrete'
 * '<S94>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S95>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S96>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/N Gain/Disabled'
 * '<S97>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/P Copy/Disabled'
 * '<S98>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Parallel P Gain/External Parameters'
 * '<S99>'  : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S100>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Saturation/Passthrough'
 * '<S101>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S102>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Sum/Sum_PI'
 * '<S103>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S104>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S105>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S106>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tsamp - Integral/Passthrough'
 * '<S107>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S108>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S109>' : 'Openloop_voltage_control/Duty Cycles/Closed loop using dashboard.slx/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S110>' : 'Openloop_voltage_control/Logic circuit/MATLAB Function'
 * '<S111>' : 'Openloop_voltage_control/Logic circuit/Sample and Hold1'
 * '<S112>' : 'Openloop_voltage_control/Logic circuit/Sample and Hold2'
 * '<S113>' : 'Openloop_voltage_control/Timer/Using dashboard.slx'
 * '<S114>' : 'Openloop_voltage_control/Timer/Using parameter.m'
 */
#endif                              /* RTW_HEADER_Openloop_voltage_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
