from control.matlab import *
import numpy as np
import matplotlib.pyplot as plt

### RLC Step response
R=22
L=11.3*10**-6
C=58*10**-12

s=tf('s')
H=1/(L*C*s**2+R*C*s+1)

T=np.arange(0,5*10**-6,0.01*10**-6)
y,t=step(H,T)
plt.grid()
plt.plot(t*10**6, y)
plt.xlabel('Time [$\mu s$]')
plt.ylabel('[$V$]')
plt.suptitle('Series RLC step response')
plt.show()