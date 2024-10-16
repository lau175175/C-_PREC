#include <stdlib.h>

#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_gpio.h"

#define DATANUM 64
typedef struct
{
uint16_t rowval;
uint16_t colval;
float adcval;
}typ_TestData;

typ_TestData testData[DATANUM];//¶¨ҥʽ¾ݽṹ


float ADC_ConvertedValueLocal;   

void delay_us(uint32_t us)  // 基于1us的延时函数
{
	volatile uint32_t count;
	while(us--)
	{
		count = 72;
		while(count--);
	}
}

/* void Delay_us(uint32_t us){
    for(; us>0; us--);
}*/

/*
void TestFunc(void)
{
	char ucol[2],urow[2];
	int icol,irow;
	if (recvstate==1)
	{
		urow[0]=recvbuff[0];
		urow[1]='\0';
		irow = atoi(urow); //		
		
		ucol[0]=recvbuff[1];
		ucol[1]='\0';
		icol = atoi(ucol); //
		switch (irow)
		{
			case 1:ROW_OFF0;
						ROW_OFF1;
						ROW_OFF2;
				break;
			case 2:
					ROW_ON0;
					ROW_OFF1;
					ROW_OFF2;
				break;
			case 3:
					ROW_OFF0;
					ROW_ON1;
					ROW_OFF2;
				break;
			case 4:
					ROW_ON0;
					ROW_ON1;
					ROW_OFF2;
				break;
			case 5:
					ROW_OFF0;
					ROW_OFF1;
					ROW_ON2;
				break;
			case 6:
					ROW_ON0;
					ROW_OFF1;
					ROW_ON2;
				break;
			case 7:
					ROW_OFF0;
					ROW_ON1;
					ROW_ON2;
				break;
			case 8:
					ROW_ON0;
					ROW_ON1;
					ROW_ON2;
				break;
		}
		switch (icol)
		{
			case 1:COL_OFF0;
						COL_OFF1;
						COL_OFF2;
				break;
			case 2:
					COL_ON0;
					COL_OFF1;
					COL_OFF2;
				break;
			case 3:
					COL_OFF0;
					COL_ON1;
					COL_OFF2;
				break;
			case 4:
					COL_ON0;
					COL_ON1;
					COL_OFF2;
				break;
			case 5:
					COL_OFF0;
					COL_OFF1;
					COL_ON2;
				break;
			case 6:
					COL_ON0;
					COL_OFF1;
					COL_ON2;
				break;
			case 7:
					COL_OFF0;
					COL_ON1;
					COL_ON2;
				break;
			case 8:
					COL_ON0;
					COL_ON1;
					COL_ON2;
				break;
		}
		ADC_ConvertedValueLocal =(float) ADC_ConvertValue/4096*3.3; // ¶Áȡת»»µāDֵ	
		//advalue=((advaluesum/10)-0.6)/5100*1000000;//ua
		printf("row:%d col:%d value:%fV \r\n",irow,icol,ADC_ConvertedValueLocal); 		
		recvstate=0;
		recvnum=0;
	}
}
*/




void InitTestDataStruct(void)
{
	for(uint16_t i=0;i<DATANUM;i++)
	{
		testData[i].adcval=0;
		testData[i].rowval=0;
		testData[i].colval=0;
	}
}

//¾ؕ󑭻·²⊔
void LoopTestFunc(void)
{
	uint16_t rind = 0;
	//typ_TestData tempdata;
	for(uint16_t irow=1; irow<9; irow++)
	{
		for(uint16_t icol=1;icol<9;icol++)
		{
			switch (irow)
			{
				case 1:ROW_OFF0;
							ROW_OFF1;
							ROW_OFF2;
					break;
				case 2:
						ROW_ON0;
						ROW_OFF1;
						ROW_OFF2;
					break;
				case 3:
						ROW_OFF0;
						ROW_ON1;
						ROW_OFF2;
					break;
				case 4:
						ROW_ON0;
						ROW_ON1;
						ROW_OFF2;
					break;
				case 5:
						ROW_OFF0;
						ROW_OFF1;
						ROW_ON2;
					break;
				case 6:
						ROW_ON0;
						ROW_OFF1;
						ROW_ON2;
					break;
				case 7:
						ROW_OFF0;
						ROW_ON1;
						ROW_ON2;
					break;
				case 8:
						ROW_ON0;
						ROW_ON1;
						ROW_ON2;
					break;
			}
			switch (icol)
			{
				case 1:COL_OFF0;
							COL_OFF1;
							COL_OFF2;
					break;
				case 2:
						COL_ON0;
						COL_OFF1;
						COL_OFF2;
					break;
				case 3:
						COL_OFF0;
						COL_ON1;
						COL_OFF2;
					break;
				case 4:
						COL_ON0;
						COL_ON1;
						COL_OFF2;
					break;
				case 5:
						COL_OFF0;
						COL_OFF1;
						COL_ON2;
					break;
				case 6:
						COL_ON0;
						COL_OFF1;
						COL_ON2;
					break;
				case 7:
						COL_OFF0;
						COL_ON1;
						COL_ON2;
					break;
				case 8:
						COL_ON0;
						COL_ON1;
						COL_ON2;
					break;
			}
			
			
			ADC_ConvertedValueLocal =(float) ADC_ConvertValue/4096*3.3; // ¶Áȡת»»µāDֵ	
			
//			tempdata.rowval=irow;
//			tempdata.colval=icol;
//			tempdata.adcval=ADC_ConvertedValueLocal;
//			
			testData[rind].rowval=irow;
			testData[rind].colval=icol;
			testData[rind].adcval=ADC_ConvertedValueLocal;
			
			rind++;
			
			delay_us(300);
		}
	}
}
//ʽ¾ݷ¢ˍ
void SendTestData(void)
{
	//printf("%02x %02x\n", 0xea, 0xeb);
	Usart_SendByte(DEBUG_USARTx,0xea);
	Usart_SendByte(DEBUG_USARTx,0xeb);
	for(uint16_t i=0;i<DATANUM;i++)
	{
		printf("row:%d col:%d value:%f \r\n",testData[i].rowval,testData[i].colval,testData[i].adcval);
		delay_us(100);
	}
	Usart_SendByte(DEBUG_USARTx,0xfa);
	Usart_SendByte(DEBUG_USARTx,0xfb);
}

//ה¶¯²⊔º¯ʽ
void AutoTestFunc(void)
{
	char dutydata[10];	
	if (recvstate==1)
	{
		for(uint16_t i=0;i<recvnum;i++)
			dutydata[i] = recvbuff[i];
		dutydata[recvnum]='\0';
		//rduty = atoi(dutydata); //	
		if ((dutydata[0] == 'r')&&(dutydata[1] == 'e'))
		{
				InitTestDataStruct();
				LoopTestFunc();
				
				SendTestData();
			
		}
		recvstate=0;
		recvnum=0;
	}
}

int main(void)
{	
	recvnum = 0;
	recvstate=0;
	// Ťփ´®¿ڍ
	USART_Config();
	//IO¿څ䖃
	GPIO_Config();
	// ADC ³õʼ»¯
	ADCx_Init();
	
	ROW_OFF0;
	ROW_OFF1;
	ROW_OFF2;
	
	COL_OFF0;
	COL_OFF1;
	COL_OFF2;
	while(1)
	{
		//TestFunc();
		//AutoTestFunc();
		AutoTestFunc();
	}
}
	
