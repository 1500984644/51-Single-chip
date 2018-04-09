/***************** pcf8591.c  �ļ�����*****************************/
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
void delay(uchar x)
{
	while(x--);
}
sbit SDA = P3^3;
sbit SCL = P3^7;
void Start_PCF8591()
{
	SCL = 0;
	SDA = 1;
	delay(10);
	SCL = 1;
	delay(10);
	SDA = 0;
	delay(10);
	SCL = 0;
}
void Stop_PCF8591()
{
	SCL = 0;
	SDA = 0;
	delay(10);
	SCL = 1;
	delay(10);
	SDA = 1;
	delay(10);
}
void Write_Byte(uchar dat)
{
	uchar i,temp;
	temp = dat;
	for(i=0; i<8; i++)
	{
		SCL = 0;
		temp = temp << 1;
		SDA = CY;
		delay(10);
		SCL = 1;
		delay(10);
	}
	SCL = 0;
	SDA = 1;
	delay(10);
	SCL = 1;
	delay(10);
	SCL = 0;
}
uchar Read_Byte()
{
	 uchar i,tmp;
	 for(i=0; i<8; i++)
	 {
	 	 	SCL = 0; 
			SDA = 1;
	  	tmp = tmp << 1;
			SCL = 1;        					//�ôӻ����͵����ݵõ��ȶ� ������⣩
			delay(10);
			if(SDA == 1)
				tmp = tmp | 0x01;
			delay(10);
	 }
	 return tmp;
	 SCL = 0;
	 SDA = 1;					 				//ֻ��ȡһ�� �ֽڣ����ӻ�һ����Ӧ��
	 delay(10);
	 SCL = 1;					 				//�ȶ���������SDAӦ�� �ȴ��ӻ�����ȡ
	 delay(10);
	 SCL = 0;
} 	   
uchar AD_PCF8591(uchar con)						//ADת��		
{
	uchar value;
	Start_PCF8591();
	Write_Byte(0x90);
	Write_Byte(con);
	Start_PCF8591();
	Write_Byte(0x91);
	value = Read_Byte();
	Stop_PCF8591();
	return value;
}	
/*void DA_PCF8591(uchar con,uchar dat)			 //	DAת��
{
	Start_PCF8591();
	Write_Byte(0x90);
	Write_Byte(con);
	Write_Byte(dat);
	Stop_PCF8591();
}*/