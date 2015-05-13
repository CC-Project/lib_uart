#include <avr/io.h>

void uart_init(uint16_t baud);
void uart_tx_char(char c);
void uart_tx_str(int8_t* str); // Prints a string
void uart_newline(void); // Prints a newline on the uart
