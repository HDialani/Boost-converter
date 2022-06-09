import math

Load=400 #Ohm
### MOSFET
MOSFET_Output_Voltage=150 #V
MOSFET_Input_Voltage=45 #V
MOSFET_Switching_Frequency = 8.0e04 #Hz
MOSFET_Current_Ripple_Ratio=0.4 #Peak-Peak



MOSFET_Duty_Cycle=1-MOSFET_Input_Voltage/MOSFET_Output_Voltage

MOSFET_Output_Current=MOSFET_Output_Voltage/Load #I
MOSFET_INPUT_Current=MOSFET_Output_Voltage*MOSFET_Output_Current/MOSFET_Input_Voltage #I
MOSFET_Ripple_Current=MOSFET_INPUT_Current*MOSFET_Current_Ripple_Ratio  #I

Mosfet_CCM_Inductance = (MOSFET_Duty_Cycle*MOSFET_Input_Voltage)/(MOSFET_Switching_Frequency*MOSFET_Ripple_Current) #H

Mosfet_CCM_I_peak=MOSFET_INPUT_Current+0.5*MOSFET_Ripple_Current
Mosfet_CCM_I_RMS=math.sqrt( (MOSFET_Output_Current/(1-MOSFET_Duty_Cycle))**2 + (MOSFET_Ripple_Current**2 /12))



### IGBT
IGBT_Output_Voltage=300 #V
IGBT_Input_Voltage=45 #V
IGBT_Switching_Frequency = 1.5e04 #Hz
IGBT_Current_Ripple_Ratio=0.5 #Peak-Peak


IGBT_Duty_Cycle=1-IGBT_Input_Voltage/IGBT_Output_Voltage

IGBT_Output_Current=IGBT_Output_Voltage/Load #I
IGBT_INPUT_Current=IGBT_Output_Voltage*IGBT_Output_Current/IGBT_Input_Voltage #I
IGBT_Ripple_Current=IGBT_INPUT_Current*IGBT_Current_Ripple_Ratio  #I

IGBT_CCM_Inductance = (IGBT_Duty_Cycle*IGBT_Input_Voltage)/(IGBT_Switching_Frequency*IGBT_Ripple_Current) #H

IGBT_CCM_I_peak=IGBT_INPUT_Current+0.5*MOSFET_Ripple_Current
IGBT_CCM_I_RMS=math.sqrt( (IGBT_Output_Current/(1-IGBT_Duty_Cycle))**2 + (IGBT_Ripple_Current**2 /12))