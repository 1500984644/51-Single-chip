/***************************************************************/
/******************AT24C04��������2015��12��15��*******************/
/***************************************************************/
#include <intrins.h>					  //�⺯����ͷ�ļ�
#define uchar unsigned char				  //�궨�壬��uchar����unsigned char
#define nop _nop_()
sbit sda = P1^0;						  //��sda��P1.0�˿�
sbit scl = P1^1;						  //��scl��P1.1�˿�
/****************************I2C���߿�ʼ*************************/
void start_2404(void)
{
	sda = 1;
	nop;
	scl = 1;
	nop;
	sda = 0;
	nop;
	scl = 0;
	nop;
}
/****************************I2C����ֹͣ*************************/ 
void stop_2404(void)
{
	sda = 0;
	nop;
	scl = 1;
	nop;
	sda = 1;
	nop;
}
/****************************Ӧ�����*************************/
void ack_2404(void)
{
	uchar i = 255;
	scl = 1;
	nop;
	while(sda && i--);
	scl = 0;
	nop;
}
/****************************I2C���߳�ʼ��*************************/
void init_2404(void)
{
	sda = 1; nop;	   					//��̬
	scl = 1; nop;	   					//��̬
}
/****************************����һ�ֽ�*************************/
uchar read_onebyte_2404(void)
{
	uchar i, dat;
	sda = 1; 							//�ͷ�����
	for(i = 8; i > 0; i--)
	{
		scl = 1;
		dat <<= 1;
		if(sda) dat |= 0x01;
		scl = 0;
	}
	sda = 1; scl = 0;
	return(dat);
}
/****************************д��һ���ֽ�*************************/
void write_onebyte_2404(uchar dat)
{
	uchar i;
	for(i = 8; i > 0; i--)
	{
		sda = (bit)(dat & 0x80);		//�ȷ������ݵĸ�λ
		dat <<= 1;
		scl = 1;
		scl = 0;
	}
	sda = 1; scl = 0;
}
/****************************��ĳһ��ַдһ���ֽ�����*************************/
void write_add_dat_2404(uchar add, uchar dat)
{
	start_2404();
	write_onebyte_2404(0xa0);
	ack_2404();
	write_onebyte_2404(add);
	ack_2404();
	write_onebyte_2404(dat);
	ack_2404();
	stop_2404();
}
/****************************��ĳһ��ַĳһ���ֽ�����*************************/
uchar read_add_dat_2404(uchar add)
{
	uchar dat;
	start_2404();
	write_onebyte_2404(0xa0);
	ack_2404();
	write_onebyte_2404(add);
	ack_2404();
	start_2404();
	write_onebyte_2404(0xa1);
	ack_2404();
	dat = read_onebyte_2404();
	stop_2404();
	return(dat);
}