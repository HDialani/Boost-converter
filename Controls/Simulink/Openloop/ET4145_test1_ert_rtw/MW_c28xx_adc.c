#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "ET4145_test1.h"
#include "ET4145_test1_private.h"

void config_ADC_SOC2()
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 0;   /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN2 = 0;/* Single sample mode set for SOC2.*/
  AdcRegs.ADCSOC2CTL.bit.CHSEL = 3;    /* Set SOC2 channel select to ADCINA3*/
  AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 0;
  AdcRegs.ADCSOC2CTL.bit.ACQPS = 6.0;
                                /* Set SOC2 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC2 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0 ;  /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC0()
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 0;   /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN0 = 0;/* Single sample mode set for SOC0.*/
  AdcRegs.ADCSOC0CTL.bit.CHSEL = 7;    /* Set SOC0 channel select to ADCINA7*/
  AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 0;
  AdcRegs.ADCSOC0CTL.bit.ACQPS = 6.0;
                                /* Set SOC0 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0 ;  /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC8()
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 0;   /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN8 = 0;/* Single sample mode set for SOC8.*/
  AdcRegs.ADCSOC8CTL.bit.CHSEL = 9;    /* Set SOC8 channel select to ADCINB1*/
  AdcRegs.ADCSOC8CTL.bit.TRIGSEL = 0;
  AdcRegs.ADCSOC8CTL.bit.ACQPS = 6.0;
                                /* Set SOC8 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL2.bit.SOC8 = 0;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0 ;  /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0;/* All in round robin mode SOC Priority*/
  EDIS;
}
