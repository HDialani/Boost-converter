### Continous Conduction Mode
import numpy as np
import matplotlib.pyplot as plt

from main import F_s
from main import V_out
from main import V_in
from main import Load
from main import Delta_I_Ratio

def CCMPlots():
    D = 1 - V_in / V_out
    I_out = V_out / Load  # A
    I_in = V_out * I_out / V_in  # A
    I_ripple = Delta_I_Ratio * I_in  # A
    Vd = 0.6  # V

    S = 1000  # Sampling resolution
    N = 4  # Number of signals, needs to be an even number
    Ts = 1 / F_s  # s
    X = np.arange(0, N * Ts, N * Ts / S)

    V_sw = []
    for i in range(N):
        Intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * 0)
        V_sw.extend(Intermediate1)
        Intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (1 - D) * Ts, N * Ts / S))) * (V_out + Vd))
        V_sw.extend(Intermediate2)

    I_sw = []
    for i in range(N):
        I_intermediate1 = np.array(I_in - I_ripple + (np.arange(0, D * Ts, N * Ts / S)) * 2 * I_ripple / (D * Ts))
        I_sw.extend(I_intermediate1)
        I_intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (1 - D) * Ts, N * Ts / S))) * 0)
        I_sw.extend(I_intermediate2)

    V_d = []
    for i in range(N):
        Intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * -V_out)
        V_d.extend(Intermediate1)
        Intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (1 - D) * Ts, N * Ts / S))) * (Vd))
        V_d.extend(Intermediate2)

    I_d = []
    for i in range(N):
        I_intermediate1 = np.array(np.arange(0, D * Ts, N * Ts / S) * 0)
        I_d.extend(I_intermediate1)
        I_intermediate2 = np.array(
            I_in + I_ripple - (np.arange(Ts / S, (1 - D) * Ts, N * Ts / S)) * 2 * I_ripple / ((1 - D) * Ts))
        I_d.extend(I_intermediate2)

    V_l = []
    for i in range(N):
        Intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * V_in)
        V_l.extend(Intermediate1)
        Intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (1 - D) * Ts, N * Ts / S))) * (V_in - V_out))
        V_l.extend(Intermediate2)

    I_l = np.add(I_d, I_sw)

    V_c = []
    for i in range(N):
        Intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * V_out)
        V_c.extend(Intermediate1)
        Intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (1 - D) * Ts, N * Ts / S))) * V_out)
        V_c.extend(Intermediate2)

    I_c = []
    for i in range(N):
        I_intermediate1 = np.array(-I_out - np.arange(0, D * Ts, N * Ts / S))
        I_c.extend(I_intermediate1)
        I_intermediate2 = np.array(
            -I_out + I_in + I_ripple - (np.arange(Ts / S, (1 - D) * Ts, N * Ts / S)) * 2 * I_ripple / ((1 - D) * Ts))
        I_c.extend(I_intermediate2)

    plt.figure(1)
    plt.subplot(211)
    plt.plot(1e6 * X, V_sw)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-5, V_out + 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_{sw}$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_sw)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-0.1, (I_in + I_ripple) + 0.1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{sw}$ [$A$]')
    plt.suptitle('Transistor')

    plt.figure(2)
    plt.subplot(211)
    plt.plot(1e6 * X, V_d)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-V_out + -5, 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_{d}$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_d)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-0.1, (I_in + I_ripple) + 0.1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{d}$ [$A$]')
    plt.suptitle('Diode')

    plt.figure(3)
    plt.subplot(211)
    plt.plot(1e6 * X, V_l)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([V_in - V_out - 5, V_in + 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_L$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_l)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-0.1, (I_in + I_ripple) + 0.1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{L}$ [$A$]')
    plt.suptitle('Inductor')

    plt.figure(4)
    plt.subplot(211)
    plt.plot(1e6 * X, V_c)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([0, V_out + 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_c$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_c)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-I_out - 0.1, (I_in + I_ripple - I_out) + 0.1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{c}$ [$A$]')
    plt.suptitle('Capacitor')
    plt.show()