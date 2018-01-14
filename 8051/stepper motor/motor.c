#include<reg51.h>
void delay();
void main()
{
while(1)
{
P2=0x0c<<4;
delay();
P2=0x06<<4;
delay();
P2=0x03<<4;
delay();
P2=0x09<<4;
delay();
}

}
void delay()
{
int i=9000;
while (i--);
}