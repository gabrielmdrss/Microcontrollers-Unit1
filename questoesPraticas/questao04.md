# Questão 04

### Nesta questão é pedido um acionamento de um LED com largura de pulso fixa de 50ms, mas com uma frequência crescente. Podemos inferir que com o aumento da frequência levará a diminuição do período, ocasionando em uma aceleração do ciclo. Com frequência inicial de 1Hz temos que o período inicial é de 1s. Fizemos uso de um laço de repetição onde através da variável "tempo", a cada iteração ocorria um aumento linear da frequência, até o ponto que a largura total fosse apenas os 50ms fixos. Após isso, reiniciando a sequência e fazendo tudo novamente.
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
