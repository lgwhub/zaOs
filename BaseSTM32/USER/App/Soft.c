/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.blkeji.com
**
**
**--------------------------------------------------------------------------------------------------------

** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <includes.h>            




//extern OS_EVENT *OSSemblinkOut2;
//extern OS_EVENT *OSSemblinkOut3;
extern OS_EVENT *OSSemUart1;
//extern OS_EVENT *OSSemUart2;
extern OS_EVENT *OSSemTimePid_StepMotor;
extern OS_EVENT *OSSemTimePid_Heat;


/* Private variables ---------------------------------------------------------*/





static  OS_STK         Task001Stk[Task001Stk_SIZE];
static  OS_STK         Task002Stk[Task002Stk_SIZE];
static  OS_STK         Task003Stk[Task003Stk_SIZE];
static  OS_STK         Task004Stk[Task004Stk_SIZE];
static  OS_STK         Task005Stk[Task005STK_SIZE];
static  OS_STK         Task006Stk[Task006Stk_SIZE];

static  OS_STK         TaskTsStk[TaskTsStk_SIZE];
static  OS_STK         TaskVirPwmStk[TaskVirPwmStk_SIZE];
static  OS_STK         TaskModbusStk[TaskModbusStk_SIZE];
static  OS_STK         TaskTimePrStk[TaskTimePrStk_SIZE];
static  OS_STK         TaskHeatStk[TaskHeatStk_SIZE];
static  OS_STK         TaskStatusStk[ TaskStatusStk_SIZE];


/* Private function prototypes -----------------------------------------------*/
static void Task005 (void);
static void Task006 (void);

//extern void TaskTs(void);
//extern void Task004(void);
//extern void Task002(void * pdata);
 
void  App_BlinkTaskCreate (void)
{
    CPU_INT08U  os_err;

	os_err = os_err; /* prevent warning... */
	

//OSSemblinkOut2 = OSSemCreate(0);
//OSSemblinkOut3 = OSSemCreate(0);

OSSemUart1 = OSSemCreate(1);
//OSSemUart2 = OSSemCreate(1);
			
OSSemTimePid_StepMotor = OSSemCreate(0);
OSSemTimePid_Heat = OSSemCreate(0);

//	os_err = OSTaskCreate((void (*)(void *)) Task006,				
//                          (void          * ) 0,							
//                          (OS_STK        * )&Task006Stk[Task006Stk_SIZE - 1],		
//                          (INT8U           ) Task006_PRIO  );	

    os_err = OSTaskCreateExt((void (*)(void *)) Task006,
                             (void          * ) 0,
                             (OS_STK        * )&Task006Stk[Task006Stk_SIZE - 1],
                             (INT8U           ) Task006_PRIO,
                             (INT16U          ) Task006_PRIO,
                             (OS_STK        * )&Task006Stk[0],
                             (INT32U          ) Task006Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));


	  os_err = OSTaskCreate((void (*)(void *)) Task005,				
                          (void          * ) 0,							
                          (OS_STK        * )&Task005Stk[Task005STK_SIZE - 1],		
                          (INT8U           ) Task005_PRIO  );							


    os_err = OSTaskCreateExt((void (*)(void *)) Task004,
                             (void          * ) 0,
                             (OS_STK        * )&Task004Stk[Task004Stk_SIZE - 1],
                             (INT8U           ) Task004_PRIO,
                             (INT16U          ) Task004_PRIO,
                             (OS_STK        * )&Task004Stk[0],
                             (INT32U          ) Task004Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));



    os_err = OSTaskCreateExt((void (*)(void *)) TaskTs,
                             (void          * ) 0,
                             (OS_STK        * )&TaskTsStk[TaskTsStk_SIZE - 1],
                             (INT8U           ) TaskTs_PRIO,
                             (INT16U          ) TaskTs_PRIO,
                             (OS_STK        * )&TaskTsStk[0],
                             (INT32U          ) TaskTsStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
    
    os_err = OSTaskCreateExt((void (*)(void *)) Task003,
                             (void          * ) 0,
                             (OS_STK        * )&Task003Stk[Task003Stk_SIZE - 1],
                             (INT8U           ) Task003_PRIO,
                             (INT16U          ) Task003_PRIO,
                             (OS_STK        * )&Task003Stk[0],
                             (INT32U          ) Task003Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));


    os_err = OSTaskCreateExt((void (*)(void *)) Task002,
                             (void          * ) 0,
                             (OS_STK        * )&Task002Stk[Task002Stk_SIZE - 1],
                             (INT8U           ) Task002_PRIO,
                             (INT16U          ) Task002_PRIO,
                             (OS_STK        * )&Task002Stk[0],
                             (INT32U          ) Task002Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));


    os_err = OSTaskCreateExt((void (*)(void *)) TaskVirPwm,
                             (void          * ) 0,
                             (OS_STK        * )&TaskVirPwmStk[TaskVirPwmStk_SIZE - 1],
                             (INT8U           ) TaskVirPwm_PRIO,
                             (INT16U          ) TaskVirPwm_PRIO,
                             (OS_STK        * )&TaskVirPwmStk[0],
                             (INT32U          ) TaskVirPwmStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));

    os_err = OSTaskCreateExt((void (*)(void *)) TaskModbus,
                             (void          * ) 0,
                             (OS_STK        * )&TaskModbusStk[TaskModbusStk_SIZE - 1],
                             (INT8U           ) TaskModbus_PRIO,
                             (INT16U          ) TaskModbus_PRIO,
                             (OS_STK        * )&TaskModbusStk[0],
                             (INT32U          ) TaskModbusStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));

    os_err = OSTaskCreateExt((void (*)(void *)) Task001,
                             (void          * ) 0,
                             (OS_STK        * )&Task001Stk[Task001Stk_SIZE - 1],
                             (INT8U           ) Task001_PRIO,
                             (INT16U          ) Task001_PRIO,
                             (OS_STK        * )&Task001Stk[0],
                             (INT32U          ) Task001Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
                             
    os_err = OSTaskCreateExt((void (*)(void *)) TaskTimePr,
                             (void          * ) 0,
                             (OS_STK        * )&TaskTimePrStk[TaskTimePrStk_SIZE - 1],
                             (INT8U           ) TaskTimePr_PRIO,
                             (INT16U          ) TaskTimePr_PRIO,
                             (OS_STK        * )&TaskTimePrStk[0],
                             (INT32U          ) TaskTimePrStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));                         
                             
     os_err = OSTaskCreateExt((void (*)(void *)) TaskHeat,
                             (void          * ) 0,
                             (OS_STK        * )&TaskHeatStk[TaskHeatStk_SIZE - 1],
                             (INT8U           ) TaskHeat_PRIO,
                             (INT16U          ) TaskHeat_PRIO,
                             (OS_STK        * )&TaskHeatStk[0],
                             (INT32U          ) TaskHeatStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));                                
                             
      os_err = OSTaskCreateExt((void (*)(void *)) TaskStatus,
                             (void          * ) 0,
                             (OS_STK        * )&TaskStatusStk[TaskStatusStk_SIZE - 1],
                             (INT8U           ) TaskStatus_PRIO,
                             (INT16U          ) TaskStatus_PRIO,
                             (OS_STK        * )&TaskStatusStk[0],
                             (INT32U          ) TaskStatusStk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));                               
                             
                             
	#if OS_TASK_NAME_EN > 0
    	
    	OSTaskNameSet(Task006_PRIO, "Task006", &os_err);
    	OSTaskNameSet(Task005_PRIO, "Task005", &os_err);
			OSTaskNameSet(Task004_PRIO, "Task004", &os_err);
    	OSTaskNameSet(Task003_PRIO, "Task003", &os_err);			
    	OSTaskNameSet(Task002_PRIO, "Task002", &os_err);
    	OSTaskNameSet(Task001_PRIO, "Task001", &os_err);
    	    	
    	OSTaskNameSet(TaskVirPwm_PRIO, "TaskVirPwm", &os_err);
    	OSTaskNameSet(TaskTs_PRIO, "TaskTs", &os_err);    	
    	OSTaskNameSet(TaskModbus_PRIO, "TaskModbus", &os_err);
     	OSTaskNameSet(TaskTimePr_PRIO, "TaskTimePr", &os_err);
    	OSTaskNameSet(TaskHeat_PRIO, "TaskHeat", &os_err);
    	OSTaskNameSet(TaskStatus_PRIO, "TaskStatus", &os_err);   	
  	
	#endif
}


//////////////
static void Task006 (void)
{
	
	for(;;)
	{
		
		
		OSTimeDlyHMSM(0, 0,1, 100);	 /* 1 seconds  */

		//LED1_ON;
		//LED2_OFF;
		//GPIO_ResetBits(GPIOE,GPIO_Pin_1);

		OSTimeDlyHMSM(0, 0, 1, 100);

		//LED2_ON;
		//LED1_OFF;
//GPIO_SetBits(GPIOE , GPIO_Pin_1);
	
	//OSTimeDly(OS_TICKS_PER_SEC);
	
		}
}


static void Task005 (void) {                 
  
   
   	for(;;)
   	{   
	    //Delay( rand()%0xfffff ); 	

//OSTimeDly(OS_TICKS_PER_SEC);
OSTimeDlyHMSM(0, 0, 0,50);	//50ms

   }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
