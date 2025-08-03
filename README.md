# xiao-timer

basically, a little pcb timer i made to help me keep track of time

<img src="images/pcb_w_3d_models.png" alt="image of pcb with 3d models" width="400px">

### features

- you can set timer for diff times depending on the number of button clicks or press type:

<table>
<tr>
<th>Button Number</th>
<th>Press Type</th>
<th>Timer Set For</th>
</tr>

<tr>
<td rowspan="2">1</td>
<td>Single Press</td>
<td>30 seconds</td>
</tr>
<tr>
<td>Long Press</td>
<td>15 minutes</td>
</tr>

<tr>
<td rowspan="2">2</td>
<td>Single Press</td>
<td>1 minute</td>
</tr>
<tr>
<td>Long Press</td>
<td>30 minutes</td>
</tr>

<tr>
<td rowspan="2">3</td>
<td>Single Press</td>
<td>5 minutes</td>
</tr>
<tr>
<td>Long Press</td>
<td>1 hour</td>
</tr>

<tr>
<td rowspan="2">4</td>
<td>Single Press</td>
<td>10 minutes</td>
</tr>
<tr>
<td>Long Press</td>
<td>2 hours</td>
</tr>
</table>

- leds light up in order to show the time elapsed
- all leds light up + buzzer beeps when the time is up
- some easter eggs here and there!

### pcb

the pcb was designed in kicad
#### schematic:
<img src="images/schematic.png" alt="image of pcb with 3d models">

#### the pcb:

<div>
<img src="images/pcb_front.png" alt="image of pcb with 3d models" width="400px">
<img src="images/pcb_back.png" alt="image of pcb with 3d models" width="400px">
</div>




### components used

- XIAO RP2040  
- 4 LEDs  
- 4 Cherry MX Switches  
- A buzzer  
