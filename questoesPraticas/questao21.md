# Questão 21



````C 
/**
  *****************************************************************************************
  * @file    Questao-21.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Reproduzir em uma saída com um LED o estado de uma entrada com um push-button
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
