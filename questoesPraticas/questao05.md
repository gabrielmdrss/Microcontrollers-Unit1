# Questão 05

### Nesta questão é pedido um acionamento de um buzzer com uma sequência específica: 4 beeps curtos de 50ms de largura, seguidos de uma pausa. Consideramos a pausa com largura de 600ms.

```C
/**
  ******************************************************************************
  * @file    Questao-5.c
  * @author  Luiz Neto, Gabriel D.
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Acionar um buzzer para emitir um som semelhante ao de um alarme sonoro.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao5(void){

	Utility_Init();
	RCC->AHB1ENR |= (1 << 2);
	GPIOC->MODER |= (0B01);

	while(1){
		for(int i=0;i < 8;i++){
			GPIOC->ODR ^= (1 << 0);
			Delay_ms(50);
		}

		Delay_ms(600);
	}
}

int main(void){
    questao5();
}
```
