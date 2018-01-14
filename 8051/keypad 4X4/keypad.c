#include<stdio.h>
#include<reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void lcd_integer(int x);
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
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
int i,j,k;
lcd_command(0x38);
lcd_command(0x0c);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_command(0x0c);
string("Press");
delay();
delay();
delay();
delay();
//lcd_command(0x01);
while(1)
{
P2=0x0f;
while(P2==0x0f);
i=P2;
//P1=i;
P2=0xf0;
while(P2==0xf0);
j=P2;
j=j>>4;
//P3=j;		  
if((i==0x0e)&&(j==0x0e))
{
k=0x00;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Zero    ");
delay();
}			 
if((i==0x0d)&&(j==0x0e))
{
k=0x01;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("One     ");
delay();
}
if((i==0x0b)&&(j==0x0e))
{
k=0x02;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Two     ");
delay();
}
if((i==0x07)&&(j==0x0e))
{
k=0x03;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Three   ");
delay();
}

if((i==0x0e)&&(j==0x0d))
{
k=0x04;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Four    ");
delay();
}			 
if((i==0x0d)&&(j==0x0d))
{
k=0x05;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Five    ");
delay();
}
if((i==0x0b)&&(j==0x0d))
{
k=0x06;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Six     ");
delay();
}
if((i==0x07)&&(j==0x0d))
{
k=0x07;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Seven   ");
delay();
}

if((i==0x0e)&&(j==0x0b))
{
k=0x08;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Eight   ");
delay();
}			 
if((i==0x0d)&&(j==0x0b))
{
k=0x09;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Nine    ");
delay();
}
if((i==0x0b)&&(j==0x0b))
{
k=0x0a;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Ten     ");
delay();
}
if((i==0x07)&&(j==0x0b))
{
k=0x0b;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Eleven");
delay();
}

if((i==0x0e)&&(j==0x07))
{
k=0x0c;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Twelve");
delay();
}			 
if((i==0x0d)&&(j==0x07))
{
k=0x0d;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Thirteen");
delay();
}
if((i==0x0b)&&(j==0x07))
{
k=0x0e;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Forteen ");
delay();
}
if((i==0x07)&&(j==0x07))
{
k=0x0f;
lcd_command(0x80);
lcd_integer(k);
lcd_data('-');
string("Fifteen ");
delay();
}
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
string(a);
}
void lcd_data(unsigned char x)
{
P1=x;
rs=1;
rw=0;
en=1;
delay();
en=0;
}
void lcd_command(unsigned char x)
{
P1=x;
rs=0;
rw=0;
en=1;
delay();
en=0;
}