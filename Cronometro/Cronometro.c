   #asm
    .equ __lcd_port=0x05
    .equ __lcd_EN=1
    .equ __lcd_RS=0
    .equ __lcd_D4=2
    .equ __lcd_D5=3
    .equ __lcd_D6=4
    .equ __lcd_D7=5
   #endasm

#include <io.h>
#include <delay.h>
#include <display.h>  
#include <mega328p.h>
#include <stdio.h>

unsigned char min = 0, seg = 0, dec = 0;
char cont=0;
char cadena[17];
char yo[8]={ 0x0E,
  0x0A,
  0x0E,
  0x04,
  0x0E,
  0x15,
  0x04,
  0x0A};
char yo2[8]={ 0x0E,
  0x0E,
  0x0E,
  0x04,
  0x0E,
  0x15,
  0x04,
  0x04}; 
  



void main(void)
{
    SetupLCD();
    PORTD.0 = 1; //Pullup in PD0
    PORTD.1 = 1; //Pullup in PD1
    CreateChar(0,yo);
    CreateChar(1,yo2);
while (1)
    {
        sprintf(cadena, "%02i:%02i.%i", min, seg, dec);
        MoveCursor(4,0);
        StringLCDVar(cadena);
        delay_ms(62);
        delay_us(520);
        if (PIND.0 == 0)
            ++dec;
        if (PIND.1 == 0){
            dec = 0;
            min = 0;
            seg = 0;
        }
        if (dec == 10){
            dec = 0;
            ++seg;
        }
            if (seg == 0){
                seg = 0;
                ++min;
            }
                if (min = 60)
                    min = 0;
        

    if (((dec%2)!=0)&& PIND.0==0) {
        //Limpiamos la parte de abajo
        MoveCursor(0,1);
        StringLCD("                ");
        //Movemos el cursor
        cont=cont+1;
        MoveCursor(cont,1);
        CharLCD(0);
    }
    if (((dec%2)==0)&& PIND.0==0) {
        //Limpiamos la parte de abajo
        MoveCursor(0,1);
        StringLCD("                ");
        cont=cont+1;
        MoveCursor(cont,1);
        CharLCD(1);
        if (cont==16)
            cont=0;
    }
    
   
 }
}   
 