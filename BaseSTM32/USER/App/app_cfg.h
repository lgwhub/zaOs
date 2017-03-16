/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.blkeji.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               app_cfg.h
** Descriptions:            ucosii configuration
**
**--------------------------------------------------------------------------------------------------------

** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__
					  

/*
*********************************************************************************************************
*                                       MODULE ENABLE / DISABLE
*********************************************************************************************************
*/
#define  OS_VIEW_MODULE                 0*DEF_ENABLED	     	/* DEF_ENABLED = Present, DEF_DISABLED = Not Present        */

#define  OS_VIEW_USART_NUMBER			1

#if   OS_VIEW_USART_NUMBER == 1
#define  OS_VIEW_USART				     USART1	    
#elif  OS_VIEW_USART_NUMBER == 2
#define  OS_VIEW_USART				     USART2    
#elif  OS_VIEW_USART_NUMBER == 3
#define  OS_VIEW_USART				     USART3    
#endif


#define  CONFIG_ADC		0
#define  CONFIG_PWM		0

#define  CONFIG_HD_TIM		1

#define SOFT_VER   2


/*
*********************************************************************************************************
*                                              TASKS NAMES
*********************************************************************************************************
*/


#define USART1_REMAP						0
#define JTAG_REMAP							0

/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                               3


#define  Task002_PRIO          	 		(OS_LOWEST_PRIO - 24)
#define  Task004_PRIO          	 		(OS_LOWEST_PRIO - 22)
#define  Task001_PRIO          	 		(OS_LOWEST_PRIO - 14)
#define  Task003_PRIO          	 		(OS_LOWEST_PRIO - 9)

#define  TaskTs_PRIO          	 		(OS_LOWEST_PRIO - 23)

#define  TaskVirPwm_PRIO          	 		(OS_LOWEST_PRIO - 16)

#define  TaskModbus_PRIO          	 		(OS_LOWEST_PRIO - 15)

#define  TaskTimePr_PRIO          	 		(OS_LOWEST_PRIO - 13)

#define  TaskHeat_PRIO          	 		(OS_LOWEST_PRIO - 12)

#define  TaskStatus_PRIO          	 		(OS_LOWEST_PRIO - 11)


#define  Task006_PRIO          	 		(OS_LOWEST_PRIO - 7)
#define  Task005_PRIO          	 (OS_LOWEST_PRIO - 6)

#define  APP_TASK_OSVIEW_TERMINAL_PRIO	 (OS_LOWEST_PRIO - 4)
#define  OS_VIEW_TASK_PRIO               (OS_LOWEST_PRIO - 3)
#define  OS_TASK_TMR_PRIO                (OS_LOWEST_PRIO - 2)




/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*                             Size of the task stacks (# of OS_STK entries)
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE                          (64+2)

#define  APP_TASK_OSVIEW_TERMINAL_STK_SIZE   			 128u
#define  OS_VIEW_TASK_STK_SIZE                           128u

#define  Task006Stk_SIZE                          (64+2u)
#define  TaskTsStk_SIZE                          (200+2u)

#define  Task005STK_SIZE                         (128+2)
#define  Task004Stk_SIZE                          (76+2u)
#define  Task003Stk_SIZE                          (76+2u)
#define  Task002Stk_SIZE                          (64+2u)
#define  Task001Stk_SIZE                          (164+2u)

#define  TaskVirPwmStk_SIZE                          (76+2u)
#define  TaskModbusStk_SIZE                          (155+2u)
#define  TaskTimePrStk_SIZE                          (88+2u)
#define  TaskHeatStk_SIZE                          (120+2u)
#define  TaskStatusStk_SIZE                          (84+2u)

/*
*********************************************************************************************************
*                                                  LIB
*********************************************************************************************************
*/

#define  uC_CFG_OPTIMIZE_ASM_EN                 DEF_ENABLED
#define  LIB_STR_CFG_FP_EN                      DEF_DISABLED

/*
*********************************************************************************************************
*                                             io def     
*********************************************************************************************************
*/







#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

