## Questão 30


````C 
/**
  ***********************************************************************************************************************
  * @file    Questao-30.c 
  * @author  , Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Jogo de Genius
 ***********************************************************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao30(void){
RCC->AHB1ENR |= (1<<2);
GPIOC->MODER |= (0b01<<0)| (0b01<<2) | (0b01<<4) | (0b01<<6); // pinos PC0 a PC3 como saida
GPIOC->MODER &= ~((0b11<<8) | (0b11 << 10) | (0b11 << 12) | (0b11 << 14)); // pinos PC4 a PC7 como entrada
GPIOC ->PUPDR |= (0b01 << 8)|(0b01 << 10)|(0b01 << 12)|(0b01 << 14);

int sequencia[7] ={0,1,2,0,1,2,3};
int jogador[7];
int parada = 0;
int contador = 0;
while(1){

for(int i =0; i<=contador; i++){
          if(sequencia[i] == 0){
              GPIOC -> ODR |= (1<<0);
              Delay_ms(500);
              GPIOC -> ODR &= ~(1<<0);
              Delay_ms(500);
          }
          else if(sequencia[i] == 1){
            GPIOC -> ODR |= (1<<1);
            Delay_ms(500);
            GPIOC -> ODR &= ~(1<<1);
            Delay_ms(500);
          }
          else if(sequencia[i] == 2){
            GPIOC -> ODR |= (1<<2);
            Delay_ms(500);
            GPIOC -> ODR &= ~(1<<2);
            Delay_ms(500);
          }
          else if(sequencia[i] == 3){
            GPIOC -> ODR |= (1<<3);
            Delay_ms(500);
            GPIOC -> ODR &= ~(1<<3);
            Delay_ms(500);
          }
}


   for(int i=0; i<=contador; i++){
       while(1){
        int b0 = GPIOC -> IDR & (1<<4);
        int b1 = GPIOC -> IDR & (1<<5);
        int b2 = GPIOC -> IDR & (1<<6);
        int b3 = GPIOC -> IDR & (1<<7);

        if (!b0){
        GPIOC -> ODR |= (1 << 0);
        jogador[i] = 0;
        Delay_ms(300);
        GPIOC -> ODR &= ~(1 << 0);
        break;
        }

        else{
        GPIOC -> ODR &= ~(1 << 0);
        }
        if (!b1){
        GPIOC -> ODR |= (1 << 1);
        jogador[i] = 1;
        Delay_ms(300);
        GPIOC -> ODR &= ~(1 << 1);
        break;
        }

        else{
          GPIOC -> ODR &= ~(1 << 1);
        }

        if (!b2){
        GPIOC -> ODR |= (1 << 2);
        jogador[i] = 2;
        Delay_ms(300);
        GPIOC -> ODR &= ~(1 << 2);
          break;
        }
        else{
          GPIOC -> ODR &= ~(1 << 2);
        }

        if (!b3){
        GPIOC -> ODR |= (1 << 3);
        jogador[i] = 3;
        Delay_ms(300);
        GPIOC -> ODR &= ~(1 << 3);
        break;
        }
        else{
          GPIOC -> ODR &= ~(1 << 3);
        }
      }
       if(sequencia[i] == jogador[i])
       {
        continue;
       }
       else{
        for(int i=0; i<=2; i++)
        {
        GPIOC -> ODR |= (1<<0);
        GPIOC -> ODR |= (1<<1);
        GPIOC -> ODR |= (1<<2);
        GPIOC -> ODR |= (1<<3);
        Delay_ms(500);
        GPIOC -> ODR &= ~(1<<0);
        GPIOC -> ODR &= ~(1<<1);
        GPIOC -> ODR &= ~(1<<2);
        GPIOC -> ODR &= ~(1<<3);
        Delay_ms(500);
        }
        parada = 1;
       }
      }
   if (parada == 1){
    int sequencia[7] ={0,1,2,3,1,2,3};
        jogador[7];
           contador = 0;
           parada = 0;
   }
   else{
    contador += 1;
   }
   Delay_ms(2000);
   }
}

int main(void){
    questao30();
}
````
