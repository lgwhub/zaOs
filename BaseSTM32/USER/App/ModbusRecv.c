

#include "includes.h"

//#define Max_ModbusBuf_Len  254
//#define DEFAULT_MODBUS_TIME  10;

/*
struct _modbus_struct
{

unsigned short int  MaxNothingMs5;   		//MODBUSû�������յ��趨ֵ  ��ʱ����������ұ���CLR��

unsigned short int  NothingTimer;      //MODBUSû�������յ���ʱ��
unsigned short int	LenA;
unsigned short int	LenB;
unsigned short int	LenC;
unsigned char BufA[Max_ModbusBuf_Len+3];
unsigned char BufB[Max_ModbusBuf_Len+3];
unsigned char BufC[Max_ModbusBuf_Len+3];
unsigned char Select;	
unsigned char OverA;
unsigned char OverB;
unsigned char OverC;
};
*/
struct _modbus_struct  Modbusx;

// ʹ�õ��ⲿ���� void ModbusRecvProcess(unsigned char *p,unsigned short int len);
//���յ�MODBUS�������жϵ�ַ��У�����Ӧ��
//���룺  p����modbus��ָ�룬len����modbus������


/////////////////////////////////////////////
// modbus���ݽ��պ���
// �˺����ڴ����ж��ڵ��ã�
// recv_char �ǽ��յ����ַ�
void ModbusRxISRHandler(unsigned char recv_char)
{
 Modbusx.NothingTimer=0;
			
 switch (Modbusx.Select)
 	 {		
		case 'C':	
			if( Modbusx.OverC == 0)
	  		{
			  if( Modbusx.LenC < Max_ModbusBuf_Len )
				    {
				    	Modbusx.BufC[Modbusx.LenC]=recv_char;
				    	Modbusx.LenC ++ ;
				    }
				}
		break;
		
	  case 'B':
 	 	  if( Modbusx.OverB == 0)
	  		  {
			     if( Modbusx.LenB < Max_ModbusBuf_Len )
				      {
				    	Modbusx.BufB[Modbusx.LenB]=recv_char;
				    	Modbusx.LenB ++ ;
				      }
				  }
		break;		 
		
		case 'A':	
	  default:
	  	if( Modbusx.OverA == 0)
	  		{
			    if( Modbusx.LenA < Max_ModbusBuf_Len )
				      {
				    	Modbusx.BufA[Modbusx.LenA]=recv_char;
				    	Modbusx.LenA ++ ;
				      }
				 }
		break;		   
	 }			
			
						
}
////////////////////////////////////////////////////////////////////
//  modbus������ʱ���жϺ���
//  �ڶ�ʱ���ж��������
//  �����л����������ӻ����������
void ModbusTimeHandler(void)
{
	
	 if(  Modbusx.NothingTimer > Modbusx.MaxNothingMs5 )     //MODBUSû�������յ���ʱ��
		     {//û�н��յ��κ�����ʱ�䳬ʱ����
  		   switch(Modbusx.Select)
	   			     {
					     case 'A':
					     if(Modbusx.LenA	> 0 )
					     	     {
					           Modbusx.Select = 'B';
			 		           Modbusx.OverA = 1;
								     //ModbusRecvProcess(Modbusx.Buf,Modbusx.len); 
							       }
				       break;
  		         
  		         case 'B':
	   			     if(Modbusx.LenB	> 0 )   
	   			     			{
	   			     				Modbusx.Select = 'C';	
			 		            Modbusx.OverB = 1;
			 		          }
			 		     
				       break;
  		          
  		         case 'C':
	   			     if(Modbusx.LenC	> 0 )
	   			     	    {
	   			           Modbusx.Select = 'A';	
			 		           Modbusx.OverC = 1;
			 		          }
			 		     break;	
			 		     
			 		     default:
			 		     	  Modbusx.Select = 'A';
			 		     break;
			 		    }				       			       
				  Modbusx.NothingTimer = 0;   
		     }
	else{
		 	
		 	  Modbusx.NothingTimer ++;
		   }
}
/////////////////////////////////////////////

//���ϵؼ��MODBUS���ջ�����
//���������������
void GetModbusPark(void)
{
if(Modbusx.OverA !=0 )
	  {//������A��
	  	if(Modbusx.LenA>0)
	  		{
			  ModbusRecvProcess(Modbusx.BufA,Modbusx.LenA);
		    }
		 Modbusx.LenA=0;
		 Modbusx.OverA	=0;
		}			
if(Modbusx.OverB !=0 )
	  {//������B��
	  	if(Modbusx.LenB>0)
	  		 {
			   ModbusRecvProcess(Modbusx.BufB,Modbusx.LenB);
		     }
		 Modbusx.LenB=0;
		 Modbusx.OverB	=0;		     
		}						
if(Modbusx.OverC !=0 )
	  {//������C��
	  	if(Modbusx.LenC>0)
	  		{
			   ModbusRecvProcess(Modbusx.BufC,Modbusx.LenC);
		    }
		 Modbusx.LenC=0;
		 Modbusx.OverC	=0;	
		 }	
}

////////////////////////////////////
void ModbusInit(void)
{

	Modbusx.LenA=0;
	Modbusx.LenB=0;	
	Modbusx.LenC=0;	
	
	Modbusx.Select='A';
	
	Modbusx.OverA=0;
	Modbusx.OverB=0;	
	Modbusx.OverC=0;
	
 Modbusx.MaxNothingMs5=DEFAULT_MODBUS_TIME ;   		//MODBUSû�������յ��趨ֵ  ��ʱ�����     //���ݲ����ʵ���ʱ��
 Modbusx.NothingTimer=0;      //MODBUSû�������յ���ʱ��	
}






