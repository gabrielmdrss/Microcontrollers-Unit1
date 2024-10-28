# Question 13

### In this question, a simulation of two traffic lights is requested. When one is green, the other must remain red. There are 6 LEDs in the implementation, 3 for each traffic light, following the normal traffic logic. A low delay is assigned for better illustration of the modeling.

```C
/**
  ******************************************************************************
  * @file    Question-13.c 
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Simulate the operation of a traffic light intersection using 6 LEDs.
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
