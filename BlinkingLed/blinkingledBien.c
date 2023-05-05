/*
 * blinkingledBien.c
 *
 * Created: 4/18/2023 10:52:32 AM
 * Author: tonys
 */

#include <mega328p.h>
#include <delay.h>

void main(void)
{
    DDRB.0=1; //COnfigura de salida PB0
while (1)
    {
    // Please write your application code here
                                     
    PORTB.0=0; //APAGA LED
    delay_ms(500);
                                      
    PORTB.0=1; //PRENDE LED
    delay_ms(500);
    }
}
