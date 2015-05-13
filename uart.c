#include "uart.h"

void uart_init(uint16_t baud)
{
    UBRR0L = baud;
    UCSR0C = (1 << UCSZ00 ) | (1 << UCSZ01 ); // 8 bits characters,
    UCSR0B = (1 << RXEN0 ) | (1 << TXEN0 ); // Turn on the transmission and reception circuitry
}

void uart_tx_char(char c)
{
    while( !(UCSR0A & (1 << UDRE0)) ); // Wait until UDR empty
    UDR0 = c;
}

void uart_tx_str(int8_t* str)
{
    while(*str)
        uart_tx_char(*str++);
}

void uart_newline(void)
{
    uart_tx_char('\r');
    uart_tx_char('\n');
}
