"""
@Author: Hitesh Dialani
@Date: 03-09-2022
"""

import numpy as np
import matplotlib.pyplot as plt


def CCM_V_out_duty_cycle(Load,V_in):
    D_length = 1000
    D = np.linspace(0, 0.99, D_length)

    Rc = 0
    Ron = 0
    Rl = 0

    V_out_ideal = (V_in * Load * (1 - D)) / (D * (1 - D) * Load * Rc / (Load + Rc) + Ron + Rl + Load * (1 - D) ** 2)

    Rc = 30 / 1000
    Ron = 0.01
    Rl = 300 / 1000
    V_out_parasitics = (V_in * Load * (1 - D)) / (D * (1 - D) * Load * Rc / (Load + Rc) + Ron + Rl + Load * (1 - D) ** 2)
    fig = plt.figure()
    plt.plot(D, V_out_ideal, color='r', label='Ideal')
    plt.plot(D, V_out_parasitics, color='b', label='Parasitics')
    plt.xlabel("Duty cycle (D)")
    plt.ylabel("Output voltage in $V$")
    plt.title('Boost converter in CCM')
    plt.xlim([0, 1])
    plt.ylim([0, 1000])
    plt.legend()
    return fig

def operation_mode(L,F_sw,Load):
   D_length = 100
   D_0_to_1 = np.linspace(0, 1, D_length)
   K_crit = D_0_to_1 * (1 - D_0_to_1) ** 2

   K = 2 * L * F_sw / Load
   K = K * np.ones(D_length)
   fig = plt.figure()
   plt.plot(D_0_to_1, K_crit, color='r', label='K_crit', )
   plt.plot(D_0_to_1, K, color='g', label='K')
   plt.xlabel("Duty cycle")
   plt.legend()
   plt.title('If K>K_crit you are in CCM and if K<K_crit you are in DCM ')
   return fig

def Duty_cycle_all_operation(V_in,V_out):
    Duty_cycle_CCM = (V_out - V_in) / V_out
    D_length = 1000
    D = np.linspace(0, 1, D_length)

    I_Out_Boundry = 27/4*D*(1 - D)**2

    I_Out_Boundry_maximum = np.max(I_Out_Boundry)
    I_out = I_Out_Boundry_maximum * np.linspace(0, 1, 1000)
    Duty_cycle_DCM = np.sqrt(4 / 27 * (V_out / V_in) * (V_out / V_in - 1) * I_out / I_Out_Boundry_maximum)

    index_of_operation = np.where((Duty_cycle_DCM >= Duty_cycle_CCM))

    Duty_cycle = Duty_cycle_DCM[0:index_of_operation[0][0]]
    Duty_cycle_CCM = Duty_cycle_CCM * np.ones(len(D) - index_of_operation[0][0])
    Duty_cycle = np.append(Duty_cycle, Duty_cycle_CCM)

    fig = plt.figure()
    plt.plot(I_Out_Boundry, D, color='r', label='I_out boundry current')
    plt.plot(I_out / I_Out_Boundry_maximum, Duty_cycle, color='m', label='$V_{in}/V_{out}=0.3$')
    plt.fill_between(I_Out_Boundry, D, color='C0', alpha=0.3)
    plt.xlabel("$I_{out}/I_{\mathrm{out}_{-} \mathrm{Boundry}_{-} \mathrm{max}}$")
    plt.ylabel("Duty cycle")
    plt.title('$V_{out}$ is constant')
    plt.legend()
    return fig