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
#include <LCD_ZK.H>
#include "stm32f10x_gpio.h"

#define uchar unsigned char 
#define uint unsigned int
#define ulong unsigned long
 
void GBZK_GPIO_Config(void)
{		
	/*¶¨ÒåÒ»¸öGPIO_InitTypeDefÀàĞÍµÄ½á¹¹Ìå*/
	GPIO_InitTypeDef GPIO_InitStructure;

	
	
		/*¿ªÆôGPIOCµÄÍâÉèÊ±ÖÓ*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 

	/*Ñ¡ÔñÒª¿ØÖÆµÄGPIOCÒı½Å*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_5 ;	

	/*ÉèÖÃÒı½ÅÄ£Ê½ÎªÍ¨ÓÃÍÆÍìÊä³ö*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*ÉèÖÃÒı½ÅËÙÂÊÎª50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*µ÷ÓÃ¿âº¯Êı£¬³õÊ¼»¯GPIOC*/
  	GPIO_Init(GPIOA, &GPIO_InitStructure);		  

	/* ¹Ø±ÕËùÓĞledµÆ	*/
	GPIO_ResetBits(GPIOA,GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_5 );	 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4 );
	
}

void GBZK_ROMOUTSET(void)
{		
	/*¶¨ÒåÒ»¸öGPIO_InitTypeDefÀàĞÍµÄ½á¹¹Ìå*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*Ñ¡ÔñÒª¿ØÖÆµÄGPIOCÒı½Å*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;	

	/*ÉèÖÃÒı½ÅËÙÂÊÎª50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*ÉèÖÃÒı½ÅÄ£Ê½ÎªÍ¨ÓÃÍÆÍìÊä³ö*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   


	/*µ÷ÓÃ¿âº¯Êı£¬³õÊ¼»¯GPIOC*/
  	GPIO_Init(GPIOA, &GPIO_InitStructure);		  	 

}

void GBZK_ROMOUTRESET(void)
{		
	/*¶¨ÒåÒ»¸öGPIO_InitTypeDefÀàĞÍµÄ½á¹¹Ìå*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*Ñ¡ÔñÒª¿ØÖÆµÄGPIOCÒı½Å*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;	

	/*ÉèÖÃÒı½ÅÄ£Ê½ÎªÍ¨ÓÃÍÆÍìÊä³ö*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*µ÷ÓÃ¿âº¯Êı£¬³õÊ¼»¯GPIOC*/
  	GPIO_Init(GPIOA, &GPIO_InitStructure);		  	 
}


/*Ğ´Ö¸Áîµ½LCDÄ£¿é*/
void transfer_command_lcd(int data1)   
{
	char i;
	lcd_rs(0);;;
	lcd_cs1(0);
	for(i=0;i<8;i++)
   {lcd_sclk(0);;;
		
		if(data1&0x80) {lcd_sid(1);;;}
		else {lcd_sid(0);;;}
		lcd_sclk(1);
		__nop();;;
	//	lcd_sclk(0);;;
	 	data1<<=1;
   }
	 	lcd_rs(1);;;
	 lcd_cs1(1);
}

/*Ğ´Êı¾İµ½LCDÄ£¿é*/
void transfer_data_lcd(int data1)
{
	char i;
	lcd_rs(1);;;
	lcd_cs1(0);
	for(i=0;i<8;i++)
	{
		lcd_sclk(0);;;
		if(data1&0x80) {lcd_sid(1);;;}
		else {lcd_sid(0);;;}
		lcd_sclk(1);;;
		__nop();;;
		//lcd_sclk(0);;;
		data1<<=1;
	}
	lcd_rs(1);;;
	lcd_cs1(1);
}

/*ÑÓÊ±*/
void delay(int n_ms)               
{
 int j,k;
 for(j=0;j<n_ms;j++)
 for(k=0;k<5500;k++);
}


/*µÈ´ıÒ»¸ö°´¼ü£¬ÎÒµÄÖ÷°åÊÇÓÃP2.0ÓëGNDÖ®¼ä½ÓÒ»¸ö°´¼ü*/
#if 0
void waitkey()
{
 repeat:
  	if (P2&0x01) goto repeat;
	else delay(6);
	if (P2&0x01) goto repeat;
	else
	delay(40);;
}
#endif


/*LCDÄ£¿é³õÊ¼»¯*/
void initial_lcd()
{	delay(400);
	//OLED_GPIO_Config();
	GBZK_GPIO_Config();
	lcd_RES(0);
	delay(400);
	lcd_RES(1);
	lcd_cs1(0);
	Rom_CS(1);
       
	transfer_command_lcd(0xAE );//--turn off oled panel
	transfer_command_lcd(0x00 );//---set low column address
	transfer_command_lcd(0x10 );//---set high column address
	transfer_command_lcd(0x40 );//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	transfer_command_lcd(0x81 );//--set contrast control register
	transfer_command_lcd(0xCF ); // Set SEG Output Current Brightness
	transfer_command_lcd(0xA1 );//--Set SEG/Column Mapping     0xa0×óÓÒ·´ÖÃ 0xa1Õı³£
	transfer_command_lcd(0xC8 );//Set COM/Row Scan Direction   0xc0ÉÏÏÂ·´ÖÃ 0xc8Õı³£
	transfer_command_lcd(0xA6 );//--set normal display
	transfer_command_lcd(0xA8 );//--set multiplex ratio(1 to 64)
	transfer_command_lcd(0x3f );//--1/64 duty
	transfer_command_lcd(0xD3 );//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	transfer_command_lcd(0x00 );//-not offset
	transfer_command_lcd(0xd5 );//--set display clock divide ratio/oscillator frequency
	transfer_command_lcd(0x80 );//--set divide ratio, Set Clock as 100 Frames/Sec
	transfer_command_lcd(0xD9 );//--set pre-charge period
	transfer_command_lcd(0xF1 );//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	transfer_command_lcd(0xDA );//--set com pins hardware configuration
	transfer_command_lcd(0x12 );
	transfer_command_lcd(0xDB );//--set vcomh
	transfer_command_lcd(0x40 );//Set VCOM Deselect Level
	transfer_command_lcd(0x20 );//-Set Page Addressing Mode (0x00/0x01/0x02)
	transfer_command_lcd(0x02 );//
	transfer_command_lcd(0x8D );//--set Charge Pump enable/disable
	transfer_command_lcd(0x14 );//--set(0x10) disable
	transfer_command_lcd(0xA4 );// Disable Entire Display On (0xa4/0xa5)
	transfer_command_lcd(0xA6 );// Disable Inverse Display On (0xa6/a7) 
	transfer_command_lcd(0xAF );//--turn on oled panel
	
	lcd_cs1(1);
}

void lcd_address(uchar page,uchar column)
{

	transfer_command_lcd(0xb0 + column);   /*ÉèÖÃÒ³µØÖ·*/
	transfer_command_lcd(((page & 0xf0) >> 4) | 0x10);	/*ÉèÖÃÁĞµØÖ·µÄ¸ß4Î»*/
	transfer_command_lcd((page & 0x0f) | 0x00);	/*ÉèÖÃÁĞµØÖ·µÄµÍ4Î»*/	
}

/*È«ÆÁÇåÆÁ*/
void clear_screen()
{
	unsigned char i,j;
	lcd_cs1(0);
	Rom_CS(1);	
	for(i=0;i<8;i++)
	{
		transfer_command_lcd(0xb0+i);
		transfer_command_lcd(0x00);
		transfer_command_lcd(0x10);
		for(j=0;j<128;j++)
		{
		  	transfer_data_lcd(0x00);
		}
	}
 	lcd_cs1(1);
}

/*ÏÔÊ¾128x64µãÕóÍ¼Ïñ*/
void display_128x64(const uchar *dp)
{
	uint i,j;
	lcd_cs1(0);
	for(j=0;j<8;j++)
	{
		lcd_address(0,j);
		for (i=0;i<128;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
	}
	lcd_cs1(1);
}

void display_3x1(const uchar *dp)
{
	uint i,j;
	lcd_cs1(0);
	for(j=0;j<8;j++)
	{
		lcd_address(0,j);
		for (i=0;i<128;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
	}
	lcd_cs1(1);
}

/*ÏÔÊ¾16x16µãÕóÍ¼Ïñ¡¢ºº×Ö¡¢ÉúÆ§×Ö»ò16x16µãÕóµÄÆäËûÍ¼±ê*/
void display_graphic_16x16(uint page,uint column,const uchar *dp)
{
	uint i,j;
 	lcd_cs1(0);
	Rom_CS(1); 	
	for(j=2;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<16;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
		page++;
	}
	lcd_cs1(1);
}


/*ÏÔÊ¾8x16µãÕóÍ¼Ïñ¡¢ASCII, »ò8x16µãÕóµÄ×ÔÔì×Ö·û¡¢ÆäËûÍ¼±ê*/
void display_graphic_8x16(uint page,uchar column,uchar *dp)
{
	uint i,j;
	lcd_cs1(0);	
	for(j=2;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<8;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
		page++;
	}
	lcd_cs1(1);
}

void display_graphic_16x32(unsigned char page,unsigned char column,unsigned char *dp)
{
	uint i,j;
	lcd_cs1(0);	
	for(j=4;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<16;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}		
		page++;
	}
	lcd_cs1(1);
}

void display_graphic_24x24(unsigned char page,unsigned char column,unsigned char *dp)
{
	uint i,j;
	lcd_cs1(0);	
	for(j=3;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<24;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
		
		page++;
	}
	lcd_cs1(1);
}

void display_graphic_32x32(unsigned char page,unsigned char column,unsigned char *dp)
{
	uint i,j;
	lcd_cs1(0);	
	for(j=4;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<32;i++)
		{	
			transfer_data_lcd(*dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
			dp++;
		}
		
		page++;
	}
	lcd_cs1(1);
}

/*ÏÔÊ¾5*7µãÕóÍ¼Ïñ¡¢ASCII, »ò5x7µãÕóµÄ×ÔÔì×Ö·û¡¢ÆäËûÍ¼±ê*/
void display_graphic_5x7(uint page,uchar column,uchar *dp)
{
	uint col_cnt;
	uchar page_address;
	uchar column_address_L,column_address_H;
	page_address = 0xb0+page-1;
	
	lcd_cs1(0);	
	
	column_address_L =(column&0x0f)-1;
	column_address_H =((column>>4)&0x0f)+0x10;
	
	transfer_command_lcd(page_address); 		/*Set Page Address*/
	transfer_command_lcd(column_address_H);	/*Set MSB of column Address*/
	transfer_command_lcd(column_address_L);	/*Set LSB of column Address*/
	
	for (col_cnt=0;col_cnt<6;col_cnt++)
	{	
		transfer_data_lcd(*dp);
		dp++;
	}
	lcd_cs1(1);
}

void display_string_8x16(uint page,uchar column,uchar *dp)
{
	uchar j = 0;
	while(dp[j] != '\0')
	{
		display_graphic_8x16(page,column,&dp[j]);
		column += 8;
		if(column>120)
		{
			column = 0;
			page += 2;
		}
		j += 16;
	}
}

void clear_graphic_16x32(unsigned char page,unsigned char column)
{
	uint i,j;
	uchar dp = 0x00;
	lcd_cs1(0);	
	for(j=4;j>0;j--)
	{
		lcd_address(column,page);
		for (i=0;i<16;i++)
		{	
			transfer_data_lcd(dp);					/*Ğ´Êı¾İµ½LCD,Ã¿Ğ´ÍêÒ»¸ö8Î»µÄÊı¾İºóÁĞµØÖ·×Ô¶¯¼Ó1*/
		}		
		page++;
	}
	lcd_cs1(1);
}
