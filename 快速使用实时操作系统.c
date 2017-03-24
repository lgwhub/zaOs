//     嵌入式实时操作系统

// 可能会颠覆原来的思路，改变原来的习惯，具体做项目时可以选择使用或者不用.

/*
有什么用
1.嵌入式实时操作系统的设计者已经考虑到了我们做程序会遇到的各种问题,我们可以在专家的肩膀上，利用专家的经验提高工作效率。
2.嵌入式实时操作系统学习可以扩大知识面，储备更多也可能是更好的方法去解决问题。老是听到老教授说汇编好，大家不会相信吧。
3.嵌入式实时操作系统我们不去接触一下，可能会搞不懂别人的代码和用语。学习容易更别人的代码对接，移植。
4.嵌入式实时操作系统的思路跟大学的单片机课程不一样，是发达国家专家的创意，可以打开我们的思维。
5.嵌入式实时操作系统的冗余，有利于我们正在使用的平台插入一些新功能，例如液晶屏


有什么功能
使用嵌入式实时操作系统，做的程序相当于多个CPU同时工作，多个工作互相独立。

怎么入门
我们的时间是有限的，工作忙，知识在爆炸，要学的东西太多。所以我们需要方法和正确的目标
目标？怎么知道这个内容好不好，谁推荐，到底会不会浪费时间，学了会不会没有用。最后我认为要用最短时间去学去用。
方法？软件工程师不要去了解电脑制造，电子应用工程师不要去了解半导体制造，精通自己的专业部分，一般书我看了都是分析操作系统原理，怎么样实现，各种问题处理，移植。我觉得暂时不需要知道原理，否则太复杂了，学了前面忘记后面，我们还是不知道有什么用，到底怎么用，然后我们也没有兴趣坚持学下去。所以我认为要简单了解，快速使用，先用起来，再慢慢边学边用。

立刻进入实战  ucos 2
准备了一个代码模板，这样可以快速使用。


*/

//代码结构

INT32S main (void)
{
  CPU_INT08U  os_err;
  
	os_err = os_err; /* prevent warning... */

	/* Note:  由于使用UCOS, 在OS运行之前运行,注意别使能任何中断. */
	CPU_IntDis();                    /* Disable all ints until we are ready to accept them.  */

  OSInit();                        /* Initialize "uC/OS-II, The Real-Time Kernel".         */
	
OSSemTimePid_StepMotor = OSSemCreate(0);   //创建

    
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

pdata = pdata;                          	 	// 避免编译警告		

OSTimeDly(OS_TICKS_PER_SEC/10);	    //延时0.1秒


 
 OSSemMotors = OSSemCreate(1);  //创建

for(;;)
		{

     OSSemPend(OSSemTimePid_StepMotor,0,&err);  //等消息



                  
    OSTimeDly(OS_TICKS_PER_SEC/500);  //补充延时

		}
}
/////////////////////////////


////////////////////////////////////////////////
void Task002(void * pdata)
{
//INT8U err;
 
 
	pdata = pdata;                          	 	// 避免编译警告	   


	for(;;)
				{
				//OS_ENTER_CRITICAL();
				//OS_EXIT_CRITICAL();

        OSSemPost(OSSemTimePid_StepMotor);   //发消息
					
			OSTimeDly(OS_TICKS_PER_SEC/20);	    //延时0.05秒		

	
					}
}


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



/*
最后我们进门了后,回头再仔细看一下UCOS2，UCOS3，找更合理的方法做我们的事情，我们像弄清楚了一盘的棋谱，接着我们自己去下吧。



*/






