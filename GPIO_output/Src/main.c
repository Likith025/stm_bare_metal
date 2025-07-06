 #include "stm32f756xx.h"

// direct led PB 14
//BSR LED PB  7
int main(){
	RCC->AHB1ENR |=0x2;
	GPIOB->MODER &= ~(3<<(28));
	GPIOB->MODER |=(1<<28);
	GPIOB->MODER &= ~(3<<(14));
	GPIOB->MODER |=(1<<14);

	while(1){
		GPIOB->ODR ^=(1<<14);
		for(int i=0;i<1000000;i++);
		GPIOB->BSRR |=(1<<7);
		for(int i=0;i<1000000;i++);
		GPIOB->BSRR |=(1<<23);
		for(int i=0;i<5000000;i++);
	}

}
