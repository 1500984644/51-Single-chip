//AD�������йؼĴ���˵�������STC15F�ֲ�
#include<intrins.h>
#define  nop    _nop_()

sfr ADC_CONTR = 0xbc;  	//AD���ƼĴ���
sfr ADC_RES = 0xbd;		//ADת�������ݴ�Ÿ�8λ
sfr ADC_RESL = 0xbe;	//ADת�������ݴ�ŵ�8λ
sfr P1ASF = 0x9D;		//����ѡ��P1��8���˿�Ϊģ���
sfr PCON2 = 0x97;		//ʱ�ӷ�Ƶ�Ĵ���������ֻ�õĵ�PCON2�е�ADRJ��ת����������䣩

unsigned int get_ad(void)
{
	unsigned int i,j;
	P1ASF = 0x02;  								//����P1.1Ϊģ������˿ڣ����ֲ�P1ASF�Ĵ���˵��	
	PCON2 = PCON2 | 0x20;						//ADRJ  = 1;
	ADC_CONTR = 0x00;
	ADC_CONTR = ADC_CONTR | 0x80 | 0x40 | 0x01; //����A/D��Դ����|ת���ٶ�����|����˿�P1.0��
												//���ֲ�ADC_CONTR�Ĵ���˵��	
	nop;nop;nop;//�ȴ���Դ�ȶ���
	ADC_CONTR = ADC_CONTR | 0x08;				//��ʼת��
	while((ADC_CONTR & 0x10) !=0x10); 			//�ȴ�ת����־��λ
	i = ADC_RES;
	j = ADC_RESL;
	i = i << 8;
	i = i | j;
	ADC_CONTR = ADC_CONTR & ~0x10;		  		//����ת����־λ
	ADC_RES = 0x00;
	ADC_RESL = 0x00;
	return(i);
}