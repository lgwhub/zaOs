
/* Includes ------------------------------------------------------------------*/
#include "includes.h"
#include "stm32f10x.h"

#if CONFIG_ADC

/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup ADC_ExtLinesTrigger
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
//#define ADC1_DR_Address    ((uint32_t)0x4001244C)
//#define ADC3_DR_Address    ((uint32_t)0x40013C4C)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_InitTypeDef   ADC_InitStructure;
DMA_InitTypeDef   DMA_InitStructure;

//#define  GET_ADC_NMB   50               //ÿͨ����50��
//#define  MAX_ADC_CH  6               //Ϊ6��ͨ��
__IO uint16_t  AD_Value[GET_ADC_NMB][MAX_ADC_CH];   //�������ADCת�������Ҳ��DMA��Ŀ���ַ
__IO uint16_t  After_filter[MAX_ADC_CH];    //���������ƽ��ֵ֮��Ľ��

//__IO uint16_t ADC_RegularConvertedValueTab[5*8+8], ADC_InjectedConvertedValueTab[32];

    
/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration_Adc(void);
void GPIO_Configuration_Adc(void);
//void NVIC_Configuration_Adc(void);

  
/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
void ADC_Configuration(void)
{
  /* System clocks configuration ---------------------------------------------*/
  RCC_Configuration_Adc();

  /* NVIC configuration ------------------------------------------------------*/
//  NVIC_Configuration_Adc();

  /* GPIO configuration ------------------------------------------------------*/
  GPIO_Configuration_Adc();


  /* DMA1 channel1 configuration ----------------------------------------------*/
  DMA_DeInit(DMA1_Channel1);
  DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)AD_Value;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = MAX_ADC_CH*GET_ADC_NMB;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//������ѭ������ģʽ
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;//DMAͨ�� xӵ�и����ȼ�
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel1, &DMA_InitStructure);
  
  /* Enable DMA1 channel1 */
  DMA_Cmd(DMA1_Channel1, ENABLE);
     
  /* ADC1 configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode =  ENABLE;//DISABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = MAX_ADC_CH;//˳����й���ת����ADCͨ������Ŀ
  ADC_Init(ADC1, &ADC_InitStructure);

  /* ADC1 regular channels configuration */ 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_28Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 2, ADC_SampleTime_28Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 3, ADC_SampleTime_28Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 4, ADC_SampleTime_28Cycles5);//ADC_SampleTime_239Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 5, ADC_SampleTime_28Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 6, ADC_SampleTime_28Cycles5);

   /*
  //���ģʽ
  //Regular discontinuous mode channel number configuration
  ADC_DiscModeChannelCountConfig(ADC1, 1);
  //Enable regular discontinuous mode 
  ADC_DiscModeCmd(ADC1, ENABLE);
  */


  /* Enable ADC1 external trigger conversion */ 
//  ADC_ExternalTrigConvCmd(ADC1, ENABLE);


#if 0
  /* Set injected sequencer length */
  ADC_InjectedSequencerLengthConfig(ADC1, 2);
  /* ADC1 injected channel configuration */ 
  ADC_InjectedChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_28Cycles5);
  ADC_InjectedChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_28Cycles5);
  /* ADC1 injected external trigger configuration */
  ADC_ExternalTrigInjectedConvConfig(ADC1, ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4);
  /* Enable ADC1 injected external trigger conversion */
  ADC_ExternalTrigInjectedConvCmd(ADC1, ENABLE);

  /* Enable JEOC interupt */
  ADC_ITConfig(ADC1, ADC_IT_JEOC, ENABLE);

#endif

  /* Enable ADC1 DMA */
  ADC_DMACmd(ADC1, ENABLE);
  
  ADC_TempSensorVrefintCmd(ENABLE);  
  
  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);  

  /* Enable ADC1 reset calibaration register */   
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));

  /* Start ADC1 calibaration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(ADC1));
/////////////////////////////////////////////////////
                         
                         
    /* Start ADC1 Software Conversion */ 
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);                       
    
}

/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */
void RCC_Configuration_Adc(void)
{
    /* ADCCLK = PCLK2/4 */
    RCC_ADCCLKConfig(RCC_PCLK2_Div8); 

/* Enable peripheral clocks --------------------------------------------------*/   
  /* Enable DMA1 clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  /* Enable GPIOs and ADC1 clock */

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | 
                         RCC_APB2Periph_AFIO |		//���ܸ���IOʱ��
                         RCC_APB2Periph_ADC1, ENABLE); 
                         
                         
                
}


/**
  * @brief  Configures the different GPIO ports.
  * @param  None
  * @retval None
  */
//ѡ��ADC��ͨ�� 234567��
//�ֱ��Ӧ�Ĺܽ�Ϊ PA1  PA2  PA3  PA4 PA5 PA6 PA7
void GPIO_Configuration_Adc(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure PC.01, PC.02 and PC.04 (ADC Channel11, Channel12 and Channel14)
   as analog input -----------------------------------------------------------*/
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* Configure PA1  PA2  PA3  PA4 PA5 PA6 PA7 (ADC Channe 234567) as analog input --------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

}

/**
  * @brief  Configures NVIC and Vector Table base location.
  * @param  None
  * @retval None
  */
//void NVIC_Configuration_Adc(void)
//{
//  NVIC_InitTypeDef NVIC_InitStructure;
//
//  /* Configure and enable ADC interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
//}


/////
void AdcFilter(void)
{
//	#define  GET_ADC_NMB   50               //ÿͨ����50��
//#define  MAX_ADC_CH  6               //Ϊ6��ͨ��
//__IO uint16_t  AD_Value[GET_ADC_NMB][MAX_ADC_CH];   //�������ADCת�������Ҳ��DMA��Ŀ���ַ
//__IO uint16_t  After_filter[MAX_ADC_CH];    //���������ƽ��ֵ֮��Ľ��


unsigned long int sum;	//32
unsigned char i,j;


		for(i=0;i<MAX_ADC_CH;i++)
		{
			sum=0;
			
			for(j=0;j<GET_ADC_NMB;j++)
					{
						sum	+= AD_Value[j][i];
						
					}
		After_filter[i]=sum/GET_ADC_NMB;	
			
		}

	
}

#endif

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/



