import numpy as np
import matplotlib.pyplot as plt

V_DC=[0,45,54,96,120,154,204,253,299,344,380]

V_opamp=[0,0.263,0.319,0.566,0.705,0.898,1.191,1.462,1.723,1.961,2.117]

x=np.linspace(0, len(V_DC), len(V_DC))
ADC_Factor=3/4096

a=V_DC[3]/V_opamp[3]

print("a =",a)
C=V_DC[3]/a*ADC_Factor
print("C =",C)

V_measure=C/ADC_Factor*a
print("V_measure =",V_measure)

