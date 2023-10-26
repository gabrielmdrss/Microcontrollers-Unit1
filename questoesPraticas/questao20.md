# Questão 20

## Na questão 20 é pedido um acionamento de um motor de passo com velocidade e sentido variáveis

## Montagem:
### Foi utilizado um motor de passo bipolar ligado em uma placa de expansão monster motor sheild com duas pontes H como drive de potência, esse modulo de expansão usado no stm32, serve especialmente controlar motores de alta potências, como motores DC ou motores de passo e com as pontes H, o controle do motor de passo se torna preciso.

## Código:
### Para a construção do código a gente considerou o seguinte cenário: o eixo do motor realizar um giro de 360º em uma direção e logo em seguida realizar o movimento inverso.
### Para fazer um motor de passo bipolar girar, você precisa ativar as bobinas em sequência específica, gerando campos eltromagnéticos que interagem com o rotor e o fazem mover-se. Script básico para fazerem se moverem é esse: Ativação de Bobina 1, Desativação de Bobina 1 e Ativação de Bobina 2, Desativação de Bobina 2.
### Cada passo completo gira o motor em um ângulo de 1,8 graus, já que existem 200 passos por revolução (360 graus / 1,8 graus por passo).
### O controle da velocidade e direção do motor de passo é alcançado ajustando o tempo durante o qual as bobinas são ativadas e a ordem das ativações. No código a gente fez uma modulação por largura de pulso (PWM) para controlar a corrente nas bobinas e, assim, a velocidade do motor. Utilizando os drives de potência para isso.




````C 
/**
  *****************************************************************
  * @file    Questao-20.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V0.1.0
  * @date    05-October-2023
  * @brief   Realizar o acionamento de um motor de passo.
  *****************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao20(void) {
	Utility_Init();
	RCC->AHB1ENR |= (1<<0)|(1<<1); // LIGA GIPIO A E B
	GPIOA->MODER |= (0b01 << 0) | (0b01 << 2);
	GPIOB->MODER |= (0b01 << 0) | (0b01 << 2) | (0b01 << 14) | (0b01 << 10);

	while (1) {
		for (int i = 0; i <= 50; i++) {
			GPIOB->ODR |= (1 << 0);
			GPIOB->ODR &= ~(1 << 1);
			GPIOA->ODR |= (1<<0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1<<0);
			GPIOB->ODR |= (1 << 7);
			GPIOB->ODR &= ~(1 << 5);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 1);
			GPIOB->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 1);
			GPIOA->ODR |= (1<<0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1<<0);
			GPIOB->ODR |= (1 << 5);
			GPIOB->ODR &= ~(1 << 7);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);
			GPIOA->ODR &= ~(1<<1);
		}

		for (int i = 0; i <= 50; i++) {
			GPIOB->ODR |= (1 << 5);
			GPIOB->ODR &= ~(1 << 7);
			GPIOA->ODR |= (1 << 0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 1);
			GPIOB->ODR &= ~(1 << 0);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 1);
			GPIOB->ODR |= (1 << 7);
			GPIOB->ODR &= ~(1 << 5);
			GPIOA->ODR |= (1 << 0);
			Delay_ms(5);

			GPIOA->ODR &= ~(1 << 0);
			GPIOB->ODR |= (1 << 0);
			GPIOB->ODR &= ~(1 << 1);
			GPIOA->ODR |= (1 << 1);
			Delay_ms(5);
			GPIOA->ODR &= ~(1 << 1);
		}
	}
}

int main(void){
    questao20();
}
````
