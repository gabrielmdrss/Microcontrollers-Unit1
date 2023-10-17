# Questão 03

### Nesta questão, um LED possui largura de pulso de 50 milíssegundos, contando que obedeça o seguinte ciclo: pisca uma vez, aguarda um tempo e, em seguida, pisca duas vezes seguidas, aguardando mais um tempo. Atribuímos o período do cíclo total de 1 segundo, possuindo frequência igual a 1Hz.
```C
/**
  ******************************************************************************
  * @file    Questao-3.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Piscar um LED com largura de pulso de 50ms, obedecendo a um ciclo.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao3(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	GPIOA->ODR |= (1 << 6);

	while(1){
		for(int i=0;i<2;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);

		for(int i=0;i<4;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);
	}

}

int main(void){
    questao3();
}
```
