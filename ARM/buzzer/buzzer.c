#include<lpc21xx.h>
void delay()
{
int i=5000;
while(i--);
}
void main()
{
IODIR0=0x0000000f;
while(1)
{
IOSET0=0x0000000f;
delay();
IOCLR0=0x0000000f;
delay();
}
}