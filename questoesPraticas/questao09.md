# Question 09

### In this question, a control of two LEDs is requested, performing a binary count of 2 bits. We represent the least significant bit with port PA6 (controlling LED D2) and the most significant bit with port PA7 (controlling LED D1). Since it is a count with only 2 bits, we created a loop of size 4 to cover the 4 possibilities, counting from 0 to 3 in decimal.

```C
/**
  ******************************************************************************
  * @file    Question-9.c
  * @author  Gabriel D., Luiz Neto.
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Display a 2-bit binary count using 2 LEDs.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao9(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while(1){
		for(int i=0;i<4;i++){
			if(i==0){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR |= (1 << 7);
			}
			else if(i==1){
				GPIOA->ODR &= ~(1 << 6);
			}
			else if(i==2){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR &= ~(1 << 7);
			}
			else
				GPIOA->ODR &= ~(1 << 6);

			Delay_ms(1000);
		}
	}
}

int main(void){
    questao9();
}
```
