/*
 * ALU.c
 *
 * Created: 4/24/2023 10:07:02 AM
 * Author: tonys
 */

#include <mega328p.h>

unsigned char A,B,op;
void main(void)
{
    DDRD=0x1F; //PD0 a PBD4 de salida
    while (1)
    {
        op=PINC&0x07; //mascara
        A=PINB&0x0F;
        B=PINB>>4;//Corrimiento de 4 posiciónes
        switch (op)
               {
               case 0:
                    PORTD=~A; //NOT A
               break;

               case 1:
                    PORTD=A&B;  // A AND B
               break;
               
               case 2:
               PORTD=~(A&B);  // A AND B
               break; 
               
               case 3:
                     PORTD= A|B;
               break;
               }
    }
}
