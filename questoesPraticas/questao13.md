# Questão 13

### Nesta questão, é pedido uma simulação de dois semáfaros. Onde quando um estiver aberto, o outro deve permanecer fechado. Tendo 6 LEDs na implementação, 3 para cada semáfaro, seguindo a lógica normal do trânsito.
```C
/**
  ******************************************************************************
  * @file    Questao-13.c 
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Implementar o efeito do LED andante nos 8 LEDs da questão anterior.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao13(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 10)
				| (0B01 << 12) | (0B01 << 14);

	while(1){

		GPIOA->ODR |= (1 << 2)|(1 << 5);
		Delay_ms(1200);
		GPIOA->ODR &= ~(1 << 2);
		GPIOA->ODR |= (1 << 1);
		Delay_ms(800);
		GPIOA->ODR &= ~(1 << 1) & ~(1 << 5);
		GPIOA->ODR |= (1 << 0)|(1 << 7);
		Delay_ms(1200);
		GPIOA->ODR &= ~(1 << 7);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(800);
		GPIOA->ODR &= ~(1 << 6) & ~(1 << 0);

	}
}


int main(void){
    questao13();
}
```
