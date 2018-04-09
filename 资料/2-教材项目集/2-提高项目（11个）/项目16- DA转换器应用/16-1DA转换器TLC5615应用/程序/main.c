//DAת����TLC5615Ӧ�ã���Խ̲����
//DAת����TLC5615���Խ������źţ�����ѹ�仯�źţ�ת��Ϊģ���źţ���������ģ�����ݣ�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<TLC5615.c>
#define uchar unsigned char										//�궨�� ����uchar ����unsigned char 
#define uint unsigned int										//�궨�� ����uint ����unsigned int
sbit P1_0 = P1^0;
uchar j;
uint moni,dat,i; 
code uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,
							0x92,0x82,0xf8,0x80,0x90};			//�����������0~9��ʾ����
/* **************T0��ʼ������*****************/
void timer0_init(void)									
{
	TMOD = 0x01;
	TL0 = (65536-2000) % 256;
	TH0 = (65536-2000) / 256;
	TR0 = 1;
	ET0 = 1;
	EA  = 1;
}
/*********** T0�жϷ�����*******************/
void timer0_isr() interrupt 1									//T0���жϴ�������������ʾ����ĵ�ѹֵ
{
	TL0 = (65536-2000) % 256;
	TH0 = (65536-2000) / 256;
	i++;
	if(i >= 500)//0.5��
	{	
		i = 0;	
		tlc5615(dat);
		if(dat >= 962)
		dat = 0;
		moni = dat * 0.489;
		dat = dat + 10;
	}
	P0 = 0xff;
	switch(j)
	{
		case 0 : P0 = seven_seg[moni %10];P2 = 0xfe;break;
		case 1 : P0 = seven_seg[moni / 10 % 10];P2 = 0xfd;break;
		case 2 : P0 = seven_seg[moni / 100] & 0x7f;P2 = 0xfb;break;		
	}
	j++;
	if(j >= 3)
	j = 0;
}
/* *****************������********************/
void main()
{
	timer0_init();
	while(1);
}
