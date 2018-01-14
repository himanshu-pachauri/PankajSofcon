#include<stdio.h>
#include<reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
int lcd_keypad();
void operation(int x,char c,int y);
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
int i=12000;
while(i--);
}
void main()		  //MAIN FUNCTION
{int x,y;
char o;
lcd_command(0x38);
lcd_command(0x0c);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_command(0x0c);
string("ON");
delay();
delay();
delay();
delay();
lcd_command(0x01);
while(1) 
{
x=lcd_keypad();
lcd_integer(x);
while(lcd_keypad()==x);

o=lcd_keypad();
lcd_data(o);
while(lcd_keypad()==o);

y=lcd_keypad();
lcd_integer(y);
delay();
lcd_data('=');
operation(x,o,y);
}
}
int  lcd_keypad()	 //KEYPAD FUNCTION
{
int result;
int i,j,k;
P2=0x0f;
while(P2==0x0f);
i=P2;
P2=0xf0;
while(P2==0xf0);
j=P2;
j=j>>4;		  
if((i==0x0e)&&(j==0x0e))
{
k=0x01;			  //one
return k;
delay();
}			 
else if((i==0x0d)&&(j==0x0e))
{
k=0x02;			  //two
return k;
delay();
}
else if((i==0x0b)&&(j==0x0e))
{
k=0x03;			  //three
return k;
delay();
}
else if((i==0x07)&&(j==0x0e))
{
k='+';			  //add
return k;
delay();
}
else if((i==0x0e)&&(j==0x0d))
{
k=0x04;			  //four
return k;
delay();
}			 
else if((i==0x0d)&&(j==0x0d))
{
k=0x05;			  //five
return k;
delay();
}
else if((i==0x0b)&&(j==0x0d))
{
k=0x06;			  //six
return k;
delay();
}
else if((i==0x07)&&(j==0x0d))
{
k='-';			  //sub
return k;
delay();
}
else if((i==0x0e)&&(j==0x0b))
{
k=0x07;			  //seven
return k;
delay();
}			 
else if((i==0x0d)&&(j==0x0b))
{
k=0x08;			  //eight
return k;
delay();
}
else if((i==0x0b)&&(j==0x0b))
{
k=0x09;			  //nine
return k;
delay();
}
else if((i==0x07)&&(j==0x0b))
{
k='*';			  //mul					
return k;
delay();
}
else if((i==0x0e)&&(j==0x07))
{
k='C';			  //clear
return k;
delay();
}			 
else if((i==0x0d)&&(j==0x07))
{
k=0x00;			  //zero
lcd_integer(k);
delay();
}
else if((i==0x0b)&&(j==0x07))
{
k='=';			  //equal to
return k;
delay();
}
else if((i==0x07)&&(j==0x07))
{
k='/';			  //div
 return k;
delay();
}
return k;
}
void operation(int x,char c,int y)
{
int result;
switch(c)
{
   case '+':
     result=x+y;
     lcd_integer(result);
       break;

   case '-':
     result=x-y;
     lcd_integer(result);
       break;
 
   case '*':
     result=x*y;
     lcd_integer(result);
       break;
   
   case '/':
     result=x/y;
     lcd_integer(result);
       break;
}
}
void lcd_integer(int x)
{	
unsigned char a[10];  
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