#include "stm32f756xx.h"
#include <stdint.h>

#define PERIPHERAL_CLK 16000000U
#define BAUDRATE       9600U

void uart3_tx_init(void);
void uart3_write(int ch);
static void set_uart_baudrate(USART_TypeDef *USART, uint32_t peripheral_clk, uint32_t baudrate);
static uint16_t cal_uart_div(uint32_t peripheral_clk, uint32_t baudrate);

int main(void) {
    uart3_tx_init();

    while (1) {
        uart3_write('l');

    }

    return 0;
}

void uart3_tx_init(void) {
    /***** GPIOD8 = USART3_TX (AF7) Setup *****/
    RCC->AHB1ENR |= (1 << 3);            // Enable GPIOD clock

    GPIOD->MODER &= ~(1 << 16);           // Clear PD8 mode bits
    GPIOD->MODER |=  (1 << 17);           // Set PD8 to alternate function mode (10)

    GPIOD->AFR[1] &= ~(0xF << 0);        // Clear AFRL for PB10
    GPIOD->AFR[1] |=  (7 << 0);          // AF7 = USART2

    /***** USART2 Setup *****/
    RCC->APB1ENR |= (1 << 18);           // Enable USART2 clock

    set_uart_baudrate(USART3, PERIPHERAL_CLK, BAUDRATE);

    USART3->CR1 = USART_CR1_TE | USART_CR1_UE; // Enable Transmitter & USART
}

void uart3_write(int ch) {
    while (!(USART3->ISR & (1 << 7)));   // Wait until TXE is set
    USART3->TDR = (ch & 0xFF);           // Write data
}

static void set_uart_baudrate(USART_TypeDef *USART, uint32_t peripheral_clk, uint32_t baudrate) {
    USART->BRR = cal_uart_div(peripheral_clk, baudrate);
}

static uint16_t cal_uart_div(uint32_t peripheral_clk, uint32_t baudrate) {
    return ((peripheral_clk + (baudrate / 2U)) / baudrate); // Rounded BRR
}
