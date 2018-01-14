#include<lpc214x.h>
void delay()
{
int i=5000;
while(i--);
}
int main()
{
PINSEL1=(1<<13);
VPBDIV=0x01;
IODIR1=0xffff0000;
AD1CR=(0x01)|(100<<8)|(1<<21);
while(1)
{
AD1CR|=(1<<24);
while((AD1GDR&(1<<31))==0);
IOPIN1=(AD1GDR<<9);
}
}
