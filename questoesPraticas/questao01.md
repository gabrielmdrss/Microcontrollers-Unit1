```C

#include "stm32f4xx.h"
#include "Utility.h"

void questao1(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	while(1){
		GPIOA->ODR ^= (1 << 6);
		Delay_ms(250);
	}
}



```
