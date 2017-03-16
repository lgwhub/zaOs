/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.blkeji.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               includes.h
** Descriptions:            includes.h for ucos
**
**--------------------------------------------------------------------------------------------------------

** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/


#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

/* Includes ------------------------------------------------------------------*/
#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <stdarg.h>
#include  <math.h>

#include  <uCOS-II\Source\ucos_ii.h>
#include  <uCOS-II\Ports\ARM-Cortex-M3\RealView\os_cpu.h>
#include  <uC-CPU\ARM-Cortex-M3\RealView\cpu.h>
#include  <lib_def.h>
#include  <lib_mem.h>
#include  <lib_str.h>

#if (OS_VIEW_MODULE == DEF_ENABLED)
#include    <uCOS-VIEW\Ports\ARM-Cortex-M3\Realview\os_viewc.h>
#include    <uCOS-VIEW\Source\os_view.h>
#endif


#include  <stm32f10x.h>
#include "Nomal.h"
#include "LoopBuf.h"
#include "uart.h"

#include "config.h"

#include "Test.h" 

#include "user.h"

#include "HD_159.h"

	#if CONFIG_ADC
			#include "adc.h"
	#endif
	
	#if CONFIG_PWM
	#include "pwm.h"
   	#endif
	
//#include "StepMotor.h"	
	
#include "ADS8328.h"
#include "AT24C1024.H"
#include "Parameter.h"
#include "ModbusProcess.h"
#include "ModbusRecv.h"
#include "pid.h"


#include "jump.h"

//#include	"GetAverage.h"
	
//	#include "STM32_DeviceId.h"
	


#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/


