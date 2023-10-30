## Questão 25


````C 
/**
  ***************************************************************************************************
  * @file    Questao-25.c 
  * @author  , Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  
 ***************************************************************************************************
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
