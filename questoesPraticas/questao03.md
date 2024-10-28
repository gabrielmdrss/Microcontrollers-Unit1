# Question 03

### In this question, an LED has a pulse width of 50 milliseconds, following the cycle: it blinks once, waits for a time, and then blinks twice in a row, waiting for more time afterward. We assign a total cycle period of 1 second, resulting in a frequency of 1Hz.
```C
/**
  ******************************************************************************
  * @file    Question-3.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Blink an LED with a pulse width of 50ms, following a cicle.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao3(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	GPIOA->ODR |= (1 << 6);

	while(1){
		for(int i=0;i<2;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);

		for(int i=0;i<4;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);
	}

}

int main(void){
    questao3();
}
```
