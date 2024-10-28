# Question 02

### In this question, the frequency is 0.5Hz, which means that the complete pulse occurs every 2 seconds, with a pulse width of 100 milliseconds. The LED will stay at a high logic level for 0.1 seconds and then will remain off for the rest of the two seconds.
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
