# Question 20

### In this question, the task is to drive a stepper motor with variable speed and direction.

## Setup:
A bipolar stepper motor was used, connected to a Monster Motor Shield expansion board with two H-bridges as the power driver. This expansion module used with the STM32 is especially designed to control high-power motors, such as DC motors or stepper motors, and with the H-bridges, the control of the stepper motor becomes precise.

## Code:
For the construction of the code, we considered the following scenario: the motor shaft performs a 360º rotation in one direction and then immediately performs the reverse movement.
To make a bipolar stepper motor rotate, you need to activate the coils in a specific sequence, generating electromagnetic fields that interact with the rotor and make it move.

### A basic script to make them move is as follows: 
Activate Coil 1, Deactivate Coil 1, Activate Coil 2, Deactivate Coil 2.

Each complete step rotates the motor by an angle of 1.8 degrees, as there are 200 steps per revolution (360 degrees / 1.8 degrees per step).
The control of the speed and direction of the stepper motor is achieved by adjusting the time during which the coils are activated and the order of activations. In the code, we implemented pulse width modulation (PWM) to control the current in the coils, thus controlling the speed of the motor and its direction, using the power drivers for this purpose.

````C 
/**
  *****************************************************************
  * @file    Question-20.c 
  * @author  Gabriel D, Luiz Neto
  * @version V0.1.0
  * @date    05-October-2023
  * @brief   Operate a stepper motor with variable speed and direction.
  *****************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao20(void) {
	Utility_Init();
	RCC->AHB1ENR |= (1<<0)|(1<<1); // LIGA GIPIO A E B
	GPIOA->MODER |= (0b01 << 0) | (0b01 << 2);
	GPIOB->MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 14) | (0b01 << 10);

	while (1) {
		for (int i = 0; i <= 50; i++) {
			GPIOB->ODR |= (1 << 0);
			GPIOB->ODR &= ~(1 << 1);
			GPIOA->ODR |= (1<<0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1<<0);
			GPIOB->ODR |= (1 << 7);
			GPIOB->ODR &= ~(1 << 5);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 1);
			GPIOB->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 1);
			GPIOA->ODR |= (1<<0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1<<0);
			GPIOB->ODR |= (1 << 5);
			GPIOB->ODR &= ~(1 << 7);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);
			GPIOA->ODR &= ~(1<<1);
		}

		for (int i = 0; i <= 50; i++) {
			GPIOB->ODR |= (1 << 5);
			GPIOB->ODR &= ~(1 << 7);
			GPIOA->ODR |= (1 << 0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 1);
			GPIOB->ODR &= ~(1 << 0);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 1);
			GPIOB->ODR |= (1 << 7);
			GPIOB->ODR &= ~(1 << 5);
			GPIOA->ODR |= (1 << 0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 0);
			GPIOB->ODR &= ~(1 << 1);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);
			GPIOA->ODR &= ~(1 << 1);
		}
	}
}

int main(void){
    questao20();
}
````
