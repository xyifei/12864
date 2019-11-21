//////////////////////////////////////////////////////////////////////////////////	 
//±¾³ÌĞòÖ»¹©Ñ§Ï°Ê¹ÓÃ£¬Î´¾­×÷ÕßĞí¿É£¬²»µÃÓÃÓÚÆäËüÈÎºÎÓÃÍ¾
//ÖĞ¾°Ô°µç×Ó
//µêÆÌµØÖ·£ºhttp://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  ÎÄ ¼ş Ãû   : LCD_ZK.H
//  °æ ±¾ ºÅ   : v2.0
//  ×÷    Õß   : HuangKai
//  Éú³ÉÈÕÆÚ   : 2014-0101
//  ×î½üĞŞ¸Ä   : 
//  ¹¦ÄÜÃèÊö   : ×Ö¿â°æ OLED SPI½Ó¿ÚÑİÊ¾Àı³Ì(STM32ÏµÁĞ)
//              ËµÃ÷: 
//              ------------------------ÒÔÏÂÎªOLEDÏÔÊ¾ËùÓÃµ½µÄ½Ó¿----------------------------------------
//              GND    µçÔ´µØ
//              VCC   ½Ó5V»ò3.3vµçÔ´
//              SCL   PA8£¨CLK£©
//              SDA   PA9£¨DIN£©
//              RES   PA10
//              DC   PA11
//              FSO   PA4                
//              CS   PA12
//							CS2		PA5
//
// ĞŞ¸ÄÀúÊ·   :
// ÈÕ    ÆÚ   : 
// ×÷    Õß   : HuangKai
// ĞŞ¸ÄÄÚÈİ   : ´´½¨ÎÄ¼ş
//°æÈ¨ËùÓĞ£¬µÁ°æ±Ø¾¿¡£
//Copyright(C) ÖĞ¾°Ô°µç×Ó2014/3/16
//All rights reserved
//******************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "LCD_ZK.h"
#include "string.h"

void Delay(__IO u32 nCount);

/*
 * º¯ÊıÃû£ºmain
 * ÃèÊö  £ºÖ÷º¯Êı
 * ÊäÈë  £ºÎŞ
 * Êä³ö  £ºÎŞ
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


void Delay(__IO u32 nCount)	 //¼òµ¥µÄÑÓÊ±º¯Êı
{
	for(; nCount != 0; nCount--);
} 
