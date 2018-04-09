//���ӱ���Խ̲����
//�ù����������P0�ڡ�P2���Լ�74hc04оƬ�����£���ʾ24Сʱ�Ƶ��ӱ� 
//���ӱ����������STC8591�ڲ��Ķ�ʱ�M������ʵ�־�ȷ������
//���ӱ����ĸ�����key1��key2��key3��key4�ֱ�ʵ�ֵ�ģʽ��
//���ӡ����١���λ���ܣ����е�ģʽ����key1���Էֱ����Сʱ�����ӡ����ӡ�����	  
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<key.c>
unsigned char i,j,k;
unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,
								0x92,0x82,0xf8,0x80,0x90};
unsigned char flash;
sbit SW = P3^3;																		//�Ӽ̵���������·���͵�ƽ�̵������ϣ����Ƶ���
void timer0_isr(void) interrupt 1
{
	TH0 = 0xf8;
	TL0 = 0x2f;
	i++;
	if(i >= 250)																	//����ʱ�䵽
	{
		flash = ~flash;																//�õ�8λ��˸����
		i = 0;
		j++;
	}
	if(j >= 2)																		//1���ӵ�
	{
		sec++;
		j = 0;
	}													
	if(sec >= 60)																	//1���ӵ�
	{																		
		min++;
		sec = 0;
	}
	if(min >= 60)																	//1Сʱ��
	{											  	
		hour++;
		min = 0;
	}
	if(hour >= 24)   
	hour = 0;
	P0 = 0xff;																		//Protuse�����������
	if(key1_flag == 0)																//������ʱ
	{
		switch(k)
		{
			case 0:P0 = seven_seg[sec % 10]; P2 = ~0x01;break;
			case 1:P0 = seven_seg[sec / 10]; P2 = ~0x02;break;
		   	case 2:P0 = seven_seg[min % 10] & (0x7f | flash); P2 = ~0x04;break;		//С������˸
		   	case 3:P0 = seven_seg[min / 10]; P2 = ~0x08;break;
		   	case 4:P0 = seven_seg[hour % 10] & (0x7f | flash); P2 = ~0x10;break;	//С������˸
		   	case 5:P0 = seven_seg[hour / 10]; P2 = ~0x20;break;
		}
	}
	if(key1_flag == 1)																//��Сʱ��Сʱ��˸
	{
		j = 0;
		switch(k)
		{
			case 0: P0 = seven_seg[sec_t % 10]; P2 = ~0x01;break;
			case 1: P0 = seven_seg[sec_t / 10]; P2 = ~0x02;break;
		   	case 2: P0 = seven_seg[min_t % 10]; P2 = ~0x04;break;
		   	case 3: P0 = seven_seg[min_t / 10]; P2 = ~0x08;break;
		   	case 4: P0 = seven_seg[hour_t % 10] | flash; P2 = ~0x10;break;			//Сʱ��˸
		   	case 5: P0 = seven_seg[hour_t / 10] | flash; P2 = ~0x20;break;			//Сʱ��˸
		}
	}
	if(key1_flag == 2)																//������
	{
		j = 0;
		switch(k)
		{
			case 0: P0 = seven_seg[sec_t % 10]; P2 = ~0x01;break;
			case 1: P0 = seven_seg[sec_t / 10]; P2 = ~0x02;break;
		   	case 2: P0 = seven_seg[min_t % 10]| flash; P2 = ~0x04;break; 			//����˸
		   	case 3: P0 = seven_seg[min_t / 10]| flash; P2 = ~0x08;break;			//����˸
		   	case 4: P0 = seven_seg[hour_t % 10] ; P2 = ~0x10;break;
		   	case 5: P0 = seven_seg[hour_t / 10]; P2 = ~0x20;break;
		}
	}	
	if(key1_flag == 3)																//����
	{
		j = 0;
		switch(k)
		{
			case 0: P0 = seven_seg[sec_t % 10]| flash; P2 = ~0x01;break;			//����˸
			case 1: P0 = seven_seg[sec_t / 10]| flash; P2 = ~0x02;break;			//����˸
		   	case 2: P0 = seven_seg[min_t % 10]; P2 = ~0x04;break;
		   	case 3: P0 = seven_seg[min_t / 10]; P2 = ~0x08;break;
		   	case 4: P0 = seven_seg[hour_t % 10] ; P2 = ~0x10;break;
		   	case 5: P0 = seven_seg[hour_t / 10]; P2 = ~0x20;break;
		}
	}
	if(key1_flag == 4)																//������Сʱ
	{
		j = 0;
		switch(k)
		{
			case 0: P0 = seven_seg[min_r % 10]; P2 = ~0x01;break;
			case 1: P0 = seven_seg[min_r / 10]; P2 = ~0x02;break;
		   	case 2: P0 = seven_seg[hour_r % 10]| flash; P2 = ~0x04;break;			//����Сʱ��˸
		   	case 3: P0 = seven_seg[hour_r  / 10]| flash; P2 = ~0x08;break;			//����Сʱ��˸
			case 4: P0 = 0xff;P2 = ~0x10;break;										//����ʾ
			case 5: P0 = 0x0c;P2 = ~0x20;break;										//��ʾ�ַ�"P"
		}
	}
	if(key1_flag == 5)																//�����ַ���
	{
		j = 0;
		switch(k)
		{
			case 0: P0 = seven_seg[min_r % 10]| flash; P2 = ~0x01;break;			//���ַ���˸
			case 1: P0 = seven_seg[min_r / 10]| flash; P2 = ~0x02;break;			//���ַ���˸
		   	case 2: P0 = seven_seg[hour_r % 10]; P2 = ~0x04;break;
		   	case 3: P0 = seven_seg[hour_r  / 10]; P2 = ~0x08;break;
			case 4: P0 = 0xff;P2 = ~0x10;break;										//����ʾ
			case 5: P0 = 0x0c;P2 = ~0x20;break;										//��ʾ�ַ�"P"
		}
	}
	k++;
	if(k >= 6)k = 0;
}
void timer0_initi(void)																//�жϳ�ʼ������
{
	TMOD = 0x01;																	
	TH0 = 0xf8;
	TL0 = 0x2f;																		//ÿ�δ����жϺ��װ��ֵ��ʹ�´ζԻ����������2000��������������ж�  Լ0.2ms
	EA = 1;																			//�����ж�
	TR0 = 1;																		//������ʱ��T0
	ET0 = 1;																		//��T0�ж�
}
void main(void)
{
	timer0_initi();
	while(1)
	{
		key();																		//���ð�������
		if(min == min_r && hour == hour_r)											//��ʱ���������			
		SW = 1;																		//��������
		else 
		SW = 0;
	}
}
