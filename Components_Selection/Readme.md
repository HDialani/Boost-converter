# Readme
Hi here I want to go over the components selection that were done. Material type and final values as well as an explanation as to what to pay attention to when selection component and values.

## Capacitor
Let's start with capacitor. In general there are 3 types of capacitor materials:Film capacitor, Multilayer Ceramic chip capacitor(MLCC's) and Electrolytic Capacitors (E-cap). They can be further divided into more sub catagories. More on that later. I am going to summarize the resutls in the table below. Most of the values are from the source:https://www.youtube.com/watch?v=2v8zBj7_sxg

E-cap | low | $150^0 C$ | high | mid/large |THT/SMD | low kHz | low | high | #9 | #10 | DC Link, Low frequency Energy storage
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |---
Film | mid | $110^0 C$ | low | mid/large | mostly THT/ rare SMD | High MHz |  | high| mid | 276 | Decoupling,Filter with certain cut-off frequency,High reliability application, EMI suppresion
MLCC's| high| $200^0 C$ | mid | lowe | mostlySMD/rare THT | can go to GHz | high | low | 272 | 276 | Decoupling,High frequency Energy storage,Filter with rough cut-off frequency, EMI suppresion
 Criterias | Cost | Max temp | Ripple current | Size | Mouniting | frequency range of operation | Reliabily of not breaking over time | energy density | 26 | 276 | Typical applicitation

### Further divisions of capacitors
For E-caps, look here for detailed explanation of differences :https://en.wikipedia.org/wiki/Electrolytic_capacitor <br />  <img src="Images/Electrolytic_capacitor_tree.jpg" width=500 >

For Film caps:https://en.wikipedia.org/wiki/Film_capacitor

For MLCC look here for detailed explanation:https://en.wikipedia.org/wiki/Ceramic_capacitor  <br />  <img src="Images/Ceramic_capacitor_classes.jpg" width=750 >, source:(https://www.electronics-notes.com/articles/electronic_components/capacitors/ceramic-dielectric-types-c0g-x7r-z5u-y5v.php)

### Important parameters
* Technology
* Capacitance
* Accuracy
* ESR
* Inductance
* Frequency
* Max current
* Max temperature
* Temperature sensativity
* Power dissipation
* Size
* Cost

### Leakage and Electrical characteristics of Capacitor

If you know this part you can skip, but people who only know ideal capacitor behaviour this might be usefull. This section is highly influenced by FesZ electronics, more specefically this video from him:https://www.youtube.com/watch?v=QpWPTolhfEo&t=1099s

Just like him I will use LTspice to try and model an actual capacitor. The LTspice simulation can be found in [LTSpice](LTSpice) and the measured signals data can be found in .... 

The circuit used to do this measurement is shown below. Blue is .. and yellow is ...

The frequency in is which the images are shown are:$0 Hz$, $10 Hz$, $100 Hz$, $1 kHz$, $5 kHz$, $100 kHz$, $500 kHz$,$1 MHz$.

At $0 Hz$ the input and measured amplitude don't match? As frequency increases the capacitor acts as it should as expected. The measured keeps decreases till ..., but after ... something interesting happens it starts to increase instead. But a capacitor shouldn't be doing this? Well an ideal capacitor won't but a practical will. 

First step is to do a impedance-frequency plot of the capacitor. So initially its impedance decreases as frequency increases, but then at a certain point it starts to increase?

Time to real world parasitics. 
 
### Understanding capacitor datasheet 

## Inductor

## Diode

## Transistor
