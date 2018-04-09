//8λ����ܶ�̬��ʾ
//��8λ�����������P0���Լ�74HC573оƬ�����£���ʾ0-7
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
sbit P3_0 = P3^0;
code unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,
									0x82,0xf8,0x80,0x90,0xbf,0xff};	//����0~9����ʾ���� 
unsigned int cp;
unsigned char tp,sec = 30,min = 30,hour = 12; 						 

void timer0_isr(void) interrupt 1	//�жϷ�����
{
	TH0 = (65535 - 2000) / 256;		//ÿ�δ����жϺ��װ��ֵ��ʹ�´ζԻ����������2000��������������ж�  Լ0.2ms
	TL0 = (65535 - 2000) % 256;
	cp++;
	if(cp >= 500)
	{
		cp = 0;
		sec++;
		if(sec >= 60){sec = 0;min++;}
		if(min >= 60){min = 0;hour++;}
		if(hour >= 24)hour = 0;
	}
	P0 = 0xff;
	switch(tp)
	{
		case 0:P3_0 = 0;P0 = 0x01;P3_0 = 1;P3_0 = 0;P0 = seven_seg[sec % 10];break;	
		case 1:P3_0 = 0;P0 = 0x02;P3_0 = 1;P3_0 = 0;P0 = seven_seg[sec / 10];break;	
		case 2:P3_0 = 0;P0 = 0x04;P3_0 = 1;P3_0 = 0;P0 = 0xbf;break;	
		case 3:P3_0 = 0;P0 = 0x08;P3_0 = 1;P3_0 = 0;P0 = seven_seg[min % 10];break;		
		case 4:P3_0 = 0;P0 = 0x10;P3_0 = 1;P3_0 = 0;P0 = seven_seg[min / 10];break;	
		case 5:P3_0 = 0;P0 = 0x20;P3_0 = 1;P3_0 = 0;P0 = 0xbf;break;	
		case 6:P3_0 = 0;P0 = 0x40;P3_0 = 1;P3_0 = 0;P0 = seven_seg[hour % 10];break;		
		case 7:P3_0 = 0;P0 = 0x80;P3_0 = 1;P3_0 = 0;P0 = seven_seg[hour / 10];break;	
	}
	tp++;if(tp >= 8)tp = 0;
}
void timer0_init(void)				//�жϳ�ʼ������
{
	TMOD = 0x01;				//T0������ʽ1
	TH0 = (65535 - 2000) / 256;		//�Ի����������2000��������������ж�  Լ0.2ms
	TL0 = (65535 - 2000) % 256;
	EA = 1;						//�����ж�
	ET0 = 1;					//��T0�ж�	
	TR0 = 1;					//������ʱ��T0
}
void main(void)
{	
	timer0_init();				//�жϳ�ʼ��
	while(1);
} 