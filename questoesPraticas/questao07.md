# Question 07

### In this question, the task is to activate an LED with different brightness intensities, changing this intensity at runtime. We have a frequency of 100Hz, which means the period is equal to 0.01s or 10,000µs.
#####
### Through a loop, we manipulated it so that, initially, the low logical level (LED on) was 0/10,000, and we incremented it until the opposite situation occurred, 10,000/0. This caused the LED to be fully lit, and after that, we created a loop with the opposite logic to turn off the LED, making the system into a cycle.

```C
/**
  ******************************************************************************
  * @file    Question-7.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Illuminate an LED with different brightness levels, varying the brightness using a software PWM technique.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao7(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while(1){

		for(int i = 1;i < 10000;i++){
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(i);
			GPIOA->ODR |= (1 << 6);
			Delay_us(10000 - i);
			i += 50;
		}

		for(int i = 1;i < 10000;i++){
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(10000 - i);
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			i += 50;
		}
	}
}

int main(void){
    questao7();
}
```
