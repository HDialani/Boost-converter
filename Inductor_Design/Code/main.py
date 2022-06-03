# Author: Hitesh Dialani
# Last modified: 27-04-22

import math as math
import scipy.constants


import ETD54
import ETD44
import Boost_parameters

def let_user_pick(options):
    for idx, element in enumerate(options):
        print("{}) {}".format(idx + 1, element))

    i = input("Choose number: ")
    try:
        if 0 < int(i) <= len(options):
            return int(i) - 1
    except:
        pass
    return None

Core_size = ["ETD44", "ETD54"]
print("Core shape option")
res = let_user_pick(Core_size)
print("Choice",Core_size[res])


if res==0:
    A_c = ETD44.A_c_middle_leg
    V_e= ETD44.V_e
else:
    A_c = ETD54.A_c_middle_leg
    V_e = ETD54.V_e

B_max=float(input("Enter max saturation point in mTesla "))

L=Boost_parameters.Mosfet_CCM_Inductance
I_peak=Boost_parameters.Mosfet_CCM_I_peak


N=(L*I_peak)/((B_max/1000)*A_c)

print("Number of turns is ", math.ceil(N))

l_air=(N**2 *A_c* scipy.constants.mu_0 /(2*L))*(10**3)

print("Airgap length ", l_air)