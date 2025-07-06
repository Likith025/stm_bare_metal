/*
 * uart.h
 *
 *  Created on: Jul 6, 2025
 *      Author: likith
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f756xx.h"
#include <stdint.h>
#include <stdio.h>

char uart_read(void);
void uart3_tx_rx_init(void);
void led_init(void);

#endif /* UART_H_ */
