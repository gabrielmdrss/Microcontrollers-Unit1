# Questão 04


```C
/**
  ***********************************************************************************************************
  * @file    Questao-4.c
  * @author  Luiz Neto, Gabriel D.
  * @version V1.0.0
  * @date    09-October-2023
  * @brief   Piscar um LED com largura de pulso fixa de 50ms, mas com frequência crescente, iniciando em 1Hz.
  ***********************************************************************************************************
*/

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

int main(void){
    questao4();
}


```