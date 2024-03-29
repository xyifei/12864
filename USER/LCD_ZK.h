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
#define _LCD_ZK_H_
#ifdef _LCD_ZK_H_

#define uchar unsigned char 
#define uint unsigned int
#define ulong unsigned long

/* the macro definition to trigger the led on or off 
 * 1 - off
 - 0 - on
 */
#define ON  0
#define OFF 1

//带参宏，可以像内联函数一样使用
#define lcd_cs1(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_12);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_12)

#define lcd_rs(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_11);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_11)


#define lcd_sid(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_9);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_9)

#define lcd_sclk(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_8);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_8)
#define Rom_CS(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_5);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_5)

#define Rom_OUT(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_4);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_4)

					
#define lcd_RES(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_10);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_10)

#define ROM_OUT    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)				
 
/*初始化*/					
void OLED_GPIO_Config(void);
void GBZK_GPIO_Config(void);
/*写指令到LCD模块*/
void transfer_command_lcd(int data1);   
/*写数据到LCD模块*/
void transfer_data_lcd(int data1);
/*延时*/
void delay(int n_ms);               
/*LCD模块初始化*/
void initial_lcd(void);
void lcd_address(unsigned char page,unsigned char column);
/*全屏清屏*/
void clear_screen(void);
/*显示128x64点阵图像*/
void display_128x64(const unsigned char *dp);
/*显示132x64点阵图像*/
//void display_132x64(unsigned char *dp);
/*显示16x16点阵图像、汉字、生僻字或16x16点阵的其他图标*/
void display_graphic_16x16(unsigned int page,unsigned int column,const unsigned char *dp);
/*显示24x24点阵图像、汉字、生僻字或16x16点阵的其他图标*/
void display_graphic_24x24(unsigned char page,unsigned char column,unsigned char *dp);
/*显示8x16点阵图像、ASCII, 或8x16点阵的自造字符、其他图标*/
void display_graphic_8x16(unsigned int page,unsigned char column,unsigned char *dp);
/*显示5*7点阵图像、ASCII, 或5x7点阵的自造字符、其他图标*/
void display_graphic_5x7(unsigned int page,unsigned char column,unsigned char *dp);
/****显示字8x16符串***/
void display_string_8x16(unsigned int page,unsigned char column,unsigned char *dp);
/****显示字16x16符串***/
void display_string_16x16(unsigned int page,unsigned char column,unsigned char *dp);
/****显示字16x32符串***/
void display_string_16x32(unsigned int page,unsigned char column,unsigned char *dp);
/****显示字32x32符串***/
void display_string_32x32(unsigned int page,unsigned char column,unsigned char *dp);

void display_graphic_16x32(unsigned char page,unsigned char column,unsigned char *dp);
void display_graphic_32x32(unsigned char page,unsigned char column,unsigned char *dp);
void clear_graphic_16x32(unsigned char page,unsigned char column);
#endif
