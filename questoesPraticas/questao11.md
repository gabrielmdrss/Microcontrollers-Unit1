# Questão 11

### Nesta questão, é pedido um sistema capaz de apresentar uma contagem de 8 bits, usando LEDs externos na implementação. Usamos o GPIOA para esse problema, sendo o bit menos significativo o PA0 e o mais significativo o PA7.
######
### Após a devida montagem, fizemos um laço de tamanho 256, sendo esse o tanto de possibilidades que 8 bits podem abranger. A cada iteração, atribuíamos o valor do indice a porta GPIOA, onde o valor era passado em binário para as respectivas portas. Para uma boa ilustração inserímos um Delay baixo, para demonstrar a capacidade de nossa montagem. 

```C
/**
  ******************************************************************************
  * @file    Questao-11.c
  * @author  Gabriel D., 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Apresentar uma contagem binária de 8 bits a partir de 8 LEDs externos.
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
