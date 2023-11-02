# Questão 27

##


````C 
/**
  ***********************************************************************************************************************
  * @file    Questao-27.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Ultizar os 3 botões do stm32 para imprimir numeros em um display de 7 segmentos
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
