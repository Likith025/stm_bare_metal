
#include "stm32f756xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"



volatile char key;
int main(void) {
     // Setup UART3
	uart3_tx_rx_init();
	led_init();
    // Enable GPIOB for LED on PB7
//    RCC->AHB1ENR |= (1 << 1);            // Bit 1 = GPIOB
//    GPIOB->MODER &= ~(3 << 14);          // Clear MODER7 bits
//    GPIOB->MODER |=  (1 << 14);          // Set PB7 to Output

    // Optional: Confirm UART working
    printf("UART ready. Send 'l' to turn ON LED, any other key to turn OFF.\r\n");

    while (1) {
        char key = uart_read();         // Wait for input from PuTTY

        if (key == 'l' || key == 'L') {
            GPIOB->ODR |= (1 << 7);      // Turn LED ON
        } else {
            GPIOB->ODR &= ~(1 << 7);     // Turn LED OFF
        }
        printf("%c\n\r",key);
    }
    //uart3_write(key);

    return 0;
}

