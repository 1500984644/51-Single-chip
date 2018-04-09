//15��Ƭ���ڲ�EEPROMʹ�ã����B105��ʵ�鿪�������
//������Ӧ�ÿɱ�̣�IAP��������Ŀ����IAP��������ʱ��������,Ȼ���ٶ�������ʾ
//��ƣ���Ƭ�����¹�����----�������ƣ�2015��12��15��
#include<reg51.h>
#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#include<display.c>
#include<15fe2prom.c>
uint cp1,cp3;
void timer0_isr(void) interrupt 1
{
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	cp1++;
	if(cp1 >= 500)							//����
	{
		cp1 = 0;
		cp3++;
		flash = ~flash;
	}
	P0 = 0xff;
	display();								//ȥ��ʾ
	cp2++;
	if(cp2 >= 8)cp2 = 0;			
}
void timer0_init(void)
{
	TMOD = 0x01;
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void main(void)
{
	timer0_init();
	hour = IAP_ReadByte(0xa800);			//�ٶ������ʱ��
	min = read_dat_1b(0xaa00);
	sec = read_dat_1b(0xac00);
	while(1)
	{
		if(cp3 >= 2)						//1�뵽��
		{	
			cp3 = 0;
			sec++;

			if(sec >= 60){sec = 0;min++;}
			if(min >= 60){min = 0;hour++;}
			if(hour >= 24)hour = 0;
			save_dat_1b(0xa800,20);			//����ʱ��
//			save_dat_1b(0xaa00,30);
//			save_dat_1b(0xac00,10);
			IAP_EraseSector(0xa800);
			IAP_WriteByte(0xa800,hour);
			IAP_EraseSector(0xaa00);
			IAP_WriteByte(0xaa00,min);
			IAP_EraseSector(0xac00);
			IAP_WriteByte(0xac00,sec);
		}	
	}
}