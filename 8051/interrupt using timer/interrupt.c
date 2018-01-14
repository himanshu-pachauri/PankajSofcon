#include<reg51.h>
void delay()
{
int i=50000;
while(i--);
}
void ex0() interrupt 1
{TH0=0xfc;
TL0=0x69;
P1=~P1;
}
void main()
{
IE=0x83;
TMOD=0x01;
TR0=1;
while(1)
{
P2=~P2;
delay();
}
}