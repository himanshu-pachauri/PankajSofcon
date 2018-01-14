#include<reg51.h>
void delay();
void main()
{
int i=0,j=0,k=8;
while(1)
{
for(i=0;i<k;i++)
{
delay();
P2=(128>>i)|j;
}
j=P2;
k--;
if(j==0x00)
{
j=0;
k=8;
}
}
}
void delay()
{
int i=50000;
while(i--);
}