# Question 22

### Question 22 asks for the reproduction of the states of its inputs with two push-buttons on two outputs with two LEDs. Question 22 is a complement to Question 21, where pressing buttons K1 and K2 on the STM32 will turn on both LEDs on the board. For this to work, it is necessary to activate the pull-up resistor present on pins PE4 and PE3 at runtime.

### The choice of pins PE4 and PE3 was made exclusively because they are responsible for controlling LEDs D1 and D2, respectively, present on the microcontroller.


````C 
/**
  ***************************************************************************************************
  * @file    Question-22.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Reproduce the states of two inputs on two LEDs using two push-buttons.
  ***************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao22(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12) | (0b01 << 14);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		int leitura2 = GPIOE->IDR & (1 << 3);
		if (leitura == 0)
			GPIOA->ODR &= ~(1 << 6);
		if (leitura2 == 0) {
			GPIOA->ODR &= ~(1 << 7);
		} else
			GPIOA->ODR |= (1 << 6) | (1 << 7);
	}
}


int main(void){
    questao22();
}
````
