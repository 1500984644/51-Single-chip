code uchar seven_seg[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uchar cp2;
xdata uchar	 hour = 12,min = 30,sec = 30;					//��ʱ��������ʱ�����

sbit P1_0 = P1^0;
xdata uchar	 flash,hour_c,min_c,sec_c;						//�Ӵ洢��������ʱ����
void display(void)
{
	switch(cp2)
	{
		case 0:	P1_0 = 0;P0 = 0x01;P1_0 = 1;P1_0 = 0;		//����λѡ����λ����������Ӹߵ�ƽ
				P0 = seven_seg[sec % 10];break;				//P0������λ��ѡ
		case 1:	P1_0 = 0;P0 = 0x02;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[sec / 10];break;				//P0�����ʮλ	
		case 2:	P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = 0xbf  | flash;break;					//P0�����˸��"-"	
		case 3:	P1_0 = 0;P0 = 0x08;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[min % 10];break;				//P0������ӵĸ�λ
		case 4:	P1_0 = 0;P0 = 0x10;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[min / 10];break;				//P0������ӵ�ʮλ
		case 5:	P1_0 = 0;P0 = 0x20;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = 0xbf  | flash;;break;					//P0�����˸��"-"	
		case 6:	P1_0 = 0;P0 = 0x40;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[hour % 10];break;			//P0���Сʱ�ĸ�λ	
		case 7:	P1_0 = 0;P0 = 0x80;P1_0 = 1;P1_0 = 0;		//����λѡ
				P0 = seven_seg[hour / 10];break;			//P0���Сʱ��ʮλ
						
	}

}