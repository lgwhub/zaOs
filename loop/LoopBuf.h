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
unsigned short int 		len;		//���г���
unsigned short int 		addTail;	//��������β
//unsigned short int 	outHead;	//�������ͷ
unsigned short int 		outTail;	//�������β
}_loopbuf;


/////
void SetLoopBuf_Non(unsigned char *buf,_loopbuf *st,unsigned long int BufSize);
void ClearLoopBuf(_loopbuf *st,unsigned long int BufSize);				//������ͻ�����
unsigned char AddLoopBuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char chr);	//���뵽���ͻ�����
unsigned char GetLoopbuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char *chr);	//�ӻ��ͻ�������ȡ






#endif
