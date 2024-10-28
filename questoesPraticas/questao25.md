# Question 25

### This question, it asks for two rules for activating the LED: first, if button K1 is pressed, nothing happens; if only K0 is pressed, nothing happens either. However, if button K0 is pressed and then exactly 1 second later button K1 is pressed, then LED D1 will be turned on.

### The choice of pins PE4 and PE3 was exclusively because they are responsible for activating LEDs D1 and D2 respectively present in the microcontroller; despite this, only LED D1 needs to be turned on in question 25.


````C 
/**
  ***********************************************************************************************************************
  * @file    Question-25.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Use two push-buttons (K0 and K1) to turn on an LED with the a rule.
 ***********************************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao25(void) {
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOA -> MODER |= (0b01 << 12) ;
	GPIOE -> PUPDR |= (0b01 << 6) | (0b01 << 8);
	while (1) {
		int leitura_k0 = !(GPIOE->IDR & (1 << 4));
		int leitura_k1 = !(GPIOE->IDR & (1 << 3));

		if (leitura_k1) {
			continue;
		}
		if (leitura_k0) {
			int i = 0;
			while (leitura_k0) {
				leitura_k0 = !(GPIOE->IDR & (1 << 4));
				leitura_k1 = !(GPIOE->IDR & (1 << 3));

				if (leitura_k0 && leitura_k1 && i < 1000) {
					GPIOA-> ODR &= ~(1 << 6);
					i = 0;
				}
				else GPIOA -> ODR |= (1 << 6);
			Delay_ms(1);
			i++;
			}
		}
		GPIOA -> ODR |= (1 << 6);
		leitura_k1 = leitura_k0 = 0;
	}
}

int main(void){
    questao25();
}
````
