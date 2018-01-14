#include<stdio.h>
#include<lpc21xx.h>
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_float(float x);
void lcd_integer(int x);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void delay()
{
int i=50000;
while(i--);
}
void main()
{
IODIR0=0x00000fff;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_float(5.255);
while(1);
}
void lcd_float(float x)
{
int y,z;
y=x;
z=(x-y)*1000;

lcd_integer(x);
lcd_data('.');
lcd_integer(z);
}
void lcd_integer(int x)
{
unsigned char a[10];
sprintf(a,"%d",x);
string(a);
}
void lcd_data(unsigned char x)
{
IOSET0=x&0x000000ff;
IOSET0=0x00000500;
delay();
IOCLR0=0x00000400;
delay();
IOCLR0=0x00000fff;
}
void lcd_command(unsigned char x)
{
IOSET0=x&0x000000ff;
IOSET0=0x00000400;
delay();
IOCLR0=0x00000400;
delay();
IOCLR0=0x00000fff;
}