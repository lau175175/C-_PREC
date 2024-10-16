/**
  ******************************************************************************
  * @file    bsp_gpio.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   GPIO应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:SPX
  *
  ******************************************************************************
  */
  
#include "bsp_gpio.h"   

 /**
  * @brief  初始化控制的IO口输出
  * @param  无
  * @retval 无
  */
void GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( ROW_GPIO_CLK | COL_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN0;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);	

		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN1;	

		/*调用库函数，初始化GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);		
	
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = ROW_GPIO_PIN2;	

		/*调用库函数，初始化GPIO*/
		GPIO_Init(ROW_GPIO_PORT, &GPIO_InitStructure);		


/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN0;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);		

/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN1;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);	
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = COL_GPIO_PIN2;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(COL_GPIO_PORT, &GPIO_InitStructure);	


		/* 关闭所有IO口	*/
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN0);
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN1);
		GPIO_SetBits(ROW_GPIO_PORT, ROW_GPIO_PIN2);
		
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN0);
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN1);
		GPIO_SetBits(COL_GPIO_PORT, COL_GPIO_PIN2);

}

/*********************************************END OF FILE**********************/
