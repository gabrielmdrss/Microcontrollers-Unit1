# Questão 09

### Nesta questão é pedido um acionamento de dois LEDs, fazendo uma contagem binária de 2 bits. Representamos o bit menos significativo com a porta PA6(controlando o LED D2) e o bit mais significativo com a porta PA7(controlando o LED D1). Por se tratar de uma contagem com 2 bits apenas, fizemos um laço de tamanho 4, para atender as 4 possibilidades, contando de 0 a 3 em decimal.

```C
/**
  ******************************************************************************
  * @file    Questao-9.c
  * @author  Gabriel D., Luiz Neto.
  * @version V1.0.0
  * @date    14-October-2023
  * @brief   Apresentar uma contagem binária de 2 bits a partir de 2 LEDs.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao9(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while(1){
		for(int i=0;i<4;i++){
			if(i==0){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR |= (1 << 7);
			}
			else if(i==1){
				GPIOA->ODR &= ~(1 << 6);
			}
			else if(i==2){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR &= ~(1 << 7);
			}
			else
				GPIOA->ODR &= ~(1 << 6);

			Delay_ms(1000);
		}
	}
}

int main(void){
    questao9();
}
```
