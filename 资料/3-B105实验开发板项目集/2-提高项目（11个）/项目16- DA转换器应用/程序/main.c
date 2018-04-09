//PCF8591Ӧ�ã��̲ĺ�B105��ʵ�鿪����ͨ��
//DAת��
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<PCF8591.c>
code uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,
							0x92,0x82,0xf8,0x80,0x90};			//�����������0~9��ʾ����
uchar cp1,cp2,cp3;
sbit P1_0 = P1^0;
uint sec,temp,temp1;	
void display(void)
{	                                            
	switch(cp3)
	{
		case 0: P0 = 0xff; 										//������ֻ������������õ�
				P1_0 = 0;P0 = 0x01;P1_0 = 1;P1_0 = 0;
				P0 = seven_seg[sec % 10]; break;
		case 1: P0 = 0xff;
				P1_0 = 0;P0 = 0x02;P1_0 = 1;P1_0 = 0;
				P0 = seven_seg[sec / 10 % 10]; break;
		case 2:	P0 = 0xff;
				P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;
				P0 = seven_seg[sec / 100]& 0x7f; break;	
		case 3: P0 = 0xff;
				P1_0 = 0;P0 = 0x08;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;break; 
		case 4: P0 = 0xff;
				P1_0 = 0;P0 = 0x10;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;break;
		case 5:	P0 = 0xff;
				P1_0 = 0;P0 = 0x20;P1_0 = 1;P1_0 = 0;
		 	   	P0 = 0xbf;break; 
		case 6: P0 = 0xff;		 
				P1_0 = 0;P0 = 0x40;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;break;
		case 7: P0 = 0xff;
				P1_0 = 0;P0 = 0x80;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;
				break;
	}
	cp3++;
	if(cp3 >= 8)cp3 = 0;
}			   
void timer0_isr(void) interrupt 1
{	
	TH0 = (65536 - 2000) / 256;									//��װ��ֵ
	TL0 = (65536 - 2000) % 256;									//��װ��ֵ
	cp1++;														//�ж�1�Σ�������1
	if(cp1 >=  250)												//���뵽��	 
	{
		cp1 = 0;
		temp = temp + 10;
		if(temp >= 256)
		temp = 0;
		sec = temp*1.91;	
		DA_PCF8591(0x40,temp);									// ��ʾ��·������00ͨ�����������������ָ��		DA����
	}
	display();
}
void timer0_init(void)
{
	TMOD = 0x01;												//T0������ʽ1
	TH0 = (65536 - 2000) / 256;									//�Ի����������2000��������������ж�
	TL0 = (65536 - 2000) % 256;
	EA = 1;														//�����ж�
	ET0 = 1;													//��T0�ж�
	TR0 = 1;													//������ʱ��T0
}
void main(void)													//������
{
	timer0_init();
	while(1);													//�ȴ��ж�  
}