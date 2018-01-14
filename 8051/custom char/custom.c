#include<reg51.h>
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
void delay();
void lcd_ini();
void lcd_character();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void main()
{
lcd_ini();
lcd_character();
}
void lcd_ini()
{
lcd_command(0x38);
lcd_command(0x0e);
lcd_command(0xc0);

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
void lcd_character()
{				  	
lcd_command(64);
lcd_data(0);
lcd_data(0x04);
lcd_data(0x0A);
lcd_data(0x11);
lcd_data(0x1f);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0);
lcd_command(0x80);
lcd_data(0);
delay();

lcd_command(72);
lcd_data(0);
lcd_data(0x1B);
lcd_data(0x1B);
lcd_data(0x15);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0x11);
lcd_data(0);
lcd_command(0x81);
lcd_data(1);
delay();

lcd_command(80);
lcd_data(0);
lcd_data(0x1f);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x1f);
lcd_data(0);
lcd_command(0x82);
lcd_data(2);
delay();

lcd_command(104);
lcd_data(0);
lcd_data(0x1f);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0x04);
lcd_data(0);
lcd_command(0x83);
lcd_data(5);
delay();
}
void delay()
{
int i=5000;
while(i--);
}