//user.c

#include "includes.h"
//extern 




//OS_EVENT *OSSemblinkOut2;
//OS_EVENT *OSSemblinkOut3;
OS_EVENT *OSSemMotors;
OS_EVENT *OSSemUart1;
//OS_EVENT *OSSemUart2;


OS_EVENT *OSSemTimePid_StepMotor;
OS_EVENT *OSSemTimePid_Heat;


unsigned char lAddressKey;  //拨码开关PB12-PB15，值，最低4位


unsigned char EventTimeBuz=0;
unsigned char EventTimeLed=0;


float wAdcResoult[MAX_TEMPRATURE_CHNALL];  //MAX_ADC_CH 


///////////////////////////////////////////////////////////////////////
//电压采样，温度探头为AD590，电阻为10K
//-23度时为250uA，此时电压值为(273-23)*10K = 2.5V
// 0度时为273uA，此时电压值为273uA*10K=2.73V,	 与2.5V差分后对应采样值为(2.73V-2.5V)*65535/2.5= 6029
//27度时为300uA，此时电压值为300uA*10K=3V,	 与2.5V差分后对应采样值为(3V-2.5V)*65535/2.5= 13107
//150度时为 423uA，此时电压值为423uA*10K=4.23V，与2.5V差分后对应采样值为(4.23V-2.5V)*65535/2.5= 45350
//num表示采样次数，temp_TC_bias表示温度偏差值，data_ptr表示数据指针
void CHECK_AD590OneTCCheckUseADS8328(unsigned int num,float data_amp,float data_bias,float temp_TC_bias,float *data_ptr)
{
	  unsigned long int temp_tt;
	  unsigned long int temp1;
	  float temp2;
	  unsigned int  temp3;
	  unsigned char temp4;
	  unsigned long int temp_max,temp_min;

	  temp_tt=0;
	  temp_max=0;
	  temp_min=0xffffff;
	  for(temp3=0;temp3< num+2;temp3++)
	    {
	     temp4=ADS8328_DataConvert(5,&temp1);
		   temp1 /= 5;
	 	 
	 	  if(temp4 == 0)		 //FAIL
		     {
		     	Coldw.ADC_error_count++;
			    return;
		     }
	     temp_tt += temp1;
	     if(temp1>temp_max)
	         {
	          temp_max=temp1;
	         }
	     if(temp1<temp_min)
	         {
	          temp_min=temp1;
	         }
	     }
	     
	  temp_tt-=temp_max;
	  temp_tt-=temp_min;
	  temp_tt/= num;



	  if(temp_tt > 13185)  //有温度探头的,温度大于0度的
	     {
	  	  temp_tt -= 13185;
		    temp2 =( float) temp_tt;
	      temp2 = temp2 / 288;//262;
	      temp2 += temp_TC_bias;
	     }
	  else  //没有温度探头
	    {
	     temp2 = 0;
	     }

	     
	  temp2 *= data_amp;  //默认 1.000
	  temp2 += data_bias; //默认 0.000
	  
	  *data_ptr = temp2;
}

///////////////////////////////////////////////////////////////////////

//CD4051  8选1选择通道，A,B,C
void CHECK_SelectChannel(unsigned char channel)
{
	
	//ABC  ...  PC5 PB0  PB1
unsigned char Tab4051[8]=
{
	4,//对应温度输入端1
	2,//对应温度输入端2
	1,//对应温度输入端3
	0,//对应温度输入端4
	5,//对应温度输入端5
	3,//对应温度输入端6
	6,//对应温度输入端7
	7,//对应温度输入端8		
};

	  //A信号
	  if((Tab4051[channel]&0x01) == 0x01)
	  {
		 Set4051A;
	  }
	  else
	  {
	    Clr4051A;
	  }
	  //B信号
	  if((Tab4051[channel]&0x02) == 0x02)
	  {
		 Set4051B;
	  }
	  else
	  {
	    Clr4051B;
	  }
	  //C信号
	  if((Tab4051[channel]&0x04) == 0x04)
	  {
		 Set4051C;
	  }
	  else
	  {
	    Clr4051C;
	  }
}
///////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
void ViewTestStatu(uchar *text)
{
#if (OS_VIEW_MODULE == DEF_ENABLED)
			OSView_TxStr(text, 1);
#else
//			SendTestStatu(text);
#endif
}
//////////////////////////////////////////////


void VirtualPwmOutPin(unsigned char ch , unsigned char High)
{
	switch(ch)
	{
		case 0:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat1;
			  }
			else{//关闭有效电平
				  ClrHeat1;
			  }
	  break;
	  
		case 1:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat2;
			  }
			else{//关闭有效电平
				   ClrHeat2;
			  }
	  break;	
	  
		case 2:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat3;
			  }
			else{//关闭有效电平
				  ClrHeat3;
			  }
	  break;
	  
		case 3:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat4;
			  }
			else{//关闭有效电平
				   ClrHeat4;
			  }
	  break;	    

		case 4:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat5;
			  }
			else{//关闭有效电平
				  ClrHeat5;
			  }
	  break;
	  
		case 5:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat6;
			  }
			else{//关闭有效电平
				   ClrHeat6;
			  }
	  break;
	  
		case 6:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat7;
			  }
			else{//关闭有效电平
				  ClrHeat7;
			  }
	  break;
	  
		case 7:
			if(High != 0)
			  {//输出有效电平
			  	SetHeat8;
			  }
			else{//关闭有效电平
				   ClrHeat8;
			  }
	  break;	  		
	}
	
}
//////////////////////////////////////////////
void TaskVirPwm(void * pdata)  //Virtual
{
INT8U err;
unsigned char i;
unsigned char curDuty[8];//占空比
unsigned char curCycle;//周期

pdata = pdata;                          	 	// 避免编译警告		


curCycle = 200;//周期

OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.1秒
for(;;)
		{
			//电加热 软件 PWM
			for(i=0;i<8;i++)
			    {
			     if(curDuty[i] > 0)
			     	  {
			     		
			     		 curDuty[i] --;
			     	  }
			     else{//关输出
			     	
			     	   VirtualPwmOutPin(i,0);
			         }
			     }
			
			  if(curCycle > 0)
			     	{
			     		curCycle --;
			     	}
			  else{
			     	 curCycle = 200 ;//周期到
                for(i=0;i<8;i++)
			            {
                   curDuty[i] = Coldw.TC_duty[i]       ;//刷新PWM值
			     	       //开输出
			     	       if(Coldw.unit_onof_flag[i]>0)
			     	       	   {
			     	       		  VirtualPwmOutPin(i,1);
			     	       	   }
			     	       
			     	       }			     	    
			       }
			        
			
		  OSTimeDly(OS_TICKS_PER_SEC/1000);	    //延时0.001秒

		}		
}

////////////////////////////////////////
void Test_Adc(void)
{
///////////////////////////////////////////////////////////////////////
//		  #if CONFIG_ADC
					
					  
//					#if CONFIG_UART1
//					AdcFilter();
//						 	#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 1) 
//
//											OSSemPend(OSSemUart1,0,&err);
//											
//											SendText_UART1("....");
//											for(i=0;i<MAX_ADC_CH;i++)
//														{
//														MakeValAsc16("",wAdcResoult[i]*330/4096,"V,",buf);
//														
//														SendText_UART1(buf);
//														
//														}
//														
//											SendText_UART1("\r\n");
//											
//											OSSemPost(OSSemUart1);
//											
//							#endif
//					#endif
					
					
//					#if CONFIG_UART1	== 0
//					//ViewTestStatu
//					//AdcFilter();
//					ViewTestStatu("....");//SendText_UART1("....");
//											for(i=0;i<MAX_TEMPRATURE_CHNALL;i++)
//														{
//														MakeValAsc16("",(uint16)(wAdcResoult[i]*10),"(0.1C),",buf);
//														
//														ViewTestStatu(buf);//SendText_UART1(buf);
//														
//														}
//					ViewTestStatu("\r\n");
//					#endif
//					
//			#endif
//			
//			
//
//			OSTimeDly(OS_TICKS_PER_SEC);
}

////////////////////////////////////////
void Test_Uart3(void)
{

		#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER !=3)
					#if CONFIG_UART3
							if(GetOneFromUart3(&temp))
									{
										Uart3CharSend(temp);
									}
					#endif
		#endif
}
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
void CheckAdrressKey(void)  //分机地址设置拨码开关
{
	static unsigned char old1,old2,old3,old4,old5;
	
	old1 = GPIO_ReadInputData(GPIOC); //PC0123 ; 
	
	if((old2==old1)&&(old3==old2)&&(old4==old3)&&(old5==old4))//滤波
		{
				lAddressKey=old1;  //拨码开关PB12-PB15，值，最低4位
		}
	old5=old4;
	old4=old3;	
	old3=old2;
	old2=old1;
}
/////////////////////////////////////////////////////////
void TaskModbus(void * pdata)
{
INT8U err;

pdata = pdata;                          	 	// 避免编译警告		

lAddressKey=0;  //拨码开关PB12-PB15，值，最低4位

TimeForSaveParam = 0;

Default_ParamInit();    //?????????问题
 /*
  if(Load_Param()==0)		//取设定值
   {
    
    gData[0].AnyError|=8;
    gData[1].AnyError|=8;
    gData[2].AnyError|=8;
    gData[3].AnyError|=8;  
    
      
    //自动恢复默认值，不允许
     _Param_SwapMemery(0,cMemBufA);   //parameter ---> cMemBufB
    cMemBufB[Max_MemBuf-2] =  FlagParamInitnized; 
    Write_Param();
   }
*/
#if CONFIG_CHECK_DEVICE_ID
		if(GetStm32F103_DeviceId_Sum6() == gpParam->Stm32IdSum6)
				{
					STM32DeviceId.Checked=1;
				}
		else{
			STM32DeviceId.Checked=0;
				}
#endif


OSTimeDly(OS_TICKS_PER_SEC/100);	    //延时0.01秒

ModbusInit();

OSTimeDly(OS_TICKS_PER_SEC/5);	    //延时0.2秒

for(;;)
		{

    OSTimeDly(OS_TICKS_PER_SEC/500);	    //延时2毫秒

    CheckAdrressKey();//分机地址设置拨码开关
    
    Coldw.SubAdr = 80 + ( lAddressKey & 0x0f ) ;//          地址设置
	
		ModbusTimeHandler();	
		
		GetModbusPark();  //慢点也可以
		
		}
}
////////////////////
void TaskTimePr(void * pdata)
{
  INT8U err;
  uchar  i;  
  unsigned short int  timer1,timer2;

  pdata = pdata;                   // 避免编译警告		
  OSTimeDly(OS_TICKS_PER_SEC/2);	    //延时0.5秒
  for(;;)
     {

      OSTimeDly(OS_TICKS_PER_SEC/100);	    //延时0.01秒
      
      timer1++;
      if(timer1 >= 20)  //200ms
           {
            timer1  = 0 ;
            OSSemPost(OSSemTimePid_Heat);   //电加热PID控制周期
           }



       timer2++;
       if(timer2 >= 50 ) //0.5s
           {
            timer2 = 0;
            OSSemPost(OSSemTimePid_StepMotor);   //水冷PID控制周期
           }
       }
}
////////////////////


////////////////////
void TaskHeat(void * pdata)
{
INT8U err;

unsigned char i;

pdata = pdata;                          	 	// 避免编译警告		

OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.5秒

for(;;)
		{
	
			OSSemPend(OSSemTimePid_Heat,0,&err);  //等待消息   OSSemTimePid_Heat
			//电加热PID
			
			for(i=0;i<8;i++)
			    {
          //PID_Calc(PID_ParaStruct *types, PidBufStruct *pidch, float NowPoint)
          
          HeatPidBuf[i].SetPoint = Coldw.T_set; //基本上多余
			    
			    PID_Calc(PidParam, &HeatPidBuf[i], ( HeatPidBuf[i].SetPoint - wAdcResoult [ i ] )); //一般是error = SetPoint - NewPoint ,这里反过来
			    
			    //HeatPidBuf[0].Qx = 200 ;
			    
			     switch(Coldw.unit_onof_flag[i])
			          {
			    	    
			    	    case 1:  //电加热自动工作
			          Coldw.TC_duty[i] = (unsigned short int)HeatPidBuf[i].Qx;   //PID结果去控制电加热
			          //输出
			          break;
			       
			          case 2:   // 电加热可以手动调整
			          break;
			       
			       
			           case 0:  //0 和 其它 值  电加热 关
			          default:  //0 和 其它 值  电加热 关
			       	  Coldw.TC_duty[i] = 0;
			          break;
			       	
			          }
			     }
	     
    Coldw.MONI_PX2 = HeatPidBuf[0].Px;  	   
    Coldw.MONI_IX2 = HeatPidBuf[0].Ix;  	       
    Coldw.MONI_DX2 = HeatPidBuf[0].Dx;  	        
    Coldw.MONI_QX2 = HeatPidBuf[0].Qx; //0.14;
    
    OSTimeDly(OS_TICKS_PER_SEC/100);	    //延时0.1秒
		}
}
/////////////////////////////////////////
void TaskStatus(void * pdata)
{
INT8U err;
uchar i;
pdata = pdata;                          	 	// 避免编译警告		

		for(i=0;i<10;i++)
					{
					LED1_ON;
					LED2_OFF;
					LED3_ON;
					LED4_OFF;
					
					OSTimeDly(OS_TICKS_PER_SEC/20);	    //延时0.05秒
					LED1_OFF;
					LED2_ON;
					LED3_OFF;
					LED4_ON;
					OSTimeDly(OS_TICKS_PER_SEC/20);	    //延时0.05秒
					}
			LED1_OFF;		
			LED2_OFF;
			LED3_OFF;
			LED4_OFF;
for(;;)
		{
		if(1)
					{
					Led_Status_Off;
					OSTimeDly(OS_TICKS_PER_SEC/4);	    //延时0.05秒
		
					Led_Status_On;
					OSTimeDly(OS_TICKS_PER_SEC/4);	    //延时0.05秒
					}
			else{
					Led_Status_On;
					OSTimeDly(OS_TICKS_PER_SEC/2);	    //延时0.1秒
					}	

		if(EventTimeBuz>0)
			{
				EventTimeBuz--;
				BUZ_ON;
			}
		else{
			BUZ_OFF;
			
				}

		if(EventTimeLed>0)
			{
				EventTimeLed--;
				Led_Event_On;
			}
		else{
				Led_Event_Off;
				}

		}
}
////////////////////


////////////////////
void TaskTs(void * pdata)
{
INT8U err;
 
unsigned char i; 
 

	//  MAX_TEMPRATURE_CHNALL
float *p_amp[8];	   
float *p_bias[8];


	pdata = pdata;                          	 	// 避免编译警告	
	   
p_amp[0]   = &Coldw.Ts1_AMP;				//温度采样放大倍数1
p_bias[0]  = &Coldw.Ts1_BIAS;				//温度采样偏移系数1  
p_amp[1]   = &Coldw.Ts2_AMP;				//温度采样放大倍数2
p_bias[1]  = &Coldw.Ts2_BIAS;				//温度采样偏移系数2
p_amp[2]   = &Coldw.Ts3_AMP;				//温度采样放大倍数3
p_bias[2]  = &Coldw.Ts3_BIAS;				//温度采样偏移系数3  
p_amp[3]   = &Coldw.Ts4_AMP;				//温度采样放大倍数4
p_bias[3]  = &Coldw.Ts4_BIAS;				//温度采样偏移系数4
p_amp[4]   = &Coldw.Ts5_AMP;				//温度采样放大倍数5
p_bias[4]  = &Coldw.Ts5_BIAS;				//温度采样偏移系数5  
p_amp[5]   = &Coldw.Ts6_AMP;				//温度采样放大倍数6
p_bias[5]  = &Coldw.Ts6_BIAS;				//温度采样偏移系数6
p_amp[6]   = &Coldw.Ts7_AMP;				//温度采样放大倍数7
p_bias[6]  = &Coldw.Ts7_BIAS;				//温度采样偏移系数7  
p_amp[7]   = &Coldw.Ts8_AMP;				//温度采样放大倍数8
p_bias[7]  = &Coldw.Ts8_BIAS;				//温度采样偏移系数8



OSTimeDly(OS_TICKS_PER_SEC);	    //延时0.5秒
ADS8328_Init();			//ADS8328初始化
ADS8328_SelectChannel(1);				//选择ADS8328通道号，1 = 通道1 ，2 = 通道2
//////
	for(;;)
				{
				//OS_ENTER_CRITICAL();
				//OS_EXIT_CRITICAL();
       

Led_Test_Adc_On1;

//delay_us(5000);//5ms

         for ( i = 0 ; i < MAX_TEMPRATURE_CHNALL ; i++ )
            {
	           CHECK_SelectChannel( i );  //TC温度采样 通道切换
	           
	           OSTimeDly(OS_TICKS_PER_SEC/500);	    //延时2ms		
	           //CHECK_AD590OneTCCheckUseADS8328( 5 , 1.000  , 0.000  ,  0.1 ,  &( wAdcResoult [ i ] ));  //大约0.8ms
             CHECK_AD590OneTCCheckUseADS8328( 5 , *p_amp[i]  , *p_bias[i]  ,  Coldw.T_bias_set ,  &( wAdcResoult [ i ] ));  //大约0.8ms
           
             Coldw.Ts[i]=wAdcResoult [ i ];
            }
		
		    Led_Test_Adc_Off1;
				   
				OSTimeDly(OS_TICKS_PER_SEC/100);	    //延时10ms			

					}
}
/////////////////////////////


//uint32 NumberHexStringToInt32(uchar *p)	//最多8位HEX码的数字字符串转换为32位无符号整型
//{
//uint32 word2;
//uchar i;
//word2=0;
//for(i=0;i<8;i++)
//	{
//	if(IsHexAsc(*p))
//        	{
//        	word2=word2*0X10+AscToHex(*p);
//        	}
//        else break;
//        p++;
//        };
//
//return  word2;    	
//}

////////////////////////////////////










/////////////////////////////
void Task004(void * pdata)
{
	INT8U err;
	
	
 	pdata = pdata;                          	 	// 避免编译警告	   


OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.1秒


//////
	for(;;)
				{
				//OS_ENTER_CRITICAL();
				//OS_EXIT_CRITICAL();


	OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.01秒

					}
}
////////////////////


////////////////////
void Task001(void * pdata)
{
INT8U err;

//uchar i;

pdata = pdata;                          	 	// 避免编译警告		

OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.1秒

 
 #if CONFIG_HD_TIM
	Init_Tim3 ();		//步进电机脉冲输出用
 #endif
 
 OSSemMotors = OSSemCreate(1);

for(;;)
		{

     OSSemPend(OSSemTimePid_StepMotor,0,&err);  //OSSemPost(OSSemTimePid_StepMotor);   OSSemTimePid_Heat



                  
    OSTimeDly(OS_TICKS_PER_SEC/500);  //补充延时

		}
}
/////////////////////////////



void Task003(void * pdata)
{
//INT8U err;
 


	pdata = pdata;     // 避免编译警告	   

		for(;;)
						{
						//OS_ENTER_CRITICAL();
						//OS_EXIT_CRITICAL();
						OSTimeDly(OS_TICKS_PER_SEC/20);	    //延时0.05秒		
						
		
				}	
}



////////////////////////////////////////////////
void Task002(void * pdata)
{
//INT8U err;
 
 
	pdata = pdata;                          	 	// 避免编译警告	   


	for(;;)
				{
				//OS_ENTER_CRITICAL();
				//OS_EXIT_CRITICAL();


					
			OSTimeDly(OS_TICKS_PER_SEC/20);	    //延时0.05秒		

	
					}
}
///////////////////////////









/////////////////



//////////////





