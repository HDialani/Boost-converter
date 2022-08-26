"""
@Author: Hitesh Dialani
@Date: 25-08-2022
"""

import numpy as np
import matplotlib.pyplot as plt
from Data import MOSFET_CCM,IGBT_CCM,IGBT_CCM_Resistor_orientation

def data_length(array,int):
    x = len(array)
    data_length = np.linspace(0, int, x)
    return data_length


Sampling_time=data_length(MOSFET_CCM[0],20)
plt.figure(1)
plt.plot(Sampling_time,MOSFET_CCM[0], label='Temperature of MOSFET heatsink')
plt.plot(Sampling_time,MOSFET_CCM[1], label='Temperature of Inductor')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperatures for CCM mode MOSFET components')
plt.legend()


Sampling_time=data_length(IGBT_CCM[0],45)
plt.figure(2)
plt.plot(Sampling_time,IGBT_CCM[0], label='Temperature of IGBT heatsink')
plt.plot(Sampling_time,IGBT_CCM[1], label='Temperature of Inductor')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperatures for CCM mode IGBT components')
plt.legend()


Sampling_time=data_length(IGBT_CCM_Resistor_orientation[0],60)
plt.figure(3)
plt.plot(Sampling_time,IGBT_CCM_Resistor_orientation[0], label='Horizontal passively cooled')
plt.plot(Sampling_time,IGBT_CCM_Resistor_orientation[1], label='Vertical passively cooled')
plt.xlim([0,np.max(Sampling_time)])
plt.xlabel('Time in  minutes')
plt.ylabel('Temperature in $C^o$')
plt.suptitle('Temperature of IGBT Resistor heatsink')
plt.legend()
plt.show()