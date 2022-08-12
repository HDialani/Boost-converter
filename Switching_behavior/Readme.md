# Read me

The micro-controller will sent PWM signal with the desired duty cycle to the gate drivers, which will then send the  desired square waves to the chosen transistor.

<img src="Images/Switching_toplevel.jpg" width=600 >

The micro-controller will send a PWM signal from 0V-3V3 or 0V-5V depending on which micro-controller is used. As will be explained a bit later this  is not the desired signal for power transistors it is fine for normal low power transistors though. So for power transistors a gate driver circuit is needed. This signal will boost and PWM logic signal to the desired square waves.

# Why is the gate driver needed?


## Parasitic capacitor
In an ideal world transistors would turn on instantly. However in the real world it takes some time till the a transistor is switched from "OFF" to "ON". This is because there a parasitic capacitance between the gate and source of the MOSFET.(This explanation uses MOSFET, but the same can be said about IGBT). This parasitic capacitance causes the transistor to turn on very slowely. Normally these switches take a few $ns$-$us$ so a little delay isn't that bad, however to big problem comes from what happens in between of going from turning "OFF" to "ON". Here "ON" means $V_{DS}$=$0V$. For those that don't know MOSFET's have 3 operating regions: cut-off region, resistive/linear region and saturation region. Read this if you want to understand more [read this](http://electricalarticle.com/power-mosfet-construction-operation-iv-characteristic/) or [watch this](https://www.youtube.com/watch?v=o3M2sOCGCKs). Ps a very common confusion is between saturation and linear region. For the BJT both regions name are swapped 🙃 look at this [fun thread](https://electronics.stackexchange.com/questions/498561/in-which-region-should-a-mosfet-be-operated-as-a-switch). 

So now that you know all the 3 regions are you can understant what the problem is when the with a switch turning "ON" very slowely. The switch will be in the saturation region for a long time. During the saturation region current will flow througt the MOSFET while there is still a voltage difference between drain and source, so there wil be a lot of power lost over the transistor. The animation below shows this effect the MOSFET is first in cut-off then due to the parasitic capacitor it stays in saturation for a while then it finally enters linear region. A problem with micro-controllers are that they can't give a lot of charge. The usuall give between $4-20mA$. So this will cause the capacitor to take forever to charge. For a power MOSFET it will take ages since it's parasitic cap is extremely large. So the gate driver steps in and deliver a large amount of current compare to the micro-controller thus charging the parasitic capacitor faster. Besides the charging of this capacitor the gatedriver also discharges this capacitor. Power MOSFET's have large parasitic caps, so even if you remove positive voltage the gate voltage can stay the same voltage for a while. So to quickly discharge this capacitor the gate driver supplies negative voltage to turn the transistor "OFF".  

<img src="Images/Power_Loss_Resistive_Regen.gif " width=500 >
<br>
<img src="Images/Negative_gate_voltage.gif " width=500 >
<br>
http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgpABZsKBTAWjDACgAncMFEFGqmAyE+AqMjYAlbr36CefPHnFUxTJFU3QEbAMqiqKfuGF9jmkADMAhgBsAzg3EpOi5T2Uol4QhcqQ2AHcQbGwRTFlvCKgpGT58OI8VWioNFW1XVlkEoXCEwQCAYwMzGhLorUgIJhgyPBoEBoRCNEbIbGUAy3LjL09jbFkoWBdgvvKojF4AsbFo8Yq2AHM3PinV3DLNINW0T28wXxjpcaTx4hELMTStHTGohNC8zrY0cjlSksPVEABxawALgwAPoANwA9rYAdYlgw2OCQMpCFsUmRqDB4JAyIRmig0rxlNh4YiQMiQOQBKR0dAIIJhpjhChiNhiA1sDwdAiwEgyaoscoNDTwHxwEgiQikSjKeRBZjsbikENCcTJeTUcRqRBeLTYPBGczWQh2Xi2EA

## Lower conduction losses

## Isolation between HV and LV ground

# Important information from datasheet


# Simple inverter circuit

http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgpABZsKBTAWjDACgAzcFPEH3sBkJ88vbCnDQkMSCjYBzcEJDYEEwcOyFeVSGwBOS4ZnXKUKGlGRw2AJSN8LDsMQm7aVSld1S2AdwcTPnw+DDc2ADcQPCpVCRiRHT5glKZpKF8AhP5uXhy9LNi1cEIi8ICNFWKwUqryh1xLSrioNjRybNFoqgsqSwA1eQBnNshyNDyw4LynAYATEYB7ZBBCSz7IYl4aH3hNoQRCFHT1WJBBpfAINasdre6MvbJCQ+OrdQh6foW2IA

# Boost converter circuit

## MOSFET
 
### IGBT
 
