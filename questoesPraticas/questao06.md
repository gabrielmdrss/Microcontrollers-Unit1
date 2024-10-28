# Question 06

### In this question, the task is to activate the LED using a PWM (Pulse Width Modulation) technique. Since in electronics we deal with values of 0 or 1 (3.3V), we cannot introduce "intermediate" values; PWM serves this purpose. 
### With a frequency of 100Hz, we have a period of 10ms, where 1/10 of that time would be at the low logical level (LED on) and the remaining time with the LED off. Due to the extremely rapid alternation, we have the impression that the LED is always on, but much weaker than what was handled in the previous questions.
```C
/**
  ******************************************************************************
  * @file    Question-6.c
  * @author  Gabriel D., Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Illuminate an LED at different brightness levels, selectable at compile time, using a PWM technique.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao6(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while(1){
		GPIOA->ODR &= ~(1 << 6);
		Delay_us(1000);
		GPIOA->ODR |= (1 << 6);
		Delay_us(9000);
	}
}

int main(void){
    questao6();
}
```
