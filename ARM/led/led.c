#include<lpc21xx.h>
#include<serial.h>
void delay()
{
int i=50000;
while(i--);
}
void main()
{
IODIR0=0xffffffff ;
PINSEL0&=~0x0f;

IODIR1=0xffffffff ;
//IOCLR1=0xffffffff ;
//IOCLR0=0xffffffff ;

while(1)
{
IOSET1=0xffff<<16 ;
IOSET0=0xffffffff ;
delay();
delay();
delay();
IOCLR1=0xffff <<16;
IOCLR0=0xffffffff ;
delay();
delay();
delay();
}
}