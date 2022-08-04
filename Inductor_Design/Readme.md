# Readme
This folder explains how I made the inductor, then how well it worked compared to the practical model. They main purpose of these experiments are to compare DCM and CCM and also MOSFET and IGBT technology. For DCM and CCM the same input,output,switching frequency and duty cycle. For IGBT vs MOSFET they have different everything except input voltage. The reason is I just went with the value given to me, I tried researching and thinking of my own values but it was wasting time and leading nowhere, so I chose what the uni chose. 

## Inductor theory
An inductor is a passive electronic componen which can store electrical energy in the form of magnetic energy. I am going to assume the reader knows about magnetic circuit model. If not, please read [this](https://automationforum.co/difference-between-the-electric-circuit-and-magnetic-circuit/) or [this](https://dipslab.com/difference-electrical-magnetic-circuit/). The resistor analogy was used to find the inductance of the circuit. For this the flux linkage equation $\lambda=N\phi=L i$ and the flux equation $\frac{Ni}{R_m}$ were combined to get $L=\frac{N^2}{R_m}$, where $N$ is the number of turns and $R_m$ is the reluctance of the material. The general equation for reluctance is $R_m=\frac{l}{\mu_0 \mu_r A}$, which looks similair to the equation for resistance $R_m=\frac{l}{\sigma A}$. Just like with a electrical model where the current going through the circuit is $i=\frac{V}{R_{tot}}$ the magnetic circuit's inductance is $L=\frac{N^2}{R_{tot}}$.

For the simulation Ni remains constant. The inductance equation can be rewritten as $L=\frac{N^2 \mu_0 \mu_r A}{l}$. Looking at the second image where the length keeps changing, if the lenght decreases the inducance increases and this causes more magnet field to circulate around the inductor. Thus if the length of the inductor increases the inductance decreases and thus less magnetic field is stored. Changing the area has the opposite effect as area increases inductance increases and as area decreases the inductance decreases. These simulations were done with on online finite element method (FEM) simulator from https://www.ipes.ethz.ch/mod/lesson/view.php?id=22

<p float="left">
  <img src="Images/Inductor_magnetic_field_different_dimensions.jpg" width=200 /> 
  <img src="Images/Inductor_magnetic_field_different_length.gif" width=200 />
  <img src="Images/Inductor_magnetic_field_different_area.gif" width=200 />
</p>

## Design requirements
* Size, the smaller the better
* Efficiency, the higher the better
* EMI, as low as possible
* Thermal limit, as low as possible
* Cost, as low as possible

## Theoretical design 
The steps taken to design this inductor are from the different articles in the article folder, with some modifications in steps taken. 

### Application
 * This is a boost converter so it is a single winding inductor.
 * I was given the operation mode is CCM, but DCM seems more logical. Sources: https://www.quora.com/What-is-differences-between-CCM-and-DCM-mode-in-buck-boost-converter-How-can-I-choose-the-right-mode and https://www.designnews.com/selecting-your-boost-converter-inductance

### Step 1  Needed input paramters
* Inductace value $L$
* Operaton frequency $f$
* Current peak $i_{peak}$
* Current RMS Inductor $i_{rms}$
* Operation mode CCM/DCM
* Allowable power dissipation $P_{core}$
* Maximum surface temperature of the inductor $T_s$
* Maximum ambient temperature $T_a$

### Step 2  Assumption parameter
* $kw$ is the window area utilization, typical values are 
* $J_{RMS}$ limited to avoid excessive h eat inside th e coil, values are
* $B_{max}$ limited due to saturation of th e core material, values are

### Step 3 Core materials type https://en.wikipedia.org/wiki/Magnetic_core#Core_materials and https://www.researchgate.net/publication/340073905_Advanced_Ferromagnetic_Materials_in_Power_Electronic_Converters_A_State_of_the_Art
* Iron based
* Powder metal
* Ferrites

Read wiki for full detail

### Step 4 core shape types
* E core
* ETD core
* I core
* Toroidal core
* Ring or bead

Pick the shape that fits your application

### Step 5 pick the size
Obviously the smaller the better

<img src="Images/AP_Method_Areas_of_Interest.jpg" width=400 >

$A_P=\frac{L\cdot i_{peak} \cdot i_{RMS}}{kw \cdot J_{RMS}\cdot B_{max}}$

$A_P= A_w A_\epsilon$

Now you need to pick the shaps, whose $A_P$ is larger than the one calculated.

### Step 6 calculate number of turns

$N=\frac{L i_{peak} }{B_{max} A_\epsilon}$

## Designed inductor

### MOSFET
* $V_{in}=45V$
* $V_{out}=150V$
* $f_{sw}=80 kHz$
* $D=0.7 $

### MOSFET transistor CCM mode
#### Given parameters
* $L=0.75mH$
* $f=80kHz$
* $i_{peak}=1.5 A$
* $i_{rms}=1.25 A$

#### Design
* 3C90 core
* ETD44 core shape
* Number of turns=39
* Airgap=0.2mm
* Wire chosen 26 AWG
* $B_{max}=$ 0.25 Tesla

#### Simulation
For simulation the program femm was used, because it is free and good enough for simple FEM simulation. https://www.femm.info/wiki/HomePage, here are some tutorials, https://www.youtube.com/watch?v=5LvWE1JscO4 , 

#### Practical model

### MOSFET transistor DCM mode
#### Given parameters
#### Design
#### Simulation
#### Practical model
### IGBT
* $V_{in}=45V$
* $V_{out}=300V$
* $f_{sw}=15kHz$
* $D=0.8 $

### IGBT transistor CCM mode
#### Given parameters
* $L=1mH$
* $f=1.5 kHz$
* $i_{peak}=  A$
* $i_{rms}=  A$

#### Design
* 3C90 core
* ETD54 core shape
* Number of turns= 87
* Airgap=1.3mm
* Wire chosen 18 AWG
* $B_{max}=$ 0.22 Tesla
#### Simulation
#### Practical model

### IGBT transistor DCM mode
#### Given parameters
#### Design
#### Simulation
#### Practical model
