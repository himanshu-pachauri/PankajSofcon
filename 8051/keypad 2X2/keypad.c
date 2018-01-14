#include<reg51.h>
void delay()
{
int i=50000;
while(i--);
}
void main()
{
int i,j;
while(1)
{
P2=0x03;
while(P2==0x03);
i=P2;
P2=0x0c;
while(P2==0x0c);
j=P2;
j=j>>2;
if((i==0x02)&&(j==0x02))
{
P1=0x0a;
delay();
}
if((i==0x01)&&(j==0x02))
{
P1=0x08;
delay();
}
if((i==0x02)&&(j==0x01))
{
P1=0x0f;
delay();
}
if((i==0x01)&&(j==0x01))
{
P1=0xf0;
delay();
}
}
}