import numpy as np
import matplotlib.pyplot as plt
MOSFET_CCM=[[22.7,22.8,23.1,23.3,23.5,23.8,24.0,24.2,24.4,24.6,24.7,24.9,25.1,25.3,25.4,25.6,25.7,25.9,26.1,26.2,26.3,26.2,26.2,26.1,26.0,25.9,25.8,25.7,25.6,25.4,25.3,25.3,25.3,25.2,25.1,25.1,25.0,25.0,25.0,24.9,24.9],
            [21.7,22.7,22.8,22.9,23.0,23.2,23.3,23.5,23.7,23.9,24.0,24.2,24.4,24.6,24.8,25.0,25.0,25.2,25.4,25.4,25.6,24.9,24.8,24.8,24.8,24.8,24.6,24.6,24.4,24.3,24.2,24.2,24.2,24.0,24.0,24.0,23.9,23.9,23.9,23.9,23.9]]

x=len(MOSFET_CCM[0])
Sampling_time=np.linspace(0, 20, x)


plt.plot(Sampling_time,MOSFET_CCM[0], label='Temperature of MOSFET')
plt.plot(Sampling_time,MOSFET_CCM[1], label='Temperature of Inductor')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperatures for CCM mode MOSFET components')
plt.legend()
plt.show()