//   HD_Line1.c     
    #include <includes.h>
    

/////////////
//void GPIO_Configuration(void)
void InitGpio(void)
{

  GPIO_InitTypeDef GPIO_InitStructure;
  
  //���������
//  GPIO_SetBits(GPIOA,GPIO_Pin_All);
//	GPIO_SetBits(GPIOB,GPIO_Pin_All); 
//	GPIO_SetBits(GPIOC,GPIO_Pin_All);	 
  //GPIO_SetBits(GPIOD,GPIO_Pin_All);
	//GPIO_SetBits(GPIOE,GPIO_Pin_All);

 ////////  GPIO  PA  //////////////////
  #if JTAG_REMAP
    		//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);
    		//GPIO_Remap_SWJ_Disable,GPIO_Remap_USART1
 				GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
  #else
  //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
  		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);
  #endif
   
  // PA0  PA3  PA6 ����
 GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_0 | GPIO_Pin_3 | GPIO_Pin_6 );
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
  //PA1,PA2,PA4,PA5,PA7 ���
 GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_8 );
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//GPIO_Mode_Out_OD;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
 
 // PA2->TXD2,PA9->TXD1
 //			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_9; // PA2->TXD2,PA9->TXD1
 			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
 			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);
	  
  
 //PA10->RXD1
 //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_10;		//PA3->RXD2,PA10->RXD1
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;		//PA3->RXD2,PA10->RXD1 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  //GPIO_Mode_IN_FLOATING;	
 GPIO_Init(GPIOA,&GPIO_InitStructure);

 
 
 
 ////////  GPIO  PB  ////////////////// 

 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,ENABLE); 
  //PB7 PB8 PB9 ��ͨ�����,		LED1 ->PB6  LED2 ->PB5  ��ָʾ��PB10->TXD3
  

  #if USART1_REMAP

 // GPIO_Pin_6 , GPIO_Pin_7 ӳ��UART1
 
    //GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE);
  #else
  //GPIO_Pin_6 , GPIO_Pin_7 ��ͨ��
 //I2C  PB6 -> SCL , PB7 -> SDA
 GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;//GPIO_Mode_Out_PP;
 GPIO_Init(GPIOB,&GPIO_InitStructure);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;//GPIO_Mode_Out_PP;
GPIO_Init(GPIOB,&GPIO_InitStructure);
 
 #endif
 
 
 //PB0 PB3 PB4 PB8 PB9����� Sensor LOAD  LED1--LED4
 GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0 | GPIO_Pin_1;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOB,&GPIO_InitStructure);
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;//GPIO_Mode_Out_PP;
 GPIO_Init(GPIOB,&GPIO_InitStructure);




 //PB0-PB1->ADIN,PB2->BOOT1
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//GPIO_Init(GPIOB,&GPIO_InitStructure);

////PB10->TXD3;
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
// GPIO_Init(GPIOB,&GPIO_InitStructure);
////PB11->RXD3,PB12 PB0->KEY
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_0;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//GPIO_Init(GPIOB,&GPIO_InitStructure);
  
  
  
//PC6--PC9 PD8--PD15 PE8--PE14  �����������  
 ////////  GPIO  PC  //////////////////

 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
//  //PC0-PC5->ADIN, 
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
// GPIO_Init(GPIOC,&GPIO_InitStructure);

// �����������  ���
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOC,&GPIO_InitStructure);
 
// // PC10��TXD4��  PC12,TXD5���
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 |  GPIO_Pin_12;
// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//GPIO_Mode_Out_PP;
// GPIO_Init(GPIOC,&GPIO_InitStructure);
 
// PC0-- PC3 ���뿪������   
 GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 GPIO_Init(GPIOC,&GPIO_InitStructure);
 
 
////////  GPIO  PD  //////////////////
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

// �����������  ���
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOD,&GPIO_InitStructure);
  
// ����ȿ���  ���
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOD,&GPIO_InitStructure);  
  

  ////////  GPIO  PE  //////////////////
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

// �����������  ���
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOE,&GPIO_InitStructure);
  

}
//////////////////////////////////////////////



//void  Init_Tim2 (void)
//{
//#if CONFIG_HD_TIM  
//	NVIC_InitTypeDef  NVIC_InitStructure;
//	
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//
//    TIM_TimeBaseStructure.TIM_Period        = 50*10;  //50us
//    //TIM_TimeBaseStructure.TIM_Period        = 100;  //100us    
//    TIM_TimeBaseStructure.TIM_Prescaler     = 71;//71;	//72��Ƶ
//    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
//    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;
//
//    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
//    TIM_SetCounter(TIM2, 0);
//    //TIM_PrescalerConfig(TIM2, 256, TIM_PSCReloadMode_Immediate);
//    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
//    TIM_Cmd(TIM2, ENABLE);
//    
//    //ʹ���ж�
//    NVIC_InitStructure.NVIC_IRQChannel	=	TIM2_IRQn;//TIM2_IRQChannel;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	=	0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//#endif
//}	


void  Init_Tim3 (void)
{
#if CONFIG_HD_TIM  
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    //TIM_TimeBaseStructure.TIM_Period        = 50;  //50us
    //TIM_TimeBaseStructure.TIM_Period        = 250;  //250us
    TIM_TimeBaseStructure.TIM_Period        = (25);  //25us  
    //TIM_TimeBaseStructure.TIM_Period        = 15;  //15us            
    TIM_TimeBaseStructure.TIM_Prescaler     = 71;//71;	//72��Ƶ
    TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
    TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    TIM_SetCounter(TIM3, 0);
    //TIM_PrescalerConfig(TIM3, 256, TIM_PSCReloadMode_Immediate);
    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM3, ENABLE);
    
    //ʹ���ж�
    NVIC_InitStructure.NVIC_IRQChannel	=	TIM3_IRQn;//TIM3_IRQChannel;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	=	0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	0;
    NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
    NVIC_Init(&NVIC_InitStructure);
#endif
}	
///////////////////////////////////////////////////



#if CONFIG_UART1
void  USART1_TxIntEn (void)
{
    USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
    USART_ITConfig(USART1, USART_IT_TC, ENABLE);	//485
}
#endif

#if CONFIG_UART2
void  USART2_TxIntEn (void)
{
    USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
    USART_ITConfig(USART2, USART_IT_TC, ENABLE);	//485
}
#endif

#if CONFIG_UART3
void  USART3_TxIntEn (void)
{
    USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
    USART_ITConfig(USART3, USART_IT_TC, ENABLE);	//485
}
#endif


#if CONFIG_UART4
void  UART4_TxIntEn (void)
{
    USART_ITConfig(UART4, USART_IT_TXE, ENABLE);
   USART_ITConfig(UART4, USART_IT_TC, ENABLE);	//485
}
#endif
 
 

#if CONFIG_UART5
void  UART5_TxIntEn (void)
{
    USART_ITConfig(UART5, USART_IT_TXE, ENABLE);
   USART_ITConfig(UART5, USART_IT_TC, ENABLE);	//485
}
#endif    
     
/////#if (OS_VIEW_USART == USART1)    

//USART_Parity_No
//USART_Parity_Even
//USART_Parity_Odd

void InitUSART1(INT32U baud_rate,uint16_t parity)
{
    
//    GPIO_InitTypeDef        GPIO_InitStructure;
    USART_InitTypeDef       USART_InitStructure;
    NVIC_InitTypeDef        NVIC_InitStructure;	


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//
//    /* Configure USARTx_Tx as alternate function push-pull */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    /* Configure USARTx_Rx as input floating */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	  
//    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate            = baud_rate;
    USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits            = USART_StopBits_1;
    USART_InitStructure.USART_Parity              = parity;		//USART_Parity_No ;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);

    /* Configure the NVIC Preemption Priority Bits */  
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /////////////////////////////////////
    #if USART1_REMAP
    	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
//
    /* Configure USARTx_Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* Configure USARTx_Rx as input floating */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	  
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    
    
    GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE);
    #endif
    
  #if CONFIG_UART1  
 	#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 1)   
    Uart1BufInit();
    USART1_TxIntEn();
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	#endif    
  #endif  
  }

/////////////////////////////////////////////////

void InitUSART2(INT32U baud_rate,uint16_t parity)
{
	USART_InitTypeDef		USART_InitStructure;
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	USART_InitStructure.USART_BaudRate 									=	baud_rate;
	USART_InitStructure.USART_WordLength 					=	USART_WordLength_8b;
	USART_InitStructure.USART_StopBits 						=	USART_StopBits_1;
	USART_InitStructure.USART_Parity 							=	parity;
	USART_InitStructure.USART_HardwareFlowControl	=	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode								=	USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2,&USART_InitStructure);
	USART_Cmd(USART2,ENABLE);
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel						=	USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	3;
	NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	#if CONFIG_UART2
	#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 2)   
		  Uart2BufInit();
    USART2_TxIntEn();
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
		#endif 
	#endif
}


/////////////////////////////////////////////////

void InitUSART3(INT32U baud_rate,uint16_t parity)
{
	USART_InitTypeDef		USART_InitStructure;
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	
	USART_InitStructure.USART_BaudRate 									=	baud_rate;
	USART_InitStructure.USART_WordLength 					=	USART_WordLength_8b;
	USART_InitStructure.USART_StopBits 						=	USART_StopBits_1;
	USART_InitStructure.USART_Parity 							=	parity;
	USART_InitStructure.USART_HardwareFlowControl	=	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode								=	USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2,&USART_InitStructure);
	USART_Cmd(USART2,ENABLE);
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel						=	USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	3;
	NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	#if CONFIG_UART3
	#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 3)	
		Uart3BufInit();
    USART3_TxIntEn();
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	#endif
	#endif
}

/////////////////////////////////////////////////

void InitUART4(INT32U baud_rate,uint16_t parity)
{
	USART_InitTypeDef		USART_InitStructure;
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
	
	USART_InitStructure.USART_BaudRate 									=	baud_rate;
	USART_InitStructure.USART_WordLength 					=	USART_WordLength_8b;
	USART_InitStructure.USART_StopBits 						=	USART_StopBits_1;
	USART_InitStructure.USART_Parity 							=	parity;
	USART_InitStructure.USART_HardwareFlowControl	=	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode								=	USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART4,&USART_InitStructure);
	USART_Cmd(UART4,ENABLE);
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel						=	UART4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	3;
	NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	#if CONFIG_UART4
			#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 4)	
					Uart4BufInit();
		    UART4_TxIntEn();
		    USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
			#endif

	#endif	
}


/////////////////////////////////////////////////
void InitUART5(INT32U baud_rate,uint16_t parity)
{
	USART_InitTypeDef		USART_InitStructure;
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);
	
	USART_InitStructure.USART_BaudRate 									=	baud_rate;
	USART_InitStructure.USART_WordLength 					=	USART_WordLength_8b;
	USART_InitStructure.USART_StopBits 						=	USART_StopBits_1;
	USART_InitStructure.USART_Parity 							=	parity;
	USART_InitStructure.USART_HardwareFlowControl	=	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode								=	USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART5,&USART_InitStructure);
	USART_Cmd(UART5,ENABLE);
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel						=	UART5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority	=	3;
	NVIC_InitStructure.NVIC_IRQChannelCmd	=	ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	#if   ( OS_VIEW_MODULE != DEF_ENABLED )|| (OS_VIEW_USART_NUMBER != 5)	
			
			#if CONFIG_UART5
		Uart5BufInit();
    UART5_TxIntEn();
    USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
		#endif

	#endif	
}

//////////////////////////////
#if CONFIG_UART1
void  USART1_RxTxISRHandler (void)
{
    CPU_SR          cpu_sr;
		unsigned char temp;

    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
    OSIntNesting++;
    CPU_CRITICAL_EXIT();


    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
    	ModbusRxISRHandler(USART_ReceiveData(USART1)&0xFF);
				AddLoopBuf(&Uart1RecvStruct,Uart1RecvBuf,UART1_RECV_BUF_SIZE,USART_ReceiveData(USART1)&0xFF);
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */
    }

    if (USART_GetITStatus(USART1, USART_IT_TXE) != RESET) {
    		if (0 == Uart1SendStruct.len)
				     			{
				     			Uart1Sending = 0;	
				     			USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
				     			}
							else{
									SetEn485_1;
									GetLoopbuf(&Uart1SendStruct,Uart1SendBuf,UART1_SEND_BUF_SIZE,&temp);
        					USART_SendData(USART1, temp);
        					}
   //     USART_ClearITPendingBit(USART1, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */
				
    }

			//485
    if (USART_GetITStatus(USART1, USART_IT_TC) != RESET) {
        //OSView_TxHandler();
				ClrEn485_1;
        USART_ClearITPendingBit(USART1, USART_IT_TC);           /* Clear the USART transmit interrupt                  */

    }


    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
}
#endif
//////////////////////////////
#if CONFIG_UART2
void  USART2_RxTxISRHandler (void)
{
    CPU_SR          cpu_sr;
		unsigned char temp;
    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
    OSIntNesting++;
    CPU_CRITICAL_EXIT();


    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
                      /* Read one byte from the receive data register         */
        AddLoopBuf(&Uart2RecvStruct,Uart2RecvBuf,UART2_RECV_BUF_SIZE,USART_ReceiveData(USART2)&0xFF);
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */

    }

    if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET) {
    		if (0 == Uart2SendStruct.len)
				     			{
				     			Uart2Sending = 0;	
				     			USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
				     			}
							else{
											SetEn485_2;
											GetLoopbuf(&Uart2SendStruct,Uart2SendBuf,UART2_SEND_BUF_SIZE,&temp);
        							USART_SendData(USART2, temp);
      						}
        //USART_ClearITPendingBit(USART2, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */

    }

			//485
    if (USART_GetITStatus(USART2, USART_IT_TC) != RESET) {
			ClrEn485_2;
        USART_ClearITPendingBit(USART2, USART_IT_TC);           /* Clear the USART transmit interrupt                  */

    }


    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
}
#endif
//////////////////////////////
#if CONFIG_UART3
void  USART3_RxTxISRHandler (void)
{
    CPU_SR          cpu_sr;
		unsigned char temp;
    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
    OSIntNesting++;
    CPU_CRITICAL_EXIT();


    if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) {
                      /* Read one byte from the receive data register         */
				AddLoopBuf(&Uart3RecvStruct,Uart3RecvBuf,UART3_RECV_BUF_SIZE,USART_ReceiveData(USART3)&0xFF);
        USART_ClearITPendingBit(USART3, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */

    }

    if (USART_GetITStatus(USART3, USART_IT_TXE) != RESET) {
    	    		if (0 == Uart3SendStruct.len)
				     			{
				     			Uart3Sending = 0;	
				     			USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
				     			}
							else{
										SetEn485_3;
						        GetLoopbuf(&Uart3SendStruct,Uart3SendBuf,UART3_SEND_BUF_SIZE,&temp);
						        USART_SendData(USART3, temp);
						      }
        //USART_ClearITPendingBit(USART3, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */

    }

			//485
    if (USART_GetITStatus(USART3, USART_IT_TC) != RESET) {
        //OSView_TxHandler();
        if (0 == Uart3SendStruct.len)
								{
									ClrEn485_3;
								}
        USART_ClearITPendingBit(USART3, USART_IT_TC);           /* Clear the USART transmit interrupt                  */

    }


    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
}
#endif
////////////////////////////
#if CONFIG_UART4
void  UART4_RxTxISRHandler (void)
{
    CPU_SR          cpu_sr;
		unsigned char temp;
    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
    OSIntNesting++;
    CPU_CRITICAL_EXIT();


    if (USART_GetITStatus(UART4, USART_IT_RXNE) != RESET) {
                      /* Read one byte from the receive data register         */
				AddLoopBuf(&Uart4RecvStruct,Uart4RecvBuf,UART4_RECV_BUF_SIZE,USART_ReceiveData(UART4)&0xFF);
        USART_ClearITPendingBit(UART4, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */

    }

    if (USART_GetITStatus(UART4, USART_IT_TXE) != RESET) {
    	    		if (0 == Uart4SendStruct.len)
				     			{
				     			Uart4Sending = 0;	
				     			USART_ITConfig(UART4, USART_IT_TXE, DISABLE);
				     			}
							else{
										SetEn485_4;
										GetLoopbuf(&Uart4SendStruct,Uart4SendBuf,UART4_SEND_BUF_SIZE,&temp);
						        USART_SendData(UART4, temp);
						      }
//        USART_ClearITPendingBit(UART4, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */

    }

			//485
    if (USART_GetITStatus(UART4, USART_IT_TC) != RESET) {
			ClrEn485_4;
        USART_ClearITPendingBit(UART4, USART_IT_TC);           /* Clear the USART transmit interrupt                  */

    }


    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
}
#endif

///////////////////////////////////////////
#if CONFIG_UART5
void  UART5_RxTxISRHandler (void)
{
    CPU_SR          cpu_sr;
		unsigned char temp;
    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
    OSIntNesting++;
    CPU_CRITICAL_EXIT();


    if (USART_GetITStatus(UART5, USART_IT_RXNE) != RESET) {
                      /* Read one byte from the receive data register         */
				AddLoopBuf(&Uart5RecvStruct,Uart5RecvBuf,UART5_RECV_BUF_SIZE,USART_ReceiveData(UART5)&0xFF);
        USART_ClearITPendingBit(UART5, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */

    }

    if (USART_GetITStatus(UART5, USART_IT_TXE) != RESET) {
    	    		if (0 == Uart5SendStruct.len)
				     			{
				     			Uart5Sending = 0;	
				     			USART_ITConfig(UART5, USART_IT_TXE, DISABLE);
				     			}
							else{
										SetEn485_5;
										GetLoopbuf(&Uart5SendStruct,Uart5SendBuf,UART5_SEND_BUF_SIZE,&temp);
						        USART_SendData(UART5, temp);
						      }
//        USART_ClearITPendingBit(UART5, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */

    }

			//485
    if (USART_GetITStatus(UART5, USART_IT_TC) != RESET) {
			ClrEn485_5;
        USART_ClearITPendingBit(UART5, USART_IT_TC);           /* Clear the USART transmit interrupt                  */

    }


    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
}
#endif

////////////////////////////
//void  USARTx_TxIntEn (void)
//{
//    USART_ITConfig(USARTx, USART_IT_TXE, ENABLE);
//    USART_ITConfig(USARTx, USART_IT_TC, ENABLE);	//485
//}
//////////////////////////////
//void  USARTx_RxTxISRHandler (void)
//{
//    CPU_SR          cpu_sr;
//
//    CPU_CRITICAL_ENTER();                                       /* Tell uC/OS-II that we are starting an ISR            */
//    OSIntNesting++;
//    CPU_CRITICAL_EXIT();
//
//
//    if (USART_GetITStatus(USARTx, USART_IT_RXNE) != RESET) {
//                      /* Read one byte from the receive data register         */
//        //OSView_RxHandler( USART_ReceiveData(OS_VIEW_USART) & 0xFF );
//
//        USART_ClearITPendingBit(USARTx, USART_IT_RXNE);          /* Clear the USART Receive interrupt                   */
//
//    }
//
//    if (USART_GetITStatus(USARTx, USART_IT_TXE) != RESET) {
//        //OSView_TxHandler();
//
//        USART_ClearITPendingBit(USARTx, USART_IT_TXE);           /* Clear the USART transmit interrupt                  */
//
//    }
//
//			//485
//    if (USART_GetITStatus(USARTx, USART_IT_TC) != RESET) {
//        //OSView_TxHandler();
//			//485
//        USART_ClearITPendingBit(USARTx, USART_IT_TC);           /* Clear the USART transmit interrupt                  */
//
//    }
//
//
//    OSIntExit();                                                /* Tell uC/OS-II that we are leaving the ISR            */
//}





