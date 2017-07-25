/**
********************************************************
*
* @file      Hal_infrared.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     机智云 只为智能硬件而生
*            Gizwits Smart Cloud  for Smart Products
*            链接|增值|开放|中立|安全|自有|自由|生态
*            www.gizwits.com
*
*********************************************************/

#include <stm32f10x.h>
#include "Hal_infrared/Hal_infrared.h"
#include "Hal_motor/Hal_motor.h"
#include "Hal_rgb_led/Hal_rgb_led.h"
#include "delay.h"
#include "Hal_temp_hum/Hal_temp_hum.h"
#define  DELAY 				Delay_Infrared(300);
#define RETURN_Infrared      if(GPIO_ReadInputDataBit(Infrared_GPIO_PORT, Infrared_GPIO_PIN)) return
#define BREAK_Infrared      if(GPIO_ReadInputDataBit(Infrared_GPIO_PORT, Infrared_GPIO_PIN)) break
void IR_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(Infrared_GPIO_CLK,ENABLE);//使能PORTA,PORTE时钟
    GPIO_InitStructure.GPIO_Pin  = Infrared_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_Init(Infrared_GPIO_PORT, &GPIO_InitStructure);
}
bool IR_Handle(void)
{
    if(GPIO_ReadInputDataBit(Infrared_GPIO_PORT, Infrared_GPIO_PIN))    //判定是否有物体遮挡，是为0，否为1。
    {
//        return 0;
			printf("NO some objects are close to us!\r\n");
			Motor_status(5);
			LED_RGB_Control(0,0,0);
    }
    else
    {
			printf("Some objects are close to us!\r\n");
			Motor_status(6);
			for(;;)
			{
			BREAK_Infrared;	
			RGB_Infrared();
//			BREAK_Infrared;
			}
//        return 1;
    }
}
/****RGB点亮****/
void RGB_Infrared(void)
{
			 RETURN_Infrared;
			LED_RGB_Control(255,0,0);			//红色
				  DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,255);				//蓝色
				  DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;			
			 RETURN_Infrared;
			LED_RGB_Control(0,128,0);     //绿色
			    DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;	
			 RETURN_Infrared;
}