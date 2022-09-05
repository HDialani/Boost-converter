/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Openloop_voltage_control.c
 *
 * Code generated for Simulink model 'Openloop_voltage_control'.
 *
 * Model version                  : 5.64
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Sep  5 11:54:25 2022
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
real_T uMultiWord2Double(const uint64_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp((real_T)u1[i], exp_0);
    exp_0 += 64;
  }

  return y;
}

void uMultiWord2MultiWord(const uint64_T u1[], int16_T n1, uint64_T y[], int16_T
  n)
{
  int16_T i;
  int16_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0ULL;
    }
  }
}

void uMultiWordShr(const uint64_T u1[], int16_T n1, uint16_T n2, uint64_T y[],
                   int16_T n)
{
  uint64_T u1i;
  uint64_T yi;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 6U);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 6U);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (64U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (64U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0ULL;
    i++;
  }
}

void uMultiWordMul(const uint64_T u1[], int16_T n1, const uint64_T u2[], int16_T
                   n2, uint64_T y[], int16_T n)
{
  uint64_T a0;
  uint64_T a1;
  uint64_T b1;
  uint64_T cb;
  uint64_T u1i;
  uint64_T w01;
  uint64_T w10;
  uint64_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0ULL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0ULL;
    u1i = u1[i];
    a1 = u1i >> 32U;
    a0 = u1i & 4294967295ULL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 32U;
      u1i &= 4294967295ULL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint64_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 32U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 32U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 32U;
      cb += w01 >> 32U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void uMultiWordShl(const uint64_T u1[], int16_T n1, uint16_T n2, uint64_T y[],
                   int16_T n)
{
  uint64_T u1i;
  uint64_T yi;
  uint64_T ys;
  int16_T i;
  int16_T nb;
  int16_T nc;
  uint16_T nl;
  nb = (int16_T)(n2 >> 6U);
  ys = (u1[n1 - 1] & 9223372036854775808ULL) != 0ULL ? MAX_uint64_T : 0ULL;
  nc = nb > n ? n : nb;
  u1i = 0ULL;
  for (i = 0; i < nc; i++) {
    y[i] = 0ULL;
  }

  if (nb < n) {
    nl = n2 - ((uint16_T)nb << 6U);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (64U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (64U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void MultiWordAdd(const uint64_T u1[], const uint64_T u2[], uint64_T y[],
                  int16_T n)
{
  uint64_T carry = 0ULL;
  uint64_T u1i;
  uint64_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0ULL ? (uint64_T)(yi <= u1i) : (uint64_T)(yi < u1i);
  }
}

void MultiWordUnsignedWrap(const uint64_T u1[], int16_T n1, uint16_T n2,
  uint64_T y[])
{
  int16_T i;
  int16_T n1m1;
  n1m1 = n1 - 1;
  for (i = 0; i < n1m1; i++) {
    y[i] = u1[i];
  }

  y[n1 - 1] = ((1ULL << (64U - n2)) - 1ULL) & u1[n1 - 1];
}

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
  real_T rtb_Divide1_g;
  real_T rtb_Divide_m;
  uint16_T rtb_IGBT_Enable;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_MOSFET_Enable;
  uint16_T rtb_DataTypeConversion2;
  static const uint128m_T tmp_9 = { { 1152921504606847ULL, 0ULL }/* chunks */
  };

  uint128m_T tmp;
  uint128m_T tmp_2;
  uint128m_T tmp_3;
  uint128m_T tmp_4;
  uint128m_T tmp_5;
  uint192m_T tmp_0;
  uint192m_T tmp_1;
  uint192m_T tmp_7;
  uint192m_T tmp_8;
  real_T rtb_Switch1;
  uint64_T rtb_Opamp_converter;
  uint64_T rtb_Sum1;
  uint64_T tmp_6;
  int16_T rtb_y1;
  int16_T rtb_y2;
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_LogicalOperator2_tmp;
  boolean_T rtb_LogicalOperator4;
  boolean_T rtb_LogicalOperator4_tmp;
  boolean_T rtb_RelationalOperator3;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

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

  /* S-Function (c28xsci_rx): '<S1>/SCI Receive' */
  {
    int i;
    int errFlg = NOERROR;
    unsigned int recbuff[10];
    for (i = 0; i < 10; i++)
      recbuff[i] = 0;

    /* Getting Data Head */
    {
      unsigned int recHead;
      int cnt = 0;
      int i = 0;
      char *expHead = "S";
      while (i < 1) {
        scia_rcv(&recHead, 1, SHORTLOOP, 1);
        if (recHead == expHead[i]) {
          i++;
        } else {
          i = 0;
        }

        if (cnt++ > 16) {
          errFlg = TIMEOUT;
          goto RXERRA;
        }
      }
    }

    /* End of Getting Data Head */

    /* Receiving data */
    errFlg = scia_rcv(recbuff, 20, LONGLOOP, 2);
    if (errFlg != NOERROR)
      goto RXERRA;

    /* Getting Data Tail */
    {
      int i;
      char *expTail = "E";
      unsigned int recTail[1];
      scia_rcv(recTail, 1, LONGLOOP, 1);
      for (i = 0; i< 1; i++) {
        if (expTail[i] != recTail[i]) {
          errFlg = DATAERR;
          goto RXERRA;
        }
      }
    }

    /* End of Getting Data Tail */
    memcpy( &Openloop_voltage_control_B.SCIReceive[0], recbuff, 10);
   RXERRA:
    asm(" NOP");
  }

  /* S-Function (c2802xadc): '<S3>/VoltMeas' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC8 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.Volt_Protection = (AdcResult.ADCRESULT8);
  }

  /* Gain: '<S7>/Opamp_converter' incorporates:
   *  Gain: '<S7>/1//ADC_resolution'
   */
  rtb_Opamp_converter = (uint64_T)((uint32_T)
    Openloop_voltage_control_P.uADC_resolution_Gain *
    Openloop_voltage_control_B.Volt_Protection) *
    Openloop_voltage_control_P.Opamp_converter_Gain;

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S7>/unit converter1'
   *  Gain: '<S7>/Opamp_converter'
   */
  rtb_DataTypeConversion2 = (uint16_T)rtb_Opamp_converter;

  /* SignalConversion generated from: '<S7>/SCI Transmit' */
  Openloop_voltage_control_B.TmpSignalConversionAtSCITransmi[0] =
    rtb_DataTypeConversion2;
  Openloop_voltage_control_B.TmpSignalConversionAtSCITransmi[1] =
    Openloop_voltage_control_B.SCIReceive[3];

  /* Product: '<S111>/Divide1' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Product: '<S7>/Divide3'
   *  Product: '<S9>/Divide1'
   *  Switch: '<S2>/Switch'
   */
  rtb_Switch1 = (real_T)((uint32_T)Openloop_voltage_control_P.Gain1_Gain *
    Openloop_voltage_control_B.SCIReceive[4]) * 0.015625;

  /* Product: '<S111>/Divide1' incorporates:
   *  Constant: '<S111>/CLK frequency1'
   */
  rtb_Divide1_g = Openloop_voltage_control_P.CLKfrequency1_Value / rtb_Switch1;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Opamp_converter'
   */
  rtb_Sum1 = ((uint64_T)Openloop_voltage_control_B.SCIReceive[3] << 48U) -
    (rtb_Opamp_converter >> 2U);

  /* Switch: '<S2>/Switch' */
  if (Openloop_voltage_control_B.SCIReceive[9] >
      Openloop_voltage_control_P.Switch_Threshold) {
    /* Product: '<S111>/Divide' incorporates:
     *  Constant: '<S9>/CLK frequency'
     *  Constant: '<S9>/V_f2'
     *  Constant: '<S9>/V_f3'
     *  Constant: '<S9>/V_in1'
     *  Product: '<S9>/Divide1'
     *  Product: '<S9>/Divide3'
     *  Product: '<S9>/Product1'
     *  Sum: '<S9>/Add1'
     *  Sum: '<S9>/Plus1'
     */
    rtb_Divide_m = (((real_T)Openloop_voltage_control_B.SCIReceive[3] +
                     Openloop_voltage_control_P.V_f2_Value) -
                    Openloop_voltage_control_P.V_in1_Value) /
      (Openloop_voltage_control_P.V_f3_Value + (real_T)
       Openloop_voltage_control_B.SCIReceive[3]) *
      (Openloop_voltage_control_P.CLKfrequency_Value / rtb_Switch1);
  } else {
    /* Sum: '<S52>/Sum' incorporates:
     *  DiscreteIntegrator: '<S43>/Integrator'
     */
    tmp_2 = Openloop_voltage_control_DW.Integrator_DSTATE;
    tmp_3 = tmp_9;
    uMultiWordMul(&tmp_2.chunks[0U], 2, &tmp_9.chunks[0U], 2, &tmp_1.chunks[0U],
                  3);
    uMultiWordShr(&tmp_1.chunks[0U], 3, 12U, &tmp_0.chunks[0U], 3);
    uMultiWord2MultiWord(&tmp_0.chunks[0U], 3, &tmp.chunks[0U], 2);

    /* Product: '<S111>/Divide' incorporates:
     *  Constant: '<S7>/CLK frequency'
     *  Product: '<S7>/Divide3'
     *  Product: '<S7>/Product1'
     */
    rtb_Divide_m = Openloop_voltage_control_P.CLKfrequency_Value_k / rtb_Switch1
      * (uMultiWord2Double(&tmp.chunks[0U], 2, 0) * 1.2621774483536189E-29);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  rtb_Switch1 = floor(rtb_Divide_m);
  if (rtIsNaN(rtb_Switch1) || rtIsInf(rtb_Switch1)) {
    rtb_Switch1 = 0.0;
  } else {
    rtb_Switch1 = fmod(rtb_Switch1, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = rtb_Switch1 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_Switch1 : (uint16_T)rtb_Switch1;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  switch (Openloop_voltage_control_B.SCIReceive[0]) {
   case 0U:
    rtb_y1 = 1000;
    rtb_y2 = 1000;
    break;

   case 1U:
    rtb_y1 = 1000;
    rtb_y2 = 0;
    break;

   case 2U:
    rtb_y1 = 0;
    rtb_y2 = 1000;
    break;

   default:
    rtb_y1 = 1000;
    rtb_y2 = 1000;
    break;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* RelationalOperator: '<S4>/Relational Operator3' incorporates:
   *  Constant: '<S4>/Constant8'
   */
  rtb_RelationalOperator3 = (Openloop_voltage_control_P.Constant8_Value <=
    (uint16_T)rtb_y2);

  /* Logic: '<S4>/Logical Operator2' incorporates:
   *  Constant: '<S4>/Constant13'
   *  Logic: '<S4>/Logical Operator7'
   *  RelationalOperator: '<S4>/Relational Operator5'
   */
  rtb_LogicalOperator2_tmp = !rtb_RelationalOperator3;
  rtb_LogicalOperator2 = ((Openloop_voltage_control_B.Volt_Protection >
    Openloop_voltage_control_P.Constant13_Value) && rtb_LogicalOperator2_tmp);

  /* Outputs for Triggered SubSystem: '<S4>/Sample and Hold2' incorporates:
   *  TriggerPort: '<S110>/Trigger'
   */
  if (rtb_LogicalOperator2 &&
      (Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S110>/In' incorporates:
     *  Constant: '<S4>/Constant16'
     */
    Openloop_voltage_control_B.In = Openloop_voltage_control_P.Constant16_Value;
  }

  Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE = rtb_LogicalOperator2;

  /* End of Outputs for SubSystem: '<S4>/Sample and Hold2' */

  /* Logic: '<S4>/Logical Operator3' incorporates:
   *  Constant: '<S4>/Constant9'
   *  Logic: '<S4>/Logical Operator1'
   */
  rtb_LogicalOperator2 = (Openloop_voltage_control_B.In ||
    (Openloop_voltage_control_P.Constant9_Value || rtb_RelationalOperator3));

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  rtb_IGBT_Enable = rtb_LogicalOperator2;

  /* RelationalOperator: '<S4>/Relational Operator1' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  rtb_RelationalOperator3 = (Openloop_voltage_control_P.Constant3_Value <=
    (uint16_T)rtb_y1);

  /* Logic: '<S4>/Logical Operator4' incorporates:
   *  Constant: '<S4>/Constant14'
   *  Logic: '<S4>/Logical Operator7'
   *  RelationalOperator: '<S4>/Relational Operator4'
   */
  rtb_LogicalOperator4_tmp = !rtb_RelationalOperator3;
  rtb_LogicalOperator4 = (rtb_LogicalOperator4_tmp &&
    (Openloop_voltage_control_P.Constant14_Value <
     Openloop_voltage_control_B.Volt_Protection));

  /* Outputs for Triggered SubSystem: '<S4>/Sample and Hold1' incorporates:
   *  TriggerPort: '<S109>/Trigger'
   */
  if (rtb_LogicalOperator4 &&
      (Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S109>/In' incorporates:
     *  Constant: '<S4>/Constant15'
     */
    Openloop_voltage_control_B.In_g =
      Openloop_voltage_control_P.Constant15_Value;
  }

  Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE = rtb_LogicalOperator4;

  /* End of Outputs for SubSystem: '<S4>/Sample and Hold1' */

  /* Logic: '<S4>/NOT1' incorporates:
   *  Logic: '<S4>/Logical Operator6'
   */
  Openloop_voltage_control_B.RedLED = ((!Openloop_voltage_control_B.In_g) &&
    (!Openloop_voltage_control_B.In));

  /* Logic: '<S4>/NOT2' incorporates:
   *  Logic: '<S4>/Logical Operator7'
   */
  Openloop_voltage_control_B.GreenLED = (rtb_LogicalOperator4_tmp ||
    rtb_LogicalOperator2_tmp);

  /* Logic: '<S4>/Logical Operator5' incorporates:
   *  Constant: '<S4>/Constant9'
   *  Logic: '<S4>/Logical Operator'
   */
  rtb_RelationalOperator3 = (rtb_RelationalOperator3 ||
    Openloop_voltage_control_P.Constant9_Value ||
    Openloop_voltage_control_B.In_g);

  /* Logic: '<S4>/NOT3' incorporates:
   *  Logic: '<S4>/Logical Operator8'
   */
  Openloop_voltage_control_B.BLUELED = (rtb_RelationalOperator3 &&
    rtb_LogicalOperator2);

  /* Product: '<S111>/Divide' incorporates:
   *  Gain: '<S1>/Gain'
   *  Product: '<S7>/Divide2'
   *  Product: '<S9>/Divide'
   *  Switch: '<S2>/Switch1'
   */
  rtb_Switch1 = (real_T)((uint32_T)Openloop_voltage_control_P.Gain_Gain *
    Openloop_voltage_control_B.SCIReceive[2]) * 0.015625;

  /* Product: '<S111>/Divide' incorporates:
   *  Constant: '<S111>/CLK frequency'
   */
  rtb_Divide_m = Openloop_voltage_control_P.CLKfrequency_Value_e / rtb_Switch1;

  /* Product: '<S7>/Divide1' incorporates:
   *  Gain: '<S7>/Opamp_converter'
   *  Sum: '<S7>/Sum'
   */
  rtb_Opamp_converter = Openloop_voltage_control_B.SCIReceive[1] == 0ULL ?
    MAX_uint64_T : (((uint64_T)Openloop_voltage_control_B.SCIReceive[1] << 48U)
                    - (rtb_Opamp_converter >> 2U)) /
    Openloop_voltage_control_B.SCIReceive[1];

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S7>/CLK frequency'
   *  Constant: '<S9>/CLK frequency'
   *  Constant: '<S9>/V_f'
   *  Constant: '<S9>/V_f1'
   *  Constant: '<S9>/V_in'
   *  Product: '<S7>/Divide2'
   *  Product: '<S7>/Product'
   *  Product: '<S9>/Divide'
   *  Product: '<S9>/Divide2'
   *  Product: '<S9>/Product'
   *  Sum: '<S9>/Add'
   *  Sum: '<S9>/Plus'
   */
  if (Openloop_voltage_control_B.SCIReceive[9] >
      Openloop_voltage_control_P.Switch1_Threshold) {
    rtb_Switch1 = (((real_T)Openloop_voltage_control_B.SCIReceive[1] +
                    Openloop_voltage_control_P.V_f_Value) -
                   Openloop_voltage_control_P.V_in_Value) /
      (Openloop_voltage_control_P.V_f1_Value + (real_T)
       Openloop_voltage_control_B.SCIReceive[1]) *
      (Openloop_voltage_control_P.CLKfrequency_Value / rtb_Switch1);
  } else {
    /* Product: '<S96>/PProd Out' incorporates:
     *  Product: '<S7>/Divide1'
     */
    tmp_6 = Openloop_voltage_control_B.SCIReceive[5];
    uMultiWordMul(&rtb_Opamp_converter, 1, &tmp_6, 1, &tmp_5.chunks[0U], 2);

    /* Sum: '<S100>/Sum' */
    uMultiWordShl(&tmp_5.chunks[0U], 2, 9U, &tmp_4.chunks[0U], 2);
    uMultiWordMul(&Openloop_voltage_control_DW.Integrator_DSTATE_k.chunks[0U], 2,
                  &tmp_9.chunks[0U], 2, &tmp_8.chunks[0U], 3);
    uMultiWordShr(&tmp_8.chunks[0U], 3, 51U, &tmp_7.chunks[0U], 3);
    uMultiWord2MultiWord(&tmp_7.chunks[0U], 3, &tmp_5.chunks[0U], 2);
    MultiWordAdd(&tmp_4.chunks[0U], &tmp_5.chunks[0U], &tmp_3.chunks[0U], 2);
    uMultiWord2MultiWord(&tmp_3.chunks[0U], 2, &tmp_1.chunks[0U], 3);
    uMultiWordShl(&tmp_1.chunks[0U], 3, 39U, &tmp_0.chunks[0U], 3);
    uMultiWord2MultiWord(&tmp_0.chunks[0U], 3, &tmp_2.chunks[0U], 2);
    rtb_Switch1 = Openloop_voltage_control_P.CLKfrequency_Value_k / rtb_Switch1 *
      (uMultiWord2Double(&tmp_2.chunks[0U], 2, 0) * 1.2621774483536189E-29);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_Switch1 = floor(rtb_Switch1);
  if (rtIsNaN(rtb_Switch1) || rtIsInf(rtb_Switch1)) {
    rtb_Switch1 = 0.0;
  } else {
    rtb_Switch1 = fmod(rtb_Switch1, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_DataTypeConversion = rtb_Switch1 < 0.0 ? (uint16_T)-(int16_T)(uint16_T)
    -rtb_Switch1 : (uint16_T)rtb_Switch1;

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  rtb_MOSFET_Enable = rtb_RelationalOperator3;

  /* S-Function (c2802xpwm): '<S5>/ePWM2_MOSFET' */
  {
    EPwm2Regs.TBPRD = (uint16_T)(rtb_Divide_m);
  }

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion);
  }

  EPwm2Regs.AQCSFRC.bit.CSFA = rtb_MOSFET_Enable;

  /* S-Function (c280xgpio_do): '<S5>/BlueLED' */
  {
    if (Openloop_voltage_control_B.BLUELED)
      GpioDataRegs.GPASET.bit.GPIO12 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;
  }

  /* S-Function (c280xgpio_do): '<S5>/GreenLED' */
  {
    if (Openloop_voltage_control_B.GreenLED)
      GpioDataRegs.GPASET.bit.GPIO19 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;
  }

  /* S-Function (c280xgpio_do): '<S5>/RedLED' */
  {
    if (Openloop_voltage_control_B.RedLED)
      GpioDataRegs.GPBSET.bit.GPIO34 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
  }

  /* S-Function (c2802xpwm): '<S5>/ePWM1_IGBT' */
  {
    EPwm1Regs.TBPRD = (uint16_T)(rtb_Divide1_g);
  }

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(rtb_DataTypeConversion2);
  }

  EPwm1Regs.AQCSFRC.bit.CSFA = rtb_IGBT_Enable;

  /* S-Function (c28xsci_tx): '<S7>/SCI Transmit' */
  {
    /* Send additional data header */
    {
      char *String = "S";
      scia_xmit(String, 1, 1);
    }

    scia_xmit((char*)
              &Openloop_voltage_control_B.TmpSignalConversionAtSCITransmi[0], 4,
              2);

    /* Send additional data terminator */
    {
      char *String = "E";
      scia_xmit(String, 1, 1);
    }
  }

  /* S-Function (c2802xadc): '<S3>/ADC_MOSFET_ON' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.MOSFET_Enable = (AdcResult.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S3>/ADC_IGBT_ON' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcRegs.ADCSOCFRC1.bit.SOC2 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #22 || NOP");
    Openloop_voltage_control_B.IGBT_Enable = (AdcResult.ADCRESULT2);
  }

  /* Update for DiscreteIntegrator: '<S43>/Integrator' */
  tmp_4 = Openloop_voltage_control_DW.Integrator_DSTATE;

  /* Product: '<S40>/IProd Out' incorporates:
   *  Sum: '<S7>/Sum1'
   */
  tmp_6 = Openloop_voltage_control_B.SCIReceive[7];
  uMultiWordMul(&rtb_Sum1, 1, &tmp_6, 1, &tmp_5.chunks[0U], 2);

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Sum: '<S100>/Sum'
   *  Switch: '<S2>/Switch1'
   */
  MultiWordAdd(&tmp_4.chunks[0U], &tmp_5.chunks[0U], &tmp_3.chunks[0U], 2);
  MultiWordUnsignedWrap(&tmp_3.chunks[0U], 2, 48U, &tmp_4.chunks[0U]);
  Openloop_voltage_control_DW.Integrator_DSTATE = tmp_4;

  /* Update for DiscreteIntegrator: '<S91>/Integrator' */
  tmp_5 = Openloop_voltage_control_DW.Integrator_DSTATE_k;

  /* Product: '<S88>/IProd Out' incorporates:
   *  Product: '<S7>/Divide1'
   */
  tmp_6 = Openloop_voltage_control_B.SCIReceive[6];
  uMultiWordMul(&rtb_Opamp_converter, 1, &tmp_6, 1,
                &Openloop_voltage_control_DW.Integrator_DSTATE_k.chunks[0U], 2);

  /* Update for DiscreteIntegrator: '<S91>/Integrator' */
  MultiWordAdd(&tmp_5.chunks[0U],
               &Openloop_voltage_control_DW.Integrator_DSTATE_k.chunks[0U],
               &tmp_3.chunks[0U], 2);
  MultiWordUnsignedWrap(&tmp_3.chunks[0U], 2, 48U, &tmp_5.chunks[0U]);

  /* Update for Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Switch: '<S2>/Switch1'
   */
  Openloop_voltage_control_DW.Integrator_DSTATE_k = tmp_5;
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

  /* Start for S-Function (c280xgpio_do): '<Root>/Eanble Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFCFF;
  GpioCtrlRegs.GPADIR.all |= 0x10;
  EDIS;

  /* Start for S-Function (c28xsci_rx): '<S1>/SCI Receive' */

  /* Initialize Openloop_voltage_control_B.SCIReceive[0] */
  {
    Openloop_voltage_control_B.SCIReceive[0] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[1] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[2] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[3] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[4] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[5] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[6] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[7] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[8] = (uint16_T)0.0;
    Openloop_voltage_control_B.SCIReceive[9] = (uint16_T)0.0;
  }

  /* Start for S-Function (c2802xadc): '<S3>/VoltMeas' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC8 ();

  /* Start for S-Function (c2802xpwm): '<S5>/ePWM2_MOSFET' */

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
    EPwm2Regs.TBPRD = 1500;            // Time Base Period Register

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
  }

  /* Start for S-Function (c280xgpio_do): '<S5>/BlueLED' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFCFFFFFF;
  GpioCtrlRegs.GPADIR.all |= 0x1000;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<S5>/GreenLED' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFF3F;
  GpioCtrlRegs.GPADIR.all |= 0x80000;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<S5>/RedLED' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCF;
  GpioCtrlRegs.GPBDIR.all |= 0x4;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S5>/ePWM1_IGBT' */

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
    EPwm1Regs.TBPRD = 8000;            // Time Base Period Register

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
    EALLOW;

    /* Enable TBCLK within the EPWM*/
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* Start for S-Function (c2802xadc): '<S3>/ADC_MOSFET_ON' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S3>/ADC_IGBT_ON' */
  if (MW_adcInitFlag == 0) {
    InitAdc();
    MW_adcInitFlag = 1;
  }

  config_ADC_SOC2 ();
  Openloop_voltage_contro_PrevZCX.SampleandHold1_Trig_ZCE = POS_ZCSIG;
  Openloop_voltage_contro_PrevZCX.SampleandHold2_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition5' */
  Openloop_voltage_control_DW.RateTransition5_Buffer0 =
    Openloop_voltage_control_P.RateTransition5_InitialConditio;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
  Openloop_voltage_control_DW.Integrator_DSTATE =
    Openloop_voltage_control_P.DiscretePIDController1_InitialC;

  /* InitializeConditions for Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S91>/Integrator'
   */
  Openloop_voltage_control_DW.Integrator_DSTATE_k =
    Openloop_voltage_control_P.DiscretePIDController2_InitialC;

  /* SystemInitialize for Triggered SubSystem: '<S4>/Sample and Hold1' */
  /* SystemInitialize for Outport: '<S109>/ ' incorporates:
   *  Inport: '<S109>/In'
   */
  Openloop_voltage_control_B.In_g = Openloop_voltage_control_P._Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Sample and Hold1' */

  /* SystemInitialize for Triggered SubSystem: '<S4>/Sample and Hold2' */
  /* SystemInitialize for Outport: '<S110>/ ' incorporates:
   *  Inport: '<S110>/In'
   */
  Openloop_voltage_control_B.In = Openloop_voltage_control_P._Y0_a;

  /* End of SystemInitialize for SubSystem: '<S4>/Sample and Hold2' */
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
