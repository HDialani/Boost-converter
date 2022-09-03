"""
@Author: Hitesh Dialani
@Date: 03-09-2022
"""

### Discontinous Conduction Mode
import math
import numpy as np
import matplotlib.pyplot as plt

def DCMPlots(V_in,V_out,Load,F_sw,I_ripple_DCM):
    Vd = 0.6  # V
    L=0.1/1000
    D=math.sqrt(((2*V_out**2/Load*L*F_sw)*(V_out-V_in)/(V_out*V_in**2)))
    Delta1=(2*(V_out/Load)*L*F_sw)/(V_in*D)
    Delta2=1-D-Delta1
    I_out = 1

    S=1000 # Sampling resoltion
    N=2 #Number of signals
    Ts=1/F_sw #s
    X= np.arange(0,N*Ts,N*Ts/S)

    V_sw=[]
    V_intermediate1=[]
    V_intermediate2=[]
    V_intermediate3=[]


    I_sw=[]
    I_intermediate1=[]
    I_intermediate2=[]
    I_intermediate3=[]

    for i in range(N):
        V_intermediate1=np.array(np.ones(len(np.arange(0,D*Ts,N*Ts/S)))* 0)
        V_sw.extend(V_intermediate1)
        V_intermediate2=np.array(np.ones(len(np.arange(Ts/S,(Delta1)*Ts,N*Ts/S)))*(V_out))
        V_sw.extend(V_intermediate2)
        V_intermediate3=np.array(np.ones(len(np.arange(Ts/S,(Delta2)*Ts,N*Ts/S)))*(V_in))
        V_sw.extend(V_intermediate3)

    for i in range(N):
        I_intermediate1=np.array(0+(np.arange(0,D*Ts,N*Ts/S))* 2*I_ripple_DCM/(D*Ts))
        I_sw.extend(I_intermediate1)
        I_intermediate2=np.array(np.ones(len(np.arange(Ts/S,(Delta1)*Ts,N*Ts/S)))*0)
        I_sw.extend(I_intermediate2)
        I_intermediate3=np.array(np.ones(len(np.arange(Ts/S,(Delta2)*Ts,N*Ts/S)))*0)
        I_sw.extend(I_intermediate3)

    del V_sw[-N:]# Ugly fix to make this a 1002 array instead of 1000 array
    del I_sw[-N:]# Ugly fix to make this a 1002 array instead of 1000 array

    V_d = []
    for i in range(N):
        V_intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * -V_out)
        V_d.extend(V_intermediate1)
        V_intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (Delta1) * Ts, N * Ts / S))) * (Vd))
        V_d.extend(V_intermediate2)
        V_intermediate3 = np.array(np.ones(len(np.arange(Ts / S, (Delta2) * Ts, N * Ts / S))) * (-V_in))
        V_d.extend(V_intermediate3)

    I_d = []
    for i in range(N):
        I_intermediate1 = np.array(np.arange(0, D * Ts, N * Ts / S) * 0)
        I_d.extend(I_intermediate1)
        I_intermediate2 = np.array(2 * I_ripple_DCM - (np.arange(Ts / S, (Delta1) * Ts, N * Ts / S)) * 2 * I_ripple_DCM / (
                    (1 - D - Delta1 + 0.04) * Ts))
        I_d.extend(I_intermediate2)
        I_intermediate3 = np.array((np.arange(Ts / S, (Delta2) * Ts, N * Ts / S)) * 0)
        I_d.extend(I_intermediate3)

    del V_d[-N:]
    del I_d[-N:]

    V_L = []
    for i in range(N):
        V_intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * V_in)
        V_L.extend(V_intermediate1)
        V_intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (Delta1) * Ts, N * Ts / S))) * (V_in - V_out))
        V_L.extend(V_intermediate2)
        V_intermediate3 = np.array(np.ones(len(np.arange(Ts / S, (Delta2) * Ts, N * Ts / S))) * 0)
        V_L.extend(V_intermediate3)
    del V_L[-N:]

    I_l = np.add(I_d, I_sw)

    V_c = []
    for i in range(N):
        V_intermediate1 = np.array(np.ones(len(np.arange(0, D * Ts, N * Ts / S))) * V_out)
        V_c.extend(V_intermediate1)
        V_intermediate2 = np.array(np.ones(len(np.arange(Ts / S, (Delta1) * Ts, N * Ts / S))) * (V_out))
        V_c.extend(V_intermediate2)
        V_intermediate3 = np.array(np.ones(len(np.arange(Ts / S, (Delta2) * Ts, N * Ts / S))) * (V_out))
        V_c.extend(V_intermediate3)

    I_c = []
    for i in range(N):
        I_intermediate1 = np.array(np.arange(0, D * Ts, N * Ts / S) * 0 - I_out)
        I_c.extend(I_intermediate1)
        I_intermediate2 = np.array(2 * I_ripple_DCM - (np.arange(Ts / S, (Delta1) * Ts, N * Ts / S)) * 2 * I_ripple_DCM / (
                    (1 - D - Delta1 + 0.04) * Ts) - I_out)
        I_c.extend(I_intermediate2)
        I_intermediate3 = np.array((np.arange(Ts / S, (Delta2) * Ts, N * Ts / S)) * 0 - I_out)
        I_c.extend(I_intermediate3)

    del I_c[-N:]
    del V_c[-N:]

    fig = plt.figure()
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
    plt.ylim([-0.1, (2*I_ripple_DCM) ])
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
    plt.ylim([-2, (2 * I_ripple_DCM) + 1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{d}$ [$A$]')
    plt.suptitle('Diode')

    plt.figure(3)
    plt.subplot(211)
    plt.plot(1e6 * X, V_L)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([V_in - V_out - 5, V_in + 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_L$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_l)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-0.1, (2 * I_ripple_DCM) + 0.1])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{L}$ [$A$]')
    plt.suptitle('Inductor')

    plt.figure(4)
    plt.subplot(211)
    plt.plot(1e6 * X, V_c)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([V_out - 5, V_out + 5])
    # plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$V_c$ [$V$]')

    plt.subplot(212)
    plt.plot(1e6 * X, I_c)
    plt.xlim([0, N * 1e6 * Ts])
    plt.ylim([-I_out - 0.5, (2 * I_ripple_DCM)])
    plt.xlabel('Time [$\mu s$]')
    plt.ylabel('$I_{c}$ [$A$]')
    plt.suptitle('Capacitor')
    plt.show()
    return fig