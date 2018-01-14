#include<reg51.h>
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
sbit in1=P3^0;
sbit in2=P3^1;
void delay();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_integer(int x);
void lcd_print(int z);
void lcd_string(unsigned char *p)
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
while(1)
{
if(i>=20)
{
in1=1;
in2=0;
}
if(i<20)
{
in1=0;
in2=0;
}
{
lcd_command(0x01);
if(sw1==0)
{
i++;
lcd_integer(i);
lcd_string("   ");
}
else if(sw2==0)
{
i--;
lcd_integer(i);
lcd_string("   ");
}
}
}
}
void lcd_integer(int x)
{
int y,z=0;
while(x>0)
{
y=(x%10);
z=z*10+y;
x=x/10;
}
lcd_print(z);
}
void lcd_print(int z)
{  
while(z>0)
{
lcd_data((z%10)+48);
z=z/10;
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
void delay()
{
int i=5000;
while(i--);
}