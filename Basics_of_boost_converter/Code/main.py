"""
@Author: Hitesh Dialani
@Date: 03-09-2022
"""

import matplotlib.pyplot as plt
import Different_plots
import CCM
import DCM

F_sw = float(8.0e04)   # Hz
V_out = int(150)   # V
V_in = int(45)   # V
Load = int(400)    # Ohm
Delta_I_Ratio = float(0.4)
L=0.75/1000

### Continous Conduction Mode
# CCM.CCMPlots(V_in,V_out,Load,F_sw,Delta_I_Ratio)

### Discontinous Conduction Mode
I_ripple_DCM = 2.5
DCM.DCMPlots(V_in,V_out,Load,F_sw,I_ripple_DCM)

### Duty cycle Plots
# Different_plots.operation_mode(L,F_sw,Load)
# Different_plots.CCM_V_out_duty_cycle(Load,V_in)

plt.show()