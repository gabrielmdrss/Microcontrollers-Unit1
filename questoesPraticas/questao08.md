# Questão 08

### Nesta questão é pedido um acionamento de dois LEDs, com largura de pulso com 50% do período. Temos a frequência igual a 2Hz, ou seja, o período de 0,5s. Ocorrendo uma alternância de valores lógicos a cada 0,25s. Começamos o LED "D1" com nível lógico 1(LED desligado) e o LED "D2" com nível lógico 0(LED ligado), para que a alternância ocorra ciclicamente, mas sempre de forma oposta. Tendo algo como 0-1, 1-0, 0-1, 1-0, ...

```C
/**
  ******************************************************************************
  * @file    Questao-8.c
  * @author  Gabriel D., 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Piscar dois LEDS, alternadamente, com largura de pulso de 50% do período.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao8(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);
	GPIOA->ODR |= (1 << 6);

	while(1){
		GPIOA->ODR ^= (1 << 6);
		GPIOA->ODR ^= (1 << 7);
		Delay_ms(250);
	}
}

int main(void){
    questao8();
}
```
