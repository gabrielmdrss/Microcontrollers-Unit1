# Question 04

### In this question, the task is to activate an LED with a fixed pulse width of 50ms, but with an increasing frequency. We can infer that as the frequency increases, the period decreases, resulting in an acceleration of the cycle. With an initial frequency of 1Hz, we have an initial period of 1s. We use a loop where, through the variable "time," a linear increase in frequency occurs at each iteration, until the total width is only the fixed 50ms. After that, the sequence restarts and everything is done again.
```C
/**
  ***********************************************************************************************************
  * @file    Question-4.c
  * @author  Gabriel D., Luiz Neto
  * @version V1.0.0
  * @date    05-October-2023
  * @brief  Blink an LED with a pulse width of 50ms, but with an increasing frequency, starting at 1Hz.
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
