# Questão 24

## Para cumprir a regra imposta pela regra questão 24, o código precisa cumprir alguns pré-requisitos, primeiro se o botão k1 for pressionado nada acontece, se somente K0 for pressionado também nada acontece, se o botão K0 e o botão K1 forem pressionados respectivamente então o led D1 é acesso.

### A escolha dos pinos pe4 e pe3 foi exclusivamente porque eles são responsáveis por acionar os leds D1 e D2 respectivamente presentes no micro, apesar disso só é necessário acender o led D1 na questão 24.


````C 
/**
  ***************************************************************************************************
  * @file    Questao-24.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Led só acende se quando o botão K0 primeiro é precionado e logo em seguida o K1
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
