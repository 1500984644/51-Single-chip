//P0��������ˮ��
//8���ư�˳��ѭ����˸
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
unsigned char  LED[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//��ˮ������
void delay(unsigned int x)	//��ʱ����
{
	while(x--);
}
void main(void)				//������
{
	unsigned char i;	
	while(1)
	{
		P0 = LED[i];		//���ε�������������
		delay(50000);		//��ʱ
		i++;			    //ѭ��1�Σ�������1
		if(i >= 8)i = 0;	//��8����
	}
}