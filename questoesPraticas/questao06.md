### Nesta questão é pedido um acionamento do LED utilizando uma técnica PWM(Pulse Widht Modulation). Já que na eletrônica lidamos com valores 0 ou 1(3,3V), não conseguimos introduzir valores "intermediários", o PDW vem para esse propósito.

```C
/**
  ******************************************************************************
  * @file    Questao-6.c
  * @author  Luiz Neto, Gabriel D.
  * @version V1.0.0
  * @date    11-October-2023
  * @brief   Mostrar um LED aceso com diferentes intensidades de brilho, utilizando uma técnica de PWM.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao6(void){
    Utility_Init();
    RCC->AHB1ENR |= 1;
    GPIOA->MODER |= (0B01 << 12);

    while(1){
       GPIOA->ODR &= ~(1 << 6);
       Delay_us(1000);
       GPIOA->ODR |= (1 << 6);
       Delay_us(9000);
    }
}

int main(void){
    questao6();
}
```
