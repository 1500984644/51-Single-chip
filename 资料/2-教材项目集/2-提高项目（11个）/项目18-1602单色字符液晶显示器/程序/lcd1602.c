#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar num[] = "0123456789";							//��ʾ��λ����ʱʹ��
sbit RS = P1^7;										//��������ѡ���
sbit RW = P1^6;										//��дѡ���
sbit E  = P1^5;										//ʹ���źŶ�
/*��ʱ����*/
void delay(uint x)
{
	while(x--);
}
/*��1602дһ������*/
void write_command(uchar command)
{
	RW = 0;			 //
	RS = 0; 		 //
	P0 = command;	 //
	E = 1;			 //
	delay(100);		//								//�ȴ����գ�ʡ���˶�״̬����
	E = 0;			//
	RW = 1;			//
}
/*��1602дһ������*/
void write_data(uchar date)
{
	RW = 0;
	RS = 1; 	
	P0 = date; 
	E = 1;
	delay(100);										//�ȴ�����
	E = 0;
	RW = 1;
}
/*��ʼ��1602*/
void F1602_init(void)
{
	write_command(0x38);							// ���У�ÿ��16�ַ���ÿ���ַ�5*7����	
	write_command(0x0f);							// �����ʾ����˸
	//write_command(0x0C);							// ��겻��ʾ
	write_command(0x06);							// ������ַ�����
}
/*��1602����*/
void F1602_clear()
{
	write_command(0x01);	
	write_command(0x02);	
}
/*��1602д�ַ���*/
void display_string(uchar *p)
{												
	while(*p)										//�ַ��ǿ�
	{
		write_data(*p);								//д�ַ�
		p++;										//����ָ���1
	}
}
/*��1602д���ֱ���(��λ)**/
void display_num(uchar x)
{
	 write_data(num[x / 10]);
	 write_data(num[x % 10]);	
}
/*��λ*/
void gotoxy(uchar y,uchar x)
{
	if(y == 1)
	write_command(0x80 + x);						//��һ��
	else if(y == 2)
	write_command(0x80 + 0x40 + x);	//�ڶ���
}
	
