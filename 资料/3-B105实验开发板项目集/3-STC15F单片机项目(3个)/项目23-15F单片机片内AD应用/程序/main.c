//15��Ƭ���ڲ�ADʹ�ã����B105��ʵ�鿪�������
//ģ���źŲ���ʵ����λ��VR1(��P1.1)����һ��0-5V��ѹ
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<display.c>
#include<15fad.c>
unsigned int cp1;

void timer0_isr(void) interrupt 1
{
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	cp1++;
	P0 = 0xff;
	display();
	cp2++;
	if(cp2 >= 8)cp2 = 0;		
}
void timer0_init(void)
{
	TMOD = 0x01;
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void main(void)
{
	timer0_init();
	while(1)
	{
		if(cp1 >= 500)//����
		{
			cp1 = 0;
			ad_dat =  get_ad();//����õ�һ��ת��������ݣ�Ȼ��ȥ��ʾ
		}
	}
}