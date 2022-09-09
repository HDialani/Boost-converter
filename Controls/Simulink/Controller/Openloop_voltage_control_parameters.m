% @Author: Hitesh Dialani
% @Date: 09-09-2022
clc; clear; close all;

%% Fixed parameters
V_in=45;
V_diode_forward_drop=1.5;

%% User input
V_MOSFET_out=150;
V_IGBT_out=300;

f_sw_MOSFET=80e3;
f_sw_IGBT=15e3;

V_MOSFET_overvolt_safety_factor=2;
V_IGBT_overvolt_safety_factor=2;

%% Calculated values 
V_MOSFET_overvolt_protection=V_MOSFET_overvolt_safety_factor*V_MOSFET_out;
V_IGBT_overvolt_protection=V_IGBT_overvolt_safety_factor*V_IGBT_out;

D_MOSFET_CCM=(V_MOSFET_out+V_diode_forward_drop-V_in)/(V_MOSFET_out+V_diode_forward_drop);
D_IGBT_CCM=(V_IGBT_out+V_diode_forward_drop-V_in)/(V_IGBT_out+V_diode_forward_drop);

%% Timer stuff
Timer_period_MOSFET=round(60e6/f_sw_MOSFET);
Timer_period_IGBT=round(60e6/f_sw_IGBT);

%% PI controllers

Kp_IGBT=0;
Ki_IGBT=0;

Kp_MOSFET=0;
Ki_MOSFET=0;