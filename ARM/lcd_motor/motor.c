#include<stdio.h>
#include<lpc21xx.h>
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_integer(int x);
void forward(int a);
void right(int b);
void left(int c);
void reverse(int d);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void delay()
{
int i=9000;
while(i--);
}	int i;
void main()
{	
IODIR0=0xffffffff;
IODIR1=0xffff0000;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_command(0x0C);
while(1)
{	i=IOPIN1&0x00030000;
forward(i);
right(i);
left(i);
reverse(i);
}
}
void forward(int a)
{
if((i)==0x00030000)
{
IOSET0=0x00005000;
{
lcd_command(0x80);
string("FORWARD");
}
delay();
IOCLR0=0x0000ff00;
}
}
void right(int b)
{
if(i==0x00010000)
{
IOSET0=0x00001000;
{
lcd_command(0x80);
string("RIGHT  ");
}
delay();
IOCLR0=0x0000ff00;
}
}
void left(int c)
{
if(i==0x00020000)
{
IOSET0=0x00004000;
{
lcd_command(0x80);
string("LEFT   ");
}
delay();
IOCLR0=0x0000ff00;
}
}
void reverse(int d)
{
if(i==0x00000000)
{
IOSET0=0x0000a000;
{
lcd_command(0x80);
string("REVERSE");
}
delay();
IOCLR0=0x0000ff00;
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