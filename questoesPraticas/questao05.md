# Question 05

### In this question, the task is to activate a buzzer with a specific sequence: 4 short beeps of 50ms width, followed by a pause. We consider the pause to have a width of 600ms.
```C
/**
  ******************************************************************************
  * @file    Question-5.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Activate a buzzer to emit a sound resembling an audible alarm.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao5(void){

	Utility_Init();
	RCC->AHB1ENR |= (1 << 2);
	GPIOC->MODER |= (0B01);

	while(1){
		for(int i=0;i < 8;i++){
			GPIOC->ODR ^= (1 << 0);
			Delay_ms(50);
		}

		Delay_ms(600);
	}
}

int main(void){
    questao5();
}
```
