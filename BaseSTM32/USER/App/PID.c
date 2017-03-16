
#include "includes.h"
#include "PID.h"

//����ȿ���
const float PID_Default[5][3]=
{
150  ,     2,       12,	
//5.0  , 0.2  ,0.6	,    //p1  i1  d1
//2.0  , 0.05  ,0.1	,    //p2  i2  d2
//2.0  , 0.05  ,0.1	,
//2.0  , 0.05  ,0.1		
};


PID_ParaStruct      PidParam[1];

PidBufStruct HeatPidBuf[MAX_TEMPRATURE_CHNALL];



void PID_Para_Refush(unsigned char i)
{
	 PidParam[0].Proportion  =  PID_Default[0][0]  * Coldw.PID_P2;          //��������
	 PidParam[0].Integral    =  PID_Default[0][1]  * Coldw.PID_I2;          //
	 PidParam[0].Derivative  =  PID_Default[0][2]  * Coldw.PID_D2;
	
		if( PidParam[0].Integral == 0 )
			{
		    PidParam[0].MaxSumError =  0;
            PidParam[0].MinSumError =  0;
		  }
		else{
        PidParam[0].MaxSumError =  MAX_PID_INTEGRAL_2/(PidParam[0].Integral);
        PidParam[0].MinSumError =  0;// (-(PWM_PERIOD_PULSE)) /(types->Integral);
        }	

}
/////////////////////
void PID_Para_Refush_All(void)
{
unsigned char i;
	for( i = 0 ; i<1 ; i++)
	    {
      PID_Para_Refush(i);
      }
}
//////////////////////////

void PID_ParaInit(void)
{

//	 gParamBlk.sPidRate[i].Proportion=1;          //��������
//	 gParamBlk.sPidRate[i].Integral=1;          //
//	 gParamBlk.sPidRate[i].Derivative
//	 Coldw.PID_P2=1;          //��������
//	 Coldw.PID_I2=1;
//	 Coldw.PID_D2=1;

 
	PID_Para_Refush_All();	    	
}


void PID_BufInit(PidBufStruct *pidch)
{
	  pidch->SetPoint=0;       //�趨Ŀ��
   
    pidch->LastError	= 0;     //�ϴ�ƫ��
    pidch->PreError   = 0;      //���ϴ�ƫ��
    pidch->SumError   = 0;     //�ۻ�ƫ��
    pidch->Qx=0;									//���   ��� Px+Ix+Dx
    pidch->Px=0;		//P����
    pidch->Ix=0;    //I����  
    pidch->Dx=0;			//D����	

}

/********************************************************
* Function:    PID_Calc
* Description: PID����
* Input:       PIDstruct *  ��Ҫ�����PID���ƽṹ��ָ��
*              NowPoint         ʵ�ʷ���ֵ
* Output:      float           PID������
* Calls:       ��
* Called by:   CtrlTemp
* Others:
*********************************************************/
void PID_Calc(PID_ParaStruct *types, PidBufStruct *pidch, float Error)
{
    float dError;
    
    float total;
    
    //Error            =    pidch->SetPoint   -   NowPoint   ;              //����ƫ��  e0
    pidch->SumError  +=   Error;                      							//�����ۼ�  e0++
    dError           =    pidch->LastError  -  pidch->PreError;     		//��ǰ΢��  e1-e2
    
    //����
    pidch->PreError  =    pidch->LastError;              							//�ϴ�ƫ������ϴ�ƫ��  e2=e1
    pidch->LastError =    Error;                 										//��ǰƫ����ϴ�ƫ��    e1=e0
    
    
    
    //////////������////////////////////////////////////////////////////MAX_PID_INTEGRAL

		    
    if( pidch->SumError   >  types->MaxSumError )
		    {
		     pidch->SumError  =  types->MaxSumError;
		    }
    else if(  pidch->SumError  <  types->MinSumError  )
		    {
		      pidch->SumError      =  types->MinSumError;
		    }		    
		    
		//////////////////////    


    
    pidch->Px =   types->Proportion *  Error;	          //P����
    pidch->Ix =   types->Integral   *  pidch->SumError;	//I����  
    pidch->Dx =   types->Derivative *  dError;	        //D����
   
   
    total     =   pidch->Px + pidch->Ix + pidch->Dx;


    if( total < MIN_PID_RESOULT_2 )
    	{   pidch->Qx  =  (signed long int)MIN_PID_RESOULT_2;
    	}
    else if( total > MAX_PID_RESOULT_2 )
    	{
    		pidch->Qx   = (signed long int)MAX_PID_RESOULT_2;
    	}
    else {
    	    pidch->Qx   = (signed long int)total;
         }
         
        
}

