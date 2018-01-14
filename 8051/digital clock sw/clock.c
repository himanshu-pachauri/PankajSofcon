#include<stdio.h>
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit sw=P1^3;
void timer_delay();
void lcd_command(unsigned char x);
void lcd_data(unsigned char x);
void digi_clock();
void lcd_integer(int x);
void lcd_print(int z);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void main()
{	  
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
while(1)
{ 
digi_clock();
}
}
void digi_clock()
{
int hh=0,mm=0,ss=0;
for(hh=0;hh<=23;hh++)
{
for(mm=0;mm<=59;mm++)
{
for(ss=0;ss<=59;ss++)
{if(sw==0)
{  
lcd_command(0x80);
lcd_integer(hh);
lcd_data(':');
lcd_integer(mm);
lcd_data(':');
lcd_integer(ss);
}
else 
lcd_command(0x01);
}
}
}
}
void lcd_integer(int x)
{
unsigned char a[10];
sprintf(a,"%d",x);
string(a);
}
void lcd_data(unsigned char x)
{
P2=x;
rs=1;
rw=0;
en=1;
timer_delay();
en=0;
}
void lcd_command(unsigned char x)
{
P2=x;
rs=0;
rw=0;
en=1;
timer_delay();
en=0;
}
void timer_delay()
{
int i=0;
for(i=0;i<10;i++)
{
TH0=0x4c;
TL0=0x00;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
TH0=0x4c;
TL0=0x00;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}
} 