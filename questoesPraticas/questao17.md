# Questão 17

### Nesta questão, é pedido um acionamento de um micro servomotor, para que ele consiga alternar suavemente da esquerda para direita. A variação do servomotor acontece em uma faixa de 500microssegundos a 2500microssegundos, onde cada valor nesse intervalo simboliza um ângulo de 0 a 180 graus. Sabendo disso, fizemos um laço para fazer o sentido esquerda-direita e outro para o sentido direita-esquerda. Ambos com tamanho 2000, sendo esse o número de possibilidades entre 500 - 2500.

```C
/**
  ******************************************************************************
  * @file    Questao-17.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Controlar um micro servomotor para que ele alterne suavemente a posição do eixo.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao17(void) {
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while (1) {

		for (int i = 500; i < 2500; i += 10) {
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(20000 - i);
		}

		for (int i = 2500; i > 500; i -= 10) {
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(20000 - i);
		}
	}
}


int main(void){
    questao17();
}
```
