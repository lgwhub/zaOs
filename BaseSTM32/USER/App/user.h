

#ifndef _USER_H
#define _USER_H




//��ƷΨһ��ݱ�ʶ�Ĵ�����96λ��
//����ַ0X1FFF F7E8
//λ15:0
//��ַƫ��0x02
//λ31:16
//��ַƫ��0x04
//λ63:32
//��ַƫ��0x06
//λ95:64





//ͨ����
#define MAX_TEMPRATURE_CHNALL   8

///////////////////////////////


extern unsigned char EventTimeBuz;
extern unsigned char EventTimeLed;


#define Led_Test_Key_On1		;//LED1_ON
#define Led_Test_Key_Off1		;//LED1_OFF

#define Led_Test_Adc_On1		;//LED1_ON
#define Led_Test_Adc_Off1		;//LED1_OFF

#define Led_Status_On		    LED1_ON
#define Led_Status_Off		  LED1_OFF

#define Led_Event_On		;//	LED4_ON
#define Led_Event_Off		;//LED4_OFF


//void MotorsRun(unsigned char ch, signed short int steps);

void TaskVirPwm(void * pdata);
void TaskModbus(void * pdata);

void Task001(void * pdata);
void Task002(void * pdata);
void Task003(void * pdata);
void Task004(void * pdata);

void TaskTimePr(void * pdata);
void TaskHeat(void * pdata);

void TaskStatus(void * pdata);

void TaskTs(void * pdata);



#endif
