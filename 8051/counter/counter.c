#include<reg51.h>
sbit sw=P3^4;
void main()
{
TMOD=0x05;

	

TR0=1;
while(1)
{
P2=TH0;
P1=TL0;



}
}