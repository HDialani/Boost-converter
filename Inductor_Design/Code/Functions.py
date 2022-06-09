import math as math
import scipy.constants
import numpy as np

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

from main import L
from main import A_c
from main import I_peak


# def user_modify_parameter(change):
#     if change == "Y":
#         print("Do you want to change number of turns(n) or airgap?(a)")
#         change_par = input("n/a\t")
#         print(change_par)
#         if change_par == "a":
#             l_air = float(input("Enter new airgap length in mm "))
#             N = np.ceil(math.sqrt(2 * L * l_air * (10 ** -3) / (scipy.constants.mu_0 * A_c)))
#             B_max = L * I_peak / (N * A_c)
#             return N, l_air, B_max
#         elif change_par == "n":
#             N = float(input("Enter new number of turns "))
#             l_air = N ** 2 * scipy.constants.mu_0 * A_c / (2 * L) * (10 ** 3)
#             B_max = L * I_peak / (N * A_c)
#             return N, l_air, B_max
#         else:
#             print("No change")
#             return None
#     else:
#         print("No change")
#     return None