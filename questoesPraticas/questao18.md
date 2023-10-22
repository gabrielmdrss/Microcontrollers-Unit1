# Questão 18

### Nesta questão, é pedido um acionamento de um motor DC, para que ele consiga acelerar até sua velocidade máxima, desacelerar e depois fazer o mesmo processo no sentido inverso. Utilizamos de um motor shield para conseguirmos controlar o motor, depois isso, conectamos três portas do STM nesse componente, para controlar as duas polaridades e o pulso PDW.
#####
### As duas polaridades dizem respeito à forma que a "bobina" interna do motor DC será enrolada, ou seja, para qual sentido o motor irá girar. Em nossa implementação, definimos os valores das portas(polaridade), após isso, utilizamos de dois laços para fazerem o motor girar em um sentido e depois alternar para o outro.
######
#### Vale-se ressaltar que de um laço para o outro ocorre uma inversão nos valores que são passados para o Motor Shield, fazendo com que ocorra uma troca no sentido adotado. Nota-se que conceitos adotados nas questões 7 e 12, como o PDW se fazem presentes aqui, já que estamos aumentando e diminuindo a potência linearmente, de modo que haja a percepção de uma aceleração ou frenagem por conta da oscilação da Tensão Média do sistema.

```C
/**
  ******************************************************************************
  * @file    Questao-18.c 
  * @author  Gabriel D.,
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Implementar o controle de velocidade de um motor DC.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao18(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4);

	GPIOA->ODR |= (1 << 0);
	GPIOA->ODR &= ~(1 << 1);

	while(1){
		for (int i = 1; i < 20000; i+=20) {
			GPIOA->ODR &= ~(1 << 2);
			Delay_us(20000 - i);
			GPIOA->ODR |= (1 << 2);
			Delay_us(i);
		}

		GPIOA->ODR &= ~(1 << 0);
		GPIOA->ODR |= (1 << 1);

		for (int i = 1; i > 20000; i+=20) {
			GPIOA->ODR |= (1 << 2);
			Delay_us(i);
			GPIOA->ODR &= ~(1 << 2);
			Delay_us(20000 - i);
		}
	}
}


int main(void){
    questao18();
}
```
