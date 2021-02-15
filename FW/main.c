/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

int main (void) {

   DDRD |= (1 << PD4);

   while(1) {
       PORTD ^= (1 << PD4);
       _delay_ms(500);
   }

   return 0;
}
