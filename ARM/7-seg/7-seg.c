#include<lpc21xx.h>
void delay()
{
int i=50000;
while(i--);	
}
void main()
{
unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i;
IODIR0=0x000000ff;
while(1)
{
for(i=0;i<10;i++)
{
IOSET0=a[i];
delay();
IOCLR0=0x0000000ff;
}
}
}