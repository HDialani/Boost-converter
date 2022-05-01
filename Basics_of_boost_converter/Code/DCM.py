### Discontinous Conduction Mode
import math

import numpy as np
import matplotlib.pyplot as plt

from main import F_s
from main import V_out
from main import V_in
from main import Load
from main import Delta_I_Ratio

def DCMPlots():
    I_out = V_out / Load  # A
    I_in = V_out * I_out / V_in  # A
    L=float(1e-03) #H
    D=math.sqrt(2*I_out*L*F_s/(V_in*V_in)* (V_out-V_in))
    T_delta1=2*I_out*L*F_s/(V_in*D)
    T_delta2=1-D-T_delta1