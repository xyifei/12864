//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : LCD_ZK.H
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2014-0101
//  最近修改   : 
//  功能描述   : 字库版 OLED SPI接口演示例程(STM32系列)
//              说明: 
//              ------------------------以下为OLED显示所用到的接�----------------------------------------
//              GND    电源地
//              VCC   接5V或3.3v电源
//              SCL   PA8（CLK）
//              SDA   PA9（DIN）
//              RES   PA10
//              DC   PA11
//              FSO   PA4                
//              CS   PA12
//							CS2		PA5
//
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2014/3/16
//All rights reserved
//******************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "LCD_ZK.h"
#include "string.h"

void Delay(__IO u32 nCount);

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
 
int main(void)
{   
	initial_lcd();	
	clear_screen();    //clear all dots 
	
	display_graphic_32x32(3,0,D);
	display_graphic_32x32(3,25,E);
	display_graphic_32x32(3,50,L);
	display_graphic_32x32(3,75,T);
	display_graphic_32x32(3,100,M);
	display_graphic_8x16(0,85,v);
	display_graphic_8x16(0,93,one);
	display_graphic_8x16(0,101,point);
	display_graphic_8x16(0,109,nine);
	delay(4000);
	clear_screen(); 
	display_128x64(bmp1);
	display_graphic_8x16(0,22,one);
	display_graphic_8x16(0,30,zero);
	display_graphic_8x16(0,38,zero);
	display_graphic_8x16(0,80,c);
	display_graphic_8x16(0,88,h);
	display_graphic_8x16(0,96,four);
	display_graphic_8x16(5,94,percent);
	display_graphic_8x16(5,102,l);
	display_graphic_8x16(5,112,e);
	display_graphic_8x16(5,120,l);
	
	while(1)
	{
		static uchar i = 90;
		
		if(i < 10)
		{
			clear_graphic_16x32(3,50);
			clear_graphic_16x32(3,30);
			display_graphic_16x32(3,70,&num[i][0]);
		}
		else if((i>=10) && (i<100))
		{
			display_graphic_16x32(3,50,&num[i/10][0]);
			display_graphic_16x32(3,70,&num[i%10][0]);
		}
		else if(i == 100)
		{
			display_graphic_16x32(3,30,&num[1][0]);
			display_graphic_16x32(3,50,&num[0][0]);
			display_graphic_16x32(3,70,&num[0][0]);
			i = 0;
		}	
		i++;
		
		delay(2000);
	}
}


void Delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 
