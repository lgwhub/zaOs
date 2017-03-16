

#ifndef _MODBUS_RECV_H
#define _MODBUS_RECV_H
//#include "includes.h"

//#define MaxModbusBufLen  252
#define DEFAULT_MODBUS_TIME  (10/2);

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

extern struct _modbus_struct  Modbusx;


// modbus���ݽ��պ���
// �˺����ڴ����ж��ڵ��ã�
// ���� recv_char �ǽ��յ����ַ�
void ModbusRxISRHandler(unsigned char recv_char);

//  modbus������ʱ���жϺ���
void ModbusTimeHandler(void);
//���ϵؼ��MODBUS���ջ�����
//���������������
void GetModbusPark(void);
void ModbusInit(void);

#endif


