
// #include "uart.h"

#ifndef __UART_H 
#define __UART_H

#define CONFIG_UART1		1
#define CONFIG_UART2		0
#define CONFIG_UART3		0
#define CONFIG_UART4		0
#define CONFIG_UART5		0

#define UART1_RECV_BUF_SIZE	270
#define UART1_SEND_BUF_SIZE	270
#define UART2_RECV_BUF_SIZE	64
#define UART2_SEND_BUF_SIZE	64
#define UART3_RECV_BUF_SIZE	64
#define UART3_SEND_BUF_SIZE	64
#define UART4_RECV_BUF_SIZE	64
#define UART4_SEND_BUF_SIZE	64
#define UART5_RECV_BUF_SIZE	64
#define UART5_SEND_BUF_SIZE	64
///////////////////////////////////////
#if CONFIG_UART1
extern uchar Uart1RecvBuf[UART1_RECV_BUF_SIZE+4];	//����1���ջ�����
extern _loopbuf Uart1RecvStruct;
extern uchar Uart1SendBuf[UART1_SEND_BUF_SIZE+4];	//����1��������
extern _loopbuf Uart1SendStruct;


extern uchar Uart1Sending;
void  Uart1BufInit(void);
uchar GetOneFromUart1(uchar *buf);
uint16 Uart1CharSend(uchar x);
void SendString_UART1(unsigned char *StrData,uint16 len);
void SendText_UART1(uchar *StrData);

#endif

///////////////////////////////////////
#if CONFIG_UART2

extern uchar Uart2RecvBuf[UART2_RECV_BUF_SIZE+4];	//����2���ջ�����
extern _loopbuf Uart2RecvStruct;
extern uchar Uart2SendBuf[UART2_SEND_BUF_SIZE+4];	//����2��������
extern _loopbuf Uart2SendStruct;




extern uchar Uart2Sending;
void  Uart2BufInit(void);
uchar GetOneFromUart2(uchar *buf);
uint16 Uart2CharSend(uchar x);
void SendString_UART2(unsigned char *StrData,uint16 len);
void SendText_UART2(uchar *StrData);

#endif

///////////////////////////////////////
#if CONFIG_UART3
extern uchar Uart3RecvBuf[UART3_RECV_BUF_SIZE+4];	//����1���ջ�����
extern _loopbuf Uart3RecvStruct;
extern uchar Uart3SendBuf[UART3_SEND_BUF_SIZE+4];	//����1��������
extern _loopbuf Uart3SendStruct;

extern uchar Uart3Sending;
void  Uart3BufInit(void);
uchar GetOneFromUart3(uchar *buf);
uint16 Uart3CharSend(uchar x);
void SendString_UART3(unsigned char *StrData,uint16 len);
void SendText_UART3(uchar *StrData);

#endif


#if CONFIG_UART4
extern uchar Uart4RecvBuf[UART4_RECV_BUF_SIZE+4];	//����2���ջ�����
extern _loopbuf Uart4RecvStruct;
extern uchar Uart4SendBuf[UART4_SEND_BUF_SIZE+4];	//����2��������
extern _loopbuf Uart4SendStruct;

extern uchar Uart4Sending;
void  Uart4BufInit(void);
uchar GetOneFromUart4(uchar *buf);
uint16 Uart4CharSend(uchar x);
void SendString_UART4(unsigned char *StrData,uint16 len);
void SendText_UART4(uchar *StrData);

#endif

#if CONFIG_UART5
extern uchar Uart5RecvBuf[UART5_RECV_BUF_SIZE+4];	//����2���ջ�����
extern _loopbuf Uart5RecvStruct;
extern uchar Uart5SendBuf[UART5_SEND_BUF_SIZE+4];	//����2��������
extern _loopbuf Uart5SendStruct;

extern uchar Uart5Sending;
void  Uart5BufInit(void);
uchar GetOneFromUart5(uchar *buf);
uint16 Uart5CharSend(uchar x);
void SendString_UART5(unsigned char *StrData,uint16 len);
void SendText_UART5(uchar *StrData);

#endif

#endif /* end __UART_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
