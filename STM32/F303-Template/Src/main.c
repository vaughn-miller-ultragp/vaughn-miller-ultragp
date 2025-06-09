/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vaughn Miller
 * @brief          : Template with blinky code
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f3xx.h"

#define INPUT_MODE  0
#define OUTPUT_MODE 1
#define AF_MODE     2
#define ANALOG_MODE 3


/*
    General Peripheral Activation Procedure:

    1. Enable peripheral clock in RCC

    2. Do peripheral-specific config

    3. Start peripheral
*/

/*
    Starts GPIO, sets single port output to OUTPUT and sets output HIGH
*/
static void startGPIO(void)
{
    RCC->AHBENR     |= RCC_AHBENR_GPIOEEN;
    GPIOE->MODER    |= (OUTPUT_MODE << GPIO_MODER_MODER8_Pos);
    GPIOE->ODR      |= GPIO_ODR_8;

}


//  TIM6_DACUNDER_IRQHandler = pos. 54

/*
    Starts TIM6
*/
static void startTIM(void)
{
    //Enable TIM6 Clock Source
    RCC->APB1ENR     |= RCC_APB1ENR_TIM6EN;  
    
    //Enable interrupt as a result of an Update Event (Overrun, Underrun, Update Gen. bit, etc.)
    TIM6->DIER      |= TIM_DIER_UIE;

    NVIC_SetPriority(54, 2);
    NVIC_EnableIRQ(54);

    
    //Auto Reload Register Value, where the counter stops and then resets to 0
    TIM6->ARR       = 20000;
    //Prescalar register, which divides the clock source by its amount
    TIM6->PSC       = 2200;
    //Clear Event Status flag
    TIM6->SR        &= ~(TIM_SR_UIF); 
    
    TIM6->EGR       |= TIM_EGR_UG;
    //Start Counter
    TIM6->CR1       &= ~(TIM_CR1_CEN);

}



int main(void)
 {

    startGPIO();
    startTIM();

    TIM6->CR1       |= TIM_CR1_CEN;
    
    while(1){

    }
}

// TIMER 6 Interrupt Handler 
void TIM6_DACUNDER_IRQHandler(void)
{
    TIM6->SR = ~(TIM_SR_UIF);   // clear Update Interrupt flag
    GPIOE -> ODR ^= GPIO_ODR_8; // toggle PE8
    
}
