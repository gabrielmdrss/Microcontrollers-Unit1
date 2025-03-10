# Question 17

### In this question, a micro servo motor is required to be activated so that it can smoothly switch from left to right. The servo motor varies in a range of 500 microseconds to 2500 microseconds, where each value in this range symbolizes an angle from 0 to 180 degrees. Knowing this, we made a loop to make the left-right direction and another for the right-left direction. Both with a size of 2000, this being the number of possibilities between 500 - 2500.

```C
/**
  ******************************************************************************
  * @file    Question-17.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Control a micro servo motor so that it smoothly changes the position of the shaft.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao17(void) {
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while (1) {

		for (int i = 500; i < 2500; i += 10) {
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(20000 - i);
		}

		for (int i = 2500; i > 500; i -= 10) {
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(20000 - i);
		}
	}
}


int main(void){
    questao17();
}
```
