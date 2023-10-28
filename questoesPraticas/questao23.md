## Questão 23


````C 
/**
  ***************************************************************************************************
  * @file    Questao-23.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Utilizar uma entrada para alternar o estado lógico de uma saída de um LED.

  ***************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao23(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	int ledState = 0;

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		if (leitura == 0){
			ledState = !ledState;
			GPIOA->ODR ^= (ledState << 6);
			while(GPIOE->IDR & (1 << 4)){

			}
		}
		Delay_ms(200);
	}
}



int main(void){
    questao23();
}
````
