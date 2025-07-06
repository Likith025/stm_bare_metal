#include "stm32f756xx.h"

int main(void){
	RCC->AHB1ENR |=0x6; //setting up 1st and 3rd bit (0x101) both B and C
	GPIOB->MODER &= ~(3<<(14));
		GPIOB->MODER |=(1<<14);

	GPIOC->MODER &=(~(3<<13)); //button PC13

	while(1){
		if(GPIOC->IDR &(1<<13)){

			GPIOB->BSRR |=(1<<7);

		}
		else{
			GPIOB->BSRR |=(1<<23);
		}
	}
}
