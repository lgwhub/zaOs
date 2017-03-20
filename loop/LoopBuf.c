
//#include <includes.h>
#include "LoopBuf.h"



/*****************************************************************************/
void SetLoopBuf_Non(unsigned char *buf,_loopbuf *st,unsigned long int BufSize)
{
unsigned long int i;
ClearLoopBuf(st,BufSize);
	for(i=0;i<BufSize;i++)
				{
					*(buf+i)=0x0;
				}	
	
}

/////////////////////////////////

void ClearLoopBuf(_loopbuf *st,unsigned long int BufSize)	//������ͻ�����
{
st->len		=	0;		//���г���
st->addTail	=	0;       	//��������β
//st->outHead=0;      			//�������ͷ
st->outTail	=	0;	//BufSize;      //�������β
}
/************************************************************************/
unsigned char AddLoopBuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char chr)	//���뵽���ͻ�����
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
unsigned char GetLoopbuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char *chr)	//�ӻ��ͻ�������ȡ
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

