#include<reg51.h>
sbit switch1=P1^1;
void delay();
void main()
{
unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

int i;
while(1)
{

for(i=0;i<10;i++)
{ 
if(switch1=1)
{
P2=a[i];

delay();




while(switch1==1);
}
}
}
}
void delay()
{
int i=50000;
while(i--);
}