#include <lpc21xx.h>
void delay();
void rx_init();
unsigned char data_rx();
void main()
{
unsigned char a;
IODIR0=0x0000fff0;	
rx_init();
while(1)
{
IOPIN0=data_rx()<<4;	
delay();
//IOCLR0=0x0000ff00;
//delay();
}
}
void rx_init()
{
PINSEL0=5;
VPBDIV=1;	
U0FCR=0x01;
U0LCR=0x83;
U0DLM=0x00;
U0DLL=0x82;
U0LCR=3;
}
unsigned char data_rx(void)
{
while (!(U0LSR&0x01));
return U0RBR;
}
void delay()
{
int i=90000;
while(i--);	
}