/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control.c
 *
 * Code generated for Simulink model 'Openloop_voltage_control'.
 *
 * Model version                  : 5.14
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Aug 26 10:38:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Openloop_voltage_control.h"
#include "Openloop_voltage_control_private.h"

/* Block signals (default storage) */
B_Openloop_voltage_control_T Openloop_voltage_control_B;

/* Block states (default storage) */
DW_Openloop_voltage_control_T Openloop_voltage_control_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Openloop_voltage_cont_T Openloop_voltage_contro_PrevZCX;

/* Real-time model */
static RT_MODEL_Openloop_voltage_con_T Openloop_voltage_control_M_;
RT_MODEL_Openloop_voltage_con_T *const Openloop_voltage_control_M =
  &Openloop_voltage_control_M_;
static void rate_monotonic_scheduler(void);
uint16_T MW_adcInitFlag = 0;

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Openloop_voltage_control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Openloop_voltage_control_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Openloop_voltage_control_M->Timing.TaskCounters.TID[1])++;
  if ((Openloop_voltage_control_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Openloop_voltage_control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Openloop_voltage_control_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  uint16_T rtb_MOSFET_Enable;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion2;
  uint16_T rtb_IGBT_Enable;
  real_T tmp;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator2_tmp;
  boolean_T rtb_LogicalOperator4;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_RelationalOperator3;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c2802xadc): '<Root>/ADC_MOSFET_ON' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.MOSFET_Enable = (AdcResult.ADCRESULT0);
  }

  /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_RelationalOperator1 = (Openloop_voltage_control_P.Constant3_Value <=
    Openloop_voltage_control_B.MOSFET_Enable);

  /* S-Function (c2802xadc): '<Root>/VoltMeas' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC8 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.Volt_Protection = (AdcResult.ADCRESULT8);
  }

  /* Logic: '<S2>/Logical Operator4' incorporates:
   *  Constant: '<S2>/Constant14'
   *  RelationalOperator: '<S2>/Relational Operator4'
   */
  rtb_LogicalOperator4 = ((!rtb_RelationalOperator1) &&
    (Openloop_voltage_control_P.Constant14_Value <
     Openloop_voltage_control_B.Volt_Protection));

  /* Outputs for Triggered SubSystem: '<S2>/Sample and Hold1' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  if (rtb_LogicalOperator4 &&
      (Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S3>/In' incorporates:
     *  Constant: '<S2>/Constant15'
     */
    Openloop_voltage_control_B.In_g =
      Openloop_voltage_control_P.Constant15_Value;
  }

  Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE = rtb_LogicalOperator4;

  /* End of Outputs for SubSystem: '<S2>/Sample and Hold1' */

  /* Logic: '<S2>/Logical Operator5' incorporates:
   *  Constant: '<S2>/Constant9'
   *  Logic: '<S2>/Logical Operator'
   */
  rtb_LogicalOperator4 = (rtb_RelationalOperator1 ||
    Openloop_voltage_control_P.Constant9_Value ||
    Openloop_voltage_control_B.In_g);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  rtb_MOSFET_Enable = rtb_LogicalOperator4;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S1>/Gain'
   */
  tmp = floor(Openloop_voltage_control_P.Timer_period_MOSFET *
              Openloop_voltage_control_P.D_MOSFET_CCM);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp :
    (uint16_T)tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Gain: '<S1>/Gain1'
   */
  tmp = floor(6.0E+7 / Openloop_voltage_control_P.f_sw_IGBT *
              Openloop_voltage_control_P.D_IGBT_CCM);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp :
    (uint16_T)tmp;

  /* S-Function (c2802xadc): '<Root>/ADC_IGBT_ON' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC2 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.IGBT_Enable = (AdcResult.ADCRESULT2);
  }

  /* RelationalOperator: '<S2>/Relational Operator3' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  rtb_RelationalOperator3 = (Openloop_voltage_control_P.Constant8_Value <=
    Openloop_voltage_control_B.IGBT_Enable);

  /* Logic: '<S2>/Logical Operator2' incorporates:
   *  Constant: '<S2>/Constant13'
   *  Logic: '<S2>/Logical Operator7'
   *  RelationalOperator: '<S2>/Relational Operator5'
   */
  rtb_LogicalOperator2_tmp = !rtb_RelationalOperator3;
  rtb_LogicalOperator2 = ((Openloop_voltage_control_B.Volt_Protection >
    Openloop_voltage_control_P.Constant13_Value) && rtb_LogicalOperator2_tmp);

  /* Outputs for Triggered SubSystem: '<S2>/Sample and Hold2' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  if (rtb_LogicalOperator2 &&
      (Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S4>/In' incorporates:
     *  Constant: '<S2>/Constant16'
     */
    Openloop_voltage_control_B.In = Openloop_voltage_control_P.Constant16_Value;
  }

  Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE = rtb_LogicalOperator2;

  /* End of Outputs for SubSystem: '<S2>/Sample and Hold2' */

  /* Logic: '<S2>/Logical Operator3' incorporates:
   *  Constant: '<S2>/Constant9'
   *  Logic: '<S2>/Logical Operator1'
   */
  rtb_RelationalOperator3 = (Openloop_voltage_control_B.In ||
    (Openloop_voltage_control_P.Constant9_Value || rtb_RelationalOperator3));

  /* DataTypeConversion: '<S2>/Data Type Conversion4' */
  rtb_IGBT_Enable = rtb_RelationalOperator3;

  /* Logic: '<S2>/NOT1' incorporates:
   *  Logic: '<S2>/Logical Operator6'
   */
  Openloop_voltage_control_B.RedLED = ((!Openloop_voltage_control_B.In_g) &&
    (!Openloop_voltage_control_B.In));

  /* Logic: '<S2>/NOT2' incorporates:
   *  Logic: '<S2>/Logical Operator7'
   */
  Openloop_voltage_control_B.GreenLED = ((!rtb_RelationalOperator1) ||
    rtb_LogicalOperator2_tmp);

  /* Logic: '<S2>/NOT3' incorporates:
   *  Logic: '<S2>/Logical Operator8'
   */
  Openloop_voltage_control_B.BLUELED = (rtb_LogicalOperator4 &&
    rtb_RelationalOperator3);

  /* S-Function (c280xgpio_do): '<Root>/BlueLED' */
  {
    if (Openloop_voltage_control_B.BLUELED)
      GpioDataRegs.GPASET.bit.GPIO12 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;
  }

  /* S-Function (c280xgpio_do): '<Root>/GreenLED' */
  {
    if (Openloop_voltage_control_B.GreenLED)
      GpioDataRegs.GPASET.bit.GPIO19 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;
  }

  /* S-Function (c280xgpio_do): '<Root>/RedLED' */
  {
    if (Openloop_voltage_control_B.RedLED)
      GpioDataRegs.GPBSET.bit.GPIO34 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
  }

  /* S-Function (c2802xpwm): '<Root>/ePWM1_IGBT' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion2);
  }

  EPwm1Regs.AQCSFRC.bit.CSFA = rtb_IGBT_Enable;

  /* S-Function (c2802xpwm): '<Root>/ePWM2_MOSFET' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  EPwm2Regs.AQCSFRC.bit.CSFA = rtb_MOSFET_Enable;

  /* RateTransition: '<Root>/Rate Transition5' */
  Openloop_voltage_control_B.RateTransition5 =
    Openloop_voltage_control_DW.RateTransition5_Buffer0;

  /* S-Function (c280xgpio_do): '<Root>/Eanble Output' */
  {
    if (Openloop_voltage_control_B.RateTransition5)
      GpioDataRegs.GPASET.bit.GPIO4 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;
  }
}

/* Model step function for TID1 */
void Openloop_voltage_control_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition5' */
  Openloop_voltage_control_DW.RateTransition5_Buffer0 =
    Openloop_voltage_control_P.Constant6_Value;
}

/* Model initialize function */
void Openloop_voltage_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Openloop_voltage_control_M, 0,
                sizeof(RT_MODEL_Openloop_voltage_con_T));

  /* block I/O */
  (void) memset(((void *) &Openloop_voltage_control_B), 0,
                sizeof(B_Openloop_voltage_control_T));

  /* states (dwork) */
  (void) memset((void *)&Openloop_voltage_control_DW, 0,
                sizeof(DW_Openloop_voltage_control_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC_MOSFET_ON' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<Root>/VoltMeas' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC8 ();

  /* Start for S-Function (c2802xadc): '<Root>/ADC_IGBT_ON' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC2 ();

  /* Start for S-Function (c280xgpio_do): '<Root>/BlueLED' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFCFFFFFF;
  GpioCtrlRegs.GPADIR.all |= 0x1000;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/GreenLED' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFF3F;
  GpioCtrlRegs.GPADIR.all |= 0x80000;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/RedLED' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCF;
  GpioCtrlRegs.GPBDIR.all |= 0x4;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM1_IGBT' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 0;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFF) | 0x30;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 4000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm1Regs.CMPA.half.CMPA = 2000;   // Counter Compare A Register
    EPwm1Regs.CMPB = 32000;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 154;// Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 3;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0xC0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm1Regs.DBRED = 0; // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0;// Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1001;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm1Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM2_MOSFET' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 0;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm2Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFF) | 0x30;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 750;             // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0;         // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
    EPwm2Regs.CMPA.half.CMPA = 525;    // Counter Compare A Register
    EPwm2Regs.CMPB = 32000;            // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 154;// Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 3;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0xC0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm2Regs.DBRED = 0; // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 0;// Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 0;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD                = 1;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1001;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm2Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0) | 0x0;
    EDIS;
    EALLOW;

    /* Enable TBCLK within the EPWM*/
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/Eanble Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFCFF;
  GpioCtrlRegs.GPADIR.all |= 0x10;
  EDIS;
  Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE = POS_ZCSIG;
  Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition5' */
  Openloop_voltage_control_DW.RateTransition5_Buffer0 =
    Openloop_voltage_control_P.RateTransition5_InitialConditio;

  /* SystemInitialize for Triggered SubSystem: '<S2>/Sample and Hold1' */
  /* SystemInitialize for Outport: '<S3>/ ' incorporates:
   *  Inport: '<S3>/In'
   */
  Openloop_voltage_control_B.In_g = Openloop_voltage_control_P._Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/Sample and Hold1' */

  /* SystemInitialize for Triggered SubSystem: '<S2>/Sample and Hold2' */
  /* SystemInitialize for Outport: '<S4>/ ' incorporates:
   *  Inport: '<S4>/In'
   */
  Openloop_voltage_control_B.In = Openloop_voltage_control_P._Y0_a;

  /* End of SystemInitialize for SubSystem: '<S2>/Sample and Hold2' */
}

/* Model terminate function */
void Openloop_voltage_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
