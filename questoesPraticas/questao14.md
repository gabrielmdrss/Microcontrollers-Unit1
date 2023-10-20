# Questão 14

### Nesta questão, é pedido uma contagem decimal/hexadecimal de um dígito com um display de 7 segmentos. Como o nome já diz, o display possui 7 segmentos, que irão em 7 portas(PA0-PA6). Para cada valor decimal/hexadecimal exibido, existe um valor em binário, logo fizemos uma lista com as 16 possibilidades, com os valores binários convertidos para inteiros decimais.
#####
### Após isso, fizemos um laço de tamanho 16 para a cada iteração, distribuir o valor em binário para as portas do GPIOA de forma crescente e outro com uma lógica inversa, para decrescer.
```C
/**
  ******************************************************************************
  * @file    Questao-14.c 
  * @author  Gabriel D., 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Apresentar uma contagem decimal/hexadecimal.
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
