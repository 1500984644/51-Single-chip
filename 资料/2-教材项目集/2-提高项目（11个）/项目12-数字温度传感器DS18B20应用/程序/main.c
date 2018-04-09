//�����¶ȴ�����Ӧ�ã��̲ĺ�B105��ʵ�鿪����ͨ��
//ʵʱ��ȡ������ʾ�¶�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<ds18b20.c>	
sbit P1_0 = P1^0;	
code  uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};			//��������������Ա���
uchar cp1,cp2;
uint aa;
uint temp_num,temp_num1,temp_dot,temp;													//temp_num��temp_num1Ϊ�¶��������֣�temp_dotС�����֣��м����temp
void timer0_init(void)																	//�жϷ�����	 
{
	TMOD = 0x01;
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	TR0 = 1;
	EA  = 1;
	ET0 = 1;
}
void timer0_isr(void) interrupt 1														//�жϷ�����		  	
{
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	cp1++;
	if(cp1 >= 250)                              										//1��
   {
		cp1 = 0;
		temp_num = Read_Temperature();													//�õ��¶�����
		temp_dot =  c * 0.625;															//�õ��¶�С��
		if((temp_num & 0x80) == 0x80)													//����¶�Ϊ��ֵ
		{	
			temp_dot = (0x0f - c) * 0.625;												//����ת��ԭ�룬С������
			temp_num1 = 0xff - temp_num;												//����ת��ԭ�룬��������	
		}
		else temp_num1 = temp_num;														//С��ת��Ϊʮ����
	}
	P0 = 0xff;
	switch(cp2)
	{
		case 0: P0 = 0xff;																//����
				P1_0 = 0;P0 = 0x01;P1_0 = 1;P1_0 = 0;
				P0 = seven_seg[temp_dot]; break;										//С��������ʾ
		case 1: P0 = 0xff;
				P1_0 = 0;P0 = 0x02;P1_0 = 1;P1_0 = 0;
				P0 = 0x7f & seven_seg[temp_num1 % 10%10]; break;						//�������ָ�λ��ʾ
		case 2:
			{	
				if(temp_num < 10)
				{
					P0 = 0xff;
					P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;
					P0 = 0xff; break;
				}																		//����¶�С��10�ȣ���Ϊ��ֵ��ʮλ0����ʾ
				if((temp_num > 0x80) && ( temp_num1 < 10))
				{
					P0 = 0xff;
					P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;
					P0 = 0xbf; break;
				}																		//����¶�С��10�ȣ���Ϊ��ֵ��ʮλ0����ʾ��ֻ��ʾ"-"
					P0 = 0xff;
					P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;
					P0 = seven_seg[temp_num1 / 10%10]; break;							//����¶ȴ���10�ȣ�10λ������ʾ
			}
		case 3:
			{
				if((temp_num < 0x80) && (temp_num1 >= 100))
				{		
					P0 = 0xff;
					P1_0 = 0;
					P0 = 0x08;
					P1_0 = 1;
					P1_0 = 0;
					P0 = seven_seg[temp_num1 / 100]; break;								//����¶�Ϊ��ֵ����ʮλ��Ϊ0����λ��ʾ"-"
				}
			
			}
	 	case 4:
			{
				if((temp_num > 0x80) && ((temp_num1 / 10) > 0))
				{
					P0 = 0xff;
					P1_0 = 0;P0 = 0x08;P1_0 = 1;P1_0 = 0;
					P0 = 0xbf; break;													//����¶�Ϊ��ֵ����ʮλ��Ϊ0����λ��ʾ"-"
				}
			}
	}
	cp2++;
	if(cp2 >= 5)
	cp2=0;
}
void main(void)	
{
	timer0_init();
	write_temprom(128,-55);																//��18B20���ݴ�д�ϡ������¶ȷֱ�Ϊ128��-55
	Write_OneChar(0x48);																//��18B20��rom��д����		
	while(1)
	{
	 	temp = read_temprom;															//����DS18B20�ж�ȡ���¶ȸ�����temp 
	}
}
