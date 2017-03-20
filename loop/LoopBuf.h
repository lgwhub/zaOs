// #include "LoopBuf.h"

#ifndef __LOOP_BUF_H
#define __LOOP_BUF_H
//#define UART0_RECV_BUF_SIZE	(128)
//#define UART0_SEND_BUF_SIZE	(64)
//#define UART1_RECV_BUF_SIZE	(16)
//#define UART1_SEND_BUF_SIZE	16
//////////////////

typedef struct
{
unsigned short int 		len;		//已有长度
unsigned short int 		addTail;	//输入数据尾
//unsigned short int 	outHead;	//输出数据头
unsigned short int 		outTail;	//输出数据尾
}_loopbuf;


/////
void SetLoopBuf_Non(unsigned char *buf,_loopbuf *st,unsigned long int BufSize);
void ClearLoopBuf(_loopbuf *st,unsigned long int BufSize);				//清除环型缓冲区
unsigned char AddLoopBuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char chr);	//加入到环型缓冲区
unsigned char GetLoopbuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char *chr);	//从环型缓冲区提取






#endif
