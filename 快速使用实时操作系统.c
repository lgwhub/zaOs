//     Ƕ��ʽʵʱ����ϵͳ

// ���ܻ�߸�ԭ����˼·���ı�ԭ����ϰ�ߣ���������Ŀʱ����ѡ��ʹ�û��߲���.

/*
��ʲô��
1.Ƕ��ʽʵʱ����ϵͳ��������Ѿ����ǵ�������������������ĸ�������,���ǿ�����ר�ҵļ���ϣ�����ר�ҵľ�����߹���Ч�ʡ�
2.Ƕ��ʽʵʱ����ϵͳѧϰ��������֪ʶ�棬��������Ҳ�����Ǹ��õķ���ȥ������⡣���������Ͻ���˵���ã���Ҳ������Űɡ�
3.Ƕ��ʽʵʱ����ϵͳ���ǲ�ȥ�Ӵ�һ�£����ܻ�㲻�����˵Ĵ�������ѧϰ���׸����˵Ĵ���Խӣ���ֲ��
4.Ƕ��ʽʵʱ����ϵͳ��˼·����ѧ�ĵ�Ƭ���γ̲�һ�����Ƿ������ר�ҵĴ��⣬���Դ����ǵ�˼ά��
5.Ƕ��ʽʵʱ����ϵͳ�����࣬��������������ʹ�õ�ƽ̨����һЩ�¹��ܣ�����Һ����


��ʲô����
ʹ��Ƕ��ʽʵʱ����ϵͳ�����ĳ����൱�ڶ��CPUͬʱ����������������������

��ô����
���ǵ�ʱ�������޵ģ�����æ��֪ʶ�ڱ�ը��Ҫѧ�Ķ���̫�ࡣ����������Ҫ��������ȷ��Ŀ��
Ŀ�ꣿ��ô֪��������ݺò��ã�˭�Ƽ������׻᲻���˷�ʱ�䣬ѧ�˻᲻��û���á��������ΪҪ�����ʱ��ȥѧȥ�á�
�������������ʦ��Ҫȥ�˽�������죬����Ӧ�ù���ʦ��Ҫȥ�˽�뵼�����죬��ͨ�Լ���רҵ���֣�һ�����ҿ��˶��Ƿ�������ϵͳԭ����ô��ʵ�֣��������⴦����ֲ���Ҿ�����ʱ����Ҫ֪��ԭ������̫�����ˣ�ѧ��ǰ�����Ǻ��棬���ǻ��ǲ�֪����ʲô�ã�������ô�ã�Ȼ������Ҳû����Ȥ���ѧ��ȥ����������ΪҪ���˽⣬����ʹ�ã�������������������ѧ���á�

���̽���ʵս  ucos 2
׼����һ������ģ�壬�������Կ���ʹ�á�


*/

//����ṹ

INT32S main (void)
{
  CPU_INT08U  os_err;
  
	os_err = os_err; /* prevent warning... */

	/* Note:  ����ʹ��UCOS, ��OS����֮ǰ����,ע���ʹ���κ��ж�. */
	CPU_IntDis();                    /* Disable all ints until we are ready to accept them.  */

  OSInit();                        /* Initialize "uC/OS-II, The Real-Time Kernel".         */
	
OSSemTimePid_StepMotor = OSSemCreate(0);   //����

    
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




    os_err = OSTaskCreateExt((void (*)(void *)) Task001,
                             (void          * ) 0,
                             (OS_STK        * )&Task001Stk[Task001Stk_SIZE - 1],
                             (INT8U           ) Task001_PRIO,
                             (INT16U          ) Task001_PRIO,
                             (OS_STK        * )&Task001Stk[0],
                             (INT32U          ) Task001Stk_SIZE,
                             (void          * ) 0,
                             (INT16U          )(OS_TASK_OPT_STK_CLR | OS_TASK_OPT_STK_CHK));
                             


	OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II).  */

	return (0);
}



////////////////////
void Task001(void * pdata)
{
INT8U err;

//uchar i;

pdata = pdata;                          	 	// ������뾯��		

OSTimeDly(OS_TICKS_PER_SEC/10);	    //��ʱ0.1��


 
 OSSemMotors = OSSemCreate(1);  //����

for(;;)
		{

     OSSemPend(OSSemTimePid_StepMotor,0,&err);  //����Ϣ



                  
    OSTimeDly(OS_TICKS_PER_SEC/500);  //������ʱ

		}
}
/////////////////////////////


////////////////////////////////////////////////
void Task002(void * pdata)
{
//INT8U err;
 
 
	pdata = pdata;                          	 	// ������뾯��	   


	for(;;)
				{
				//OS_ENTER_CRITICAL();
				//OS_EXIT_CRITICAL();

        OSSemPost(OSSemTimePid_StepMotor);   //����Ϣ
					
			OSTimeDly(OS_TICKS_PER_SEC/20);	    //��ʱ0.05��		

	
					}
}


void Task003(void * pdata)
{
//INT8U err;
 


	pdata = pdata;     // ������뾯��	   

		for(;;)
						{
						//OS_ENTER_CRITICAL();
						//OS_EXIT_CRITICAL();
						OSTimeDly(OS_TICKS_PER_SEC/20);	    //��ʱ0.05��		
						
		
				}	
}



/*
������ǽ����˺�,��ͷ����ϸ��һ��UCOS2��UCOS3���Ҹ�����ķ��������ǵ����飬������Ū�����һ�̵����ף����������Լ�ȥ�°ɡ�



*/






