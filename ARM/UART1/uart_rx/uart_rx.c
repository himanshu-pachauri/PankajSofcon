#include <lpc21xx.h>
void delay();
void rx_init();
unsigned char data_rx();
void main()
{
//unsigned char a;
IODIR0=0x0000ffff;	
rx_init();
while(1)
{
IOPIN0=data_rx();	
delay();
//IOCLR0=0x0000ff00;
//delay();
}
}
void rx_init()
{
PINSEL0=0x00050000;
VPBDIV=1;	
U1FCR=0x01;
U1LCR=0x83;
U1DLM=0x00;
U1DLL=0x82;
U1LCR=3;
}
unsigned char data_rx(void)
{
while (!(U1LSR&0x01));
return U1RBR;
}
void delay()
{
int i=90000;
while(i--);	
}