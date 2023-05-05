/*
 * comparador.c
 *
 * Created: 4/24/2023 9:06:34 AM
 * Author: tonys
 */

#include <mega328p.h>

unsigned char X,Y;

void main(void)
{
DDRC.0=1;   //PC0 de salida
DDRC.1=1;   //PC1 de salida
while (1)
    {   
    X=PINB;
    Y=PIND;
    if (X==Y){
        PORTC.0=1;
        PORTC.1=0;
        }
    else
       {
       PORTC.0=0;
       if (X>Y)
          {
          PORTC.1=1; //X>Y
          }
       else
       {
        PORTC.1=0;  //X<Y
       }
       }
    }
}
