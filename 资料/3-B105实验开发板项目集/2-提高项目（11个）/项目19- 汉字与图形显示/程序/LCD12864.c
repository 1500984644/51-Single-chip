#include <reg51.h>
#include <stdio.h>
#include <math.h>
#include "tupian.c"
uchar len;
uchar xdata RAM[64][16];
sbit    CS =P0^3;						//4������
sbit    SID=P0^4;						//5������
sbit    SCK=P0^5;						//6������ 
sbit    RES=P0^6;						//17������ 
void  delay(uint m)						//��ʱ����
{
	uint i,j;
	for(i=0;i<m;i++)
	for(j=0;j<10;j++);
}
void SendByte(uchar Dbyte)
{
     uchar i;
     for(i=0;i<8;i++)
     {
           SCK = 0;
           Dbyte=Dbyte<<1;				//����һλ
           SID = CY;					//�Ƴ���λ��SID
           SCK = 1;
           SCK = 0;
     }
}
/*************************************************
д����
*************************************************/
void TransferCom(uchar data0)  
{
  CS=1;
  SendByte(0xf8);						//11111ABC,RW(0),RS(1),0
  SendByte(0xf0&data0);					//����λ
  SendByte(0xf0&data0<<4);				//����λ(��ִ��<<)
  CS=0;
}

/*************************************************
д����
*************************************************/
void TransferData(uchar data1)  
{
  CS=1;
  SendByte(0xfa);						//11111ABC,RW(0),RS(1),0
  SendByte(0xf0&data1);					//����λ
  SendByte(0xf0&data1<<4);				//����λ(��ִ��<<)
  CS=0;
}
/*************************************************
Һ����ʼ�� ����
*************************************************/
void initinal(void)						//LCD�ֿ��ʼ������
{
	delay(40);							//����40MS����ʱ����
	RES=0;								//��λ
	delay(1);							//��ʱ
	RES=1;								//��λ�ø�
	delay(10);	
	TransferCom(0x30);					//Extended Function Set :8BIT����,RE=0: basic instruction set, G=0 :graphic display OFF
	delay(100);							//����100uS����ʱ����
	TransferCom(0x0c);					//Display Control,D=1,��ʾ��
	delay(100);							//����100uS����ʱ����
	TransferCom(0x01);					//Display Clear
	delay(10);							//����10mS����ʱ����
	TransferCom(0x06);					//Enry Mode Set,�����������1λ�ƶ�
	delay(100);							//����100uS����ʱ����
}
//��������
//********************************************************
void Display_Clear(void)
{
	TransferCom(0x01);					//д�������ʾ����0x01
	delay(100);
}
/*************************************************
 ������ʾ
*************************************************/
void lcd_mesg(uchar han,uchar lie,uchar k,uchar *chn)
{	
	uchar i;
	switch(han)
	{
		case 1:TransferCom(0x80+lie);break;
		case 2:TransferCom(0x90+lie);break;
		case 3:TransferCom(0x88+lie);break;
		case 4:TransferCom(0x98+lie);break;
		default:;
	}
	delay(100);
	len=sizeof(chn);
	for(i=0;i<k;i++)
	{
		TransferData(chn[i]);
	}
}

//**********��ͼ��ʾ������������������ָ���ڻ�ͼʱ�����ã�
void gui_clear()
{
	uchar i,j,k;
	TransferCom(0x34);					//��չָ���8λ���ݴ���
	TransferCom(0x34);					//�رջ�ͼ
	for(i = 0; i < 2; i ++)				//����������д  
	{   
	  for(j = 0; j < 32; j ++)   
		{    
		    TransferCom(0x80 + j);		//дy����    
			delay(1);     
			if(i == 0)					//дx����    
			{      
				TransferCom(0x80);      
				delay(1);    
			}
			else						//д�°���    
			 {      
			   TransferCom(0x88);      
			   delay(1);    
			 }     
			 for(k = 0; k < 16; k ++)	//дһ��������    
			 {     
				 TransferData(0x00);	//д���ֽ�     
				 TransferData(0x00);	//д���ֽ�         
				 delay(1);
			 }   
		} 
		
   } 
   for(j=0;j<64;j++)
   {
   		for(k=0;k<16;k++)
		RAM[j][k]=0;
   }  
   TransferCom(0x36);					//�򿪻�ͼ��ʾ  
   TransferCom(0x30);					//�򿪻���ָ�  
}
//***************�� �� �� �� ʾ �� �� �� �� �� �� ��
void GUI_Point(unsigned char y,unsigned char x) 
{
	unsigned char x_Dyte,x_byte,xx;		//�����е�ַ���ֽ�λ�������ֽ��е���1λ   
	unsigned char y_Dyte,y_byte;		//����Ϊ����������(ȡֵΪ0��1)���е� ַ(ȡֵΪ0~31)  
	unsigned char  GDRAM_h,GDRAM_l;
	TransferCom(0x36);					//��չָ������   /***X,Y���껥��������ͨ��X,Y����***/  
	xx=x/8;
	x_Dyte=x/16;						//������16���ֽ��е���һ��  
	x_byte=x%16;						//�����ڸ��ֽ��е���һλ  
	y_Dyte=y/32;						//0Ϊ�ϰ�����1Ϊ�°���   
	y_byte=y%32;						//������0~31���е���һ��
	delay (1);
	TransferCom(0x80+y_byte);			//��дY����
	TransferCom(0x80+y_Dyte*8+x_Dyte);	//��дX����
	delay (1);
	if(x_byte<8)
	{
		TransferData(RAM[y][xx]|0X01<<(7-x_byte));
		GDRAM_l=0X01<<(7-x_byte);
		RAM[y][xx]|=GDRAM_l;
	}
	else 
	{
		TransferData(RAM[y][xx-1]);
		TransferData(RAM[y][xx]|0X01<<(15-x_byte));
		GDRAM_h=0X01<<(15-x_byte);
		RAM[y][xx]|=GDRAM_h;
	}
	TransferCom(0x30);
}
//***************�����ʾͼƬ
void xianshi(void)
{
	uchar bb;
	uchar i,j,m;
	uint k;
	bb = aa[k];
	for(i = 0;i <= 63;i++)
	{
		for(j = 0;j <= 127;j++)
		{
			if((bb & 0x80) == 0x80)
			{
				GUI_Point(i,j);
				bb = bb << 1;
			}
			else bb = bb << 1;
			m++;
			if(m > 7)
			{
				m = 0;
				k++;
				bb = aa[k];
				k = k % 1024;
			}	
		}	
	}
}

