# Questão 21

## A questão 21 pede para a que, seja reproduzida em uma saída com um Led o estado de uma entrada com um push-button. Basicamente no proprio botão k1 do stm32, quando pressionado, o led da placa vai ser acesso, para isso funcionar é necessário acionar em tempo de execução o resistor pull-up presente no pino pe4.

### A escolha do pino pe4 foi exclusivamente porque ele é responsável por acionar o led D1 presente no micro.

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
