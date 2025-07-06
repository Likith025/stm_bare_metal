//LED connnected to PB7


#define PERIPHERALS_BASE	(0x40000000ul)
#define AHB1_OFFSET			(0x00020000ul)

#define AHB1_PERIPH_BASE	(PERIPHERALS_BASE+AHB1_OFFSET)




#include <stdint.h>

void delay(){
	for(uint32_t i=0;i<=500000;i++);
}


int main(void)
{

	uint32_t *pClk= (uint32_t *)(0x40023830);
	uint32_t *pPinmode=(uint32_t *)(0x40020400);
	uint32_t *pOpdata=(uint32_t *)(0x40020414);

	*pClk|=1<<1;
	*pPinmode&=~(3<<12);
	*pPinmode|=(1<<14);
	*pOpdata|=(1<<7);
	while(1){
		delay();
		*pOpdata^=(1<<7);
	}
}
