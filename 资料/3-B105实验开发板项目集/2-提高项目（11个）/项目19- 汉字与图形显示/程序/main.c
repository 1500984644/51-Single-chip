//LCD1286Һ������ʾ�����B105��ʵ�鿪�������
//��һ����ʾͼƬ���Ķ�����ʾ����
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include"LCD12864.c"
#include <intrins.h>
void Delay1000ms()						//@11.0592MHz
{
	unsigned char i, j, k;
	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void main(void)
{
   	initinal();
   	gui_clear();
   	Display_Clear();
	xianshi();							//��һ��ͼƬ��ʾ
	Delay1000ms();	Delay1000ms();
	gui_clear();
   	while(1)
	{	
		lcd_mesg(1,1,12,"����һ��ƽ����");
		lcd_mesg(2,1,12,"ף��һ����˳��");
		lcd_mesg(3,1,9,"123456789");
		lcd_mesg(4,1,12,"abcdefghij");	
	}
}
