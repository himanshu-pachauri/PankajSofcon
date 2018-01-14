#include<reg51.h>
sbit ss1=P1^1;
sbit ss2=P1^2;
void delay();
void main()
{
unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
int i,j,k;
while(1)
{for(i=0;i<10;i++)
for(j=0;j<10;j++)
for(k=0;k<5000;k++)
{
ss1=0;
ss2=1;
P2=a[i];
delay();
P2=0x00;
	 
ss1=1;
ss2=0;
P2=a[j];
    delay();
P2=0x00;

}}
}


void delay()
{ 
int i=5;
while(i--);
}