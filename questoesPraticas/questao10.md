# Questão 10 

### Nesta questão, semelhante à questão 7, é cobrado um acionamento alternado de dois LEDs com o uso da técnica PDW(Pulse Widht Modulation). Mas enquanto um irá acender linearmente, o outro irá apagar linearmente. Em poucas palavras, isso significa que em locais onde assumíamos o nível lógico alto para PA6(LED D2), atribuímos nível lógico baixo para PA7(LED D1)e vice-versa. Fazendo com que para um LED seja um laço para acender e apagar, e no outro LED, um laço será apagar e acender, de forma invertida.

```C
/**
  ******************************************************************************
  * @file    Questao-10.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Acender dois LEDs com diferentes intensidades de brilho.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao10(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while (1) {

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(10000 - i);
			i += 50;
		}

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(10000 - i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(i);
			i += 50;
		}
	}
}

int main(void){
    questao10();
}
```
