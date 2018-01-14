#include<reg51.h>
void delay()
{
int i=50000;
while(i--);
}

void ex0() interrupt 0
{
P2=~P2;
}
void main()
{
IE=0x81;
while(1)
{
	   P1=0xff;
	   delay();
	   P1=0x00;
	   delay();
}
}