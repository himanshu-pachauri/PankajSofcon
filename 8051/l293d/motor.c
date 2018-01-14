#include<reg51.h>
sbit in1=P3^0;
sbit in2=P3^1;
sbit in3=P3^2;
sbit in4=P3^3;
sbit sw1=P1^0;
sbit sw2=P1^1;
void delay();
void main()
{
while(1)
{			  							
if(sw1==0)
{
in1=0;
in2=1;
delay();
}
		  							
if(sw2==0)
{
in3=0;
in4=1;
delay();
}

{
if(sw1==0)
{
in1=0;
in2=1;
delay();
}
		  							
if(sw2==1)
{
in3=1;
in4=0;
delay();
}
}

{
if(sw1==1)
{
in1=1;
in2=0;
delay();
}
		  							
if(sw2==0)
{
in3=0;
in4=1;
delay();
}
}

{
if(sw1==1)
{
in1=1;
in2=0;
delay();
}
		  							
if(sw2==1)
{
in3=1;
in4=0;
delay();
}
}
P3=0x00;
}
}

void delay()
{
int i=500000;
while(i--);
}