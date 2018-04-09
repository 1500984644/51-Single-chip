#define uchar unsigned char
#define uint unsigned int
sbit DQ = P1^2;													//���嵥Ƭ����P2.7��DS18B20���ݶ˿�������һ��                                    													 
/********��ʱ����********/
void delay(uint x)
{
	while(x--); 
}
/********��ʼ������********/
void Init_DS18B20(void)											//������������1
{
	unsigned char x = 255;
	DQ = 1;														//����DQ��1
	DQ = 0;														//��Ƭ����DQ����
	delay(80);													//��ʱ480-960us
	DQ = 1;														//�ͷ�����
	while(DQ && x--);											//�ȴ����صĵ͵�ƽ��Ӧ ���û����Ӧ������������ʱ�Զ�����ִ��
	delay(20);
}
/********��DS18B20�ж�һ���ֽ�********/
uchar Read_OneChar(void)										//������������2
{
	uchar i = 0;
	uchar dat = 0;
	for (i=8;i>0;i--)
	{
  		DQ = 0;													//���������ź�
  		dat >>= 1;									  	
  		DQ = 1;													//�ͷ�����
  		if(DQ)													//�ж������Ƿ�Ϊ�ߵ�ƽ
  		dat |= 0x80;											//����Ǹߵ�ƽ�����dat�����λ��1��������ǣ�Ĭ����0
  		delay(10);
	}
	return(dat);
}
/********��18B20��дһ���ֽ�********/
void Write_OneChar(uchar dat)									//������������3
{
	uchar i=0;
	for (i=8; i>0; i--)
	{
		DQ = 0;
		DQ = dat & 0x01;										//ȡdat�����λ
		delay(10);
		DQ = 1;
		dat >>= 1;
	}
	delay(8);
}
/********��ȡ�¶�********/
uchar a,b,c;
uchar Read_Temperature(void)									//Ӧ�ò�������1
{
	uchar i = 0,t = 0;
	Init_DS18B20();
	Write_OneChar(0xcc);										// ����������кŵĲ���
	Write_OneChar(0x44);										// �����¶�ת��
	Init_DS18B20();
	Write_OneChar(0xcc);										//����������кŵĲ���
	Write_OneChar(0xbe);										//��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	a = Read_OneChar();											//��ȡ�¶�ֵ��λ
	b = Read_OneChar();											//��ȡ�¶�ֵ��λ
	c = 0x0f & a;												//�õ�С������
	a = a >> 4;													//��λ����4λ
	b = b << 4;													//��λ����4λ
     t = a | b;													//�õ�8λ�¶ȵ��������֣����1λΪ����λ
	return(t);
}
/********�����¶�������********/
void write_temprom(uchar temp_up_set,uchar temp_down_set )		//Ӧ�ò�������2
{
 	Init_DS18B20();
	Write_OneChar(0xcc);										//����������кŵĲ���
	Write_OneChar(0x4e);										//д׼�� 
	Write_OneChar(temp_up_set);									//��18B20���ݴ�д����		 
	Write_OneChar(temp_down_set);								//��18B20���ݴ�д����
	Write_OneChar(0x7f);
	Init_DS18B20();
	Write_OneChar(0xcc); 
	Write_OneChar(0x48);										//��18B20��rom��д����
	Init_DS18B20();
	Write_OneChar(0xcc);
	Write_OneChar(0xb8);
} 
/********��ȡ�¶�������********/
uchar  temp_up,temp_down;										//�¶�������ֵ
void read_temprom(void)											//Ӧ�ò�������3
{
   	uchar i;
	Init_DS18B20();
	Write_OneChar(0xcc);										//����������кŵĲ���        	
	Write_OneChar(0xbe);										//��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	i = Read_OneChar();											//��0��ַ�Ĵ������ӵ�
	i = Read_OneChar();											//��1��ַ�Ĵ������ӵ�
	temp_up = Read_OneChar();									//��2��ַ�Ĵ���
	temp_down = Read_OneChar();									//��3��ַ�Ĵ���
}

