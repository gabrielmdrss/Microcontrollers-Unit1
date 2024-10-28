# Question 11

### In this question, a system is requested that can display an 8-bit count using external LEDs in the implementation. We used GPIOA for this problem, with the least significant bit being PA0 and the most significant bit being PA7.

### After the proper setup, we created a loop of size 256, which is the number of possibilities that 8 bits can encompass. In each iteration, we assigned the index value to the GPIOA port, where the value was passed in binary to the respective ports. To provide a good illustration, we inserted a low delay to demonstrate the capability of our setup.

```C
/**
  ******************************************************************************
  * @file    Question-11.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Display an 8-bit binary count using 8 external LEDs.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao11(void) {

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);
	while (1) {

		for (int i = 0; i < 256; i++) {
			GPIOA -> ODR = (i);
			Delay_ms(150);
		}

	}
}

int main(void){
    questao11();
}
```
