% @Author: Hitesh Dialani
% @Date: 09-09-2022
clc; clear; close all;
%% General Parameters
V_DC=45; % 
R_Load=400; 
C_out=25e-3;
V_f=1.5; 

%% MOSFET 
V_MOSFET_out=150;
L_MOSFET=750e-6;
D_MOSFET=(V_MOSFET_out+V_f-V_DC)/(V_MOSFET_out+V_f)*100; % Calculated duty cycle
t_sw_MOSFET=1/(80e3);
R_DC_MOSFET=0.3;

%% IGBT
V_IGBT_out=300; 
L_IGBT=1e-3;
D_IGBT=(V_IGBT_out+V_f-V_DC)/(V_IGBT_out+V_f)*100; % Calculated duty cycle
t_sw_IGBT=1/(15e3);
R_DC_IGBT=0.1;

%% Closed loop
Kp_MOSFET=0.6;
Ki_MOSFET=4.5;
 
Kp_IGBT=0.8;
Ki_IGBT=5;