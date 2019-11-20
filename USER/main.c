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

//#define    MI_ERR    (-2)

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
	
		display_128x64(bmp1);
/*	lcd_cs1(0);
	 transfer_command_lcd(0x2E);
    transfer_command_lcd(0x29);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x07);
    transfer_command_lcd(0x01);
    transfer_command_lcd(0x2F);
	lcd_cs1(1);*/
	while(1)
	{
		#if 1
		display_128x64(bmp1);
		delay(2000);
		clear_screen();	
		display_GB2312_string(0,1,"12864,带中文字库");	/*在第1页，第1列，显示一串16x16点阵汉字或8x16的ASCII字*/
		display_GB2312_string(2,1,"16X16简体汉字库,");  /*显示一串16x16点阵汉字或8x16的ASCII字.以下雷同*/
		display_GB2312_string(4,1,"或8X16点阵ASCII,");
		display_GB2312_string(6,1,"或5X7点阵ASCII码");			
		delay(2000);
		delay(2000);
		delay(2000);
		/************************************这里是让屏滚动的代码想测试的话可以把注释去了********
		transfer_command_lcd(0x29);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x07);
    transfer_command_lcd(0x01);
    transfer_command_lcd(0x2F);	
		
		************************************这里是让屏滚动的代码想测试的话可以把注释去了***********************/
		clear_screen();
		display_GB2312_string(0,16,"中景园电子");	
		display_GB2312_string(2,1,"主要生产OLED模块");	
		display_GB2312_string(4,1,"顾客至上真诚服务");	
		display_GB2312_string(6,1,"诚信与质量第一！");	
		delay(2000);	
		delay(2000);
		delay(2000);
			 transfer_command_lcd(0x2E);
    transfer_command_lcd(0x29);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x07);
    transfer_command_lcd(0x01);
    transfer_command_lcd(0x2F);
		clear_screen();		
		display_GB2312_string(0,1,"GB2312简体字库及");	
		display_GB2312_string(2,1,"有图型功能，可自");	
		display_GB2312_string(4,1,"编大字或图像或生");	
		display_GB2312_string(6,1,"僻字，例如：");
		
		display_graphic_16x16(6,97,jiong1);					/*在第7页，第81列显示单个自编生僻汉字“囧”*/
		display_graphic_16x16(6,113,lei1);					/*显示单个自编生僻汉字"畾“*/
		delay(2000);	
delay(2000);
delay(2000);
		
		clear_screen();			
		display_GB2312_string(0,1,"<!@#$%^&*()_-+]/");	/*在第1页，第1列，显示一串16x16点阵汉字或8*16的ASCII字*/
		display_string_5x7(3,1,"<!@#$%^&*()_-+]/;.,?[");/*在第3页，第1列，显示一串5x7点阵的ASCII字*/
		display_string_5x7(4,1,"XY electronics Co.,  ");/*显示一串5x7点阵的ASCII字*/
		display_string_5x7(5,1,"Ltd. established at  ");/*显示一串5x7点阵的ASCII字*/	
		display_string_5x7(6,1,"year 2010.Focus OLED ");/*显示一串5x7点阵的ASCII字*/
		display_string_5x7(7,1,"Mobile:13265585975");/*显示一串5x7点阵的ASCII字*/
		display_string_5x7(8,1,"Tel:0755-32910715   ");/*显示一串5x7点阵的ASCII字*/
		delay(2000);
		display_GB2312_string(0,1,"啊阿埃挨哎唉哀皑");	/*在第1页，第1列，显示一串16x16点阵汉字或8x16的ASCII字*/
		display_GB2312_string(2,1,"癌蔼矮艾碍爱隘鞍");  /*显示一串16x16点阵汉字或8x16的ASCII字.以下雷同*/
		display_GB2312_string(4,1,"氨安俺按暗岸胺案");
		display_GB2312_string(6,1,"肮昂盎凹敖熬翱袄");		        
		delay(2000);	
		display_GB2312_string(0,1,"鬟鬣麽麾縻麂麇麈");
		display_GB2312_string(2,1,"麋麒鏖麝麟黛黜黝");
		display_GB2312_string(4,1,"黠黟黢黩黧黥黪黯");
		display_GB2312_string(6,1,"鼢鼬鼯鼹鼷鼽鼾齄");		        
		delay(2000);
		delay(2000);
		delay(2000);
		#else

		display_string_5x7(0,0,"123456789012345678901");/*显示一串5x7点阵的ASCII字*/			
		#endif
		
	}
}


void Delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 


/******************* 2013                          信意电子科技 *****END OF FILE************/
