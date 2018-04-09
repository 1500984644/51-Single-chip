//TLC549Ӧ�ã���Խ̲����
//ʵʱ��ȡ��ȡtlc549�ļ���ѹ����
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg52.h>
#include<tlc549.c>
code uchar  seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,									  	
							0x92,0x82,0xf8,0x80,0x90};											//����0~9����ʾ����
uchar cp1,cp2;
uint dat_ad;
/***************�ж�T0��ʼ������**************/
void timer0_isr(void) interrupt 1																// timer0�жϷ�����
{
	TL0 = (65535 - 5000) % 255;
	TH0 = (65535 - 5000) / 255;             
	cp1++;
	if(cp1 >= 100) 																				//0.5��
	{
		cp1 = 0;
		dat_ad = tlc549_ad();
		dat_ad = dat_ad * 1.96;																		//����255��Ӧģ���ѹ5V 
	}
	P0 = 0xff;																					//Protuse����ʱ��������
	switch(cp2)
	{
		case 0: P0 = seven_seg[dat_ad % 10];P2 = ~0x01; break;   	
		case 1: P0 = seven_seg[dat_ad / 10 %10];P2 = ~0x02; break;   	
		case 2: P0 = seven_seg[dat_ad / 100] & 0x7f;P2 = ~0x04; break;							//����С���� 	
	}                
	cp2++;
	if(cp2 >= 3)
	cp2 = 0;
}
/**************�ж�T0�жϷ�����************/
void timer0_init (void)            																// timer0�жϳ�ʼ������
{                   
	TMOD = 0x01;                                  
	TL0 = (65535 - 5000) % 255;
	TH0 = (65536 - 5000) / 256;                                     
	ET0 = 1;                     
	EA = 1;                      
	TR0 = 1;                      
}
/**************������*********************/ 						
void main(void)				 																	//������
{  
	timer0_init();
	while(1);
}