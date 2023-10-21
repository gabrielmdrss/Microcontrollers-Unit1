# Questão 15

### Nesta questão, é pedido um acionamento de dois displays de 7 segmentos apartir de 2 transistores, para fazer uma contagem decimal/hexadecimal de 256 possibilidades(16x16). Na nossa montagem, os dois displays foram conectados nas mesmas portas, ou seja, se ligados no mesmo momento, exibiriam os mesmos resultados. Para evitar essa situação, fizemos uso de uma funçao tempo, que tem duração de 1 segundo. Nesse 1 segundo a função irá alternar rapidamente entre ligar e desligar um transistor por vez, dando a falsa impressão que os dois estão ligados paralelamente, denominado pseudoparalelismo.
#####
### Assim como a questão 14, fizemos uso de uma lista de inteiros, representando a máscara em binário de cada digito do sistema decimal/hexadecimal. Assim, fízemos um loop dentro de um loop, para ser uma espécie de matriz, com os indices "i" e "j", retratando as dezenas e as unidades, respectivamente. Desse modo, dentro do segundo loop implementamos a função tempo, para conseguir passar a impressão que os displays estão operando em conjunto.

```C
/**
  ***************************************************************************************
  * @file    Questao-15.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Apresentar uma contagem decimal/hexadecimal em dois displays de 7 segmentos.
  ***************************************************************************************
*/

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


int main(void){
    questao15();
}
```
