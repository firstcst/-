/**
********************************************************
*
* @file      Hal_infrared.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     ������ ֻΪ����Ӳ������
*            Gizwits Smart Cloud  for Smart Products
*            ����|��ֵ|����|����|��ȫ|����|����|��̬
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

    RCC_APB2PeriphClockCmd(Infrared_GPIO_CLK,ENABLE);//ʹ��PORTA,PORTEʱ��
    GPIO_InitStructure.GPIO_Pin  = Infrared_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_Init(Infrared_GPIO_PORT, &GPIO_InitStructure);
}
bool IR_Handle(void)
{
    if(GPIO_ReadInputDataBit(Infrared_GPIO_PORT, Infrared_GPIO_PIN))    //�ж��Ƿ��������ڵ�����Ϊ0����Ϊ1��
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
/****RGB����****/
void RGB_Infrared(void)
{
			 RETURN_Infrared;
			LED_RGB_Control(255,0,0);			//��ɫ
				  DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,255);				//��ɫ
				  DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;			
			 RETURN_Infrared;
			LED_RGB_Control(0,128,0);     //��ɫ
			    DELAY;
			 RETURN_Infrared;
			LED_RGB_Control(0,0,0);
			    DELAY;	
			 RETURN_Infrared;
}