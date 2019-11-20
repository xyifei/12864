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

//#define    MI_ERR    (-2)

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
		display_GB2312_string(0,1,"12864,´øÖĞÎÄ×Ö¿â");	/*ÔÚµÚ1Ò³£¬µÚ1ÁĞ£¬ÏÔÊ¾Ò»´®16x16µãÕóºº×Ö»ò8x16µÄASCII×Ö*/
		display_GB2312_string(2,1,"16X16¼òÌåºº×Ö¿â,");  /*ÏÔÊ¾Ò»´®16x16µãÕóºº×Ö»ò8x16µÄASCII×Ö.ÒÔÏÂÀ×Í¬*/
		display_GB2312_string(4,1,"»ò8X16µãÕóASCII,");
		display_GB2312_string(6,1,"»ò5X7µãÕóASCIIÂë");			
		delay(2000);
		delay(2000);
		delay(2000);
		/************************************ÕâÀïÊÇÈÃÆÁ¹ö¶¯µÄ´úÂëÏë²âÊÔµÄ»°¿ÉÒÔ°Ñ×¢ÊÍÈ¥ÁË********
		transfer_command_lcd(0x29);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x07);
    transfer_command_lcd(0x01);
    transfer_command_lcd(0x2F);	
		
		************************************ÕâÀïÊÇÈÃÆÁ¹ö¶¯µÄ´úÂëÏë²âÊÔµÄ»°¿ÉÒÔ°Ñ×¢ÊÍÈ¥ÁË***********************/
		clear_screen();
		display_GB2312_string(0,16,"ÖĞ¾°Ô°µç×Ó");	
		display_GB2312_string(2,1,"Ö÷ÒªÉú²úOLEDÄ£¿é");	
		display_GB2312_string(4,1,"¹Ë¿ÍÖÁÉÏÕæ³Ï·şÎñ");	
		display_GB2312_string(6,1,"³ÏĞÅÓëÖÊÁ¿µÚÒ»£¡");	
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
		display_GB2312_string(0,1,"GB2312¼òÌå×Ö¿â¼°");	
		display_GB2312_string(2,1,"ÓĞÍ¼ĞÍ¹¦ÄÜ£¬¿É×Ô");	
		display_GB2312_string(4,1,"±à´ó×Ö»òÍ¼Ïñ»òÉú");	
		display_GB2312_string(6,1,"Æ§×Ö£¬ÀıÈç£º");
		
		display_graphic_16x16(6,97,jiong1);					/*ÔÚµÚ7Ò³£¬µÚ81ÁĞÏÔÊ¾µ¥¸ö×Ô±àÉúÆ§ºº×Ö¡°‡å¡±*/
		display_graphic_16x16(6,113,lei1);					/*ÏÔÊ¾µ¥¸ö×Ô±àÉúÆ§ºº×Ö"®š¡°*/
		delay(2000);	
delay(2000);
delay(2000);
		
		clear_screen();			
		display_GB2312_string(0,1,"<!@#$%^&*()_-+]/");	/*ÔÚµÚ1Ò³£¬µÚ1ÁĞ£¬ÏÔÊ¾Ò»´®16x16µãÕóºº×Ö»ò8*16µÄASCII×Ö*/
		display_string_5x7(3,1,"<!@#$%^&*()_-+]/;.,?[");/*ÔÚµÚ3Ò³£¬µÚ1ÁĞ£¬ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/
		display_string_5x7(4,1,"XY electronics Co.,  ");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/
		display_string_5x7(5,1,"Ltd. established at  ");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/	
		display_string_5x7(6,1,"year 2010.Focus OLED ");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/
		display_string_5x7(7,1,"Mobile:13265585975");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/
		display_string_5x7(8,1,"Tel:0755-32910715   ");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/
		delay(2000);
		display_GB2312_string(0,1,"°¡°¢°£°¤°¥°¦°§°¨");	/*ÔÚµÚ1Ò³£¬µÚ1ÁĞ£¬ÏÔÊ¾Ò»´®16x16µãÕóºº×Ö»ò8x16µÄASCII×Ö*/
		display_GB2312_string(2,1,"°©°ª°«°¬°­°®°¯°°");  /*ÏÔÊ¾Ò»´®16x16µãÕóºº×Ö»ò8x16µÄASCII×Ö.ÒÔÏÂÀ×Í¬*/
		display_GB2312_string(4,1,"°±°²°³°´°µ°¶°·°¸");
		display_GB2312_string(6,1,"°¹°º°»°¼°½°¾°¿°À");		        
		delay(2000);	
		display_GB2312_string(0,1,"÷ß÷à÷á÷â÷ã÷ä÷å÷æ");
		display_GB2312_string(2,1,"÷ç÷è÷é÷ê÷ë÷ì÷í÷î");
		display_GB2312_string(4,1,"÷ï÷ğ÷ñ÷ò÷ó÷ô÷õ÷ö");
		display_GB2312_string(6,1,"÷÷÷ø÷ù÷ú÷û÷ü÷ı÷ş");		        
		delay(2000);
		delay(2000);
		delay(2000);
		#else

		display_string_5x7(0,0,"123456789012345678901");/*ÏÔÊ¾Ò»´®5x7µãÕóµÄASCII×Ö*/			
		#endif
		
	}
}


void Delay(__IO u32 nCount)	 //¼òµ¥µÄÑÓÊ±º¯Êı
{
	for(; nCount != 0; nCount--);
} 


/******************* 2013                          ĞÅÒâµç×Ó¿Æ¼¼ *****END OF FILE************/
