#include<lpc21xx.h>
void delay()
{
int i=50000;
while(i--);
}
void main()
{
IODIR0=0xffffffff;
while(1)
{
IOSET0=0xffffffff;
delay();
IOCLR0=0xffffffff;
delay();
}
}