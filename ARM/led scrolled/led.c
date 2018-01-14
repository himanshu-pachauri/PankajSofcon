#include<lpc21xx.h>
void delay()
{
int i=5000;
while(i--);
}
void main()
{
int i=0,j=0;
IODIR0=0xffffffff;
while(1)
{
for(i=0;i<27;i++)
{
IOSET0=(1<<i)|j;
delay();
IOCLR0=0xffffffff;
delay();
}
}
}