#include<lpc21xx.h>
void delay()
{
int i=50;
while(i--);	
}
void main()
{
unsigned char a[12]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i,j,b;
IODIR0=0x00000fff;
while(1)
{
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
for(b=0;b<500;b++)
{
IOPIN0=0x00000100;
IOSET0=a[j%10];
delay();
IOCLR0=0x0000000ff;
delay();
IOPIN0=0x00000200;
IOSET0=a[i%10];
delay();
IOCLR0=0x0000000ff;
delay();
}
}
}
}
}