# Question 19

## In question 19, a relay is activated from a load in direct current (DC) of 5V.

## Setup:
The relay used in this question is a 1-channel 5V relay. To connect it to the STM32, three connections were established: the VCC output of the relay was connected to the 5V output of the STM32, the GND of the relay was connected to any GND terminal of the microcontroller, and the "IN" output was connected to pin PA6.

## Code:
This code is simple; the only exception was exclusively in activating pin PA6 in Open-Drain mode. Open-Drain is necessary in this case because it allows the control of relays with different operating voltages, as the high level is determined by the relay's supply voltage and the external pull-up resistor, not by the voltage level of the microcontroller.

````C 
/**
  ******************************************************************************
  * @file    Question-21.c 
  * @author  Gabriel D, Luiz Neto 
  * @version V1.0.0
  * @date    05-October-2023
  * @brief   Switch an AC load at 220V using a relay.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "Utility.h"

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

int main(void){
    questao19();
}
````
