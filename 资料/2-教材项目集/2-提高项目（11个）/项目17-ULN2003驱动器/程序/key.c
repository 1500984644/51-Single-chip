#define uchar unsigned char											//�궨����uchar ���� unsigned char
#define uint unsigned int											//�궨����uint ���� unsigned int
sbit key1 = P1^4;													//��ת				
sbit key2 = P1^5;													//��ת
sbit key3 = P1^6;													//ֹͣ
uchar key1_down,key2_down,key3_down,key1_flag,key2_flag,key3_flag;	//��������
/***************��������***************/
void delay(uint x)
{
	while(x--);
}
/************����ɨ�躯��*************/
void key_scan(void)
{
	if(key1 == 0)													//�����������
	{
		delay(100);													//��������
		if(key1 == 0)key1_down = 1;	
	}
	if(key1_down == 1 && key1 == 1)									//��������̧����Ч
	{
		key1_down = 0;
		key1_flag = 1;
		key2_flag = 0;
		key3_flag = 0;		
	}
	if(key2 == 0)													//�����������
	{
		delay(100);													//��������
		if(key2 == 0)key2_down = 1;									//��������̧����Ч
	}
	if(key2_down == 1 && key2 == 1)
	{
		key2_down = 0; 
		key2_flag = 1;
		key1_flag = 0;
		key3_flag = 0;
	}
	if(key3 == 0)													//�����������
	{
		delay(100);													//��������
		if(key3 == 0)key3_down = 1;									//��������̧����Ч
	}
	if(key3_down == 1 && key3 == 1)
	{
		key3_down = 0; 
		key3_flag = 1;
		key1_flag = 0;
		key2_flag = 0;
	}
}