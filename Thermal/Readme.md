# Readme
This will explain what gets hot, how to calculate the temperature rise, simulate it using LTspice, measure and compare finally compare theory and practic.

## What gets hot
![](Images/Boost_converter_schematics.jpg)

Looking at the model either the inductor(L),transistor(S),capacitor(C), diode(D) or load can get hot. 

## How to calculate the temperature rise

### Resistive load

### Transistor

 For the transistors and diode they follow the same top level approach. Since these are used in "high power" application a heatsink is needed, else they will fry. shows a cross section of chip on heatsink and below that you can see the how the heat transferes. 
 ![](Images/3D_Model_Thermal_transfer_IC.jpg)
 source:https://www.electronics-cooling.com/2017/07/advanced-cooling-power-electronics/

A nice overview of each component and how they effect the temperature of the IC.<br />
 ![](Images/IC_with_heatsink_thermal.gif)
 source:https://www.ipes.ethz.ch/mod/lesson/view.php?id=16
 
### Diode

### Inductor

### Capacitor

## Is cooling needed?

If components get too hot they can explode, so to make sure this doesn't happen cooling is needed. So the following are the commenly used cooling options: Air, forced air cooling, heatsink, heatsink and forced air and water cooling. Each of them have their own pros and cons.

Method                 | Cost                                                               | Cooling effect  |Space               | Effort | Risk
---                    | ---                                                                | ---             | ---                | ---    | ---
Air                    | Free                                                               |                 |Takes no extra space|        |        
Forced air             | Needs fans,powersupply for fan and optional PWM controller for fan |                 |      |        |
Heatsink               | Needs a big piece of metal with fins                               |  
Heatsink and forced air| Needs both the above mentioned things                              |
Water cooling          | Needs water, tubes, pump with powersupply and controller to move water and reservoir to store water|  

## Simulated temperatures

### Simulated vs practical 

