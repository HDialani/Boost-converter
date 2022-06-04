import math as math

#ETD44
ETD44_V_e=17800e-9  #m^3  effective volume
ETD44_I_e=103e-3 #m  effective length
ETD44_A_e=173e-6 #m^2 effective area
ETD44_A_min=172e-6  #m^2 minimum area
ETD44_mass=47e-3  # kg mass of core half

ETD44_h_full= 22.3e-3  #m full length single core
ETD44_h_leg= 16.1e-3  #m leg single core

ETD44_w=15.2e-3  #m width core

ETD44_l_round=15.2e-3  #m diameter of middle leg
ETD44_l_min=15.2e-3  #m of full core
ETD44_l_max=32.5e-3  #m of full core

ETD44_A_c=(ETD44_l_round/2)**2*math.pi  #m^2 core area
ETD44_A_w= 2*ETD44_h_leg*((ETD44_l_max-ETD44_l_min)/2) #m^2 window area
ETD44_A_p=ETD44_A_w*ETD44_A_c #m^4

#ETD54

ETD54_V_e=35500e-9  #m^3  effective volume
ETD54_I_e=127e-3 #m  effective length
ETD54_A_e=280e-6 #m^2 effective area
ETD54_A_min=270e-6  #m^2 minimum area
ETD54_mass=90e-3  # kg mass of core half

ETD54_h_full= 27.6e-3  #m full length single core
ETD54_h_leg= 20.2e-3  #m leg single core

ETD54_w=18.9e-3  #m width core

ETD54_l_round=18.9e-3  #m diameter of middle leg
ETD54_l_min=18.e-3  #m of full core
ETD54_l_max=41.2e-3  #m of full core

ETD54_A_c=(ETD54_l_round/2)**2*math.pi #m^2 core area
ETD54_A_w= 2*ETD54_h_leg*((ETD54_l_max-ETD54_l_min)/2) #m^2 window area
ETD54_A_p=ETD54_A_w*ETD54_A_c #m^4