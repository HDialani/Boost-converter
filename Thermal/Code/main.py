import numpy as np
import matplotlib.pyplot as plt
MOSFET_CCM=[[22.7,22.8,23.1,23.3,23.5,23.8,24.0,24.2,24.4,24.6,24.7,24.9,25.1,25.3,25.4,25.6,25.7,25.9,26.1,26.2,26.3,26.2,26.2,26.1,26.0,25.9,25.8,25.7,25.6,25.4,25.3,25.3,25.3,25.2,25.1,25.1,25.0,25.0,25.0,24.9,24.9],
            [21.7,22.7,22.8,22.9,23.0,23.2,23.3,23.5,23.7,23.9,24.0,24.2,24.4,24.6,24.8,25.0,25.0,25.2,25.4,25.4,25.6,24.9,24.8,24.8,24.8,24.8,24.6,24.6,24.4,24.3,24.2,24.2,24.2,24.0,24.0,24.0,23.9,23.9,23.9,23.9,23.9]]

x=len(MOSFET_CCM[0])
Sampling_time=np.linspace(0, 20, x)

plt.figure(1)
plt.plot(Sampling_time,MOSFET_CCM[0], label='Temperature of MOSFET heatsink')
plt.plot(Sampling_time,MOSFET_CCM[1], label='Temperature of Inductor')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperatures for CCM mode MOSFET components')
plt.legend()


IGBT_CCM=[[21.7,23.2,28.3,34.2,39.6,44.6,48.9,52.7,56.6,58.9,61.4,62.9,64.3,65.6,66.4,69.3,71.2,72.5,73.5,74.0,74.5,74.6,74.8,75.1,75.2,75.7,77.0,77.2,77.5,77.9,78.0,76.5,69.8,64.1,60.2,55.7,51.2,47.9,44.8,43.1,40.6,39.1,36.8,35.2,34.1,33.1],
          [21.6,25.0,25.9,25.9,27.8,28.8,29.9,31.0,31.9,32.6,33.5,34.4,35.2,36.5,37.4,38.2,38.6,39.8,40.1,41.1,41.9,42.5,42.5,43.1,43.3,43.7,43.8,45.0,45.0,45.3,45.5,42.5,42.4,41.2,40.4,39.5,39.1,38.5,37.6,37.0,36.3,35.7,35.0,34.3,33.5,33.1]]

x=len(IGBT_CCM[0])
Sampling_time=np.linspace(0, 45, x)

plt.figure(2)
plt.plot(Sampling_time,IGBT_CCM[0], label='Temperature of IGBT heatsink')
plt.plot(Sampling_time,IGBT_CCM[1], label='Temperature of Inductor')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperatures for CCM mode IGBT components')
plt.legend()
plt.show()