//�ⲿ�жϿ���LED��˸����Խ̲����
//�������£�P3.2�˿��½��ش����жϣ�LED״̬�ı�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
sbit LED = P0^0;
void timer0_isr()interrupt 0
{
	LED = !LED;
}
void timer0_init()		//�жϳ�ʼ��
{
	IT0 = 1;			//TCON�п���INT0������ʽλ��INT0�½��ش����ж�
	EA = 1;  			//���ж�����
	EX0 = 1;			//�ж�����
}
void main()
{
	P0 = 0x00;			//��LEDȫ��
	timer0_init();		
	while(1);		   	//�ȴ��ж�
}