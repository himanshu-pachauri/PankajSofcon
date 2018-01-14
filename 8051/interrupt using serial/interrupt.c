#include<reg51.h>
void delay()
{
int i=50000;
while(i--);
}
void com() interrupt  4
{
if(RI==1)
{
P2=SBUF;
RI=0;
}
}
void main()
{  
TMOD=0x20;
TH1=0xfd;
TR1=1;
SCON=0x50;
IE=0x91;
while(1)
{
P1=~P1;
delay();
}
}