//�õ�Ƭ��P3.2�˿ڿ���LED����˸����Խ̲����
//�������²�̧��LED�ı�״̬
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
sbit key1 = P3^2;				   //����key1ΪP3.2�˿�
sbit LED = P0^0;				   //����LEDΪP0.0�˿�
void delay(unsigned int x)
{
	while(x--);
} 
void key(void)						//��������
{
	if(key1 == 0)					//���P3.2�˿��Ƿ�Ϊ�͵�ƽ
	{
		delay(500);					//��ʱһ��ʱ�䣬�ﵽ������Ŀ��
		if(key1 == 0)				//�ٴ��жϰ����Ƿ���
		{
			while(key1 == 0);		//�ȴ�����̧��
			LED = !LED;				//̧���ʹLEDȡ��
		}
	}
}
void main(void)
{									
	P0 = 0X00;						//��LEDȫ��
	while(1)
	{
		key();						//���ð�������
	}
}