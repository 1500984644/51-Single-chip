#include<reg51.h>
sfr CCON = 0xd8;				//�ɱ�̼�����PCA�Ŀ��ƼĴ���
sfr CMOD = 0xd9;				//�ɱ�̼���������ģʽ�Ĵ���
sfr CL = 0xe9;					//�ɱ�̼������ĵͰ�λ
sfr CH = 0xf9;					//�ɱ�̼������ĸ߰�λ
/********PWMģ��0��P1.1���*********/
sfr CCAPM0 = 0xda;				//PWM���ܼĴ���			 
sfr CCAP0L = 0xea;				//�߰�λ
sfr CCAP0H = 0xfa;				//�Ͱ�λ
sfr PCA_PMW0 = 0xf2;			//PWM�����Ĵ���				  
/********PWMģ��1��P1.0���*********/
sfr CCAPM1 = 0xdb;
sfr CCAP1L = 0xeb;
sfr CCAP1H = 0xfb;
sfr PCA_PMW1 = 0xf3;
/********PWMģ��2��P3.7���********/
sfr CCAPM2 = 0xdc;
sfr CCAP2L = 0xec;
sfr CCAP2H = 0xfc;
sfr PCA_PMW2 = 0xf4;
void STC_pwm_init(void)
{
	CMOD = 0x0a;				//PWMƵ�� = ʱ��Ƶ�� / 4 /256,��ʱ��Ƶ��Ϊ12M����PWM��Ƶ��Ϊ11.7K��
	CL = 0x00;					//PCA��������8λ����
	CH = 0x00;					//PCA����������8λ����
	/********PWMģ��0��P1.1���*********/
	PCA_PMW0 = 0x00;			//8λPMW��ռ�ձȵĵھ�λEPC0LΪ0
	CCAPM0 = 0x42;				//����Ƚϣ�P1.1���	
	/********PWMģ��0��P1.0���********/
	PCA_PMW1 = 0x00;			//8λPMW��ռ�ձȵĵھ�λEPC0LΪ0
	CCAPM1 = 0x42;				//����Ƚϣ�P1.0���
	/********PWMģ��0��P3.7���*********/
	PCA_PMW2 = 0x00;			//8λPMW��ռ�ձȵĵھ�λEPC0LΪ0
	CCAPM2 = 0x42;				//����Ƚϣ�P3.7���	
	CCON = 0x40;				//����PAC����������Ƶ��Ϊʱ��Ƶ��/4��
}

