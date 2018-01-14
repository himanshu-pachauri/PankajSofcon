#include<lpc214x.h>
void delay()
{
int i=50000;
while(i--);
}
void uart_init()
{
PINSEL0=0x00050000;
VPBDIV=0x01;
//U1TER=0x80;
U1FCR=0x01;
U1LCR=0x83;
U1DLM=0x00;
U1DLL=0x82;
U1LCR=0x03;
} 
void main()
{
uart_init();
{
U1THR=('A');
while ((U1LSR&0x20)==0);
U1LSR=0;
while(1);
}
}