#include<reg51.h>
void timer_delay();
void main()
{
TMOD=0x01;
while (1)
{
timer_delay();
P2=0x00;
timer_delay();
P2=0xff;
}
}
void timer_delay()
{int i=0;
for(i=0;i<20;i++)
{
TH0=0x4c;
TL0=0x00;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;

TH0=0x4c;
TL0=0x00;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
 }
}
