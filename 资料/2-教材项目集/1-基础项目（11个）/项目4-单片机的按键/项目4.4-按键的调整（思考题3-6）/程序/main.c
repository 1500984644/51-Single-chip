//���ð�����������ܵ���ֵ����Խ̲����
//�����������ֱ���ƼӺͼ�
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<key.c>
sbit P1_0 = P1^0;
unsigned char k;
code unsigned char seven_seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void display()				//��ʾ����
{
	P0 = 0xff;
	switch(k)
	{
		case 0:P0 = 0x01;P1_0 = 0;P1_0 = 1;P1_0 = 0;P0 = seven_seg[i % 10];break;
		case 1:P0 = 0x02;P1_0 = 0;P1_0 = 1;P1_0 = 0;P0 = seven_seg[i / 10];break;
	}
	k++;
	if(k > 1) k = 0;
}
void main()
{
	while(1)
	{
		key_scan();			//���ð�������
		display();			//������ʾ����
		delay(300);			
	}
}