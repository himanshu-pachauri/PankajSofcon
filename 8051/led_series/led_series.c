#include<reg51.h>
void delay();
void main()
{
while(1)
{
P2=0x00;
delay();
P2=0x03;
delay();
P2=0x0c;
delay();
P2=0x30;
delay();
P2=0xc0;
delay();
P2=0xc0;
delay();
P2=0x30;
delay();
P2=0x0c;
delay();
P2=0x03;
delay();
}
}
void delay()
{
int i=50000;
while(i--);
}
