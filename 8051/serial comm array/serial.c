#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void lcd_ini();
void delay();
void string(unsigned char *x)
{
while(*x)
{
SBUF=*x;
while(TI==0);
TI=0;
delay();
x++;
}
}
void string1(unsigned char *x)
{
while(*x)
{
lcd_data(*x++);

}
}

void main()
{
char a[13]="ABCDEFGHIJKL";
int i;

lcd_ini();
TMOD=0x20;
TH1=0xfd;
TR1=1;
SCON=0x50;
while(1)
{
for(i=0;i<12;i++)
{
while(RI==0);
a[i]=SBUF;
RI=0;
}
a[i]=0;
string1(a);
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