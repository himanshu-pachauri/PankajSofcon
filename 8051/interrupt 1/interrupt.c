#include<reg51.h>
void delay()
{
int i=5000;
while(i--);
}

void ex1() interrupt 2
{
P2=~P2;
}
void main()
{
IE=0x84;
while(1)
{
	   P1=0xff;
	   delay();
	   P1=0x00;
	   delay();
}
}