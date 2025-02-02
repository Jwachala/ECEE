# 2160 Lab 11 Report

Patrick Taylor and James Wachala

Section Number: 1

April 10th, 2019

## Prelab

### a)

![Prelab Design][imgpre0]

The ConfigurablePWM takes an angle in degree and converts it to PWM, it does this by converting degrees to PWM in milliseconds but in the clock of the program at 50000 iterations per second. Meaning 20 milliseconds is 1000 cycles. The counter (Full Pulse) counts from 0-1000 (20 ms) and when the Angle (converted to the appropriate ms equivelent for the PWM) is less than the Full Pulse value the PWM outputs 1 which is the peak of the PWM signal, the rest of the pulse is 0 (off)

### b)

![0 Zoom][imgpre1]

Works as intended, 30 cycles is equivalent to .6 milliseconds. In the design, inputing 0 as the angle will output the pwm signal with a peak for 30 cycles (.6 milliseconds) and a low for the remaining 970 cycles (the remaining of the 20 milliseconds).

![90 Zoom][imgpre2]

Works as intended, 75 cycles is equivalent to 1.5 milliseconds. In the design, inputing 90 as the angle will output the pwm signal with a peak for 75 cycles (90/2 + 30) and a low for the remaining 925 cyles (the remaining of the 20 milliseconds).

![180 Zoom][imgpre3]

Works as intended, 120 cycles is equivalent to 2.4 milliseconds. In the design, inputing 180 as the angle will output the pwm signal with a peak for 120 cycles (180/2 + 30) and a low for the remaining 880 cyles (the remaining of the 20 milliseconds).

## 1)

### a)

![Design][img1]

Pulse is set to one whenever the Counter reaches the value of 50000/Speed (in the instances of below Speed gets set to 4 and 7) As the counter gets reset whenever it hits that value which sends a 1 to Pulse when the Counter resets.

### b)

![4 as Speed][img1.1]

Pulses 4 times per second (1 second is 50000 cycles)

![7 as Speed][img1.2]

Pulses 5 times per second

## 2)

### a)

![Design][img2]

The speed input determines how fast the arm moves to the intented position. the block it is piped into pulses such that it only enables the counter it is connected to at the rate speed tells the arm to move, adding or subtracting one degree from that counter. However, we only want the pulses to get through when the current angle doesn't match the desired angle, hence the not equals relational operator and AND gate. The other relational operator determines which direction the arm needs to move, either to a smaller angle or a larger one. Finally, Configurable PWN converts the angle into a PWN signal recognizable by the robot arm.

### b)

![First][img2.1]

![Last][img2.2]

This circuit behaves correctly, as the PWM width changes from its starting value (90 degrees, 74 pulse widths) to the final position (80 degrees, 70 pulse width.)

## 3)

![Design][img3]

![Mapping][img3.1]
![Mapping Cont][img3.2]

## 4)

See Video Attached. Object was thrown 18 inches.

[imgpre0]: preDes.PNG
[imgpre1]: pre0Zoom.PNG
[imgpre2]: pre90Zoom.PNG
[imgpre3]: pre180Zoom.PNG

[img1]: assignment1.PNG
[img1.1]: assignment1b4.PNG
[img1.2]: assignment1b7.PNG


[img2]: assignment2.PNG
[img2.1]: assignment2i.PNG
[img2.2]: assignment2f.PNG

[img3]: assignment3.PNG
[img3.1]: assignment31.PNG
[img3.2]: assignment32.PNG
