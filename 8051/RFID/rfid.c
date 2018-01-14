#include<reg51.h>
void delay()
{
int i=5;
while(i--);
}
unsigned char rx()
{
while(RI==0);
RI=0;
return SBUF;
}
void tx(unsigned char x)
{SBUF=x;
while(TI==0);
TI=0;
}
void string(unsigned char *p)
{
while(*p)
{
tx(*p++);
}
}
void string_cmp(unsigned char a[])
{unsigned char d[][13]={"123456789011"//;
  					,	"123456789012"///										
  				,"123456789013"//
			,"123456789014"};
  
int i=0,j=0;
for(j=0;j<4;j++)
{  for(i=0;(a[i]==d[j][i]) && (i<13 ) ;i++);
if(i==13)
{
break;
}
}
i--;
if((i==12))
{  
switch(j)
{
case 0:
string(" Pankaj");
break;
case 1:
string(" GAURAV");
break;  
case 2:
string(" VIMAL");
break;
case 3:
string(" AMAR");
break;
}
}
else
string(" YOU ARE NOT AUTHORIZED");
}
void main()
{int i=0;
unsigned char a[13];
TMOD=0x20;
TH1=-3;
TR1=1;
SCON=0x50;
tx('a');
while(1)
{
for(i=0;i<12;i++)
{
a[i]=rx();
}
a[i]=0;
string_cmp(a);
}
}
