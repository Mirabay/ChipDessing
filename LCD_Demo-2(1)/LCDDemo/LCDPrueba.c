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
               
char car0[8]={0x00,0x0A,0x15,0x11,0x0A,0x04,0x00,0x00};
char car1[8]={0x1F,0x00,0x1F,0x00,0x1F,0x00,0x1F,0x00};    

void main()
{
    SetupLCD(); 
    CreateChar(0,car0);  
    CreateChar(1,car1);
       
    MoveCursor(5,0);
    StringLCD("Micros");  
    MoveCursor(5,1);
    StringLCD2("Rules!",150);
    UnderscoreCursor();
    delay_ms(3000);
    NoUnderscoreCursor();  
    delay_ms(3000);
    BlinkCursor();  
    delay_ms(3000);
    NoBlinkCursor(); 
    CharLCD(0);
    CharLCD(1);
    while(1)
    {
    }              
}
