#include<reg51.h>
sbit key1 = P1^4;																//ģʽ��
sbit key2 = P1^5;																//���Ӽ�
sbit key3 = P1^6;																//���ټ�
sbit key4 = P1^7;																//�˳��趨��ȡ������
bit key1_s,key2_s,key3_s,key4_s;												//��������״̬
unsigned char hour = 12,min = 30,sec =30;										//�����ߵ�ʱ�����
char hour_t,min_t,sec_t;														//�������м�ʱ�����
unsigned char min_r,hour_r;														//���ֵ�ʱ�����
unsigned char key1_flag;														//�������Ʊ��������Ƶ������󡢿�����ʾ����
void delay(unsigned int x)														//��ʱ����
{											   	
	while(x--);
}											 	
void key(void)																	//��������
{
	if(key1 == 0)																//����key1����
	{
		delay(300);
		if(key1 == 0);
		key1_s = 1;
	}
	if(key1 == 1 && key1_s == 1)
	{
		key1_s = 0;
		key1_flag++;
		if(key1_flag >= 6)key1_flag = 1;
		hour_t = hour;															//�������ߵ�ʱ�������ֵ
		min_t = min;
		sec_t = sec;	
	}
	if(key2 == 0)																//����key2����
	{
		delay(300);
		if(key2 == 0);
		key2_s = 1;
	}
	if(key2 == 1 && key2_s == 1)
	{
		key2_s = 0;
		if(key1_flag == 1)hour_t++;if(hour_t >= 24)hour_t = 0;hour = hour_t;	//��Сʱ���е��ڣ��ѵ������ʱ�丳ֵ���ߵ�ʱ��
		if(key1_flag == 2)min_t++;if(min_t >= 60)min_t = 0;min = min_t;			//�Է��ӽ��е��ڣ��ѵ������ʱ�丳ֵ���ߵ�ʱ��
		if(key1_flag == 3)sec_t++;if(sec_t >= 60)sec_t = 0;sec = sec_t;			//��Сʱ���е��ڣ��ѵ������ʱ�丳ֵ���ߵ�ʱ��
		if(key1_flag == 4)hour_r++;if(hour_r >= 24)hour = 0;					//��Сʱ���е��ڣ��ѵ������ʱ�丳ֵ���ߵ�ʱ��
		if(key1_flag == 5)min_r++;if(min_r >= 24)min_r = 0;						//��Сʱ���е��ڣ��ѵ������ʱ�丳ֵ���ߵ�ʱ��
	}
	if(key3 == 0)																//����key3����
	{
		delay(300);
		if(key3 == 0);
		key3_s = 1;
	}
	if(key3 == 1 && key3_s == 1)
	{
		key3_s = 0;
		if(key1_flag == 1)hour_t--;if(hour_t <= 0)hour_t = 23;hour = hour_t;
		if(key1_flag == 2)min_t--;if(min_t <= 0)min_t = 59;min = min_t;
		if(key1_flag == 3)sec_t--;if(sec_t <= 0)sec_t = 59;sec = sec_t;
		if(key1_flag == 4)hour_r--;if(hour_r <= 0)hour = 23;
		if(key1_flag == 5)min_r--;if(min_r <= 0)min_r = 59;		
	}
 	if(key4 == 0)																//����key4����
	{
		delay(300);
		if(key4 == 0);
		key4_s = 1;
	}
	if(key4 == 1 && key4_s == 1)																				
	{
		key1_flag = 0;
		key4_s = 0;
	}
}
