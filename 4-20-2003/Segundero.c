/*
 * Segundero.c
 *
 * Created: 4/24/2023 8:50:20 AM
 * Author: tonys
 */

#include <mega328p.h>
#include <delay.h>

unsigned char SieteSeg[10]={0xFC,0x60,0xDB,0xF3,0x66,0xB7,0xBE,0xE1,
                            0xFE,0xF6};   
unsigned char seg=0;

void main(void)
{
    PORTC=0x0F; //pull-ups en PC0 a PC3
    DDRD=0xFF;  //PD0 a PD7 de salida
while (1)
    {
     PORTD=SieteSeg[seg];
     if (PINC.0==0)
        seg++;
     if (seg==10)
        seg=0;
     delay_ms(1000);
    }
}

