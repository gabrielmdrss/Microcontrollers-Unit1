/**
  ******************************************************************************
  * @file    main.c
  * @author  Luiz Neto, Gabriel D.
  * @version V0.1.0
  * @date    05-October-2023
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

void questao1(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	while(1){
		GPIOA->ODR ^= (1 << 6);
		Delay_ms(250);
	}
}

void questao2(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);

	while(1){
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(100);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(1900);

		}
}

void questao3(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	GPIOA->ODR |= (1 << 6);

	while(1){
		for(int i=0;i<2;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);

		for(int i=0;i<4;i++){
			GPIOA->ODR ^= (1 << 6);
			Delay_ms(50);
		}
		Delay_ms(950);
	}

}

void questao4(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12);
	GPIOA->ODR |= (1 << 6);

	while(1){
		for(int tempo = 950; tempo > 0 ;tempo--){
		GPIOA->ODR &= ~(1 << 6);
		Delay_ms(50);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(tempo);
		tempo -= 49;
		}


	}
}

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

void questao8(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);
	GPIOA->ODR |= (1 << 6);

	while(1){
		GPIOA->ODR ^= (1 << 6);
		GPIOA->ODR ^= (1 << 7);
		Delay_ms(250);
	}
}

void questao9(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while(1){
		for(int i=0;i<4;i++){
			if(i==0){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR |= (1 << 7);
			}
			else if(i==1){
				GPIOA->ODR &= ~(1 << 6);
			}
			else if(i==2){
				GPIOA->ODR |= (1 << 6);
				GPIOA->ODR &= ~(1 << 7);
			}
			else
				GPIOA->ODR &= ~(1 << 6);

			Delay_ms(1000);
		}
	}
}

void questao10(void){

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 12)|(0B01 << 14);

	while (1) {

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(10000 - i);
			i += 50;
		}

		for (int i = 1; i < 10000; i++) {
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR |= (1 << 7);
			Delay_us(10000 - i);
			GPIOA->ODR |= (1 << 6);
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(i);
			i += 50;
		}
	}
}

void questao11(void) {

	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);
	while (1) {

		for (int i = 0; i < 256; i++) {
			GPIOA -> ODR = (i);
			Delay_ms(150);
		}

	}
}

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

void questao13(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 10)
				| (0B01 << 12) | (0B01 << 14);

	while(1){

		GPIOA->ODR |= (1 << 2)|(1 << 5);
		Delay_ms(1200);
		GPIOA->ODR &= ~(1 << 2);
		GPIOA->ODR |= (1 << 1);
		Delay_ms(800);
		GPIOA->ODR &= ~(1 << 1) & ~(1 << 5);
		GPIOA->ODR |= (1 << 0)|(1 << 7);
		Delay_ms(1200);
		GPIOA->ODR &= ~(1 << 7);
		GPIOA->ODR |= (1 << 6);
		Delay_ms(800);
		GPIOA->ODR &= ~(1 << 6) & ~(1 << 0);

	}
}

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

void questao15(void){

	Utility_Init();
	RCC->AHB1ENR |= 1|(1 << 2);
	GPIOA->MODER |= (0B01 << 0) | (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);
	GPIOC->MODER |= (0B01 << 0) | (0B01 << 2);

	int sec = 100000;
	int lista[16] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57,
			94, 121, 113 };

	void tempo(int indiceDez, int indiceUni, int delay){
		for(int i=0;i<delay;i+=10){
			GPIOC->ODR |= (1 << 0);
			GPIOA->ODR = lista[indiceUni];
			Delay_us(10);
			GPIOC->ODR &= ~(1 << 0);
			GPIOC->ODR |= (1 << 1);
			GPIOA->ODR = lista[indiceDez];
			Delay_us(10);
			GPIOC->ODR &= ~(1 << 1);
		}
	}

	while(1){

		for(int i=0;i<16;i++){
			for(int j=0;j<16;j++){
				tempo(i,j,sec);
				Delay_ms(1);
			}
		}
	}

}

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

void questao21(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		if (leitura == 0)
			GPIOA->ODR &= ~(1 << 6);
		else
		GPIOA->ODR |= (1 << 6);
	}
}

void questao22(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12) | (0b01 << 14);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		int leitura2 = GPIOE->IDR & (1 << 3);
		if (leitura == 0)
			GPIOA->ODR &= ~(1 << 6);
		if (leitura2 == 0) {
			GPIOA->ODR &= ~(1 << 7);
		} else
			GPIOA->ODR |= (1 << 6) | (1 << 7);
	}
}

void questao23(void){
	Utility_Init();
	RCC->AHB1ENR |= 1;
	RCC->AHB1ENR |= 1 << 4;
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	int ledState = 0;

	while (1) {
		int leitura = GPIOE->IDR & (1 << 4);
		if (leitura == 0){
			ledState = !ledState;
			GPIOA->ODR ^= (ledState << 6);
			while(GPIOE->IDR & (1 << 4)){

			}
		}
		Delay_ms(200);
	}
}

void questao24(void){
	Utility_Init();
	    RCC -> AHB1ENR |= (1 << 0) | (1 << 4);
	    GPIOA -> MODER |= (0b01 << 12) ;
	    GPIOE -> PUPDR |= (0b01 << 6) | (0b01 << 8);

	    int k1, k0;

	    while(1){
	        k1 = !(GPIOE->IDR & (1 << 3));
	        k0 = !(GPIOE->IDR & (1 << 4));
	        if(k1){
	            continue;
	        }

	        if(k0){
	            while(k0){
	            k0 = !(GPIOE->IDR & (1 << 4));
	            k1 = !(GPIOE->IDR & (1 << 3));


	            if(k1 && k0){
	                GPIOA->ODR &= ~(1 << 6);
	                }else GPIOA->ODR |= (1 << 6);
	            }
	        }
	        GPIOA->ODR |= (1 << 6);
	        k1 = k0 = 0;
	    }
}

void questao25(void) {
	Utility_Init();
	RCC -> AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOA -> MODER |= (0b01 << 12) ;
	GPIOE -> PUPDR |= (0b01 << 6) | (0b01 << 8);
	while (1) {
		int leitura_k0 = !(GPIOE->IDR & (1 << 4));
		int leitura_k1 = !(GPIOE->IDR & (1 << 3));

		if (leitura_k1) {
			continue;
		}
		if (leitura_k0) {
			int i = 0;
			while (leitura_k0) {
				leitura_k0 = !(GPIOE->IDR & (1 << 4));
				leitura_k1 = !(GPIOE->IDR & (1 << 3));

				if (leitura_k0 && leitura_k1 && i < 1000) {
					GPIOA-> ODR &= ~(1 << 6);
					i = 0;
				}
				else GPIOA -> ODR |= (1 << 6);
			Delay_ms(1);
			i++;
			}
		}
		GPIOA -> ODR |= (1 << 6);
		leitura_k1 = leitura_k0 = 0;
	}
}

void questao26(void) {

	Utility_Init();
	RCC->AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOA->MODER |= (0b01 << 12);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);

	int pos = 500;
	int k1, k0;

	while (1) {

		k1 = !(GPIOE->IDR & (1 << 3));
		k0 = !(GPIOE->IDR & (1 << 4));

		if (k1 && (pos > 500))
			pos -= 10;

		if (k0 && (pos < 2500))
			pos += 10;

		GPIOA->ODR |= (1 << 6);
		Delay_us(pos);
		GPIOA->ODR &= ~(1 << 6);
		Delay_us(20000 - pos);
	}
}

void questao27(void) {

	Utility_Init();
	RCC->AHB1ENR |= (1 << 0) | (1 << 4);
	GPIOA->MODER |= (0B01 << 2) | (0B01 << 4) | (0B01 << 6)
			| (0B01 << 8) | (0B01 << 10) | (0B01 << 12) | (0B01 << 14);
	GPIOE->MODER &= ~(0b11 << 8) & ~(0b11 << 6);
	GPIOA->MODER &= ~(0b11 << 0);
	GPIOE->PUPDR |= (0b01 << 6) | (0b01 << 8);
	GPIOA->PUPDR |= (0b10 << 0);

	while (1) {

		int leitura = !(GPIOA->IDR & (1 << 0));
		if (leitura == 0) {
			GPIOA->ODR = (6 << 1);
			while (GPIOA->IDR & (1 << 0)) {
			}
		}
		Delay_ms(200);

		int leitura2 = GPIOE->IDR & (1 << 4);
		if (leitura2 == 0) {
			GPIOA->ODR = (91 << 1);
			while (GPIOE->IDR & (1 << 4)) {
			}
		}
		Delay_ms(200);

		int leitura3 = GPIOE->IDR & (1 << 3);
		if (leitura3 == 0) {
			GPIOA->ODR = (79 << 1);
			while (GPIOE->IDR & (1 << 3)) {
			}
		}
		Delay_ms(200);
	}
}

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
	Utility_Init();
	questao30();
}
