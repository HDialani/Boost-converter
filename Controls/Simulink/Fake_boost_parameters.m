clc; clear; close all;

V_DC=45;

% D=(1-V_DC/V_desire)*100; 
V_MOSFET_out=150;
V_f=1.5;

D_MOSFET=(V_MOSFET_out+V_f-V_DC)/(V_MOSFET_out+V_f)*100;

% Works with discontinous powergui
% Kp=1;
% Ki=2;

% Works with continous powergui
Kp=0.5;
Ki=0.9;

V_IGBT_out=300;
% D_IGBT=(1-V_DC/V_IGBT_out)*100; 
D_IGBT=(V_IGBT_out+V_f-V_DC)/(V_IGBT_out+V_f)*100;

Kp1=0.5;
Ki1=0.9;