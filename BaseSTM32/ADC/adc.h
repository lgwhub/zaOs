//	#include "adc.h"
#ifndef _ADC_H
#define _ADC_H

#define ADC1_DR_Address    ((uint32_t)0x4001244C)
#define ADC3_DR_Address    ((uint32_t)0x40013C4C)


#define  GET_ADC_NMB   50               //每通道采50次
#define  MAX_ADC_CH  6               //为6个通道

#if CONFIG_ADC

		extern __IO uint16_t  AD_Value[GET_ADC_NMB][MAX_ADC_CH];   //用来存放ADC转换结果，也是DMA的目标地址
		extern __IO uint16_t  After_filter[MAX_ADC_CH];    //用来存放求平均值之后的结果
		
		void ADC_Configuration(void);
		/////
		void AdcFilter(void);

#endif


#endif



