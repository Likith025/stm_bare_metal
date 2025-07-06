
//LED is at PB14
#include <stdint.h>

#define PERIPHERAL_BASE	      		(0x40000000ul)
#define	AHB1_OFFSET			  		(0x20000ul)
#define AHB1_BASE					(PERIPHERAL_BASE + AHB1_OFFSET)

#define GPIO_B_OFFSET				(0x400ul)
#define	GPIO_B_BASE					(AHB1_BASE + GPIO_B_OFFSET)

#define	GPIOx_MODER_OFFSET			(0x0ul)
#define GPIOx_ODR_OFFSET			(0x14ul)

#define	RCC_OFFSET					(0x3800ul)
#define	RCC_BASE					(AHB1_BASE + RCC_OFFSET)

#define RCC_AHB1ENR_OFFSET			(0x30ul)

#define	RCC_AHB1ENR_reg				(*(volatile unsigned int *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define	GPIO_B_MODER_reg			(*(volatile unsigned int *)(GPIO_B_BASE + GPIOx_MODER_OFFSET))
#define GPIO_B_ODR_reg				(*(volatile unsigned int *)(GPIO_B_BASE + GPIOx_ODR_OFFSET))

int main(void)
{
	RCC_AHB1ENR_reg |=(1<<1);
	GPIO_B_MODER_reg &= ~(3<<(28));
	GPIO_B_MODER_reg |=(1<<28);
	GPIO_B_ODR_reg |=(1<<14);

	while(1){
		GPIO_B_ODR_reg ^=(1<<14);
		for(int i=0;i<1000000;i++);
	}

}
