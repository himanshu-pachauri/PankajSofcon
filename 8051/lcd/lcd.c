#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void delay();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
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
lcd_integer(1234);
while(1);
}

void lcd_integer(int x)
{
int y,z;
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