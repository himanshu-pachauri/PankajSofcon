#include<lpc214x.h>
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
int i=1500;
while(i--);
}
void print_day(unsigned char x)
{
x=x&0x07;
switch(x)
{
case 0:
string("SUN");
break;
case 1:
string("MON");
break;
case 2:
string("TUE");
break;
case 3:
string("WED");
break;
case 4:
string("THU");
break;
case 5:
string("FRI");
break;
case 6:
string("SAT");
break;
}
}
int main()
{
unsigned char hour,min,sec;
unsigned char date,month,year;
unsigned char day;
IODIR0=0x00000fff;
VPBDIV=0x01;
CCR=0x11;
SEC=50;
MIN=59;
HOUR=23;
DOM=31;
MONTH=12;
YEAR=12;
DOW=1;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_command(0x0c);
while(1)
{
hour=HOUR;			 //////////// TIME ////////////
min=MIN;
sec=SEC;

lcd_command(0x80);
lcd_integer(hour);
lcd_data(':');	  
lcd_integer(min);
lcd_data(':');  	  
lcd_integer(sec);
 
date=DOM;			 //////////// DATE ////////////
month=MONTH;
year=YEAR;

lcd_command(0xc0);
lcd_integer(date);
lcd_data('/');	  
lcd_integer(month);
lcd_data('/');  	  
lcd_integer(year);

day=DOW;		
lcd_command(0xc9);
string("DAY");
lcd_data(':');   
lcd_command(0xcd);
print_day(day);
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
