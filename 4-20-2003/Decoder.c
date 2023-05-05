/*
 * Decoder.c
 *
 * Created: 4/24/2023 8:30:09 AM
 * Author: tonys
 */

#include <mega328p.h>

unsigned char SieteSeg[16]={0xFC,0x60,0xDB,0xF3,0x66,0xB7,0xBE,0xE1,
                            0xFE,0xF6,0xEE,0x3F,0x9C,0x7B,0x9E,0x8E};   
unsigned char dato;

void main(void)
{
    PORTC=0x0F; //pull-ups en PC0 a PC3
    DDRD=0xFF;  //PD0 a PD7 de salida
while (1)
    {
     dato=PINC & 0x0F;   //mascara
     PORTD=SieteSeg[dato];
    }
}
