#include<reg51.h>
sbit ss1=P1^0;
sbit ss2=P1^1;
sbit switch1=P1^3;
sbit switch2=P1^4;
 void delay()
 {
 
 int i=50;
 while(i--);
 }
void main()
{
unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
int i=0,j=0;
P2=0x00;
while(1)
{
if(switch1==0)
{
i--;
 while (switch1==0);
}
if(switch2==0)
{
i++;
while(switch2==0);
}
if(i>99)
{
i=0;
}
if(i<0)
{
i=99;
}
j=i;
ss1=0;ss2=1;
P2=a[j/10];
delay();
P2=0x00;		

ss1=1;ss2=0;
P2=a[j%10];
delay();
 P2=0x00;
}
}




