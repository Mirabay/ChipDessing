/*
 * programa1.c
 *
 * Created: 4/20/2023 9:22:02 AM
 * Author: tonys
 */

#include <mega328p.h>

void main(void)
{
    DDRB.1=1;   //PB1 de salida
    PORTB.0=1;  //PULL UP en PB0
while (1)
    {
    // Please write your application code here
     if (PINB.0==0)
         PORTB.1=1;
     else
        PORTB.1=0;
    }
}
