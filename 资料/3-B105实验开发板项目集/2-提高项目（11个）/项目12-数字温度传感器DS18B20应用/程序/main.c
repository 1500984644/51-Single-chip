//�����¶ȴ�����Ӧ�ã��̲ĺ�B105��ʵ�鿪����ͨ��
//ʵʱ��ȡ������ʾ�¶�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<ds18b20.c>	
	
code  uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};			//��������������Ա���
uchar cp1;
uint cp;
sbit P3_0 = P3^0;													//temp_num��temp_num1Ϊ�¶��������֣�temp_dotС�����֣��м����temp
void timer0_init(void)																	//�жϷ�����	 
{
	TMOD = 0x01;
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	TR0 = 1;
	EA  = 1;
	ET0 = 1;
}
void timer0_isr(void) interrupt 1														//�жϷ�����		  	
{
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	cp++;
	P0 = 0xff;
	switch(cp1)
	{
		case 0:P3_0 = 0;P0 = 0x01;P3_0  = 1;P3_0 = 0;
		P0 = seven_seg[c];break;
		case 1:P3_0 = 0;P0 = 0x02;P3_0  = 1;P3_0 = 0;
		P0 = seven_seg[t % 10] & 0x7f;break;
		case 2:P3_0 = 0;P0 = 0x04;P3_0  = 1;P3_0 = 0;
		P0 = seven_seg[t / 10];break;
	}
	cp1++;if(cp1 >= 3)cp1 = 0;
}
void main(void)	
{
	timer0_init();																//��18B20��rom��д����		
	while(1)
	{
	 	if(cp >= 500)
		{
			cp = 0;
			Read_Temperature();
			c = c * 0.625;
		}	
	}
}
