#include<stdio.h>
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit sw=P3^4;
void delay();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_ini();
void lcd_integer(int x);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void main()
{
int i=1;
lcd_ini();
{
TMOD=0x05;
TR0=1;
while(1)
{
i=(TH0<<8)+TL0;
lcd_integer(i);
lcd_command(0x80);
}
}
}
void lcd_ini()
{
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
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
void delay()
{
int x=30000;
while(x--);
} 