//#include "nomal.h"
#include <includes.h>
#include "LoopBuf.h"

//uchar Uart0RecvBuf[UART0_RECV_BUF_SIZE+4];	//����0���ջ�����
//_loopbuf Uart0RecvStruct;
//uchar Uart0SendBuf[UART0_SEND_BUF_SIZE+4];	//����0��������
//_loopbuf Uart0SendStruct;
//
//
//uchar Uart1RecvBuf[UART1_RECV_BUF_SIZE+4];	//����1���ջ�����
//_loopbuf Uart1RecvStruct;
//uchar Uart1SendBuf[UART1_SEND_BUF_SIZE+4];	//����1��������
//_loopbuf Uart1SendStruct;



/*****************************************************************************/
void SetLoopBuf_Non(uchar *buf,_loopbuf *st,uint32 BufSize)
{
uint32 i;
ClearLoopBuf(st,BufSize);
	for(i=0;i<BufSize;i++)
				{
					*(buf+i)=0x0;
				}	
	
}

/////////////////////////////////

void ClearLoopBuf(_loopbuf *st,uint32 BufSize)	//������ͻ�����
{
st->len		=	0;		//���г���
st->addTail	=	0;       	//��������β
//st->outHead=0;      			//�������ͷ
st->outTail	=	0;	//BufSize;      //�������β
}
/************************************************************************/
bool AddLoopBuf(_loopbuf *st,uchar *buf,uint32 BufSize,uchar chr)	//���뵽���ͻ�����
{
if( (st->addTail != st->outTail) || (0 == st->len) )
	{
	*(buf+st->addTail) = chr;	
	if(st->addTail<BufSize)
		{
		st->addTail++;
		}
	else{
		st->addTail=0;	//ѭ��
		}
	st->len++;
	return 1;		
	}	
else{	//��������
	return 0;
	}	
}


/************************************************************************/
bool GetLoopbuf(_loopbuf *st,uchar *buf,uint32 BufSize,uchar *chr)	//�ӻ��ͻ�������ȡ
{
if( st->len > 0 )
	{
	*chr = *( buf + st->outTail );
	if(st->outTail<BufSize)
		{
		st->outTail ++;	
		}
	else{	//ѭ��
		st->outTail = 0;
		}	
	st->len--;
	if( st->outTail == st->addTail )
		{
		st->len = 0;
		}
	return 1;	//��������
	}
else return 0;	//������û������

}

