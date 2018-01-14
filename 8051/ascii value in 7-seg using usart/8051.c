#include<reg51.h>
void delay()
{
int i=5;
while(i--);
}
unsigned char rx()
{
while(RI==0);
RI=0;
return SBUF;	
}
void tx(unsigned char x)
{SBUF=x;
while(TI==0);
TI=0;
}
void main()
{unsigned char a[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D , 0x7D, 0x07, 0x7F, 0x6F};
int x=543;
TMOD=0x20;
TH1=-3;
TR1=1;
SCON=0x50;
tx('A');
while(1)
{	 
if(RI==1)
{
x=SBUF;
RI=0; 	
}
P2=a[x/100];
P1=~0x01;
delay();
P2=0x00;
P2=a[(x%100)/10];
P1=~0x02;
delay();
P2=0x00;
P2=a[(x%10)];
P1=~0x04;
delay();
P2=0x00;
}
}