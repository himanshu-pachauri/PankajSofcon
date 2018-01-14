#include<lpc214x.h>
void delay()
{
int i=5000;
while(i--);
}
void main()
{
PINSEL1=(1<<24);
VPBDIV=0x01;
IODIR1=0xffff0000;
//AD0DR1=0x01;
//AD0CR=(1<<21)|(1<<1);
AD0CR=(0x02)|(100<<8)|(1<<21);
while(1)
{
AD0CR|=(1<<24);
//AD0GDR=(1<<24);
while(((AD0GDR&(1<<31))==0));
///AD0GDR=1;
IOPIN1=(AD0GDR<<9);
}
}
