# Question 21

### This question asks for an output with an LED to reproduce the state of an input with a push-button. Basically, when the K1 button on the STM32 is pressed, the LED on the board will be turned on. For this to work, it is necessary to activate the pull-up resistor present on pin PE4 at runtime.

### The choice of pin PE4 was made exclusively because it is responsible for turning on the LED D1 present on the microcontroller.


````C 
/**
  *****************************************************************************************
  * @file    Question-21.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Reproduce an input state on an output LED using a push-button.
  *****************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao21(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		if (leitura == 0)
			GPIOA->ODR &= ~(1 << 6);
		else
		GPIOA->ODR |= (1 << 6);
	}
}


int main(void){
    questao21();
}
````
