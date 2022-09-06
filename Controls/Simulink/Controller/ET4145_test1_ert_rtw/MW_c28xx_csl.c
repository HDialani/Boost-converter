#include "c2000BoardSupport.h"
#include "F2802x_Device.h"
#include "f2802x_examples.h"
#include "f2802x_globalprototypes.h"
#include "rtwtypes.h"
#include "ET4145_test1.h"
#include "ET4145_test1_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

void configureGPIOExtInterrupt (void)
{
}

void enableExtInterrupt (void)
{
}
