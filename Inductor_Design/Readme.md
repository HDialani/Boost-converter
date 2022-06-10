# Readme
This folder explains how I made the inductor, then how well it worked compared to the practical model.

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

### Step 2  Core materials type https://en.wikipedia.org/wiki/Magnetic_core#Core_materials and https://www.researchgate.net/publication/340073905_Advanced_Ferromagnetic_Materials_in_Power_Electronic_Converters_A_State_of_the_Art
* Iron based
* Powder metal
* Ferrites

Read wiki for full detail

### Step 3 core shape types
* E core
* ETD core
* I core
* Toroidal core
* Ring or bead

Pick the shape that fits your application

### Step 4 pick the size
Obviously the smaller the better

<img src="Images/AP_Method_Areas_of_Interest.jpg" width=400 >


$A_P=\frac{L\cdot i_{peak} \cdot i_{RMS}}{kw \cdot J_{RMS}\cdot B_{max}}$

## Designed inductor

### MOSFET transistor CCM mode
#### Given parameters
* $L=0.75mH$
* $f=80kHz$
* $i_peak=1.5 A$
* $i_rms=1.25 A$


#### Design
* 3C90 core
* ETD44 core shape
* Number of turns=39
* Airgap=0.2mm
* Wire chosen 26 AWG
* Peak inductance 0.25 Tesla
* 

#### Simulation

#### Practical model

### MOSFET transistor DCM mode


### IGBT transistor CCM mode


### IGBT transistor DCM mode
