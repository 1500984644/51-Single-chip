//ULN2003�������̲ĺ�B105��ʵ�鿪����ͨ��
//key1_falg���Ƶ����ת  key2_flag���Ƶ����ת key3_flag���Ƶ��ֹͣ
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include <key.c>
#include <moto.c>
void main(void)
{ 
   	while(1)
    {  
      	key_scan();
		if(key1_flag == 1)
			motor_ffw();			//�����ת
		if(key2_flag == 1)
			motor_rev();			//�����ת
      	if(key3_flag == 1) 
			P2 = 0x0f;				//���ֹͣ
	}
}