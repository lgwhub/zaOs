
#ifndef _MODBUS_PROCESS_H
#define _MODBUS_PROCESS_H
//#include "ModbusProcess.h"
//������λ��ǰ
#define MODBUS_FLOAT_HIGHBYTE_FORWORD  0
#define MODBUS_HIGHBYTE_FORWORD_2X2    1


#define MODBUS_CHECKSUM_HIGHBYTE_FORWORD  1

// MODBUS������Ĵ�����ַ        
//#define  PARAM_ADR_RAM     0X1000
//#define  PARAM_ADR_MEMORY  0X2000
//#define  PARAM_ADR_PUBLIC  0X3000

//// MODBUS������Ĵ�����ַ        
//#define  PARAM_ADR_READ       0
//#define  PARAM_ADR_USER       0X100
//#define  PARAM_ADR_SYS        0X200
//#define  PARAM_ADR_PID        0X300
//#define  PARAM_ADR_MONI       0X400



//����Ȧ
#define MODBUS_READ_BIT        0x01
//д��Ȧ
#define MODBUS_WRITE_BIT       0x05
//���Ĵ���
#define MODBUS_READ_REGISTER   0x03
//д�Ĵ���
#define MODBUS_WRITE_REGISTER  0x10


#define MaxModbusWordNumb   (120)
#define Max_ModbusBuf_Len  ( MaxModbusWordNumb*2 + 9 +1 ) 



void _ModbusReadBit(unsigned char Channl,unsigned char *p,unsigned short int len);//����Ȧ

///////////////////////
void _ModbusWriteBit(unsigned char Channl,unsigned char *p,unsigned short int len);//д��Ȧ


void _ModbusReadWord(unsigned char Channl, unsigned char *p, unsigned short int len, unsigned char *pr);//���Ĵ���

///////////////////////
void _ModbusWriteWord(unsigned char Channl,unsigned char *p,unsigned short int len, unsigned char *pr);//д�Ĵ���

///////////////////////
//void _ModbusParameterProcess(unsigned char Channl,unsigned char *p,unsigned short int len);


//���յ�MODBUS�������жϵ�ַ��У�����Ӧ��
//���룺  p����modbus��ָ�룬len����modbus������
void ModbusRecvProcess(unsigned char *p,unsigned short int len);

unsigned short GetCRC_Checksum4(unsigned char *puchMsg,unsigned short usDataLen);
//unsigned  short int GetModbusCheckSumCrc(unsigned char *p, short int len);

#endif



