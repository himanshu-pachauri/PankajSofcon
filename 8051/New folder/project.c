#include<stdio.h>
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit sw1=P1^3;
sbit sw2=P1^4;
sbit in1=P1^6;
sbit in2=P1^7;
void delay();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_integer(int x);
void ser_comm();
void string1(unsigned char *p);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void main()
{
int i=0;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
ser_comm();
while(1)
{
if((sw1==0))
{
if(i>=20)
i=20;
lcd_command(0x80);
i++;
lcd_integer(i);
string("   ");
while(sw1==0);
}
else if(sw2==0 )
{
if(i>=20)
i=20;
lcd_command(0x80);
i--;
lcd_integer(i);
string("   ");
while(sw2==0);
}
}
}
void ser_comm(unsigned char p)
{
TMOD=0x20;
TH1=-3;
TR1=1;
SCON=0x50;
SBUF=p;
while(TI==0);
TI=0;
}
void string1(unsigned char *p)
{
while(*p)
{
ser_comm(*p);
p++;
}
}
void lcd_data(unsigned char x)
{
P2=x;
rs=1;
rw=0;
en=1;
delay();
en=0;
}
void lcd_command(unsigned char x)
{
P2=x;
rs=0;
rw=0;
en=1;
delay();
en=0;
}
void lcd_integer(int x)
{	
unsigned char a[10];  
if(x>=20)
{
string1("The room is full");
x=20;
}
if(x<20)
{
in1=1;
in2=0;
delay();
in1=0;
in2=1;
delay();
in1=0;
in2=0;
}
sprintf(a,"%d",x);
string(a);
}
void delay()
{
int i=5000;
while(i--);
}