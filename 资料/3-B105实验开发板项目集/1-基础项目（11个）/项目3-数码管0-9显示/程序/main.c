//���������0-9��ʾ
//���������������P0���Լ�74hc573оƬ�����£�ѭ����ʾ0-9
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
sbit P3_0 = P3^0;
unsigned char cp;
code unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};//����0~9����ʾ����
void delay(unsigned int x)
{
	while(x--);
}
void main(void)
{
	P0 = 0x01;
	P3_0 = 0;P3_0 = 1;P3_0 = 0;//P3.0��������أ�ʹ74HC573����,	Q0����ߵ�ƽ�� 
	while(1)			
	{	
		P0 = seven_seg[cp];
		delay(50000);
		cp++;				//cpÿ�μ�1
		if(cp >= 10)cp = 0;	//��10����	
	}
}