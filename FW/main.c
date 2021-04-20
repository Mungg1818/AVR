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

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
// #include <util/delay.h>

/**
 * @brief 
 * 
 */
volatile uint32_t ulTick = 0;
volatile uint8_t ucMsTickEvent = 0u;

/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    static uint32_t ulMsTickCount = 0u;

    clock_prescale_set(clock_div_1);

    DDRD |= (1 << PD4 | 1 << PD5 | 1 << PD6 | 1 << PD7);
    PORTD ^= (1 << PD7);

    // TCCR0B |= (1 << CS01);
    // TIMSK0 |= (1 << TOIE0);

    OCR1AH = 0x1F;
    OCR1AL = 0x40;
    TCCR1B |= (1 << WGM12 | 1 << CS00);
    TIMSK1 |= (1 << OCIE1A);

    sei();

    while (1)
    {
        if (0u != ucMsTickEvent)
        {
            ucMsTickEvent = 0u;
            ulMsTickCount++;
            if (0 == ulMsTickCount % 500u)
            {
                PORTD ^= (1 << PD4);
                // usLed = 0u;
            }
            // if (usLed >= 2u)
            // {
            //     PORTD ^= (1 << PD5);
            // }
            // if (ulTick >= 0x10000){
            //     PORTD ^= (1 << PD6);
            // }
        }
    }

    return 0u;
}

/**
 * @brief Construct a new ISR object
 * 
 */
ISR(TIMER1_COMPA_vect)
{
    // ulTick++;
    // if (0 == (ulTick % 4))
    // {
        ucMsTickEvent = 0x01u;
    // }
    // if (0 == ulTick % 500)
    // {
    //     PORTD ^= (1 << PD4);
    // }
}
