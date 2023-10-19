# Questão 02

### Nesta questão, a frequência é de 0.5Hz, o que quer dizer que o pulso completo ocorre a cada 2 segundos e com largura de pulso igual a 100 milissegundos. O led ficará 0,1 segundos no nível lógico alto e, logo após isso, passará o restante dos dois segundos desligado.
```C
/**
  ******************************************************************************
  * @file    Questao-2.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Piscar um LED numa frequência de 0.5Hz, com largura de pulso de 100ms.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao2(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while(1){
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(100);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(1900);

		}
}

int main(void){
    questao2();
}
```
