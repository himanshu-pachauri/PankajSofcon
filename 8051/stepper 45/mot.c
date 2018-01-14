#include<reg51.h>
void delay();
void main()
{

P2=0x01;
delay();
P2=0x02;
delay();
P2=0x04;
delay();

while(1);

}
void delay()
{
int i=50000;
while(i--);
}