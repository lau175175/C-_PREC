/**
  ******************************************************************************
  * @file    bsp_gpio.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   GPIOӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:SPX
  *
  ******************************************************************************
  */
  
#include "bsp_gpio.h"   

 /**
  * @brief  ��ʼ�����Ƶ�IO�����
  * @param  ��
  * @retval ��
  */
void GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( ROW_GPIO_CLK | COL_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN0;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);	

		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN1;	

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);		
	
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN2;	

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);		


/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN0;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);		

/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN1;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);	
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN2;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);	


		/* �ر�����IO��	*/
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN0);
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN1);
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN2);
		
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN0);
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN1);
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN2);

}

/*********************************************END OF FILE**********************/
