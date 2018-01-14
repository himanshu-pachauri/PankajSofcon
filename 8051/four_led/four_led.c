#include<reg51.h>
void delay();
void main()
{
while(1)
{
P2=0x00;
delay();
P2=0x81;
delay();
P2=0x42;
delay();
P2=0x24;
delay();
P2=0x18;
delay();
P2=0x18;
delay();
P2=0x24;
delay();
P2=0x42;
delay();
P2=0x81;
delay();
}
}
void delay()
{
int i=50000;
while(i--);
}
