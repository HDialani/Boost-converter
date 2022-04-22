# Author: Hitesh Dialani
# Last modified: 23-04-22

import numpy as np
import matplotlib.pyplot as plt

F_s = float(8.0e04)   # Hz
V_out = int(150)   # V
V_in = int(45)   # V
Load = int(400)    # Ohm
Delta_I_Ratio = float(0.4)

### Continous Conduction Mode
D=1-V_in/V_out
I_out=V_out/Load

N=1000 # Sampling resolution
Ts=1/F_s #s
X= np.arange(0, 2*Ts,2*Ts/N)

V_L1=np.array(np.ones(len(np.arange(0,D*Ts,2*Ts/N)))* V_in)
V_L2=np.array(np.ones(len(np.arange(Ts/N,(1-D)*Ts,2*Ts/N)))*(V_in-V_out))
V_L3=np.array(np.ones(len(np.arange(Ts/N,D*Ts,2*Ts/N)))* V_in)
V_L4=np.array(np.ones(len(np.arange(Ts/N,(1-D)*Ts,2*Ts/N)))*(V_in-V_out))

V_La=np.append(V_L1,V_L2)
V_Lb=np.append(V_L3,V_L4)
V_L=np.append(V_La,V_Lb)

plt.subplot(2, 1, 1)
plt.plot(1e6*X, V_L)
plt.xlim([0,2*1e6*Ts])
plt.ylim([V_in-V_out-5,V_in+5])
plt.xlabel('Time [$\mu s$]')
plt.ylabel('$V_L$ [$V$]')
plt.show()