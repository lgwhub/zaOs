    
#include "includes.h"

#if CONFIG_PWM    
    
    /*
    TIM1 TIM8�Ǹ߼���ʱ��
    �߼���ʱ������ʱ��72MHZ,����TIM1����3������������źţ�Ƶ��1HZ,ռ�ձ�25%��50%,75%,�ֱ���1/10000������������ʱ�䡣
    
    Ԥ����Ĵ�����ֵ=72000000/10000  -1 =7199
    �ȽϼĴ���1��ֵ=10000x25%=2500
		�ȽϼĴ���2��ֵ=10000x50%=5000
		�ȽϼĴ���3��ֵ=10000x75%=7500    
    */
    
void PWM_Configuration(void)
{
    
    TIM_TimeBaseInitTypeDef  		TIM_TimeBaseStructure;
		TIM_OCInitTypeDef						TIM_OCInitStructure;
		TIM_BDTRInitTypeDef					TIM_BDTRInitStructure;


    //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		
    //TIM_TimeBaseStructure.TIM_Prescaler     = 7199;		//Ԥ����Ĵ���
   	TIM_TimeBaseStructure.TIM_Prescaler     = 72000000/4000/1000-1;			//Ԥ����Ĵ���   4khz    
    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Down;//TIM_CounterMode_Up;
    //TIM_TimeBaseStructure.TIM_Period        = 10000;
    TIM_TimeBaseStructure.TIM_Period        = 1000;		//  1/1000
    
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;


    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    

		//����ͨ��1,2,3������PWMģʽ
		TIM_OCInitStructure.TIM_OCMode				=	TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OutputState		=	TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_OutputNState	=	TIM_OutputNState_Enable;
    TIM_OCInitStructure.TIM_Pulse					=	200;//2500;
    TIM_OCInitStructure.TIM_OCPolarity		=	TIM_OCPolarity_Low;
    TIM_OCInitStructure.TIM_OCNPolarity		=	TIM_OCNPolarity_Low;
    TIM_OCInitStructure.TIM_OCIdleState		=	TIM_OCIdleState_Set;
    TIM_OCInitStructure.TIM_OCNIdleState	=	TIM_OCNIdleState_Set;
    
    TIM_OC1Init(TIM1,&TIM_OCInitStructure);
    
//    TIM_OCInitStructure.TIM_Pulse					=	5000;
//    TIM_OC2Init(TIM1,&TIM_OCInitStructure);
//    
//    TIM_OCInitStructure.TIM_Pulse					=	7500;
//    TIM_OC3Init(TIM1,&TIM_OCInitStructure);   
    
    
    //�������ɲ���ź�������������ʱ�䣬��������
    TIM_BDTRInitStructure.TIM_OSSRState		=		TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState		=		TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel		=		TIM_LOCKLevel_1;
    TIM_BDTRInitStructure.TIM_DeadTime			=		20;		//����ʱ��2us
    //TIM_BDTRInitStructure.TIM_Break				=		TIM_Break_Enable;
    //TIM_BDTRInitStructure.TIM_BreakPolarity		=		TIM_BreakPolarity_High;
    TIM_BDTRInitStructure.TIM_AutomaticOutput	=		TIM_AutomaticOutput_Enable;
    
    TIM_BDTRConfig(TIM1,&TIM_BDTRInitStructure);
    
//    TIM_SetCounter(TIM2, 0);
//    TIM_PrescalerConfig(TIM2, 256, TIM_PSCReloadMode_Immediate);
		
		//TIM1�������
    TIM_Cmd(TIM1, ENABLE);
    //�����������
    TIM_CtrlPWMOutputs(TIM1,ENABLE);
    
}

////////////////////////    

void GPIO_Configuration_PWM(void)
{
		GPIO_InitTypeDef	GPIO_InitStructure;
		
		//GPIOAͨ��1,2,3			PA8  PA9  PA10
		GPIO_InitStructure.GPIO_Pin		=		GPIO_Pin_8;// | GPIO_Pin_9 | GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode	=		GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed	=		GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		//GPIOBͨ��1N,2N,3N		PB13 PB14 PB15
		GPIO_InitStructure.GPIO_Pin		=	GPIO_Pin_13;// | GPIO_Pin_14 | GPIO_Pin_15;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		//GPIOBɲ���ܽ�   PB12
		GPIO_InitStructure.GPIO_Pin		=		GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Mode	=		GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
}

#endif

