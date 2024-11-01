# Question 01

### In this question, the frequency is 2Hz, which means that the complete pulse occurs every 0.5 seconds, and every 250 milliseconds, the LED on the board will be turned off and then back on again.

```C
/**
  ******************************************************************************
  * @file    Question-1.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Blink an LED at a frequency of 2Hz, with a pulse width of 250ms.
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
