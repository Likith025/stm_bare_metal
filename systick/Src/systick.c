#include"stm32f756xx.h"
// Systick is a core arm peripheral all its details is found in arm user guide not in stm ref manual

// DELAY=(LOAD)/SYSTEM_CLK freq

#define SYSTICK_LOAD	16000
#define	CTRL_ENABLE		(1<<0)
#define	CTRL_CLKSRC		(1<<2)
#define	CTRL_COUNTFLAG	(1<<16)

void systickMs(int delay){
	//SETTING LOAD
	SysTick->LOAD=SYSTICK_LOAD;
	SysTick->VAL=0;
	//ENABLING SYSTICK TIMMER AND SETTING UP INTERNAL CLOCK
	SysTick->CTRL=CTRL_ENABLE | CTRL_CLKSRC;

	for(int i=0;i<delay;i++){
		while(!(SysTick->CTRL & CTRL_COUNTFLAG));

	}

	SysTick->CTRL=0;
}
