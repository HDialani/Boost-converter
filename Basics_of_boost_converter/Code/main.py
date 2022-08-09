# Author: Hitesh Dialani
# Last modified: 24-04-22

import numpy as np
import matplotlib.pyplot as plt

def operation_mode(L,F_s,Load):
   D_length = 100
   D_0_to_1 = np.linspace(0, 1, D_length)
   K_crit = D_0_to_1 * (1 - D_0_to_1) ** 2

   K = 2 * L * F_s / Load
   K = K * np.ones(D_length)
   fig = plt.figure()
   plt.plot(D_0_to_1, K_crit, color='r', label='K_crit', )
   plt.plot(D_0_to_1, K, color='g', label='K')
   plt.xlabel("Duty cycle")
   plt.legend()
   plt.title('If K>K_crit you are in CCM and if K<K_crit you are in DCM ')
   return fig


F_s = float(8.0e04)   # Hz
V_out = int(150)   # V
V_in = int(45)   # V
Load = int(400)    # Ohm
Delta_I_Ratio = float(0.4)

### Continous Conduction Mode  FIX THE IMPORT PROBLEM
# import CCM
#
# CCM.CCMPlots()

L=0.75/1000
K=operation_mode(0.75/1000,F_s,Load)
plt.show()
