#include<lpc214x.h>
void delay()
{
int i=50000;
while(i--);
}
void uart_init()
{
PINSEL0=1;
VPBDIV=1;
U0TER=0x80;
U0LSR=0x01;
U0LCR=0x83;
U0DLM=0x00;
U0DLL=0x82;
U0LCR=3;
} 
void main()
{
uart_init();
{
U0THR=('A');
while ((U0LSR&0x20)==0);
U0LSR=0;
while(1);
}
}