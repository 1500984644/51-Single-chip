//��Ƭ���ڲ����Ź�Ӧ�ã��̲ĺ�B105��ʵ�鿪����ͨ��
//�������Ź����趨���Ź����ʱ��Ϊһ�룬�����Ź������λ��LED�Ʋ�ͣ��˸	
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
sfr WDT_CONTR = 0xe1;			//���嵥Ƭ���ڲ����Ź��Ĵ���
sbit LED = P0^0;
void delay(uint x)
{
	while(x--);
}
void main(void)
{
	WDT_CONTR = 0x24;			//�������Ź����趨���Ź����ʱ��Ϊһ��	
	while(1)
	{
		//WDT_CONTR = 0x14;		//ι���������δ˾䣬���Ź������λ��LED�Ʋ�ͣ��˸
		LED = 1;
		delay(50000);
		LED = 0;
		delay(50000);	;
	}
}