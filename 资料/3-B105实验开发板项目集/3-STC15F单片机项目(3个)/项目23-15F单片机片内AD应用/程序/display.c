unsigned char seven_seg[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char cp2;
xdata ad_dat;
//xdata�����ı�����16λ������ڵ�Ƭ������չRAM�У�STCΪƬ��256B���ϵĿռ�
//bdata�����ı�����16λ������ڵ�Ƭ����0��128B�ռ䣬λ��Ѱַ���磺
//bdata BB;sbit BB_15 = BB^12;//BB_15��BB��ĳһλ
sbit P1_0 = P1^0;
void display(void)
{
	switch(cp2)
	{
		case 0:	P1_0 = 0;P0 = 0x01;P1_0 = 1;P1_0 = 0;		//����λѡ����λ����������Ӹߵ�ƽ
				P0 = seven_seg[ad_dat % 10];break;			//P0�����λ
		case 1:	P1_0 = 0;P0 = 0x02;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[ad_dat % 100 / 10];break;	//P0���ʮλ	
		case 2:	P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[ad_dat / 100 % 10];break;	//P0�����λ	
		case 3:	P1_0 = 0;P0 = 0x08;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[ad_dat / 1000];break;		//P0���ǧλ	
		/*
		case 4:	P1_0 = 0;P0 = 0x10;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[1];break;					//P0�����ѡ	
		case 5:	P1_0 = 0;P0 = 0x20;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[2];break;					//P0�����ѡ	
		case 6:	P1_0 = 0;P0 = 0x40;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[3];break;					//P0�����ѡ	
		case 7:	P1_0 = 0;P0 = 0x80;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[4];break;					//P0�����ѡ
		*/				
	}

}