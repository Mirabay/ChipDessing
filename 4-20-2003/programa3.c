
/*
 * programa3.c
 *
 * Created: 4/20/2023 9:29:22 AM
 * Author: tonys
 */

#include <mega328p.h>
#include <delay.h>

bit encendido=0;

void main(void)
{
    DDRB.1=1;
    PORTB.0=1;
while (1)
    {
    // Please write your application code here
    if (PINB.0==0)
       { 
        encendido=~encendido;
        PORTB.1=encendido;
        delay_ms(30);   //retardo del rebote de presionar 
        while (PINB.0==0); //ESPERA A SOLTAR SWITCH
        delay_ms(10);
        
        delay_ms(125);
        PORTB.1=0;
        delay_ms(125);
       }
    }
}
