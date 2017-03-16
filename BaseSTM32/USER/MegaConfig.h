//#include "config.h"

#ifndef _MEGA_CONFIG_H
#define _MEGA_CONFIG_H





/*
mega16 ��˿λ
��˿λ���ֽ�
��˿���ֽ�		λ��			����																Ĭ��ֵ
OCDEN(4) 			7 				ʹ��OCD 														1 ( δ��̣� OCD ����)
JTAGEN(5) 		6 				ʹ�� JTAG 													0 ( ��̣� JTAG ʹ��)
SPIEN(1) 			5 				ʹ�ܴ��г������������							0 ( ����̣� SPI ���ʹ��)
CKOPT(2) 			4 				����ѡ��													1 ( δ���)
EESAVE 				3 				ִ��оƬ����ʱEEPROM �����ݱ���			1 ( δ�����)��EEPROM ���ݲ�����
BOOTSZ1 			2 				ѡ�� Boot ����С										0 ( �����)(3)
BOOTSZ0 			1 				ѡ�� Boot ����С										0 ( �����)(3)
BOOTRST 			0 				ѡ��λ����												1 ( δ�����) 

Notes: 
1. ��SPI ���б��ģʽ��SPIEN ��˿λ���ɷ��ʡ�
2. CKOPT ��˿λ������CKSEL λ���þ�������� P23 �� ʱ��Դ�� ��
3. BOOTSZ1..0 Ĭ��ֵΪ���Boot ��С����� P244Table 100��
4. ������λ��JTAGEN��˿λ����Ϊʲô����Ʒ����ʱ����OCDEN��̡���OCDEN��
˿λ��̺��ʹ��ϵͳʱ�ӵ�ĳЩ���������е�����ģʽ�����С�������ӹ��ġ�
5. ���û������JTAG �ӿڣ�Ӧ������ȡ��JTAGEN ��˿λ�ı��״̬��������������
JTAG �ӿ�֮TDO ���ŵľ�̬������
*/


/*
��˿λ��λ�ֽ�
��˿λ��λ�ֽ�		λ��		����								Ĭ��ֵ
BODLEVEL 					7 			BOD ������ƽ				1 ( δ�����)
BODEN 						6 			BOD ʹ��						1 ( δ����̣� BOD ����)
SUT1 							5 			ѡ������ʱ��				1 ( δ�����)(1)
SUT0 							4				ѡ������ʱ��				0 ( �����)(1)
CKSEL3 						3 			ѡ��ʱ��Դ					0 ( �����)(2)
CKSEL2 						2 			ѡ��ʱ��Դ					0 ( �����)(2)
CKSEL1 						1 			ѡ��ʱ��Դ					0 ( �����)(2)
CKSEL0 						0 			ѡ��ʱ��Դ					1 ( δ�����)(2)

Notes: 
1. ����Ĭ��ʱ��Դ��SUT1..0 ��Ĭ��ֵ����������ʱ�䡣
2. CKSEL3..0��Ĭ�����õ�����Ƭ��RC����������1 MHz��
��˿λ��״̬����оƬ���������Ӱ�졣�������λ1(LB1) ���������˿λ����������
�������λǰ�ȱ����˿λ��
*/

#define MEGA16H_OCDEN			BIT7
#define MEGA16H_JTAGEN		BIT6
#define MEGA16H_SPIEN			BIT5
#define MEGA16H_CKOPT			BIT4
#define MEGA16H_EESAVE		BIT3
#define MEGA16H_BOOTSZ1		BIT2
#define MEGA16H_BOOTSZ0		BIT1
#define MEGA16H_BOOTRST		BIT0

#define MEGA16L_BODLEVEL	BIT7
#define MEGA16L_BODEN			BIT6
#define MEGA16L_SUT1			BIT5
#define MEGA16L_SUT0			BIT4
#define MEGA16L_CKSEL3		BIT3
#define MEGA16L_CKSEL2		BIT2
#define MEGA16L_CKSEL1		BIT1
#define MEGA16L_CKSEL0		BIT0


//#define MEGA16L_NO				(	MEGA16L_BODLEVEL 	|	\
//														MEGA16L_BODEN 		|	\		
//														MEGA16L_SUT1 			|	\	
//														MEGA16L_SUT0			|	\
//														MEGA16L_CKSEL3		|	\
//														MEGA16L_CKSEL2		|	\
//														MEGA16L_CKSEL1		|	\
//														MEGA16L_CKSEL0		\
//													)
//#define MEGA16H_NO		{
//													MEGA16H_OCDEN		|	\
//													MEGA16H_JTAGEN	|	\
//													MEGA16H_SPIEN		|	\
//													MEGA16H_CKOPT		|	\
//													MEGA16H_EESAVE	|	\
//													MEGA16H_BOOTSZ1	|	\
//													MEGA16H_BOOTSZ0	|	\
//													MEGA16H_BOOTRST	|	\
//													}

#define MEGA16L_DEFAULT		(	MEGA16L_BODLEVEL 	|	MEGA16L_BODEN		|	MEGA16L_SUT1	| MEGA16L_CKSEL0	)
												
													
#define MEGA16H_DEFAULT		(	MEGA16H_OCDEN		|	MEGA16H_CKOPT	|	MEGA16H_EESAVE	|	MEGA16H_BOOTRST		)

											
#define MEGA16L_RCEV12M		(	MEGA16L_BODLEVEL 	|	MEGA16L_BODEN |	MEGA16L_SUT1	|	MEGA16L_CKSEL1	|	MEGA16L_CKSEL0	)													
#define MEGA16H_RCEV12M		(	MEGA16H_OCDEN	|	MEGA16H_JTAGEN	|	MEGA16H_CKOPT	|	MEGA16H_BOOTRST		)

//�ⲿ 4MHZ		
#define MEGA16L_RCEV13		(	MEGA16L_BODLEVEL 	|	MEGA16L_BODEN |	MEGA16L_SUT1 	|	MEGA16L_SUT0	|	MEGA16L_CKSEL3	|	MEGA16L_CKSEL2	|	MEGA16L_CKSEL1	|	MEGA16L_CKSEL0	)													
#define MEGA16H_RCEV13		(	MEGA16H_OCDEN		|	MEGA16H_JTAGEN	|	MEGA16H_CKOPT		|	MEGA16H_BOOTRST	)

//�ⲿ 4MHZ		
#define MEGA16L_RCEV14		(	MEGA16L_BODLEVEL 	|	MEGA16L_BODEN |	MEGA16L_SUT1 	|	MEGA16L_SUT0	|	MEGA16L_CKSEL3	|		MEGA16L_CKSEL2	|	MEGA16L_CKSEL0	)													
#define MEGA16H_RCEV14		(	MEGA16H_OCDEN		|	MEGA16H_JTAGEN	|	MEGA16H_BOOTRST	)

////////////////////////////////


/////////////////////////////////////////////////////////////////
/*
mega48
��˿���ֽ�		λ��			����																Ĭ��ֵ
RSTDISBL(1) 	7 				�ⲿ��λ����										1 ( δ�����)
DWEN 					6 				������ʹ��											1 ( δ�����)
SPIEN(2) 			5 				ʹ�ܴ��г������������					0 ( ����̣� SPI ���ʹ��)
WDTON(3) 			4 				���Ź���ʱ��һֱ����						1 ( δ�����)
EESAVE 				3 				ִ��оƬ����ʱEEPROM�����ݱ���	1 ( δ�����)�� EEPROM���ݲ�����
BODLEVEL2(4) 	2 				BOD ������ƽ										1 ( δ�����)
BODLEVEL1(4) 	1 				BOD ������ƽ										1 ( δ�����)
BODLEVEL0(4) 	0 				BOD ������ƽ										1 ( δ�����)

��˿λ��λ�ֽ�
��˿λ��λ�ֽ�	λ��		����							Ĭ��ֵ
CKDIV8(4) 			7 			ʱ��8 ��Ƶ				0 ( �����)
CKOUT(3) 				6 			ʱ�����					1 ( δ�����)
SUT1 						5 			ѡ������ʱ��			1 ( δ�����)(1)
SUT0 						4 			ѡ������ʱ��			0 ( �����)(1)
CKSEL3 					3 			ѡ��ʱ��Դ				0 ( �����)(2)
CKSEL2 					2 			ѡ��ʱ��Դ				0 ( �����)(2)
CKSEL1 					1 			ѡ��ʱ��Դ				1 ( δ�����)(2)
CKSEL0 					0 			ѡ��ʱ��Դ				0 ( �����)(2)


*/

#define MEGA48H_RSTDISBL		BIT7
#define MEGA48H_DWEN				BIT6
#define MEGA48H_SPIEN				BIT5
#define MEGA48H_WDTON				BIT4
#define MEGA48H_EESAVE			BIT3
#define MEGA48H_BODLEVEL2		BIT2
#define MEGA48H_BODLEVEL1		BIT1
#define MEGA48H_BODLEVEL0		BIT0

#define MEGA48L_CKDIV8		BIT7
#define MEGA48L_CKOUT			BIT6
#define MEGA48L_SUT1			BIT5
#define MEGA48L_SUT0			BIT4
#define MEGA48L_CKSEL3		BIT3
#define MEGA48L_CKSEL2		BIT2
#define MEGA48L_CKSEL1		BIT1
#define MEGA48L_CKSEL0		BIT0



#define MEGA48H_DEFAULT		(	MEGA48H_RSTDISBL	|	MEGA48H_DWEN	|	MEGA48H_WDTON	|	MEGA48H_EESAVE	|	MEGA48H_BODLEVEL2	|	MEGA48H_BODLEVEL1	|	MEGA48H_BODLEVEL0	)
#define MEGA48L_DEFAULT		(	MEGA48L_CKOUT			|	MEGA48L_SUT1	|	MEGA48L_CKSEL1	)

//�ⲿ 4MHZ		
#define MEGA88H_PUSH5		(	MEGA48H_RSTDISBL	|	MEGA48H_DWEN	|	MEGA48H_WDTON	|	0*MEGA48H_EESAVE	|	MEGA48H_BODLEVEL2	|	0*MEGA48H_BODLEVEL1	|	MEGA48H_BODLEVEL0	)
#define MEGA88L_PUSH5		(	MEGA48L_CKOUT			|	MEGA48L_SUT1	|	MEGA48L_SUT0	|	MEGA48L_CKSEL3 | MEGA48L_CKSEL2	|	0*MEGA48L_CKSEL1	|	MEGA48L_CKSEL0	)

//�ⲿ 4MHZ	 ������λ������	
#define MEGA48H_POLICE		(	MEGA48H_RSTDISBL	|	MEGA48H_DWEN	|	MEGA48H_WDTON	|	MEGA48H_EESAVE	|	MEGA48H_BODLEVEL2	|	MEGA48H_BODLEVEL1	|	MEGA48H_BODLEVEL0	)
#define MEGA48L_POLICE		(	MEGA48L_CKOUT			|	MEGA48L_SUT1	|	MEGA48L_SUT0	|	MEGA48L_CKSEL3 | MEGA48L_CKSEL2	|	0*MEGA48L_CKSEL1	|	MEGA48L_CKSEL0	)

//LOCK_BYTE
#define BLB12		BIT5
#define BLB11		BIT4
#define BLB02		BIT3
#define BLB01		BIT2
#define LB2			BIT1
#define LB1			BIT0

#endif


