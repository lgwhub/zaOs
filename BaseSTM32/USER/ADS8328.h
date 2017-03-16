/*****************************************************************************
Copyright: Hangzhouzhongan Elec. Co., Ltd.
File name: ADS8328���Ƴ���
Description: 
Author: chaijunbiao
Version: v1.0
Date: 2015-10-29
History: �޸���ʷ��¼�б� ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ�����


*****************************************************************************/
#ifndef __ADS8328_H
#define __ADS8328_H

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x.h"
/* Private define ------------------------------------------------------------*/

void delay_us(unsigned short int temp);

/* Private function prototypes -----------------------------------------------*/
void ADS8328_Init(void);			//ADS8328��ʼ��
unsigned char ADS8328_DataConvert(unsigned char  sample_times, unsigned long int *data_ptr); //ADS8328����ת��������sample_times= ����������	data_ptr = ��������洢��λ�ã�������ֵΪ���������Ƿ���Ч
void  ADS8328_SelectChannel(unsigned char  channel);				//ѡ��ADS8328ͨ���ţ�1 = ͨ��1 ��2 = ͨ��2
unsigned short int ADS8328_ReadWord(unsigned short int command);						//��������ţ���ADC8328�ж���16λ���ݣ�
void ADS8328_WriteWord(unsigned short int temp);						//��ADC8328д��һ���֣���Ҫ��д������Ĵ���

#endif 
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
