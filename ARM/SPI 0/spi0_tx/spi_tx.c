#include<lpc214x.h>
void delay()
{
int i=5000;
while(i--);
}
void spi_ini()
{
PINSEL0=(1<<8)|(1<<10)|(1<<12)|(1<<14);
VPBDIV=0x01;
S0SPCR=(1<<5)|(1<<11);
S0SPCCR=200;

}
void main()
{
spi_ini();
S0SPDR='A';
while((S0SPSR&0x80)==0);
S0SPSR=1;
}