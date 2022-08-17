# Readme
The magic of controls engineering. 

# Series RLC Step responce
Here you can see how R,L and C can effect a step responce. 

<img src="Images/RLC_circuit_diagram.jpg" width=500 >

## Differential equation
$v_{in}(t)-v_{R}(t)-v_{L}(t)-v_{C}(t)=0$ (KVL) <br>
$v_{R}(t)=R i(t)$<br> 
$v_{L}(t)=L \frac{d i}{d t}$<br> 
$i(t)=C \frac{d v_{C}}{d t}$

## Transfer Function
First rewrite it in Laplace 
$V(s)-V_{R}(s)-V_{L}(s)-V_{C}(s)=0 $<br>
$\frac{d}{d t}=s$<br>
$V_{R}(s)=R I(s)  $<br>
$V_{L}(s)=L s I(s)$<br>
$I(s)=C s V_{C}(s)$

Rewritting everything gives $\frac{V_{C}(s)}{V(s)}=\frac{1}{R C s+L C s^{2}+1}$, since $V_{C}=V_{in}$ it becomes $H(s)=\frac{1}{R C s+L C s^{2}+1}$
