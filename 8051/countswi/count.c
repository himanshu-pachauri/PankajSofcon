#include<reg51.h>
sbit switch1=P1^1;
void delay();
void main()
{int i=0;
while(1)
{
   if(switch1==0)
   {
   i++;
   P2=i;
   while(switch1==0);
   }




}
}
void delay()
{
int i=50000;
while(i--);
}