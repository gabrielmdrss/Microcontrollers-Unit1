# Questão 01

### Nesta questão, a frequência é de 2Hz, o que quer dizer que o pulso completo ocorre a cada 0.5 segundos, e a cada 250 milissegundos, o LED na placa será desligado e ligado novamente.

```C
/**
  ******************************************************************************
  * @file    Questao-1.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Piscar um LED numa frequência de 2Hz, com largura de pulso de 250ms.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao1(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	while(1){
		GPIOA->ODR ^= (1 << 6);
		Delay_ms(250);
	}
}

int main(void){
    questao1();
}
```
