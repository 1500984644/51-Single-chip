#include<intrins.h>
#define nop _nop_();
#define uchar unsigned char
#define uint unsigned int
sbit CS = P3^0;									//����λ���� ��CSƬѡ�źŽ���P3.0�˿�
sbit CLK = P3^1;								//����λ���� ��CLKʱ���źŽ���P3.1�˿�
sbit DIDO = P3^2;								//����λ���� ������ѡͨ�źŽ���P3.2�˿�
/**********ADC0832��ʼ������***********/
void dac0832_init(void)
{
	CS = 1;_nop_();
	CLK = 1;
	CS = 0;	
}
/*****��ת��CH0ͨ����ģ���źź���******/
uchar dac0832_ch0(void)//����11��CLK�½���
{		
	uchar i,dat1;
	dac0832_init();
	DIDO = 1;CLK = 0;nop;CLK = 1;nop;			//SCK��1���½�������ʱ��DI = 1����DAC0832
	DIDO = 1;CLK = 0;nop;CLK = 1;nop;			//SCK��2���½���
	DIDO = 0;CLK = 0;nop;CLK = 1;nop;			//SCK��3���½���,����1��0ѡ��ͨ��ch0
	DIDO = 1;									//�ͷ����� 
	for(i = 0;i < 8;i++)						//SCK��4���½��ص���11���½���,
	{	
		CLK = 0;nop;
		if(DIDO)dat1 = dat1 | 0x01;
		CLK = 1;nop;
		dat1 = dat1 << 1;
	}
		return(dat1);
		CS = 1;	
}