//LCD1602Һ����Ӧ�ã����B105���������
//LCD1602������ʾ�����ַ���ÿ����������ʾ16���ַ�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<74hc595.c>
#include<lcd1602.c>
#define uchar unsigned char
#define uint unsigned int
/*******************������*******************/
void main (void)  
{
	FLCD1602_init();
  	FLCD1602_clear();
  	while(1)
  	{ 	
		gotoxy(1,0);											//�ӵ�һ�е�һλ��ʼ��ʾ
  		display_string("How are you");							//��һ����ʾ��How are you������
  		gotoxy(2,0);											//�ӵڶ��е�һλ��ʼ��ʾ
  		display_string("dat:2012/09/01");						//�ڶ�����ʾ��dat��2012/09/01��
  		delay(50000);delay(50000);delay(50000);delay(50000);	
	} 
}