# Author: Hitesh Dialani
# Last modified: 04-06-22

import math as math
import scipy.constants

import Core_material
import Core_shape
import Boost_parameters
import Functions

kw=0.4                    # Window area utilization
Jrms=5                    #A/mm^2   Current density in wire
B_max_factor=0.64

print("")
B_max=B_max_factor*Core_material.Bsat_3C90
L=Boost_parameters.Mosfet_CCM_Inductance
I_peak=Boost_parameters.Mosfet_CCM_I_peak
I_RMS=Boost_parameters.Mosfet_CCM_I_RMS

Ap=L*I_peak*I_RMS/(kw*Jrms*B_max*10**-3)
print("Window area is ",Ap,"mm^4\n")

Core_size = ["ETD44,Ap=50541 mm^4","ETD54,Ap=131477 mm^4"]
print("Core shape option")
res = Functions.let_user_pick(Core_size)
print("Choice",Core_size[res],"\n")


if res==0:
    A_c = Core_shape.ETD44_A_c
    V_e= Core_shape.ETD44_V_e
else:
    A_c = Core_shape.ETD54_A_c
    V_e = Core_shape.ETD54_V_e


N=(L*I_peak)/(B_max*A_c)
print("Number of turns is ", math.ceil(N))

l_air=(N**2 *A_c* scipy.constants.mu_0 /(2*L))*(10**3)
print("Airgap length ", l_air,"mm")

B_peak=L*I_peak/(N *A_c)
print("Peak flux density", B_peak,"Tesla")