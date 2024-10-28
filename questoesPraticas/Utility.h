/*
 * Utility.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Prof. Dr. Fagner de Araujo Pereira
 */

#ifndef UTILITY_H_
#define UTILITY_H_

//Declarations of utility functions
void Utility_Init(void);            //initialization of library functions
void Configure_Clock(void);         //clock system configuration
void TIM2_Setup(void);              //Timer2 setup as 1us time base
void Delay_us(uint32_t delay);      //delay in microseconds
void Delay_ms(uint32_t delay);      //delay in milliseconds

//Initialization of library functions
void Utility_Init(void)
{
    Configure_Clock();   //initializes the clock system
    TIM2_Setup();        //configures Timer2 as 1us time base
}

//Clock system configuration for maximum speed on all buses
//external crystal of 8MHz and 168 MHz HCLK
void Configure_Clock(void)
{
    //Main PLL parameters
    #define PLL_M    4
    #define PLL_N    168
    #define PLL_P    2
    #define PLL_Q    7

    //Resets the RCC module registers to the initial state
    RCC->CIR = 0;                //disables all RCC interrupts
    RCC->CR |= RCC_CR_HSION;     //turns on the HSI oscillator
    RCC->CFGR = 0;               //resets the CFGR register
    //Turns off HSE, CSS, PLL, and HSE bypass
    RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_CSSON |
               RCC_CR_PLLON | RCC_CR_HSEBYP);
    RCC->PLLCFGR = 0x24003010;   //resets the PLLCFGR register

    //Configures the clock source (HSE), PLL parameters,
    //prescalers for AHB and APB buses
    RCC->CR |= RCC_CR_HSEON;                //enables HSE
    while(!((RCC->CR) & RCC_CR_HSERDY));    //waits for HSE to be ready
    RCC->CFGR |= 0x9400;    //HCLK = SYSCLK/1, PCLK2 = HCLK/2, PCLK1 = HCLK/4

    //Configures the clock source and main PLL parameters
    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                   (0x400000)           | (PLL_Q << 24);

    RCC->CR |= RCC_CR_PLLON;            //enables the PLL
    while(!(RCC->CR & RCC_CR_PLLRDY));  //waits for PLL to be ready by checking the PLLRDY flag

    RCC->CFGR |= 0x2;                   //selects the PLL as SYSCLK source
    while((RCC->CFGR & 0xC) != 0x8);    //waits for PLL to be the SYSCLK source
}

//Sets up Timer 2 as a 1us time base
void TIM2_Setup(void)
{
    //The default mode of the counter is up-counting
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //enables Timer2 clock
    TIM2->PSC = 83;                     //prescaler for increments every 1uS
    TIM2->EGR = TIM_EGR_UG;             //update event to write the prescaler value
    TIM2->CR1 |= TIM_CR1_CEN;           //enables the timer
}

//Microsecond delay creation
void Delay_us(uint32_t delay)
{
    TIM2->CNT = 0;             //initializes the counter to 0
    while(TIM2->CNT < delay);  //waits for the time to pass
}

//Millisecond delay creation
void Delay_ms(uint32_t delay)
{
    uint32_t max = 1000 * delay;
    TIM2->CNT = 0;             //initializes the counter to 0
    while(TIM2->CNT < max);    //waits for the time to pass
}

#endif /* UTILITY_H_ */
