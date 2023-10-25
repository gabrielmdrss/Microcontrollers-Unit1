# Questão 20

````C 
/**
  *****************************************************************
  * @file    Questao-19.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V0.1.0
  * @date    05-October-2023
  * @brief   Realizar o acionamento de um motor de passo.
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
