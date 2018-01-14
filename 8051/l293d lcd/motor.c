#include<reg51.h>
sbit in1=P3^0;
sbit in2=P3^1;
sbit in3=P3^2;
sbit in4=P3^3;
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit rs=P1^2;
sbit rw=P1^3;
sbit en=P1^4;
void delay();
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_forward(int a);
void lcd_left(int b);
void lcd_right(int c);
void lcd_reverse(int d);
void string(unsigned char *p)
{while(*p)
{lcd_data(*p++);}
}
void main()
{lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
while(1)
{lcd_forward(1);
lcd_left(2);
lcd_right(3);
lcd_reverse(4);}
}
void lcd_forward(int a)
{	
{if((sw1==0)&&(sw2==0))
{string("FORWARD     ");}
}if(sw1==0)
{in1=1;
in2=0;
}if(sw2==0)
{in3=1;
in4=0;}
}
void lcd_left(int b)
{
{if((sw1==0)&&(sw2==1))
{string("LEFT        ");}
}if(sw1==0)
{in1=1;
in2=0;
}if(sw2==1)
{in3=0;
in4=1;}
}
void lcd_right(int c)
{
{if((sw1==1)&&(sw2==0))
{string("RIGHT       ");}
lcd_command(0x01);
}if(sw1==1)
{in1=0;
in2=1;
}if(sw2==0)
{in3=1;
in4=0;}
}
void lcd_reverse(int d)
{
{if((sw1==1)&&(sw2==1))
{string("REVERSE     ");}
}if(sw1==1)
{in1=0;
in2=1;}
if(sw2==1)
{in3=0;
in4=1;}
}
void lcd_data(unsigned char x)
{P2=x;
rs=1;
rw=0;
en=1;
delay();
en=0;}
void lcd_command(unsigned char x)
{P2=x;
rs=0;
rw=0;
en=1;
delay();
en=0;}
void delay()
{int i=500000;
while(i--);}