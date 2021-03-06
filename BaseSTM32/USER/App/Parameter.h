#ifndef _PARAMETER_H
#define _PARAMETER_H


/////struct	struct_save

//参数已经初始化标记
#define FlagParamInitnized	0xB0

#define Max_MemBuf  20

extern unsigned char cMemBufA[Max_MemBuf+2];
extern unsigned char cMemBufB[Max_MemBuf+2];


extern unsigned short int TimeForSaveParam;

/////////////////////////////////////////////////////////////////////////////
/*
extern unsigned char FlagRuning[SUB_NMB_CHNALL];
extern unsigned char FlagVoltInEnough[SUB_NMB_CHNALL];
extern unsigned char WaitRunTime[SUB_NMB_CHNALL];
*/

typedef struct
{
    unsigned long  int  CMD;                  //命令寄存器
    unsigned long  int  WATCHING;             //监视状态
    unsigned long  int  BOARD_STATE;          //插板状态
    unsigned long  int  device_type;          //设备型号
    float               Ts1_AMP;              //温度采样放大倍数1
    float               Ts1_BIAS;             //温度采样偏移系数1
    float               Ts2_AMP;              //温度采样放大倍数2
    float               Ts2_BIAS;             //温度采样偏移系数2
    float               Ts3_AMP;              //温度采样放大倍数3
    float               Ts3_BIAS;             //温度采样偏移系数3
    float               Ts4_AMP;
    float               Ts4_BIAS;
    float               Ts5_AMP;
    float               Ts5_BIAS;
    float               Ts6_AMP;
    float               Ts6_BIAS;
    float               Ts7_AMP;
    float               Ts7_BIAS;
    float               Ts8_AMP;
    float               Ts8_BIAS;

    float               PID_P1;                //水冷增量PID
    float               PID_I1;
    float               PID_D1;
    float               PID_P2;                //
    float               PID_I2;
    float               PID_D2;    

    float               MONI_PX1;                //
    float               MONI_IX1;
    float               MONI_DX1;
    signed long int               MONI_QX1;
    
    float               MONI_PX2;                //
    float               MONI_IX2;
    float               MONI_DX2;
    unsigned long int               MONI_QX2;    
        
    float               NC[22];               //

    unsigned long  int  Burnin_type;          //老化类型

    float               T_set;                //温度设置值
    float               T_bias_set;           //温度偏差设置值
    float               T_upper_set;          //
    float               T_down_set;           //

    unsigned long  int  Cycle_times_set;      //
    
    float               TC_sx;                //温度上限设置值
    
    unsigned long  int  unit_onof_flag[8];    //
    unsigned long  int  TC_duty_set;          //占空比
    signed long  int  FAN_duty_set;         //步进电机
    unsigned long  int  Moter_step_set;       //强制走几步
    unsigned long  int  Moter_direction;      //方向
    unsigned long  int  one_unit_flag;        //
    unsigned long  int  one_onoff_flag;       //
    unsigned long  int  limit_recode[8];      //

    float               Ts[8];                //

    unsigned long  int  TC_duty[8];           //占空比
    signed long  int  FAN_duty[8];          //步进电机
    unsigned long  int  Clcle_times;          //
    unsigned long  int  ADC_error_count;      //
    
    

    
        unsigned long  int  lBackupRestore;
    unsigned long  int  SubAdr;
    unsigned long  int  SoftVer;     
    unsigned long  int  lSysSwitch_reserve;          //默认开机 系统开关
    unsigned long  int 	lstats;  //统计信息  
    
    
    
  unsigned long  int   Counter_MaxOpen[8];				//温度超过设定值15度以上，不使用PID,强制打开水冷，开n次后暂停，然后等温度到正常范围
  unsigned long  int   Counter_MaxClose[8];				//温度低于设定值15度以上，不使用PID,强制关闭水冷，关n次后暂停，然后等温度到正常范围
  
   
   

}  _param_water8;    //  字节

extern _param_water8  Coldw;


extern unsigned char ModBusParaByte[];   //modbus 参数 拷贝缓冲区

extern unsigned char FlagSetAllDefault;

void Default_ParamInit0(void);//不需要保存的参数
void Default_ParamInit1(void); //普通参数  //需要保存的参数
void Default_ParamInit2(void); //整定值

void Default_ParamInit(void);
void InitSaveParam(void);
unsigned char Write_Param(void);
unsigned char Load_Param(void);

#endif




