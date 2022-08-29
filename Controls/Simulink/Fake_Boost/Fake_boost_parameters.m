clc; clear; close all;

V_DC=45;

V_MOSFET_out=150;
V_f=1.5;

D_MOSFET=(V_MOSFET_out+V_f-V_DC)/(V_MOSFET_out+V_f)*100;

% % Works with continous powergui
 Kp=0.6;
 Ki=4.5;

V_IGBT_out=300; 
D_IGBT=(V_IGBT_out+V_f-V_DC)/(V_IGBT_out+V_f)*100;


Kp1=0.6;
Ki1=4;