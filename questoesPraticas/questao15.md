# Question 15

### In this question, the task is to control two 7-segment displays using 2 transistors to perform a decimal/hexadecimal count of 256 possibilities (16x16). In our setup, both displays were connected to the same ports, meaning that if turned on simultaneously, they would display the same results. To avoid this situation, we used a timing function that lasts for 1 second. During this 1 second, the function will rapidly alternate between turning one transistor on and off at a time, giving the false impression that both are connected in parallel, referred to as pseudoparallelism.

#####
### Similar to question 14, we utilized a list of integers representing the binary mask for each digit in the decimal/hexadecimal system. Thus, we created a loop within a loop, resembling a matrix with indices "i" and "j", representing the tens and units, respectively. Consequently, within the second loop, we implemented the timing function to create the impression that the displays are operating together.

```C
/**
  ***************************************************************************************
  * @file    Question-15.c 
  * @author  Gabriel D., Luiz
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Display an ascending/descending decimal/hexadecimal count of two digits on two 7-segment displays.
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
