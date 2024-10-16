#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* �������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
#define ROW_GPIO_PORT    	GPIOB		              /* GPIO�˿� */
#define ROW_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */

#define ROW_GPIO_PIN0			GPIO_Pin_12			        
#define ROW_GPIO_PIN1			GPIO_Pin_13
#define ROW_GPIO_PIN2			GPIO_Pin_14

//*********************************************************************

#define COL_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define COL_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */

#define COL_GPIO_PIN1		GPIO_Pin_5			        
#define COL_GPIO_PIN0	  GPIO_Pin_6	
#define COL_GPIO_PIN2		GPIO_Pin_7	


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
/*
#define LED1(a)	if (a)	\
					GPIO_SetBits(ROW_GPIO_PORT,ROW_GPIO_PIN);\
					else		\
					GPIO_ResetBits(ROW_GPIO_PORT,ROW_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

*/


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
//#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define ROW_OFF0		   digitalLo(ROW_GPIO_PORT,ROW_GPIO_PIN0)
#define ROW_OFF1		   digitalLo(ROW_GPIO_PORT,ROW_GPIO_PIN1)
#define ROW_OFF2		   digitalLo(ROW_GPIO_PORT,ROW_GPIO_PIN2)

#define ROW_ON0			   digitalHi(ROW_GPIO_PORT,ROW_GPIO_PIN0)
#define ROW_ON1			   digitalHi(ROW_GPIO_PORT,ROW_GPIO_PIN1)
#define ROW_ON2			   digitalHi(ROW_GPIO_PORT,ROW_GPIO_PIN2)

//#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define COL_OFF0		   digitalLo(COL_GPIO_PORT,COL_GPIO_PIN0)
#define COL_OFF1		   digitalLo(COL_GPIO_PORT,COL_GPIO_PIN1)
#define COL_OFF2		   digitalLo(COL_GPIO_PORT,COL_GPIO_PIN2)

#define COL_ON0			   digitalHi(COL_GPIO_PORT,COL_GPIO_PIN0)
#define COL_ON1			   digitalHi(COL_GPIO_PORT,COL_GPIO_PIN1)
#define COL_ON2			   digitalHi(COL_GPIO_PORT,COL_GPIO_PIN2)

void GPIO_Config(void);

#endif /* __LED_H */
