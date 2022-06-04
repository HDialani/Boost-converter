import math

### MOSFET
MOSFET_Output_Voltage=150 #V
MOSFET_Input_Voltage=45 #V
MOSFET_Switching_Frequency = 8.0e04 #Hz
MOSFET_Current_Ripple_Ratio=0.4 #Peak-Peak

MOSFET_Load=400 #Ohm

MOSFET_Duty_Cycle=1-MOSFET_Input_Voltage/MOSFET_Output_Voltage

MOSFET_Output_Current=MOSFET_Output_Voltage/MOSFET_Load #I
MOSFET_INPUT_Current=MOSFET_Output_Voltage*MOSFET_Output_Current/MOSFET_Input_Voltage #I
MOSFET_Ripple_Current=MOSFET_INPUT_Current*MOSFET_Current_Ripple_Ratio  #I

Mosfet_CCM_Inductance = (MOSFET_Duty_Cycle*MOSFET_Input_Voltage)/(MOSFET_Switching_Frequency*MOSFET_Ripple_Current) #H

Mosfet_CCM_I_peak=MOSFET_INPUT_Current+0.5*MOSFET_Ripple_Current
Mosfet_CCM_I_RMS=math.sqrt( (MOSFET_Output_Current/(1-MOSFET_Duty_Cycle))**2 + (MOSFET_Ripple_Current**2 /12))