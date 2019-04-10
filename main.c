/*
 */

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

volatile int Flag1=0, Flag2=0;
int main(void)
{
    DDRD&=~(1<<2);
    DDRD&=~(1<<3);
    PORTD|=(1<<2);
    PORTD|=(1<<3);

    DDRB|=(1<<PB0);
    DDRB|=(1<<PB1);
    EICRA|=(1<<ISC00);
    EICRA|=(1<<ISC10);
    EIMSK|=(1<<INT0);
    EIMSK|=(1<<INT1);
    sei();

    while(1)
    {
        if(Flag1==1)
        {
         PORTB|=(1<<0);
         _delay_ms(2000);
         Flag1=0;
        }
        else
        {
         PORTB&=~(1<<0);
        }

        if(Flag2==1)
        {
         PORTB|=(1<<1);
         _delay_ms(2000);
         Flag2=0;
        }
        else
        {
         PORTB&=~(1<<1);
        }
    }
    return 0;
}
ISR(INT0_vect)
{
    Flag1=1;
}
ISR(INT1_vect)
{
    Flag2=1;
}
