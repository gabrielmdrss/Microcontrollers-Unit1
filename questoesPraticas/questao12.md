# Question 12

### In this question, a system is requested to present the effect of the "walking LED". Using external LEDs in the implementation, we utilized GPIOA for this problem, with the least significant bit as PA0 and the most significant bit as PA7.

### We created two loops, one to move from right to left and another to move from left to right, both with a size of 8, which is the number of connected LEDs. We were passing the index "i" instead of passing the port number. This caused one of the 8 ports to be activated and deactivated with each iteration, continuing to the next LED, occurring cyclically. We assigned a low delay for better illustration of the modeling.

```C
/**
  ******************************************************************************
  * @file    Question-12.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   12. Implement the walking LED effect across the 8 LEDs
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao12(void) {
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);

	while (1) {

		for (int i = 0; i < 8; i++) {
			GPIOA->ODR |= (1 << i);
			Delay_ms(25);
			GPIOA->ODR &= ~(1 << i);
		}
		for (int j = 8; j > 0; j--) {
			GPIOA->ODR |= (1 << j);
			Delay_ms(25);
			GPIOA->ODR &= ~(1 << j);
		}
	}
}

int main(void){
    questao12();
}
```
