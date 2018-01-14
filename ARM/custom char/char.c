#include<stdio.h>
#include<lpc21xx.h>
void custom_character();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
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
int i=5000;
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
while(1)
{
custom_character();
}
}
void custom_character()
{
lcd_command(64);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_data(0x1f);
lcd_command(0x80);
lcd_data(0);
delay();
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