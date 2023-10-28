## Questão 22

## A questão 22 pede para a que, seja reproduzida em duas saídas com dois Leds os estados de suas entradas com dois push-button. A questão 22 é um complemento da questão 21 onde no proprio botão k1 e k2 do stm32, quando pressionados, os dois leds da placa vai ser acesso, para isso funcionar é necessário acionar em tempo de execução o resistor pull-up presente no pino pe4 e pe3.

### A escolha dos pinos pe4 e pe3 foi exclusivamente porque eles são responsáveis por acionar os leds D1 e D2 respectivamente presentes no micro.

````C 
/**
  ***************************************************************************************************
  * @file    Questao-22.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Reproduzir em duas saída com dois LEDs os estados de suas entradas com dois push-buttons
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
