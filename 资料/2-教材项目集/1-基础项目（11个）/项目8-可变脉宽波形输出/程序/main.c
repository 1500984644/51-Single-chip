//�ɱ���������������B105��ʵ�鿪�������
//��һ�����ڣ��Զ���������
//��ƣ���Ƭ�����¹�����--������� ��2015��12��15��
#include<reg51.h>
sbit P1_7 = P1^7;
unsigned char cp1,cp2,tt;
void timer0_init(void)									//�жϳ��Ի�����
{
	TMOD = 0x02;										//T0������ʽ2
	TL0 = 156;						
	TH0 = 156;											//����ʱ����ֵ
	EA = 1;												//�����ж�
	ET0  = 1;											//��T0�ж�
	TR0 = 1;											//������ʱ��T0
}
void timer0_isr(void) interrupt 1						//�жϷ�����
{
	cp1++;cp2++;										//���þֲ�����
	if(cp1++ >= tt)P1_7 = 1;
	if(cp1++ >= 20){P1_7 = 0;cp1 = 0;}
	if(cp2 >= 255){cp2 = 0;tt++;if(tt >= 20) tt = 0;}
}
void main()
{
	timer0_init();										//�жϳ�ʼ��
	while(1);
}