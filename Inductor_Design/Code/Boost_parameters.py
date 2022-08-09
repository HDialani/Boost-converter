import math

Load=400 #Ohm


### MOSFET
MOSFET_Output_Voltage=150 #V
MOSFET_Input_Voltage=45 #V
MOSFET_Switching_Frequency = 8.0e04 #Hz
MOSFET_Duty_Cycle=1-MOSFET_Input_Voltage/MOSFET_Output_Voltage

##CCM
MOSFET_Current_Ripple_Ratio=0.4 #Peak-Peak

MOSFET_Output_Current=MOSFET_Output_Voltage/Load #I
MOSFET_CCM_Inductance= (MOSFET_Duty_Cycle*MOSFET_Input_Voltage)/(MOSFET_Switching_Frequency*MOSFET_Current_Ripple_Ratio*MOSFET_Output_Voltage*MOSFET_Output_Current/MOSFET_Input_Voltage ) #H

MOSFET_CCM_Ripple_Current=MOSFET_Input_Voltage*MOSFET_Duty_Cycle/(MOSFET_CCM_Inductance*MOSFET_Switching_Frequency) #I
MOSFET_CCM_I_RMS=math.sqrt((MOSFET_Output_Current/(1-MOSFET_Duty_Cycle))**2 + (MOSFET_CCM_Ripple_Current**2 /12))
MOSFET_CCM_I_peak=MOSFET_CCM_I_RMS+0.5*MOSFET_CCM_Ripple_Current

##DCM
MOSFET_DCM_Inductance=MOSFET_Duty_Cycle**2*Load*MOSFET_Input_Voltage**2/(2*MOSFET_Output_Voltage*MOSFET_Switching_Frequency*(MOSFET_Output_Voltage-MOSFET_Input_Voltage))
MOSFET_DCM_Delta_1=2*MOSFET_Output_Voltage*MOSFET_DCM_Inductance*MOSFET_Switching_Frequency/(MOSFET_Input_Voltage*MOSFET_Duty_Cycle*Load)

MOSFET_DCM_Ripple_Current= MOSFET_Input_Voltage*MOSFET_Duty_Cycle/(MOSFET_DCM_Inductance*MOSFET_Switching_Frequency)
MOSFET_DCM_I_peak=MOSFET_Input_Voltage* MOSFET_Duty_Cycle/(MOSFET_DCM_Inductance*MOSFET_Switching_Frequency)
MOSFET_DCM_I_RMS=math.sqrt((MOSFET_Duty_Cycle+MOSFET_DCM_Delta_1)*MOSFET_DCM_Ripple_Current**2 /3)

### IGBT
IGBT_Output_Voltage=300 #V
IGBT_Input_Voltage=45 #V
IGBT_Switching_Frequency = 1.5e04 #Hz
IGBT_Duty_Cycle=1-IGBT_Input_Voltage/IGBT_Output_Voltage

##CCM
IGBT_Current_Ripple_Ratio=0.5 #Peak-Peak

IGBT_Output_Current=IGBT_Output_Voltage/Load #I
IGBT_CCM_Inductance= (IGBT_Duty_Cycle*IGBT_Input_Voltage)/(IGBT_Switching_Frequency*IGBT_Current_Ripple_Ratio*IGBT_Output_Voltage*IGBT_Output_Current/IGBT_Input_Voltage ) #H

IGBT_CCM_Ripple_Current=IGBT_Input_Voltage*IGBT_Duty_Cycle/(IGBT_CCM_Inductance*IGBT_Switching_Frequency) #I
IGBT_CCM_I_RMS=math.sqrt((IGBT_Output_Current/(1-IGBT_Duty_Cycle))**2 + (IGBT_CCM_Ripple_Current**2 /12))
IGBT_CCM_I_peak=IGBT_CCM_I_RMS+0.5*IGBT_CCM_Ripple_Current

##DCM
IGBT_DCM_Inductance=IGBT_Duty_Cycle**2*Load*IGBT_Input_Voltage**2/(2*IGBT_Output_Voltage*IGBT_Switching_Frequency*(IGBT_Output_Voltage-IGBT_Input_Voltage))
IGBT_DCM_Delta_1=2*IGBT_Output_Voltage*IGBT_DCM_Inductance*IGBT_Switching_Frequency/(IGBT_Input_Voltage*IGBT_Duty_Cycle*Load)

IGBT_DCM_Ripple_Current= IGBT_Input_Voltage*IGBT_Duty_Cycle/(IGBT_DCM_Inductance*IGBT_Switching_Frequency)
IGBT_DCM_I_peak=IGBT_Input_Voltage* IGBT_Duty_Cycle/(IGBT_DCM_Inductance*IGBT_Switching_Frequency)
IGBT_DCM_I_RMS=math.sqrt((IGBT_Duty_Cycle+IGBT_DCM_Delta_1)*IGBT_DCM_Ripple_Current**2 /3)