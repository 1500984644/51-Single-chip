//8λ����ܶ�̬��ʾ����Խ̲����
//��8λ�����������P0���Լ�74hc573оƬ�����£���ʾ0-7
//��ƣ���Ƭ�����¹�����--��������ƣ�2015��12��15��
#include<reg51.h>
code unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,
									0x82,0xf8,0x80,0x90,0xbf,0xff}; 
unsigned char t;						 
void timer0_isr()interrupt 1						//�жϷ�����
{
	TH0 = (65536-2000)/256;							//ÿ�δ����жϺ��װ��ֵ��ʹ�´ζԻ����������2000��������������ж�  Լ0.2ms
	TL0 = (65536-2000)%256;
    P0 = 0xff;										//Proteus ������Ҫ����
	switch(t)
	{
		case 0:P0 = seven_seg[0];P2 = ~0x01;break;	//����ܶ�ѡ�������λѡ
		case 1:P0 = seven_seg[1];P2 = ~0x02;break;
		case 2:P0 = seven_seg[2];P2 = ~0x04;break;
		case 3:P0 = seven_seg[3];P2 = ~0x08;break;
		case 4:P0 = seven_seg[4];P2 = ~0x10;break;
		case 5:P0 = seven_seg[5];P2 = ~0x20;break;
		case 6:P0 = seven_seg[6];P2 = ~0x40;break;
		case 7:P0 = seven_seg[7];P2 = ~0x80;break;
	}
	t++;if(t>=8)t=0;
}
void timer0_init()									//�жϳ�ʼ������
{
	TMOD = 0X01;									//T0������ʽ1
	TH0 = (65536-2000)/256;							//�Ի����������2000��������������ж�  Լ0.2ms
	TL0 = (65536-2000)%256;
	EA = 1;											//�����ж�
	TR0 = 1;										//������ʱ��T0
	ET0 = 1;										//��T0�ж�
}
void main()
{	
	timer0_init();									//�жϳ�ʼ��
	while(1);
} 