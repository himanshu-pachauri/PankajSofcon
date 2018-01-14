#include<lpc21xx.h>
void delay()
{
int i=50;
while(i--);	
}
void main()
{
unsigned char a[12]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i,j,k,l,b;
IODIR0=0x00000fff;
while(1)
{
for(l=0;l<10;l++)
{
for(k=0;k<10;k++)
{
for(j=0;j<10;j++)
{
for(i=0;i<10;i++)
{
for(b=0;b<500;b++)
{
IOPIN0=a[l]|(1<<9)|(1<<10)|(1<<11);				 
 delay();
 IOCLR0=0x00fff;
  delay();

IOPIN0=a[k]|(1<<8)|(1<<10)|(1<<11);				 
 delay();
 IOCLR0=0x00fff;
  delay();

 IOPIN0=a[j]|(1<<8)|(1<<9)|(1<<11);				 
 delay();
 IOCLR0=0x00fff;
  delay();
  
IOPIN0=a[i]|(1<<8)|(1<<10)|(1<<9);				 
 delay();
  IOPIN0=0x00;
  delay();
}
}
}
}
}
}
}