#include "stm32f756xx.h"
#include <stdint.h>
#include <stdio.h>

#define PERIPHERAL_CLK 16000000U
#define BAUDRATE       9600U

void uart3_tx_rx_init(void);
void uart3_write(int ch);
char uart_read(void);
static void set_uart_baudrate(USART_TypeDef *USART, uint32_t peripheral_clk, uint32_t baudrate);
static uint16_t cal_uart_div(uint32_t peripheral_clk, uint32_t baudrate);

int __io_putchar(int ch){
	uart3_write(ch);
	return ch;
}

volatile char key;
int main(void) {
    uart3_tx_rx_init();  // Setup UART3

    // Enable GPIOB for LED on PB7
    RCC->AHB1ENR |= (1 << 1);            // Bit 1 = GPIOB
    GPIOB->MODER &= ~(3 << 14);          // Clear MODER7 bits
    GPIOB->MODER |=  (1 << 14);          // Set PB7 to Output

    // Optional: Confirm UART working
    printf("UART ready. Send 'l' to turn ON LED, any other key to turn OFF.\r\n");

    while (1) {
        char key = uart_read();          // Wait for input from PuTTY

        if (key == 'l' || key == 'L') {
            GPIOB->ODR |= (1 << 7);      // Turn LED ON
        } else {
            GPIOB->ODR &= ~(1 << 7);     // Turn LED OFF
        }
        uart3_write(key);
    }
    //uart3_write(key);

    return 0;
}

void uart3_tx_rx_init(void) {
    /***** GPIOD8 = USART3_TX (AF7) Setup *****/
    RCC->AHB1ENR |= (1 << 3);            // Enable GPIOD clock

    GPIOD->MODER &= ~(1 << 16);           // Clear PD8 mode bits
    GPIOD->MODER |=  (1 << 17);           // Set PD8 to alternate function mode (10)

    GPIOD->AFR[1] &= ~(0xF << 0);        // Clear AFRL for PD8
    GPIOD->AFR[1] |=  (7 << 0);          // AF7 = USART2

    /**********GPIO D9=USART_RX (AF7) Setup********/
    GPIOD->MODER &= ~(1 << 18);           // Clear PD8 mode bits
    GPIOD->MODER |=  (1 << 19);           // Set PD8 to alternate function mode (10)

    GPIOD->AFR[1] &= ~(0xF << 4);        // Clear AFRL for Pd9
    GPIOD->AFR[1] |=  (7 << 4);


    /***** USART2 Setup *****/
    RCC->APB1ENR |= (1 << 18);           // Enable USART2 clock

    set_uart_baudrate(USART3, PERIPHERAL_CLK, BAUDRATE);

    USART3->CR1 = USART_CR1_TE | USART_CR1_UE | USART_CR1_RE ; // Enable Transmitter & USART
}

void uart3_write(int ch) {
    while (!(USART3->ISR & (1 << 7)));   // Wait until TXE is set
    USART3->TDR = (ch & 0xFF);           // Write data
}
char uart_read(void){
	  while (!(USART3->ISR & (1 << 5))){}  // Wait until rXE is set
return USART3->RDR;           // Read data

}
static void set_uart_baudrate(USART_TypeDef *USART, uint32_t peripheral_clk, uint32_t baudrate) {
    USART->BRR = cal_uart_div(peripheral_clk, baudrate);
}

static uint16_t cal_uart_div(uint32_t peripheral_clk, uint32_t baudrate) {
    return ((peripheral_clk + (baudrate / 2U)) / baudrate); // Rounded BRR
}

