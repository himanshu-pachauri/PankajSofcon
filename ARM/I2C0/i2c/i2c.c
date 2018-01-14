#include<lpc214x.h>
void delay()
{
int i=5000;
while(i--);
}
void i2c_ini()
{
PINSEL0=(1<<4)|(1<<6);
VPBDIV=0x01;
I2C0SCLL=100;
I2C0CONSET=(1<<6);
}
i2c_start()
{
I2C0CONSET=(1<<5);
I2C0CONCLR=(1<<3);
while((I2C0CONSET&0x08)==0x00);
}
i2c_stop()
{
I2C0CONSET=(1<<4);
}
i2c_write(unsigned char data)
{
I2C0DAT=data;
I2C0CONCLR=(1<<3);
while((I2C0CONSET&0x08)==0);
I2C0CONSET=0;
}
i2c_read()
{
I2C0CONSET=(1<<2)|(1<<6);
I2C0CONCLR=(1<<3);
while((I2C0CONSET&0x08)==0);
I2C0CONSET=0;
return I2C0DAT;
}
void main()
{IODIR0=0xfff000;
i2c_ini();
i2c_start();
IOPIN0=0xfff000;
i2c_write('A');
while(1);
//i2c_stop();
}
