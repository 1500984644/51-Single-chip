sbit din = P1^5;							//����λ���� ��������˿�
sbit scl = P1^1;							//����λ���� ����˿�
sbit cs = P1^6;								//����λ���� оƬƬѡ�˿�
#define uchar unsigned char					//�궨�� ����uchar ����unsigned char 
#define uint unsigned int					//�궨�� ����uint ����unsigned int
/***************TLC5615��ʼ������*********************/
void tlc5615_init(void)
{
	cs = 1;
	scl = 0;
	cs = 0;
}

/* ************TLC5615ת������***********************/
void tlc5615(uint dat)						//����TLC5615��ʮλת��������һ��16λ�ı���
{
	uchar i;
	dat <<= 6;								//�����ֽ���ʮ��λ��ȥ������λʣ��ʮλ��Чλ
	tlc5615_init();							//��ʼ��
	for(i = 0;i < 12;i ++)	
	{
		din = (bit)(dat & 0x8000);
		scl = 1;							//ǰ��һ�������DA = CY�����棬�������˳��Ҫ��������
		dat <<= 1;
		scl = 0;
	}
	cs = 1;
	scl = 0;       
}