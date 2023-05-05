/*
 * OndasTimer.c
 *
 * Created: 5/4/2023 9:51:50 AM
 * Author: tonys
 */

#include <mega328p.h>
//
//void delay5msT0(){
//    TCCR0B=0x03; //Timer cuenta a una frecuencia de CK/64
//    TCNT0=178;   //256-78 (Cuentas)=178
//    while(TIFR0.0==0); //Esperaa Overflow
//    TIFR0.0=1;   //Apaga el OverFlow
//    TCCR0B=0;    // Apaga el Timer
//}
void delay5msT1(){
    TCCR1B=0x01;        //Timer cuenta a una frecuencia de CK
    TCNT1H=60536>>8;    //
    TCNT1L=60536&0xFF;
    while (TIFR1.0==0);
    TIFR1.0=1;
    TCCR1B=0;
}

void main(void)
{              
    DDRB.0=1;
while (1)
    {
    // Please write your application code here
      PORTB.0=0;
      delay5msT1();
      PORTB.0=1;
      delay5msT1();
    }
}
