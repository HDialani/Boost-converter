### Discontinous Conduction Mode
import math

import numpy as np
import matplotlib.pyplot as plt

from main import F_s
from main import V_out
from main import V_in
from main import Load
from main import Delta_I_Ratio

L=0.1/1000
D=math.sqrt(((2*V_out**2/Load*L*F_s)*(V_out-V_in)/(V_out*V_in**2)))

Delta1=(2*(V_out/Load)*L*F_s)/(V_in*D)

Delta2=1-D-Delta1

S=1000 # Sampling resoltion
N=2 #Number of signals
Ts=1/F_s #s
X= np.arange(0,N*Ts,N*Ts/S)

V_L=[]
V_intermediate1=[]
V_intermediate2=[]
V_intermediate3=[]

for i in range(N):
    V_intermediate1=np.array(np.ones(len(np.arange(0,D*Ts,N*Ts/S)))* V_in)
    V_L.extend(V_intermediate1)
    V_intermediate2=np.array(np.ones(len(np.arange(Ts/S,(Delta1)*Ts,N*Ts/S)))*(V_in-V_out))
    V_L.extend(V_intermediate2)
    V_intermediate3=np.array(np.ones(len(np.arange(Ts/S,(1-D-Delta1)*Ts,N*Ts/S)))*0)
    V_L.extend(V_intermediate3)

del V_L[-N:] # Ugly fix for having an array of 1002 instead of 1000

plt.subplot(2, 1, 1)
plt.plot(1e6*X, V_L)
plt.xlim([0,N*1e6*Ts])
plt.ylim([V_in-V_out-5,V_in+5])
plt.xlabel('Time [$\mu s$]')
plt.ylabel('$V_L$ [$V$]')
plt.show()