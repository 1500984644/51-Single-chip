//1602��ɫ�ַ�Һ����ʾ������Խ̲����
//ͨ��1602��ɫҺ����ʾ��
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<lcd1602.c>
void main (void)  
{
  	uchar i,sec = 56;
	F1602_init();
  	F1602_clear();
  	while(1)
  	{ 																	//��������
  		F1602_clear();
		display_string("How are you");	
  		gotoxy(2,0);																	//��λ�ڶ���
  		display_string("dat:2012/09/01");
  		delay(50000);
		delay(50000);
		delay(50000);
		delay(50000);							//��һ����ʱ
  		F1602_clear();
  		display_string("Time:");
		display_num(sec);
		display_string("  ");
		display_num(i);		//iΪ�ظ���ʾ�Ĵ���	
		gotoxy(2,0);
		display_string("End");	
		delay(50000);
		delay(50000);
		delay(50000);
		delay(50000);							//�ڶ�����ʱ
		i++;if(i > 100)i = 0;
	} 
}
