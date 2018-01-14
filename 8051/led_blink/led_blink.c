#include<reg51.h>
void delay();
void main()
{
while(1)
{
P2=0xff;
delay();
P2=0x00;
delay();
}

}
void delay()
{
int i=50000;
while(i--);
}
