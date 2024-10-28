# Question 24

### To comply with the rule imposed by this question, the code needs to meet some prerequisites. First, if button K1 is pressed, nothing happens. If only K0 is pressed, nothing happens either. If button K0 and button K1 are pressed respectively, then LED D1 is turned on.

### The choice of pins PE4 and PE3 was made exclusively because they are responsible for activating LEDs D1 and D2 respectively present on the microcontroller. However, only LED D1 needs to be turned on in question 24.



````C 
/**
  ***************************************************************************************************
  * @file    Question-24.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Use two push-buttons (K0 and K1) to turn on an LED with a rule.
 ***************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao24(void){
	Utility_Init();
	    RCC -> AHB1ENR |= (1 << 0) | (1 << 4);
	    GPIOA -> MODER |= (0b01 << 12) ;
	    GPIOE -> PUPDR |= (0b01 << 6) | (0b01 << 8);

	    int k1, k0;

	    while(1){
	        k1 = !(GPIOE->IDR & (1 << 3));
	        k0 = !(GPIOE->IDR & (1 << 4));
	        if(k1){
	            continue;
	        }

	        if(k0){
	            while(k0){
	            k0 = !(GPIOE->IDR & (1 << 4));
	            k1 = !(GPIOE->IDR & (1 << 3));

	            if(k1 && k0){
	                GPIOA->ODR &= ~(1 << 6);
	                }else GPIOA->ODR |= (1 << 6);
	            }
	        }
	        GPIOA->ODR |= (1 << 6);
	        k1 = k0 = 0;
	    }
}

int main(void){
    questao24();
}
````
