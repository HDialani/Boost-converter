#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "Openloop_voltage_control.h"
#include "Openloop_voltage_control_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

void init_SCI(void)
{                                      /* initialize SCI & FIFO registers */
  EALLOW;

  /*
   * Initialize SCI_A with following parameters:
   *    BaudRate              : 9603
   *    CharacterLengthBits   : 8
   *    EnableLoopBack        : 0
   *    NumberOfStopBits      : 1
   *    ParityMode            : None
   *    SuspensionMode        : Free_run
   *    CommMode              : Raw_data
   */
  SciaRegs.SCICCR.bit.STOPBITS = 0;
                    /*Number of stop bits. (0: One stop bit, 1: Two stop bits)*/
  SciaRegs.SCICCR.bit.PARITY = 0;/*Parity mode (0: Odd parity, 1: Even parity)*/
  SciaRegs.SCICCR.bit.PARITYENA = 0;   /*Enable Pary Mode */
  SciaRegs.SCICCR.bit.LOOPBKENA = 0;   /*Loop Back enable*/
  SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;/*ADDR/IDLE Mode control*/
  SciaRegs.SCICCR.bit.SCICHAR = 7;     /*Character length*/
  SciaRegs.SCICTL1.bit.RXERRINTENA = 0;/*Disable receive error interrupt*/
  SciaRegs.SCICTL1.bit.SWRESET = 1;    /*Software reset*/
  SciaRegs.SCICTL1.bit.TXENA = 1;      /* SCI transmitter enable*/
  SciaRegs.SCICTL1.bit.RXENA = 1;      /* SCI receiver enable*/
  SciaRegs.SCIHBAUD = 3U;
  SciaRegs.SCILBAUD = 12U;

  /*Free run, continue SCI operation regardless of suspend*/
  SciaRegs.SCIPRI.bit.FREE = 1;        /* Free emulation mode control*/
  SciaRegs.SCIPRI.bit.SOFT = 0;        /* Interrupt priority select*/
  SciaRegs.SCIFFCT.bit.ABDCLR = 0;
  SciaRegs.SCIFFCT.bit.CDC = 0;
  SciaRegs.SCIFFTX.bit.SCIRST = 1;     /* SCI reset rx/tx channels*/
  SciaRegs.SCIFFTX.bit.SCIFFENA = 1;   /* SCI FIFO enhancements are enabled.*/
  SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;/* Re-enable transmit FIFO operation.*/
  SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;/* Re-enable receive FIFO operation.*/
  EDIS;
}

void init_SCI_GPIO(void)
{
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;  /*Enable pull-up for GPIO28*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1; /*Configure GPIO28 as SCIRXDA*/
  GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;  /*Enable pull-up for GPIO29*/
  GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1; /*Configure GPIO29 as SCITXDA*/
  EDIS;
}

void configureGPIOExtInterrupt (void)
{
}

void enableExtInterrupt (void)
{
}
