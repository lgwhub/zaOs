/*****************************************************************************
Copyright: Hangzhouzhongan Elec. Co., Ltd.
File name: ADS8328���Ƴ���
Description: 
Author: chaijunbiao
Version: v1.0
Date: 2015-10-29
History: �޸���ʷ��¼�б� ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ�����

*****************************************************************************/
//#include "SysTick/systick.h"

//#include "user_inc/hzzadz_Macro_conf.h"

#include <includes.h>   


#define DELAY_US_100    delay_us(100)
#define DELAY_US_2      delay_us(2)
#define DELAY_US_1      ;


void delay_us(unsigned short int temp)  //ʵ����1.5us
{
	unsigned short int i;
	while(temp>0)
	{
	for(i=0;i<8;i++)
	   {
	   }
	 temp--;
  }
	
}

///////////////////////////////////////////////////////////////////
/////////////////////ģ��ת��(AD)//////////////////////////////////
///////////////////////////////////////////////////////////////////
//////////////////ADS8328///////////////
//��ADC8328д��һ���֣���Ҫ��д������Ĵ���
//0x0000 = ѡ��ͨ��0
//0x1000 = ѡ��ͨ��1
//0xE000 = ��CFR�Ĵ�����д�����
void ADS8328_WriteWord(unsigned short int temp)     //д��
{
	 unsigned short int temp1;
	 unsigned int i;
	 ADS8328_CS1(0);//nADS8328_CS1=0
	 for (i=0;i<16;i++)
	  {
		   temp1=temp&0x8000;
		   if(temp1==0)		
		    ADS8328_DIN(0);//MOSI=0
		   else
		    ADS8328_DIN(1);//MOSI=1
		   DELAY_US_1;
		   ADS8328_SCK(1);//SCLK =1  
		   DELAY_US_1;
		   ADS8328_SCK(0);//SCLK=0
		   DELAY_US_1;
		   temp<<=1;
	  }    
	 ADS8328_CS1(1);//nCS=1
	 ADS8328_SCK(0);//SCLK=0
	 ADS8328_DIN(1);//MOSI =1
}
//��������ţ���ADC8328�ж���16λ���ݣ�
//0xC000 = ����CFR
//0xD000 = ��������
unsigned short int ADS8328_ReadWord(unsigned short int command)//����Ĵ���
{
	 unsigned short int temp,temp1,temp2;
	 unsigned char i;
	 
	 temp=0;	   	   
	 ADS8328_CS1(0);//nADS8328_CS1=0
	 DELAY_US_2;
	 for(i=0; i<16; i++)
	 {
		  temp2 = command&0x8000;
		  if(temp2 == 0)		
		   ADS8328_DIN(0);//MOSI=0
		  else
		   ADS8328_DIN(1);//MOSI=1
		  command<<=1;
		  DELAY_US_1;
		  ADS8328_SCK(1);//SCLK =1  
		  DELAY_US_1;
		
			temp1= ADS8328_DOUT;
		
		  ADS8328_SCK(0);//SCLK=0
		  DELAY_US_1;
		  temp<<=1;
		  if(temp1!=0) 
		   temp|=0x0001;
		  else
		   temp&=0xfffe;       
		  DELAY_US_1;     
	 }	
	 ADS8328_DIN(1);//MOSI=1
	 DELAY_US_1;
	 ADS8328_CS1(1);//nCS=1
	 DELAY_US_2;
	 return temp;
}

//ѡ��ADS8328ͨ���ţ�1 = ͨ��0 ��2 = ͨ��1
void  ADS8328_SelectChannel(unsigned char channel)
{
	if(	channel == 1)
	{
		ADS8328_WriteWord(0x0000);//ѡ��ģ��ͨ��0	
	}
	else
	{
		ADS8328_WriteWord(0x1000);//ѡ��ģ��ͨ��1		
	}
}

//ADS8328����ת��������sample_times= ����������	data_ptr = ��������洢��λ�ã�������ֵΪ���������Ƿ���Ч
unsigned char ADS8328_DataConvert(unsigned char sample_times, unsigned long int *data_ptr)
{
	unsigned short int temp1;
	unsigned short int i;
	unsigned long int temp2;
	unsigned short int sample_delay_count;
	unsigned short int sample_max,sample_min;

	sample_max = 0;
	sample_min = 0xFFFF;
	sample_times += 2;    //��Ϊ��Ҫ���������Сֵ�����Բ���������2
	temp2 = 0;
	 for(i=0; i < sample_times ; i++)
	 {
	  
		ADS8328_CNV(0);//nCONVST=0
		sample_delay_count = 0;  
		do
		{
		 	ADS8328_SCK(0);//SCLK=0
		    DELAY_US_1;
		  	ADS8328_SCK(1);//SCLK =1  
		  	DELAY_US_1;
			temp1 = ADS8328_EOC ;
			sample_delay_count ++;

	    } while((temp1 == 0)&&(sample_delay_count < 10000)); 
		ADS8328_CNV(1);//nCONVST=1
	    DELAY_US_2;
		if(	sample_delay_count < 10000)
		{
			temp1 = ADS8328_ReadWord(0xd000);//������
			if( temp1 > sample_max )
			{
				sample_max = temp1;	
			}

			if( temp1 < sample_min )
			{
			 	sample_min = temp1;	
			}

			temp2 += temp1;
  	    	//delay_us(60);
		}
		else
		{
			return (0);
		}
		
	  }
	  temp2 -=  sample_max;
	  temp2 -= 	sample_min;	 //���������Сֵ

	  *data_ptr =  temp2 ;
	  return (1);
	  
	  	
}

//
void ADS8328_Init(void)			//ADS8328��ʼ��
{
	unsigned short int temp1;

 #define CFR_11  (0 << 11 )    //Channel select mode, 0 =`Manual, 1 = Auto;
 #define CFR_10	 (1 << 10 )	  //Conversion clock (CCLK) source select,	1: Conversion clock (CCLK) = Internal OSC,0=SCK/2
 #define CFR_9	 (1 << 9 )	  //Trigger (conversion start) select, 0=Auto trigger��1 =Manual trigger
 #define CFR_8	 (0 << 8 )	  //Don't care
 #define CFR_7	 (1 << 7 )	  //Pin 10 polarity select when used as an output (EOC/INT)��0= high��1= low
 #define CFR_6	 (1 << 6 )	  //Pin 10 function select when used as an output (EOC/INT)��0 =INT��1=EOC
 #define CFR_5	 (1 << 5 )	  //Pin 10 I/O select for chain mode operation ��0 =CDI��1=EOC/INT output
 #define CFR_4	 (1 << 4 )	  //Auto nap power-down enable/disable ,0= enable,1= disable
 #define CFR_3	 (1 << 3 )	  //Nap power-down,0=Enable, 1= disable
 #define CFR_2	 (1 << 2 )	  //Deep power-down.0=Enable, 1= disable
 #define CFR_1	 (0 << 1 )	  //TAG bit enable.0: TAG bit disabled; 1: TAG bit output enabled
 #define CFR_0	 (0 << 0 )	  //Reset,0 = Reset ,1 =Normal operation  

  temp1 =  CFR_0 + CFR_1 + CFR_2 + CFR_3 +
  		   CFR_4 + CFR_5 + CFR_6 + CFR_7 +
		   CFR_8 + CFR_9 + CFR_10+ CFR_11 ;

 temp1 += 0xE000;	   		//����Ĵ���λ����ֵ		   	
 DELAY_US_100;
 ADS8328_WriteWord(temp1);	//ϵͳ��λ
 DELAY_US_100;
 ADS8328_WriteWord(temp1);	//ϵͳ��λ
 DELAY_US_100;
 ADS8328_WriteWord(temp1 + 1);//дCFR�Ĵ���0xe6fd
 DELAY_US_100;
 ADS8328_WriteWord(temp1 + 1);//дCFR�Ĵ���0xe6fd
 //�ֶ�ͨ��ѡ��ʹ�ܣ��ڲ�ʱ�ӣ�nCONVST��ʼת����NC
 //P10=EOC,EOC=low,P10=EOC���,1  
}

