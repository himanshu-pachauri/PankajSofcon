#include<reg51.h>
void delay();
void main()
{
TMOD=0x20;
TH1=-3;
TR1=1;
SCON=0x50;

while(1)
{
SBUF='A';
while(TI==0);
TI=0;
delay();
while(1);
}
}
void delay()
{
int i=50000;
while(i--);
}