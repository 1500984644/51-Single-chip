#define uchar unsigned char					//�� unsigned char �궨��Ϊ uchar
#define uint unsigned int					//�� unsigned int �궨��Ϊ uint
sbit sd = P3^5;								//������
sbit cs = P3^4;								//Ƭѡ
sbit scl = P3^7;							//I/O��ʱ��
/********��TLC549����ת��*************/
uchar tlc549_ad(void)						//TLC549����
{
  	uchar i,dat_temp = 0;
	scl = 0;
	cs = 0; 
  	for(i = 0;i < 8;i++)					//��ȡ�ɼ����ݣ���ȡ������һ�βɼ�����
    {	
	  	scl = 1;
		dat_temp = dat_temp << 1;   
	  	if(sd)dat_temp |= 0x01;
	  	scl = 0;   	
	} 	
  	cs = 1;
  	return(dat_temp); 
}