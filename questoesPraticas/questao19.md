# Questão 19

## Na questão 19 um relé é acionado a partir carga em corrente contínua (DC) de 5V..

## Montagem:
### O Relé utilizado na questão foi um, relé de 1 canal 5V. Para conectá-lo ao STM32, foram estabelecidas três conexões: a saída VCC do relé foi conectada à saída de 5V do STM32, o GND do relé foi conectado a qualquer terminal GND do microcontrolador e a saída "IN" foi conectada ao pino PA6.

## Código:
### Esse código é simples, a única exceção foi exclusivamente no acionamento do pino PA6 no modo OTYPER como Open-Drain. O Open-Drain torna-se necessário nessa questão porque possibilita o controle de relés com diferentes tensões de operação, uma vez que o nível alto é determinado pela tensão de alimentação do relé e do resistor de pull-up externo, não pelo nível de tensão do microcontrolador.

````C 
/**
  ******************************************************************************
  * @file    Questao-19.c 
  * @author  Gabriel D., Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Realizar o acionamento de uma carga partir de um relé.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao19(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (1 << 12);
	GPIOA->OTYPER |= (1 << 6);

	while(1){

		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(1000);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(1000);
	}
}

int main(void){
    questao19();
}
````
