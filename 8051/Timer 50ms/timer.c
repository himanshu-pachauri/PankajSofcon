#include<reg51.h>
void main()
{
TMOD=0x02;
TH0=256-4;
while(1)
{
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
P2=0x00;

TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
P2=0xff;
}
}