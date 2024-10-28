# Question 18

### In this question, a control of a DC motor is requested, so that it can accelerate to its maximum speed, decelerate, and then perform the same process in the reverse direction. We used a motor shield to control the motor, after which we connected three STM ports to this component to control the two polarities and the PWM pulse.
#####
### The two polarities refer to how the internal "coil" of the DC motor will be wound, that is, the direction in which the motor will rotate. In our implementation, we defined the port values (polarity), and then we used two loops to make the motor rotate in one direction and then switch to the other.
######
#### It is worth mentioning that from one loop to the next, there is an inversion in the values passed to the Motor Shield, causing a change in the adopted direction. It is noted that concepts used in questions 7 and 12, such as PWM, are present here, as we are increasing and decreasing the power linearly, so that there is a perception of acceleration or deceleration due to the oscillation of the system's Average Voltage.

```C
/**
  ******************************************************************************
  * @file    Question-18.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Implement DC motor speed control to accelerates to maximum speed and then decelerates.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao18(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4);

	GPIOA->ODR |= (1 << 0);
	GPIOA->ODR &= ~(1 << 1);

	while(1){
		for (int i = 1; i < 20000; i+=20) {
			GPIOA->ODR &= ~(1 << 2);
			Delay_us(20000 - i);
			GPIOA->ODR |= (1 << 2);
			Delay_us(i);
		}

		GPIOA->ODR &= ~(1 << 0);
		GPIOA->ODR |= (1 << 1);

		for (int i = 1; i > 20000; i+=20) {
			GPIOA->ODR |= (1 << 2);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 2);
			Delay_us(20000 - i);
		}
	}
}


int main(void){
    questao18();
}
```
