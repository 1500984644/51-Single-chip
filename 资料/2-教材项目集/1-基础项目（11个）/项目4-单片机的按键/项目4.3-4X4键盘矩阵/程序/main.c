//4*4���̾��󰴼�����Խ̲����
//����������ʾ��ֵ��������ʾ"88"
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#define uchar unsigned char
code P1_scan[]={0x7f,0xbf,0xdf,0xef};
code key_temp_value[]={0xee,0xed,0xeb,0xe7,
					   0xde,0xdd,0xdb,0xd7,
					   0xbe,0xbd,0xbb,0xb7,
					   0x7e,0x7d,0x7b,0x77};
code uchar seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uchar n = 88;
void delay(uchar x)
{
	while(x--);
}
uchar key_scan(void)
{
	uchar i,j;
	for(i = 0;i < 4;i++)							//�ü����������ɨ������
	{
		P1 = P1_scan[i];
		if(P1 != P1_scan[i])
		{
			delay(200);								//�����������а���ȷʵ����
			if(P1 != P1_scan[i])					//����а������£�P1�ڲ���ԭ����ɨ������
			{
				for(j = 0;j < 16;j++)
				{
					if(P1 == key_temp_value[j])		//�жϼ�ֵ�����ĸ���������
					n = j;							//���ذ����ı��
				}
			}
		}
	}
	return (n);										//���û�а������£������־"88"
}
void display(uchar i)								//��ʾ����
{
	P2 = ~0x01;P0 = seven_seg[i % 10];				//��ʾ������Ÿ�λ
	delay(300);										//�ø�λ��ʾһ��ʱ��
	P2 = ~0x02;P0 = seven_seg[i / 10];				//��ʾ�������ʮλ
	delay(300);										//��ʮλ��ʾһ��ʱ��
	P0 = 0xff;										//ˢ��P0�ӿڣ�������
}
void main()
{
	uchar i;
	while(1)
	{
		i = key_scan();
		display(i);
	}
}