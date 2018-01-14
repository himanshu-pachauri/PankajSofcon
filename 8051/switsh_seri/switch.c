#include<reg51.h>
sbit switch1=P1^1;
void delay();
void main()
{
int i=0,j=0;
while(1)
{
for(i=0;i<8;i++)
{
if(switch1==0)
{
P2=(1<<i)|j;
delay();
}
else if(switch1==1)
P2=(128>>i)|j;
delay();
}
}
}
void delay()
{
int i=50000;
while(i--);
}