//�ⲿ�ж�Ӧ��
//����һ�����������½��أ�������Ƭ�����ⲿ�ж�INT0
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
sbit LED = P0^0;
void int0_isr(void) interrupt 0	//INT0�жϷ�����
{
	LED = !LED;
}
void int0_init(void) //INT0�жϳ�ʼ��
{
	IT0 = 1;
	EA = 1;
	EX0 = 1;
}

void main()
{
	int0_init();	//INT0�жϳ�ʼ��
	while(1);
}