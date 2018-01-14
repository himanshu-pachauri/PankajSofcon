#include<reg51.h>
sbit ss1=P1^0;
sbit ss2=P1^1;
unsigned char recieve();
void delay()
{
int i=5000;
while(i--);
}
void main()
{
unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i=recieve();
while(1)
{
if(RI==1)
{
i=SBUF;
RI=0;
i=i%100;
}
P2=a[i/10];
ss1=0;
ss2=1;
P2=0x00;
P2=a[i%10];
ss1=1;
ss2=0;
P2=0x00;
}
}
unsigned char recieve()
{
TMOD=0x20;
TH1=-3;
TR1=1;
SCON=0x50;
SBUF='A';
while(TI==0);
TI=0;
while(RI==0);
RI=0;
return SBUF;
}