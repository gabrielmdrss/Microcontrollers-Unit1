# Question 27

### Question 27 requires the use of a 4x4 membrane keypad, and based on its decoding, to display the pressed key on a 7-segment display. However, this code works only for the buttons k0, k1, and k_up that are already on the STM32.

### The code is simple; it basically reads which button is being pressed, and each button will print a number from 1 to 3 on the 7-segment display. A delay between readings becomes necessary if the buttons are clicked too quickly, preventing a bug in the number displayed.

````C 
/**
  ***********************************************************************************************************************
  * @file    Question-27.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Use a 4x4 membrane keypad and decode it, displaying the pressed key on a 7-segment display.
 ***********************************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao27(void) {

	Utility_Init();
	RCC->AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOA->MODER |= (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOA->MODER &= ~(0b11 << 0);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);
	GPIOA->PUPDR |= (0b10 << 0);

	while (1) {

		int leitura = !(GPIOA->IDR & (1 << 0));
		if (leitura == 0) {
			GPIOA->ODR = (6 << 1);
			while (GPIOA->IDR & (1 << 0)) {
			}
		}
		Delay_ms(200);

		int leitura2 = GPIOE->IDR & (1 << 4);
		if (leitura2 == 0) {
			GPIOA->ODR = (91 << 1);
			while (GPIOE->IDR & (1 << 4)) {
			}
		}
		Delay_ms(200);

		int leitura3 = GPIOE->IDR & (1 << 3);
		if (leitura3 == 0) {
			GPIOA->ODR = (79 << 1);
			while (GPIOE->IDR & (1 << 3)) {
			}
		}
		Delay_ms(200);
	}
}

int main(void){
    questao27();
}
````
