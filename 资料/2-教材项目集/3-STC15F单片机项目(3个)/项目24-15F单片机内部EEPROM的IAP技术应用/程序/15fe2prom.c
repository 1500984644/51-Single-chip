//�ڲ�E2PROM����
//0-121��������61k��ǰ50����Ϊ���������ӵ�51������ʼ,
//��62������ΪIAPӦ�ô洢��,ÿ����������ʼ��ַΪ��
	/*0x6400,0x6600,0x6800,0x6a00,0x6c00,0x6e00,0x7000,0x7200,
	0x7400,0x7600,0x7800,0x7a00,0x7c00,0x7e00,0x8000,0x8200,
	0x8400,0x8600,0x8800,0x8a00,0x8c00,0x8e00,0x9000,0x9200,
	0x9400,0x9600,0x9800,0x9a00,0x9c00,0x9e00,0xa000,0xa200,
	0xa400,0xa600,0xa800,0xaa00,0xac00,0xae00,0xb000,0xb200,
	0xb400,0xb600,0xb800,0xba00,0xbc00,0xbe00,0xc000,0xc200,
	0xc400,0xc600,0xc800,0xca00,0xcc00,0xce00,0xd000,0xd200,
	0xd400,0xd600,0xd800,0xda00,0xdc00,0xde00,
	*/
#include<intrins.h>
sfr IAP_DATA = 0XC2;
sfr IAP_ADDRH = 0XC3;
sfr IAP_ADDRL = 0XC4;
sfr IAP_CMD = 0XC5;
sfr IAP_TRIG = 0XC6;
sfr IAP_CONTR = 0XC7;

#define CMD_IDLE      0
#define CMD_READ      1
#define CMD_PROGRAM   2
#define CMD_ERASE     3
#define ENABLE_IAP 	0x86
#define IAP_ADDRESS 0x6400						//e2prom�׵�ַ

void IAP_Idle(void)								//IAP����ʹ�ܺ���
{
	IAP_CONTR = 0;
	IAP_CMD = 0;	
	IAP_TRIG = 0;
	IAP_ADDRH = 0x64;
	IAP_ADDRL = 0;
}
unsigned char IAP_ReadByte(uint addr)			//��ISP/IAP/EEPROM����ȡһ���ֽڣ���ַΪaddr
{
	uchar x;
	IAP_CONTR = ENABLE_IAP;
	IAP_CMD	= CMD_READ; 
	IAP_ADDRL = addr;	
    IAP_ADDRH = addr >> 8;
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	_nop_();
	x = IAP_DATA;
	IAP_Idle();
	return x;
}
void IAP_WriteByte(uint addr,uchar x)			//��һ�ֽ����ݵ�ISP/IAP/EEPROM���򣬵�ַΪaddr
{
	IAP_CONTR = ENABLE_IAP;
	IAP_CMD	= CMD_PROGRAM;    
	IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
	IAP_DATA = x;
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	_nop_();
	IAP_Idle();
}
void IAP_EraseSector(uint addr)					//������������512�ֽڣ�addrΪ�������׵�ַ
{
	IAP_CONTR = ENABLE_IAP;
	IAP_CMD	= CMD_ERASE;
	IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	_nop_();
	IAP_Idle();
}
void save_dat_1b(unsigned int x1,unsigned char x2)
{
	IAP_EraseSector(x1);
	IAP_WriteByte(x1,x2);
}
/*
void save_dat_2b(uint x1,uint x2)
{
	uchar da1,da2;
	da1 = x2;									//���ݵ�8λ
	da2 = x2 >> 8;								//���ݸ�8λ
	IAP_EraseSector(x1);
	IAP_WriteByte(x1,da1);
	IAP_WriteByte(x1+1,da2);
}
void save_dat_4b(uchar x,uint x1,uint x2)
{
	uchar da1,da2,da3,da4;
	if(x >= 62)x = 62;							//��ౣ��62������
	da1 = x1;									//���ȵ�8λ
	da2 = x1 >> 8;								//���ȸ�8λ
	da3 = x2;									//������8λ
	da4 = x2 >> 8;								//������8λ
	IAP_EraseSector(add[x]);
	IAP_WriteByte(add[x],da1);
	IAP_WriteByte(add[x] + 1,da2);
	IAP_WriteByte(add[x] + 2,da3);
	IAP_WriteByte(add[x] + 3,da4);
}*/
uchar read_dat_1b(uint x)
{
	uchar i;	
	i = IAP_ReadByte(x);
	return(i);
}
/*
uint read_dat_2b(uint x)
{
	uint i,j;	
	i = IAP_ReadByte(x);
	j = IAP_ReadByte(x + 1);
	j = j << 8;
	i = i | j;
	return(i);
}
uint read_add_4b(uint x,uchar y)
{
	uint i,j;	
	i = IAP_ReadByte(add[x] + y);
	j = IAP_ReadByte(add[x] + y + 1);
	j = j << 8;
	i = i | j;
	return(i);
}
*/
