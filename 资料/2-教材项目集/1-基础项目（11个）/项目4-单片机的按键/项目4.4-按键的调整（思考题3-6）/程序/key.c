sbit key1 = P3^0;					//���尴��1��P3.0
sbit key2 = P3^1;					//���尴��2��P3.1
unsigned char i = 23;
void delay(unsigned int x)
{
	while(x--);
}
void key_scan()
{
	if(key1 == 0)					//�����������
	{
		delay(300);					//��ʱ������������
		if(key1 == 0)				//�ٴ��жϰ����Ƿ���
		{
			while(key1 == 0);
			i++;
			if(i > 99) i = 0;
		}
	}
	if(key2 == 0)
	{
		delay(300);
		if(key2 == 0)
		{
			while(key2 == 0);
			i--;
			if(i < 0) i = 99;
		}
	}
}