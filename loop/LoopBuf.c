
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

void ClearLoopBuf(_loopbuf *st,unsigned long int BufSize)	//清除环型缓冲区
{
st->len		=	0;		//已有长度
st->addTail	=	0;       	//输入数据尾
//st->outHead=0;      			//输出数据头
st->outTail	=	0;	//BufSize;      //输出数据尾
}
/************************************************************************/
unsigned char AddLoopBuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char chr)	//加入到环型缓冲区
{
if( (st->addTail != st->outTail) || (0 == st->len) )
	{
	*(buf+st->addTail) = chr;	
	if(st->addTail<BufSize)
		{
		st->addTail++;
		}
	else{
		st->addTail=0;	//循环
		}
	st->len++;
	return 1;		
	}	
else{	//缓冲区满
	return 0;
	}	
}


/************************************************************************/
unsigned char GetLoopbuf(_loopbuf *st,unsigned char *buf,unsigned long int BufSize,unsigned char *chr)	//从环型缓冲区提取
{
if( st->len > 0 )
	{
	*chr = *( buf + st->outTail );
	if(st->outTail<BufSize)
		{
		st->outTail ++;	
		}
	else{	//循环
		st->outTail = 0;
		}	
	st->len--;
	if( st->outTail == st->addTail )
		{
		st->len = 0;
		}
	return 1;	//读到数据
	}
else return 0;	//缓冲区没有数据

}

