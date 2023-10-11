# Questão 05

```C
/**
  ******************************************************************************
  * @file    Questao-5.c
  * @author  Luiz Neto, Gabriel D.
  * @version V1.0.0
  * @date    10-October-2023
  * @brief   Acionar um buzzer para emitir um som semelhante ao de um alarme sonoro.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao5(void){

    Utility_Init();
    RCC->AHB1ENR |= (1 << 2);
    GPIOC->MODER |= (0B01);

    while(1){
       for(int i=0;i < 8;i++){
          GPIOC->ODR ^= (1 << 0);
          Delay_ms(50);
       }

       Delay_ms(600);
    }
}

int main(void){
    questao5();
}
```