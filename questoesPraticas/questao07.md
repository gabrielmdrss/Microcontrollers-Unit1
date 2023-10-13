# Questão 07

### Nesta questão é pedido um acionamento de um LED com diferentes intensidades de brilho, alterando essa intensidade em tempo de execução. Temos a frequência igual a 100Hz, ou seja, o período é igual a 0,01s ou 10.000us.
#####
### Por um laço de repetição, manipulamos para que, inicialmente, o nível lógico baixo(LED aceso) fosse 0/10.000 e íamos incrementando até que houvesse a situação contrária 10.000/0. Isso fez com que o LED acendesse totalmente e, logo após isso, fizemos um laço com a lógica contrária para apagar o LED, fazendo com que o sistema se tornasse um ciclo.

```C
/**
  ******************************************************************************
  * @file    Questao-7.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Acender um LED com diferentes intensidades de brilho, alterando essa intensidade.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao7(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while(1){

		for(int i = 1;i < 10000;i++){
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(i);
			GPIOA->ODR |= (1 << 6);
			Delay_us(10000 - i);
			i += 50;
		}

		for(int i = 1;i < 10000;i++){
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(10000 - i);
			GPIOA->ODR |= (1 << 6);
			Delay_us(i);
			i += 50;
		}
	}
}

int main(void){
    questao7();
}
```
