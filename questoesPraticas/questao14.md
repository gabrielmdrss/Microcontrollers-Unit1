# Question 14

### In this question, a decimal/hexadecimal counting of a digit is requested using a 7-segment display. As the name suggests, the display has 7 segments, which will connect to 7 ports (PA0-PA6). For each decimal/hexadecimal value displayed, there is a corresponding binary value; therefore, we created a list with the 16 possibilities, with the binary values converted to decimal integers.

#####

### After that, we created a loop of size 16 to distribute the binary value to the GPIOA ports in increasing order for each iteration, and another with inverse logic to decrease.

```C
/**
  ******************************************************************************
  * @file    Question-14.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Display an ascending/descending decimal/hexadecimal count of a single digit on a 7-segment display.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao14(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);

	int lista[16] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57,
				94, 121, 113 };
	while (1) {

		for (int i = 0; i < 16; i++) {
			GPIOA -> ODR = (lista[i]);
			Delay_ms(400);
		}

		for (int i = 0; i < 16; i++) {
			GPIOA -> ODR = (lista[15 - i]);
			Delay_ms(400);
		}
	}
}


int main(void){
    questao14();
}
```
