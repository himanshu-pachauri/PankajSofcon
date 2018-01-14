#include<stdio.h>
#include<lpc214x.h>
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_integer(int x);
void lcd_string(unsigned char *p)
{
while(*p)
{
lcd_data(*p++);
}
}
void delay()
{
int i=10000;
while(i--);
}
void i2c_ini()
{
PINSEL0=(1<<4)|(1<<6);
VPBDIV=0x01;
I2C0SCLL=50;
I2C0CONSET=(1<<6);
}
void i2c_start()
{
I2C0CONSET=(1<<5);
I2C0CONCLR=(1<<3);
while((I2C0CONSET&0x08)==0);
I2C0CONCLR=(1<<5);
}
void i2c_stop()
{
I2C0CONSET=(1<<4);
I2C0CONCLR=(1<<3);
delay();
I2C0CONCLR=(1<<4);
}
void i2c_write(unsigned char z)
{
I2C0DAT=z;
I2C0CONCLR=(1<<2)|(1<<3);
while((I2C0CONSET&0x08)==0);
I2C0CONSET=0;
}
unsigned char i2c_read()
{
I2C0CONCLR=(1<<2)|(1<<3);
while(!(I2C0CONSET&0x08)==1);
return I2C0DAT;
}		   
int main()
{
char s=0;
IODIR1=0x0fff0000;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
i2c_ini();
i2c_start();
i2c_write(0xD0); //address for write
i2c_write(0x00);
i2c_start();
i2c_write(0xD0); //address for write
i2c_write(0x00);
i2c_write(0x00); //second
i2c_write(0x00); //minute
i2c_write(0x00); //hour
i2c_stop();		  
while(1)
{				
i2c_ini();
i2c_start();
i2c_write(0xd0);
i2c_write(0x00);
i2c_stop();
i2c_start();
i2c_write(0xd1); //address for read
i2c_write(0x00);
lcd_command(0x80);
lcd_data(':');	 
s=i2c_read();
lcd_integer(s);
i2c_stop();	
}
}
void lcd_integer(int x)
{											
unsigned char a[10];
if(x<10)
{
lcd_data(0+48);																															 
}																								  
sprintf(a,"%d",x);
lcd_string(a);
}
void lcd_data(unsigned char x)
{
IOSET1=(x&0x00ff)<<16;
IOSET1=0x0500<<16;
delay();
IOCLR1=0x0400<<16;
delay();
IOCLR1=0x0fff<<16;
}
void lcd_command(unsigned char x)
{
IOSET1=(x&0x00ff)<<16;
IOSET1=0x0400<<16;
delay();
IOCLR1=0x0400<<16;
delay();
IOCLR1=0x0fff<<16;
}
