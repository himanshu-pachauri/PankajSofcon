#include<reg51.h>
sbit switch1=P1^1;
void delay();
void main()
{

while(1)
{if(switch1==0)
{
P2=0x11;

}
else
P2=0x00;
}

}
void delay()
{
int i=50000;
while(i--);
}