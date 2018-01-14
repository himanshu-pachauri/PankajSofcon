#include<lpc21xx.h>
void delay()
{
int i=5;
while(i--);	
}
void main()
{
unsigned char a[12]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i,j,k,l,m,n,o,p,b;
IODIR0=0x0000ffff;
while(1)
{
for(p=0;p<10;p++)
{
for(o=0;o<10;o++)
{
for(n=0;n<10;n++)
{
for(m=0;m<10;m++)
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
IOPIN0=a[p]|(1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();

IOPIN0=a[o]|(1<<8)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();

 IOPIN0=a[n]|(1<<8)|(1<<9)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();
  
IOPIN0=a[m]|(1<<8)|(1<<10)|(1<<9)|(1<<12)|(1<<13)|(1<<14)|(1<<15);				 
 delay();
  IOPIN0=0x00;
  delay();

IOPIN0=a[l]|(1<<9)|(1<<10)|(1<<11)|(1<<8)|(1<<13)|(1<<14)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();

IOPIN0=a[k]|(1<<8)|(1<<10)|(1<<11)|(1<<12)|(1<<9)|(1<<14)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();

 IOPIN0=a[j]|(1<<8)|(1<<9)|(1<<11)|(1<<12)|(1<<13)|(1<<10)|(1<<15);				 
 delay();
 IOCLR0=0x0ffff;
  delay();
  
IOPIN0=a[i]|(1<<8)|(1<<10)|(1<<9)|(1<<12)|(1<<13)|(1<<14)|(1<<11);				 
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
}
}
}
}