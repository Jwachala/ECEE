# 2160 Lab 89 Report

Patrick Taylor and James Wachala

Section Number: 1

March 207th, 2019

## Prelab

![Prelab Design][imgpre1]

The value for the comparator was chosen so that it only pulses once the button has been held down for 250ms straight. For the 50kHz test clock, this value is 12,500 as `12500/50000 = .25`. A value of 50000 was chosen for the first counter's upper limit so that it would reset every second. The other counter runs free, as it only toggles between 0 and 1 based upon the pulses from the comparator, which if the button is held down, is every second, as the first counter resets every second.

![Prelab Scope][imgpre2]

The scope provided here shows the intended behavior. The setup used to produce these graphs is simulating holding the button down. Notes that .5 on the x axis is one second on the 50kHz clock. So, it begins being held down at .5 seconds. Note that this is where graph 1 starts ticking up. .25 seconds later, the counter pulses on graph 2 (fulfilling the requrement for the button to be on for 250ms before starting). This pulse causes the output (graph 3) to turn to 1. 1 second later, the graph falls back down to zero, behaving as intened. It then cycles as inteded after.

## Assignment 1

The values here were chosen because they are 1000 time greater than the ones in the test simulation, showing the shift from a 50kHz clock to a 50MHz clock, which is 1000 times faster.

## Assignment 2

![2 design][img2]

## Assignment 3

![3 design][img3]

![3 first graph][img3_1]

![3 second graph][img3_2]

[imgpre1]: prelab_design.PNG
[imgpre2]: prelab_graphs.PNG
[img2]: assignment2.PNG
[img3]: assignment3.PNG
[img3_1]: assignment3_1.PNG
[img3_2]: assignment3_2.PNG
