//AT24C04Ӧ�ã��̲ĺ�B105��ʵ�鿪����ͨ��
//��ȡ���Ҵ洢��ַ��
//��ƣ���Ƭ�����¹�����--��������ƣ�2015��12��15��
#include<reg51.h>								//ͷ�ļ�
#include<at24c04.c>								//����AT24C04������ͷ�ļ�
#define uint unsigned int
void delay(uint x)
{
	while(x--);
}
void main(void)
{
	init_2404();							   //AT24C04����
	while(1)
	{
		write_add_dat_2404(1,0x0f);			   //��ַ1����0x0f
		delay(300);
		write_add_dat_2404(2,0xf0);			   //��ַ2����0xf0
		delay(300);
		P0 = read_add_dat_2404(1);			   //����ַ1����0x0f������P0����ʾ
		delay(50000);
		P0 = read_add_dat_2404(2);			   //����ַ2����0xf0������P0����ʾ
		delay(50000);
	}
}