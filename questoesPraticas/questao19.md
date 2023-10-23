# Questão 19
````C 
/**
  ******************************************************************************
  * @file    Questao-19.c 
  * @author  Luiz, 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Realizar o acionamento de uma carga partir de um relé.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao19(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (1 << 12);
	GPIOA->OTYPER |= (1 << 6);

	while(1){

		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(1000);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(1000);
	}
}

int main(void){
    questao19();
}
````