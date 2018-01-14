#include<reg51.h>
void ex0() interrupt 0
{
	P1=~P1;
}
void ex1() interrupt 2
{
	P2=~P2;
}
void main()
{
	IE=0x8A;
	while(1);
}