//ѧϰPWM����ռ�ձ��趨,���B105��ʵ�鿪�������
//15F��Ƭ���ڲ���3��PWMģ�飬���ñ�̵ķ������Ըı�,����ģ��0����һ��PWM������P1.1�����ʾ�����۲죻
//��ƣ���Ƭ�����¹�����--�������ƣ�2015��12��15��
#include<reg51.h>
#include<15fpwm.c>
unsigned char cp1,cp2,pwm_num0,pwm_num1 = 100,pwm_num2 = 200;
xdata pwm_s;//ռ�ձ�,ռ�ռ�16λ
void timer0_isr(void) interrupt 1
{
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	cp1++;
	if(cp1 >= 100)//0.1����
	{
		pwm_num0++;
		if(pwm_num0 >= 256)pwm_num0 = 0;
		cp1 = 0;
	}			
	CCAP0H =  pwm_num0;			//P3.5���
	CCAP1H =  pwm_num1; 		//P3.6���
	CCAP2H =  pwm_num2;			//P3.7���		
}
void timer0_init(void)
{
	TMOD = 0x01;
	TH0 =  (65536 - 1000) / 256;
	TL0 =  (65536 - 1000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void main(void)
{
	timer0_init();
	STC_pwm_init();
	while(1);
}