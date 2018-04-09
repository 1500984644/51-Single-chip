//LED������ʾ�����B105��ʵ�鿪�������
//ͨ��LED����ʾ����
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char 
#define uint unsigned int
sbit  ds1 = P2^1;
sbit  sh_cp1 = P2^0;
sbit  st_cp1 = P2^2;
sbit  ds2 = P2^6;
sbit  sh_cp2 = P2^5;
sbit  st_cp2 = P2^7;
sbit  OE = P2^3;
sbit  e = P2^4;
extern uchar code dat[];
extern void dat595(uchar as,uchar bs);									//����HC595�������ݺ���
extern void shuchu();													//����HC595������ݺ���
extern void suocun();													//����HC595�������ݺ���
/************����ȡģ**************************/
uchar code dat[] = {
/*--  ����:  ��  --*/
/*--  Times New Roman12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x00,0x24,0x24,0x24,0x24,0x24,0x24,0x7F,0x44,0x44,0x44,0x44,0x44,0x04,0x00,0x00,
0x40,0x40,0x40,0x40,0x40,0x42,0x41,0xFE,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
/*--  ����:  ��  --*/
/*--  Times New Roman12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
0x10,0x10,0x13,0xFF,0x12,0x11,0x10,0x00,0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,
0x20,0xC0,0x00,0xFF,0x00,0x82,0x0C,0x30,0xC0,0x00,0x00,0x00,0xFC,0x02,0x1E,0x00,
};
void dat595(uchar as,uchar bs)											//��HC595��������
{
	uchar i,b;
	e = 1;																			
	b = bs;																//��д�ڶ�����������ȡģ��ʱ������ģ�ĵڶ������ݣ���16������д��16*16���������2��8*8���� 
	for(i = 0; i < 8; i++)
	{					  		
		ds1 = b & 0x01;													//д����2�����λ	
		sh_cp1 = 0;	 
		_nop_();_nop_();_nop_();										//�ղ�����
		sh_cp1 = 1;														//��ʱ��������д������
		b >>= 1;														//����һλ
	}	
	b = as; 
	for(i = 0; i < 8; i++)												//��д��һ����������ȡģ��ʱ������ģ�ĵ�һ�����ݣ���16������д��16*16���������2��8*8����
	{	
		ds1 = b&0x01;													//д����1�����λ
		sh_cp1 = 0;	 
		_nop_();_nop_();_nop_();
		sh_cp1 = 1;														//��ʱ��������д������
		b >>= 1;														//����һλ
	}
}
void shuchu()															//HC595�������
{
	st_cp2 = 0;	
	st_cp1 = 0;
	st_cp2 = 1; 														//��ʱ���������������
	st_cp1 = 1;															//��ʱ���������������
}																		
void suocun()															//HC595��������
{
	sh_cp2 = 0;															//��ʱ��������д������
	sh_cp2 = 1;	
	ds2 = 1;
}
void main(void)
{
	uchar j;
	while(1)
	{
		OE = 0 ;
		ds2= 0 ;														//һ��ѡ��
		for(j  =0; j < 16; j++)											//д��"��"�ֵĵ���
		{
			dat595(dat[j],dat[16+j]);
			suocun();													//HC595���溯��
			shuchu();													//HC595�������
		} 	 
		for(j = 0; j < 16; j++)											//д��"��"�ֵĵ���
		{
			dat595(dat[32 + j], dat[32 + 16 +j ]);
			suocun();
			shuchu();
		}
	}
}

