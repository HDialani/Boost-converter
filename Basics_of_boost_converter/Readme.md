# Readme
This is a simplified explanation of what a boost converter is for people without a bachelor of Electrical Engineering knowledge. What a Boost converter does is it boost up the input voltage while boost down the input current, since power in= power out. It does this by controlling the electronic switch(S). 

## How it works
When the switch is closed a large current _I_ flows through the inductor(L) and switch(S) causing the inductor to start storing magnetic field $ \frac{1}{2}LI^{2}$     . The moment that the switch opens the current flowing through the inductor will decrease since a load is now limiting the current. This change doesn't happen instantaniously due to the fact that the inductor has some "current delay". As the current decreases the stored magnetic field will collapse, this causes the stored magentic field energie to be released. Now that the inductor is releasing energy it can be seen as an additional voltage source in series to the input voltage source. So during the period that the switch is open both the input voltage source and the collaped voltage produced by the inductor goes to the output an the collapsed volatge is larger than the input voltage. These voltages are then stored at the capcaitor(C).  

When the switch is open the voltage at the output is equal to the voltage over the capacitor, when the switch is closed the capacitor slowely discharges since it has a "voltage delay". This causes the voltage at the output to slowely decrease untill the switch is open again. The swithch is opening and closing at super fast rate>100 kHz so the sudden swithcing in output voltage is not noticed and instead the average voltage will be noticed at the output.

Now for the final component the diode (D). The diode can be seen as a wire that allows current to flow in the direction of the arrow. When the switch is open the voltage over the cap is larger than the voltage of the input source, so the capacitor will try to discharge the current towards the input voltage. To stop this the diode make sure that current can't flow back into the input source and instead goes to the output.

As for the output current, only when the switch is open current goes to the output, when the switch is closed it flows back into the battery. So the output current will be less than the input current.

## Schematic and operation of boost converter
![](Images/Boost_converter_schematics.jpg)

### Continous conduction mode (CCM),Boundry condition mode (BCM) and Discontinous conduction mode (DCM)
As mentioned before the current throught the inductor will be rising when the switch is closed and discharging when the switch is open. If the current rises and discharges above _0A_ it is in CCM. If it rises and discharges at _0A_ it is in BCM. Current can't go below _0A_ for the system so instead in the BCM it will first discharge to _0A_ and stays _0A_ untill it starts rising again. 

## Operation mode of boost converter in CCM, BCM
![](Images/Boost_converter.gif)
Websimulation link:
http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWK0BMLIHZNgBxgQGyQFYAsBICkll1CApgLRhgBQAZiOjuAJwpdCfAQGYBYaEhiQUrAErDwpUkpVhlUTaTqbqMBKwDugimAwUUQ9SsisANousnVmiNLC8MKFqTRYMOHAiPLYAJs5OYtROAqH07ACGAK52AC5GIFHOlhZCtsY52ULcUKwA5kW5Fl66rABOIMo8Tk3O0fAZrYVZhfmZ6C6tTrYA8o2kzRqkvKYabqwAblyQPIUlHgLU4vA0UsgGBSuVbazovP3RGj15yPCQELywVHB4ARgiBB+39+CnmI5zfggGaNEAANQAlgA7P4YcaTFStEEqMEAeyS6VR4AENkoYio4D00DcXGxmVYWJYoK2kAmOKJEEZrGCZIAYhA9mA4CBmCAACIYgCeAB0AM4AYUFAGM7PRWEA
### On stage
![](Images/Boost_converter_ON_mode.jpg)
### Off stage
![](Images/Boost_converter_OFF_mode.jpg)

## Operation mode of boost converter in DCM
![](Images/Boost_converter_DCM.gif)
http://www.falstad.com/circuit/circuitjs.html?ctz=CQAgjCAMB0l3BWKsEA4wHYvoCwCZIBOVSVHEBSCiqhAUwFowwAoAMxANXEL04QBsPPgGY+YaEhiQ8LAErDwOcmGVLyVKjlpRdMBCwDu-IZiF5B6qCwA2i1eQum1m2KRA5ohSAMIjIgj4CYKgYAozckCwAJiZWYlQOnCDRdGwAhgCuNgAuRiAJcU5xUcbF5ZZc1gDmRZWVGHyaLABOHjjcScrcxYnw+d1xhb35hV0dVlEA8u2dajiEzirWAG6c7uXuYLy64vDUUsgGZRv15pZRBIQFBPG3vcjwcIQvr2-v1yFeGGB4IqiLTDoRqPSAQVgEDD2NTbPiLDwgABqAEsAHYsSGzKyDeHkREAe0yeXx4D4GgoYko4FcECo4lELBJzARdMgHT4txg4PAjIKLI8RChYFcjmSIgKLH+pJAADEIIdhVQmCAACJEgCeAB0AM4AYXVAGMbHQWEA
### On stage
![](Images/Boost_converter_ON_mode.jpg)
### △1 stage
![](Images/Boost_converter_OFF_mode.jpg)
### Zero stage

<img src="Images/Boost_converter_Zero_mode.jpg" width=1800 >

## Mathamatics for boost converter
All graphs made in this section are made using the code found in [Code](Code)

### CCM
#### Inductor
General equation for inductor $ I_L=\frac{1}{L}\int_{t_2}^{t_1} V_L \,dt$  <br />
When S is closed $V_L=V_{in}$    <br />
When S is open $V_L=V_{in}-V_{out}$   <br />

![](Images/CCM_Inductor_Plots.svg)

#### Transistor
When S is closed $V_{S}=0$  and $I_{S}=I_L$ <br />
When S is open $V_{S}=V_{out}$  and $I_{S}=0$

![](Images/CCM_Transistor_Plots.svg)

#### Diode
When S is closed $V_{D}=V_{out}$ and $I_{D}=0$ <br />
When S is open $V_{D}=V_{forward-drop}$ and $I_{D}=I_L$ <br />

![](Images/CCM_Diode_Plots.svg)

#### Capacitor
When S is closed $V_C=V_{out}$ and $I_C=-I_{out}$ <br />
When S is open $V_C=V_{out}$ and $I_C=I_{D}-I_{out}$ <br />

![](Images/CCM_Capacitor_Plots.svg)

## Generatal equations. 

### CCM-BCM
![](Images/CCM-BCM-Equations.jpg)
### DCM
![](Images/DCM-Equations.jpg)

## When can it enter DCM or CCM/BCM?

There are only 4 paramters that can change the Boost operation mode: inductor value, load resistance, switching frequency and duty cycle. This part show how each of them can effect this.

### Load resistor
Assuming everything else is the same increasing the load resistance can push the Boost converter to enter discontinuous mode. The relationship is that as load resistance increases the output current decreases, which means the average current of the inductor will decrease. The load resistance does not affect the ripple current, however, so if the average input current is less than the ripple current it will go to zero and stay zero till the inductor starts to charge again. The boundary condition is $I_{in}=\frac{\Delta I_L}{2}$ if $I_{in}=\frac{\Delta I_L}{2}>$ then it is CCM, the other way around is DCM.

<p float="left">
  <img src="Images/CCM_DCM_R_Load_CCM_Mode.jpg" width=500 > 
  <img src="Images/CCM_DCM_R_Load_DCM_Mode.jpg" width=500 > 
</p>


### Inductance 
For inductance you are manipulating $\Delta I_L$, while keeping $I_{in}$ the same. 
This is due to the equation $\Delta I_L=\frac{V_{in}}{L}DT_{S}$
Changin $L$ doen't effect $I_{in}$. 
So this time increasing the inductance can result in the boost converter going from CCM to DCM mode and decreasing it can mode the converter from DCM to CCM mode.

$L_{crit}=\frac{ V_{in}^2DR}{2f_{sw}V_{out}^2}$ this video shows the entire derivation if you are interested
https://www.youtube.com/watch?v=YIg7J3YjnbM&list=PLmK1EnKxphinxBub5hL0ZoJXWoqjkGE19&index=33&t=3

If $L>L_{crit}$ you are in CCM mode. <br />
If $L< L_{crit}$ you are in DCM mode.

### Switching frequency


### Duty cycle

<p float="left">
  <img src="Images/CCM_DCM_K_crit_graph.jpg" width=300 > 
  <img src="Images/CCM_DCM_operation_check.svg" width=700 > 
</p>
 

source left:https://ninova.itu.edu.tr/en/courses/institute-of-science-and-technology/132/elk-506e/ekkaynaklar?g45743 <br />
source right me [Code](Code)

Here $K_{crit}=D*(1-D)^2$ and $K=\frac{2Lf_{sw}}{R}$
