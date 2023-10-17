# Questão 12

### Nesta questão, é pedido um sistema capaz de apresentar o efeito do "LED andante". Usando LEDs externos na implementação, fizemos uso do GPIOA para esse problema, sendo o bit menos significativo o PA0 e o mais significativo o PA7.
######
### Fizemos dois laços, um para ir da direita para esquerda e outro para ir da esquerda para direita, os dois com tamanho 8, sendo esse o número de LEDs conectados. Estavámos passando o índice "i", ao invés de passar o número da porta. Fazendo com que a cada iteração, 1 das 8 portas fossem acionadas e desligadas, dando continuidade para o LED seguinte, ocorrendo ciclicamente. Atribuímos um Delay baixo para uma melhor ilustração da modelagem.
```C
/**
  ******************************************************************************
  * @file    Questao-12.c
  * @author  Gabriel D., 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   12. Implementar o efeito do LED andante nos 8 LEDs da questão anterior.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao12(void) {
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);

	while (1) {

		for (int i = 0; i < 8; i++) {
			GPIOA->ODR |= (1 << i);
			Delay_ms(25);
			GPIOA->ODR &= ~(1 << i);
		}
		for (int j = 8; j > 0; j--) {
			GPIOA->ODR |= (1 << j);
			Delay_ms(25);
			GPIOA->ODR &= ~(1 << j);
		}
	}
}

int main(void){
    questao12();
}
```
