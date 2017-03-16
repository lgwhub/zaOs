#ifndef    _PID_INC_H   
#define    _PID_INC_H


//PWM_PERIOD_PULSE
//#define MAX_PID_INTEGRAL_1   100
//#define MIN_PID_INTEGRAL_1   (-100)

#define MAX_PID_INTEGRAL_2   200
#define MIN_PID_INTEGRAL_2   (0)

#define MAX_PID_RESOULT_2  MAX_PID_INTEGRAL_2
#define MIN_PID_RESOULT_2  MIN_PID_INTEGRAL_2

/********************************************************
* PID���ƽṹ������
*********************************************************/
typedef struct 
{
    float Proportion;          //��������
    float Integral;            //���ֳ���
    float Derivative;          //΢�ֳ���
    float MaxSumError;    
    float MinSumError;    

}PID_ParaStruct;


extern PID_ParaStruct      PidParam[1];


typedef struct 
{
    float SetPoint;            //�趨Ŀ��
    
    float LastError;           //�ϴ�ƫ��
    float PreError;            //���ϴ�ƫ��
    float SumError;            //�ۻ�ƫ��



    float Px;									//P����
    float Ix;        					//I����  ��� Px+Ix+Dx
    float Dx;        					//D����

   
    signed long int Qx;                 //���������
    
}PidBufStruct;  //��ʱ����

extern PidBufStruct HeatPidBuf[MAX_TEMPRATURE_CHNALL];



/********************************************************
* Function:    PID_Calc
* Description: PID����
* Input:       pPIDxxx  ��Ҫ�����PID���ƽṹ��ָ��
*              NowPoint         ʵ�ʷ���ֵ
* Output:      float           PID������
* Calls:       ��
* Called by:   CtrlTemp
* Others:
*********************************************************/
//float

void PID_BufInit(PidBufStruct *pidch);
void PID_ParaInit(void);//PID_ParaStruct *types,float p, float i, float d);


//void PID_Calc(PID_ParaStruct *types, PidBufStruct *pidch, float NowPoint);
void PID_Calc(PID_ParaStruct *types, PidBufStruct *pidch, float Error);

void PID_Para_Refush_All(void);
#endif

