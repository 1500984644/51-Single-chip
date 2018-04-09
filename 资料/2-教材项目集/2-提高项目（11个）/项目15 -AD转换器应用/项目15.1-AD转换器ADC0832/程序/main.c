//ADת����ADC0832Ӧ�ã���Խ̲����
/*
   ���ڵ�λ��R1���Բ���һ��ģ���0~5V��ѹԴ������ADC0832��CH0���˿ڣ�

   ADC0832ת��������ݷ�ΧΪ0~255������λ����������ADC0832��DI

   ��DO�����ӵ�Ƭ����P3.2�ڣ�/CS��P3.0�ڣ�CLK��P3.1�ڡ�Ϊ�˵õ�

   CH0ͨ��ת���õ������ݣ���������Ҫ��CLK��2��3���½�������ʱ��DI

   ����1��0��Ȼ����ܽ���ADC0832��ת�����ݣ�ÿ��ת������ʱ��/CS ��Ч��
*/
//ʵʱ��ȡADC0832����ѹ���ݲ���ʾ
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<intrins.h>
#include"ADC0832.c"
#define uchar unsigned char										//�� unsigned char �궨��Ϊ uchar
code  uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,
							0x92,0x82,0xf8,0x80,0x90};			//����0~9����ʾ����
uchar cp1,cp2,dat_ad;
void timer0_init(void)											// timer0�жϳ�ʼ������
{
	TMOD = 0x01;
	TH0 = 0xec;
	TL0 = 0x78;
	TR0 = 1;
	EA  = 1;
	ET0 = 1;
}
void timer0_isr(void) interrupt 1								// timer0�жϷ�����
{
	TH0 = 0xec;
	TL0 = 0x78;
	cp1++;
	if(cp1 >= 100)												//0.5��
   	{
			cp1 = 0;
			dat_ad = dac0832_ch0();								//0.5����ADC0832ת��һ��
		}
		P0 = 0xff;
		switch(cp2)
		{
			case 0:P0 = seven_seg[dat_ad  % 10];P2 = ~0x01;break;
			case 1:P0 = seven_seg[dat_ad % 100 / 10];P2 = ~0x02;break;
			case 2:P0 = seven_seg[dat_ad / 100];P2 = ~0x04;break;
		}
		cp2++;
		if(cp2 >= 3)
		cp2 = 0;
}
void main(void)													//������ 
{
		timer0_init();
		dac0832_init();	
		while(1);
}
