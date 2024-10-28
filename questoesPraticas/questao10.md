# Question 10

### In this question, similar to question 7, an alternating activation of two LEDs is required using the PDW (Pulse Width Modulation) technique. However, while one will light up linearly, the other will turn off linearly. In simple terms, this means that in places where we assumed a high logical level for PA6 (LED D2), we assign a low logical level for PA7 (LED D1) and vice versa. This results in one LED having a loop to turn on and off, while the other LED will have a loop to turn off and on, in reverse order.

```C
/**
  ******************************************************************************
  * @file    Questao-10.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Light up two LEDs with different brightness levels, alternating the intensity at runtime.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao10(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while (1) {

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(10000 - i);
			i += 50;
		}

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(10000 - i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(i);
			i += 50;
		}
	}
}

int main(void){
    questao10();
}
```
