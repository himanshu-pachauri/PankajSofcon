#include<stdio.h>
#include<reg51.h>
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
void delay();
void lcd_character();
void lcd_integer(int x);
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void string1(unsigned char *p);
void string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void string1(unsigned char *p)
{
while(*p)
{
lcd_data(*p);
p++;
}
}
void main()
{
lcd_command(0x38);
lcd_command(0x0c);
lcd_integer();
/*lcd_command(0xd0);
lcd_command(0x18);
string1("HELLO WORLD!!!!");
*/
}
void lcd_integer(int x)
{	
unsigned char a[10];  
sprintf(a,"%d",x);
{
lcd_command(0x90);
lcd_command(0x1c);
string("HELLO WORLD!!!!");
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
int i=500;
while(i--);
}