//4*4���̾��󰴼�
//����������ʾ��ֵ��������ʾ��88��
//���ϿƼ�ѧԺ-��Ƭ��Э�ᣬ2016��10��9��		 
#include<reg51.h>
sbit P3_0 = P3^0;
code unsigned char seven_seg[10] = {0xc0,0xf9,0xa4,0xb0,0x99,
									0x92,0x82,0xf8,0x80,0x90,};
code unsigned char key_scan[] = {0xef,0xdf,0xbf,0x7f,};
code unsigned char key_num[] = 	{
									0xee,0xed,0xeb,0xe7,
									0xde,0xdd,0xdb,0xd7,
									0xbe,0xbd,0xbb,0xb7,
									0x7e,0x7d,0x7b,0x77,
								}; //�������µļ�ֵ

void delay(unsigned int x)					//��ʱ����
{
	while(x--);
}
void display(unsigned char x)				//��ʾ����
{	
	P0 = 0xff;								//ˢ��P0�ڣ�������
	P3_0 = 0;P0 = 0x01;P3_0 = 1;P3_0 = 0;
	P0 = seven_seg[x % 10];					//��ʾ������ŵĸ�λ
	delay(300);								//�ø�λ��ʾһ��ʱ��
	P0 = 0xff;									//ˢ��P0�ڣ�������
	P3_0 = 0;P0 = 0x02;P3_0 = 1;P3_0 = 0;
	P0 = seven_seg[x / 10];					//��ʾ������ŵ�ʮλ
	delay(300);								//��ʮλ��ʾһ��ʱ��
}
unsigned char key(void)						//��������
{
	unsigned char i,j;
	for(i = 0;i < 4;i++)
	{
		P2 = key_scan[i];
		if(P2 != key_scan[i])
		{
			delay(500);							//�����������а���ȷʵ����
			if(P2 != key_scan[i]);				//����а������£�P2�ڲ���ԭ��ɨ������
			for(j = 0;j < 16;j++)				//�ü����������ɨ������
			{
				if(P2 == key_num[j])return(j);	//�жϼ�ֵ,���ذ����ı��				
			} 
		}
	}
	return(88);			//���û�а������£������׼"88"
}
void main(void)			//������
{
	unsigned char k;
	while(1)
	{
		k = key();
		display(k);
	}			
}