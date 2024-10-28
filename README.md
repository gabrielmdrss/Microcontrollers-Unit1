# Microcontrollers - Unit 1
Practical activity for Unit 1 of the Microprocessors and Microcontrollers course, using the STM32F407.

### `01.` [Blink an LED at a frequency of 2Hz, with a pulse width of 250ms.](questoesPraticas/questao01.md)

### `02.` [Blink an LED at a frequency of 0.5Hz, with a pulse width of 100ms, producing behavior similar to aircraft beacons on low-altitude buildings.](questoesPraticas/questao02.md)

### `03.` [Blink an LED with a pulse width of 50ms, following this cycle: blink once, wait a while, then blink twice consecutively, followed by another wait.](questoesPraticas/questao03.md)

### `04.` [Blink an LED with a pulse width of 50ms, but with an increasing frequency, starting at 1Hz.](questoesPraticas/questao04.md)

### `05.` [Activate a buzzer to emit a sound resembling an audible alarm: 4 short beeps of 50ms width, followed by a pause.](questoesPraticas/questao05.md)

### `06.` [Illuminate an LED at different brightness levels, selectable at compile time, using a PWM technique via software (use a PWM frequency of 100Hz).](questoesPraticas/questao06.md)

### `07.` [Illuminate an LED with different brightness levels, varying the brightness during runtime using a software PWM technique (use a PWM frequency of 100Hz). The LED should start off, gradually increase to full brightness, and then gradually dim back to off, repeating this process indefinitely.](questoesPraticas/questao07.md)

### `08.` [Blink two LEDs alternately, with a pulse width of 50% of the period at a frequency of 2Hz, mimicking vehicle exit beacons in garages. (Note: check LED activation simultaneity).](questoesPraticas/questao08.md)

### `09.` [Display a 2-bit binary count using 2 LEDs.](questoesPraticas/questao09.md)

### `10.` [Light up two LEDs with different brightness levels, alternating the intensity at runtime, similarly to question 7.](questoesPraticas/questao10.md)

### `11.` [Display an 8-bit binary count using 8 external LEDs. (Note: for easier code implementation, connect LEDs to contiguous pins of the same GPIO).](questoesPraticas/questao11.md)

### `12.` [Implement the walking LED effect across the 8 LEDs from the previous question: activate the first LED and make it move from the first to the last LED, lighting up one at a time. Once it reaches the last LED, it should move back to the first, reversing the direction.](questoesPraticas/questao12.md)

### `13.` [Simulate the operation of a traffic light intersection using 6 LEDs.](questoesPraticas/questao13.md)

### `14.` [Display an ascending/descending decimal/hexadecimal count of a single digit on a 7-segment display.](questoesPraticas/questao14.md)

### `15.` [Display an ascending/descending decimal/hexadecimal count of two digits on two 7-segment displays. (Note: Use multiplexing to minimize pin usage). Use transistors as power drivers for the multiplexing system.](questoesPraticas/questao15.md)

### `17.` [Control a micro servo motor to alternate its axis position smoothly between left and right, continuously.](questoesPraticas/questao17.md)

### `18.` [Implement DC motor speed control so that it gradually accelerates to maximum speed and then decelerates, repeating the same in the reverse direction. Use an H-bridge as a power driver for the motor.](questoesPraticas/questao18.md)

### `19.` [Switch an AC load at 220V using a relay.](questoesPraticas/questao19.md)

### `20.` [Operate a stepper motor with variable speed and direction, considering both unipolar and bipolar types. For each type, use full-step, half-step, and micro-step modes. When the motor is unipolar, implement a transistor power driver. When bipolar, use two H-bridges as the power driver, or an integrated power driver.](questoesPraticas/questao20.md)

### `21.` [Reproduce an input state on an output LED using a push-button.](questoesPraticas/questao21.md)

### `22.` [Reproduce the states of two inputs on two LEDs using two push-buttons.](questoesPraticas/questao22.md)

### `23.` [Use a push-button to toggle the logic state of an output connected to an LED.](questoesPraticas/questao23.md)

### `24.` [Use two push-buttons (K0 and K1) to turn on an LED with the following rule: the LED should only light up if both buttons are pressed together, with button K0 pressed first, followed by button K1.](questoesPraticas/questao24.md)

### `25.` [Use two push-buttons (K0 and K1) to turn on an LED with the following rule: the LED should only light up if both buttons are pressed together, but K0 must be pressed first, followed by K1. If K1 is not pressed within 1 second after K0 is pressed, the LED should not light up.](questoesPraticas/questao25.md)

### `26.` [Control a micro servo motor to alternate its axis position between left and right using two push-buttons, one for left and one for right.](questoesPraticas/questao26.md)

### `27.` [Use a 4x4 membrane keypad and decode it, displaying the pressed key on a 7-segment display.](questoesPraticas/questao27.md)

### `30.` [Implement the classic memory game "Simon Says" (Use the functions rand() or srand() to create a random sequence to memorize).](questoesPraticas/questao30.md)
