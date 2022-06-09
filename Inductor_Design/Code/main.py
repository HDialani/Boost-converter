# Author: Hitesh Dialani
# Last modified: 04-06-22

import math as math
import scipy.constants
import numpy as np

import Core_material
import Core_shape
import Boost_parameters
import Functions

# f = open("Wire_choice_table.txt","r") # Open file for reading
# my_file_data = f.read()
# f.close()
# print(my_file_data)

kw=0.4                    # Window area utilization
Jrms=5                    #A/mm^2   Current density in wire
B_max_factor=0.64

print("")
B_max=B_max_factor*Core_material.Bsat_3C90

Transistor = ["IGBT CCM","MOSFET CCM"]
print("Enter number")
mode = Functions.let_user_pick(Transistor)
print("Choice",Transistor[mode],"\n")

if mode==0:
    L = Boost_parameters.IGBT_CCM_Inductance
    I_peak = Boost_parameters.IGBT_CCM_I_peak
    I_RMS = Boost_parameters.IGBT_CCM_I_RMS
    Ap = L * I_peak * I_RMS / (kw * Jrms * B_max * 10 ** -3)
else:
    L = Boost_parameters.Mosfet_CCM_Inductance
    I_peak = Boost_parameters.Mosfet_CCM_I_peak
    I_RMS = Boost_parameters.Mosfet_CCM_I_RMS
    Ap = L * I_peak * I_RMS / (kw * Jrms * B_max * 10 ** -3)

print("Window area is ", Ap, "mm^4\n")
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

A_wire=I_RMS/Jrms
print("Minimum wire diameter ", math.sqrt(A_wire/math.pi),"mm")


l_air=(N**2 *A_c* scipy.constants.mu_0 /(2*L))*(10**3)
print("Airgap length ", l_air,"mm")

B_peak=L*I_peak/(N*A_c)
print("Peak flux density", B_peak,"Tesla")

print("Do you want to modify chosen parameters?")
change=input("Y/N\t")
print(change)

# [N, l_air, B_max]=Functions.user_modify_parameter(change)    #Need to fix this function still

if change == "Y" :
  print("Do you want to change number of turns(n) or airgap?(a)")
  change_par = input("n/a\t")
  print(change_par)
  if change_par=="a":
     l_air=float(input("Enter new airgap length in mm "))
     N=np.ceil(math.sqrt(2*L*l_air*(10**-3)/(scipy.constants.mu_0*A_c)))
     B_max=L*I_peak/(N*A_c)
     print("You need ", Core_size[res], "core with", N, "number of turns and an airgap of ", l_air, "mm peak flux density is ",B_max,"Tesla")
  elif change_par=="n":
     N = float(input("Enter new number of turns "))
     l_air=N**2 *scipy.constants.mu_0*A_c/(2*L)*(10**3)
     B_max = L * I_peak / (N * A_c)
     print("You need ", Core_size[res], "core with", N, "number of turns and an airgap of ", l_air, "mm peak flux density is ",B_max,"Tesla")
  else:
     print("No change")
else:
    print("You need ", Core_size[res], "core with", N, "number of turns and an airgap of ", l_air, "mm peak flux density is ",B_max,"Tesla")



