//��ɫҺ����ʾ�����105��ʵ�鿪�������
//ͨ����ɫҺ����ʾ��ɫͼƬ��ʹ�õ�Ƭ��Ϊ15Fϵ�е�Ƭ��
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include <reg51.h>
#include <intrins.h>
#include<tupian.c>
#include<TFT.c>
void main(void)
{  
    P2 = 0xff;
    P0 = 0xff;   
    LCD_init();
    LCD_clear(0);
    pic_play(0,128,0,160);
//  pic_play(68,122,8,74);
// 	pic_play(7,61,82,148);
// 	pic_play(68,122,82,148);
    while(1);
}
