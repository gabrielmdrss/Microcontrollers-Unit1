# Question 08

### In this question, the activation of two LEDs is requested, with a pulse width of 50% of the period. We have a frequency of 2Hz, meaning a period of 0.5s. Logical values alternate every 0.25s. We start with LED "D1" at a logical level of 1 (LED off) and LED "D2" at a logical level of 0 (LED on), so that the alternation occurs cyclically but always in an opposite manner. It will look like 0-1, 1-0, 0-1, 1-0, ...


```C
/**
  ******************************************************************************
  * @file    Question-8.c
  * @author  Gabriel D., Luiz Neto.
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Blink two LEDs alternately, with a pulse width of 50% of the period at a frequency of 2Hz.
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
