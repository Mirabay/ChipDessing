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
char arbol[8]={ 0x0E,
  0x0E,
  0x0E,
  0x04,
  0x0E,
  0x15,
  0x04,
  0x04};
char flor[8]={0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x0A,
  0x04,
  0x04};
char cont=0;
char contF=2;
void main(void)
{
    SetupLCD();
    PORTD.0 = 1; //Pullup in PD0
    PORTD.1 = 1; //Pullup in PD1
    CreateChar(0,yo);
    CreateChar(1,yo2);
    CreateChar(2,arbol);
    CreateChar(3,flor);
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
        
    }  
    if (dec>0)
       {
        contF++;
        cont++;
        if (cont>16)
            cont=0;
        if (contF>16)
            cont=0;
        MoveCursor(0,1);
        StringLCD("      ");
        MoveCursor(cont,1);
        CharLCD(2);
        MoveCursor(contF,1);
        CharLCD(2);
        MoveCursor(5,1);
        if(dec%2==0)
            CharLCD(0);
        else
            CharLCD(1);
        
       }
//    if (dec == 0) {
//        //Mover cursor
//        //poner monito 1
//        // Prohibido poner delays
//        //para quitar animacion se pone un espacio
//        
//    }
//    if (dec == 5) {
//        //Mover cursor
//        //poner monito 2
//        
//    }
}   
 