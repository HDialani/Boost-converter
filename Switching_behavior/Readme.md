# Read me

The micro-controller will sent PWM signal with the desired duty cycle to the gate drivers, which will then send the  desired square waves to the chosen transistor.

<img src="Images/Switching_toplevel.jpg" width=600 >

The micro-controller will send a PWM signal from 0V-3V3 or 0V-5V depending on which micro-controller is used. As will be explained a bit later this  is not the desired signal for power transistors it is fine for normal low power transistors though. So for power transistors a gate driver circuit is needed. This signal will boost and PWM logic signal to the desired square waves.

# Why is the gate driver needed?


## Parasitic capacitor

<img src="Images/Power_Loss_Resistive_Regen.gif " width=500 >
<br>
<img src="Images/Negative_gate_voltage.gif " width=500 >
<br>
http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgpABZsKBTAWjDACgAncMFEFGqmAyE+AqMjYAlbr36CefPHnFUxTJFU3QEbAMqiqKfuGF9jmkADMAhgBsAzg3EpOi5T2Uol4QhcqQ2AHcQbGwRTFlvCKgpGT58OI8VWioNFW1XVlkEoXCEwQCAYwMzGhLorUgIJhgyPBoEBoRCNEbIbGUAy3LjL09jbFkoWBdgvvKojF4AsbFo8Yq2AHM3PinV3DLNINW0T28wXxjpcaTx4hELMTStHTGohNC8zrY0cjlSksPVEABxawALgwAPoANwA9rYAdYlgw2OCQMpCFsUmRqDB4JAyIRmig0rxlNh4YiQMiQOQBKR0dAIIJhpjhChiNhiA1sDwdAiwEgyaoscoNDTwHxwEgiQikSjKeRBZjsbikENCcTJeTUcRqRBeLTYPBGczWQh2Xi2EA

## Isolation between HV and LV ground

# Important information from datasheet


# Simple inverter circuit

http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWcMBMcUHYMGZIA4UA2ATmIxAUgpABZsKBTAWjDACgAzcFPEH3sBkJ88vbCnDQkMSCjYBzcEJDYEEwcOyFeVSGwBOS4ZnXKUKGlGRw2AJSN8LDsMQm7aVSld1S2AdwcTPnw+DDc2ADcQPCpVCRiRHT5glKZpKF8AhP5uXhy9LNi1cEIi8ICNFWKwUqryh1xLSrioNjRybNFoqgsqSwA1eQBnNshyNDyw4LynAYATEYB7ZBBCSz7IYl4aH3hNoQRCFHT1WJBBpfAINasdre6MvbJCQ+OrdQh6foW2IA

# Boost converter circuit

## MOSFET
 
### IGBT
 
