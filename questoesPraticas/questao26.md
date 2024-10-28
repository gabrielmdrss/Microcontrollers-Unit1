# Question 26

### The control of the servomotors in question 26 is relatively simple. The main difference from question 26 is that the angle of the motor shaft will be controlled by buttons k1 and k0. Depending on which button you press, the servomotor will move either to the left or to the right.
````C 
/**
  ***********************************************************************************************************************
  * @file    Question-26.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Control a micro servo motor to alternate its axis position between left and right using two push-buttons.
 ***********************************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao26(void) {

	Utility_Init();
	RCC->AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);

	int pos = 500;
	int k1, k0;

	while (1) {

		k1 = !(GPIOE->IDR & (1 << 3));
		k0 = !(GPIOE->IDR & (1 << 4));

		if (k1 && (pos > 500))
			pos -= 10;

		if (k0 && (pos < 2500))
			pos += 10;

		GPIOA->ODR |= (1 << 6);
		Delay_us(pos);
		GPIOA->ODR &= ~(1 << 6);
		Delay_us(20000 - pos);
	}
}

int main(void){
    questao26();
}
````
