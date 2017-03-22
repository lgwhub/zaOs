
#include "includes.h"

//�Զ�������ʱ��
unsigned short int TimeAutoLock1;
unsigned short int TimeAutoLock2;
unsigned short int TimeAutoLock3;
//#define ISP_ADDR        0x1FFFF000
void JumpAppAdr(unsigned long int adr)
{
	
   void  (*func)(void);	
   unsigned long int  spval;	
	
     spval =  *(unsigned long int *)(adr);
     
     __set_MSP(spval);//����SP.
     
	   func  =  (void(*)(void))( (unsigned long int )(adr+4)|1 );
	   //func ();
     (*func)();

}

////////////////////////////////////////////
void IspMarkLoad(void)
{
//void LoadFromBKP(void)
unsigned short int iMark1,iMark2;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP,ENABLE);
PWR_BackupAccessCmd(ENABLE);
BKP_ClearFlag();
	
	//IspMarkWrite(CMND_ISP_22);
  //��	
	iMark1  =  BKP_ReadBackupRegister(BKP_DR2);
	iMark2  =  BKP_ReadBackupRegister(BKP_DR3);

  //clr
  BKP_WriteBackupRegister(BKP_DR2,0);	
  BKP_WriteBackupRegister(BKP_DR3,0);
	
	

if(iMark1 != CMND_ISP_22)
	{
		return;
	}
if(iMark2 != (CMND_ISP_22+3) )
	{
		return;
	}	
	
// to isp
	
//JumpAppAdr(unsigned long int adr)
//#define ISP_ADDR        0x1FFFF000
JumpAppAdr(0x1FFFF000);   //��ת�����س���

}
/////////////////////////////////////////////////////
void IspMarkWrite(uint16_t ix)
{
	BKP_WriteBackupRegister(BKP_DR2,ix);
	BKP_WriteBackupRegister(BKP_DR3,ix+3);
}	


void SoftReset(void)
{//RCC_BackupResetCmd
 __set_FAULTMASK(1);      // �ر������ж�
 NVIC_SystemReset();// ��λ

//       �ڹٷ������� core_cm3.h �ļ��� ֱ���ṩ�� ϵͳ��λ�ĺ��� 
//          
//        static __INLINE void NVIC_SystemReset(void)
//        {
//          SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      | 
//                                   (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) | 
//                                   SCB_AIRCR_SYSRESETREQ_Msk);                   /* Keep priority group unchanged */
//          __DSB();                                                                                       /* Ensure completion of memory access */              
//          while(1);                                                                                        /* wait until reset */
//        }
//        ���ǲ���ֱ�ӵ������������OK�ˣ� 
//        ��Cortex-M3Ȩ��ָ��������ôһ�仰 
//        ������һ��Ҫע������⣺��SYSRESETREQ ����Ϊ��Ч������λ������ִ�и�λ��� 
//        ��������һ����ʱ���ڴ���ʱ�ڼ䣬��������Ȼ������Ӧ�ж����󡣵����ǵı���������Ҫ 
//        �ô˴�ִ�е���Ϊֹ����Ҫ�����κ����������ˡ����ԣ�����ڷ�����λ����ǰ���Ȱ� 
//        FAULTMASK ��λ�� 
//        ��������ڽ�FAULTMASK ��λ������һʧ�� 
//        ͬ���ٷ� core_cm3.h �ļ���Ҳֱ���ṩ�˸ú��� 
//          
//        static __INLINE void __set_FAULTMASK(uint32_t faultMask)
//        {
//          register uint32_t __regFaultMask       __ASM("faultmask");
//          __regFaultMask = (faultMask & 1);
//        }
 	
}



//////////////////////
void ModbusCommand1(void)//�յ�����ʱִ��һ��
{
//Coldw.lyy_reserve,Coldw.lSysSwitch_reserve
      if(Coldw.lBackupRestore == 0 ) 
           {
	          return;
            }

          switch(Coldw.lBackupRestore)//Coldw.lyy_reserve
          			{
          			case 1:  //���� 1 ��Ȼ�� 2 Ȼ��
          				TimeAutoLock1 = 6;  //6�� //�Զ�������ʱ��

          		  break;

          			case 2: //���� 1 ��Ȼ�� 2
          				if(TimeAutoLock2 > 0 )
          				     {
          				   	  TimeAutoLock3 = 6;  //12�� //�Զ�������ʱ��
          				     }

          		  break;          
          		  
          			case 3: //���� 1 ��Ȼ�� 2
          				if(TimeAutoLock1 > 0 )
          				     {
          				   	  TimeAutoLock2 = 6;  //12�� //�Զ�������ʱ��
          				     }

          		  break;           		  			
          		  
          		  case CMND_RESET_21: //���� 1 ��Ȼ�� 2 Ȼ��21
          			  if(TimeAutoLock3 > 0)
          			  	  {
          			  	  Coldw.lBackupRestore +=3;	
          			  		OSTimeDly(OS_TICKS_PER_SEC*6);
          			  		SoftReset();
          			  	  }
          			break;
          			
          			case CMND_ISP_22: //���� 1 ��Ȼ�� 2 Ȼ��22
          			if(TimeAutoLock3 > 0)
          			  	  {
          			  	  	
          			  	  Coldw.lBackupRestore +=3;		
          			  	  IspMarkWrite(CMND_ISP_22);	//Coldw.lBackupRestore);//
          			  	  
          			  	  
          			  		
          			  		OSTimeDly(OS_TICKS_PER_SEC*6);
          			  		SoftReset();
          			  	  }
          			break;          
          			
  
          		          						

          			case CMND_EXTREN_33:
          			//��modbus�������ͨѶ�������д�洢��
          			if(TimeAutoLock3 > 0)
          				{
          					
          				}
          			
          			break; 

								case CMND_MEMERY_45:
								//initalize backup  Restore  parameter
								if(TimeAutoLock3 > 0)
          				{
          					
          				}
          			break; 

								case 91:
								//initalize 0								
								if(TimeAutoLock3 > 0)
          				{
          					//Default_ParamInit0();
          					//FlagSetAllDefault = 1;
                    FlagSetAllDefault = 1;
                    Coldw.lBackupRestore =0; 
          				}
								break;
          	
          	    
								case 95:
								//initalize   1
								if(TimeAutoLock3 > 0)
          				{
          					//FlagSetAllDefault = 2;
				 	         FlagSetAllDefault = 2;
				 	    
                   Coldw.lBackupRestore =0;
         
                   //Default_ParamInit1();    ////��Ҫ����Ĳ���
                   }
								break;          	
								case 98:
								//initalize 2 all
								if(TimeAutoLock3 > 0)
          				{
          					//FlagSetAllDefault = 3;
          					//Default_ParamInit0();
                    //Default_ParamInit1();    ////��Ҫ����Ĳ���
                    //Default_ParamInit2();    ////����ֵ
                   Coldw.lBackupRestore =0;
          				}
								break;           	
          			}

	
      	
}


