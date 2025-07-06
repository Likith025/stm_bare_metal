
#include "stm32f756xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "systick_delay.h"



volatile char key;
int main(void) {
     // Setup UART3
	uart3_tx_rx_init();
	led_init();

	int sec=0;
    // Optional: Confirm UART working

    while (1) {

    //uart3_write(key);
    	printf("one sec passed %d \n \r",sec);
    	systickMs(1000);
    	sec++;


    }
    return 0;
}


