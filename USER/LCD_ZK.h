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

//´ø²Îºê£¬¿ÉÒÔÏñÄÚÁªº¯ÊıÒ»ÑùÊ¹ÓÃ
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
 
/*³õÊ¼»¯*/					
void OLED_GPIO_Config(void);
void GBZK_GPIO_Config(void);
/*Ğ´Ö¸Áîµ½LCDÄ£¿é*/
void transfer_command_lcd(int data1);   
/*Ğ´Êı¾İµ½LCDÄ£¿é*/
void transfer_data_lcd(int data1);
/*ÑÓÊ±*/
void delay(int n_ms);               
/*LCDÄ£¿é³õÊ¼»¯*/
void initial_lcd(void);
void lcd_address(unsigned char page,unsigned char column);
/*È«ÆÁÇåÆÁ*/
void clear_screen(void);
/*ÏÔÊ¾128x64µãÕóÍ¼Ïñ*/
void display_128x64(const unsigned char *dp);
/*ÏÔÊ¾132x64µãÕóÍ¼Ïñ*/
//void display_132x64(unsigned char *dp);
/*ÏÔÊ¾16x16µãÕóÍ¼Ïñ¡¢ºº×Ö¡¢ÉúÆ§×Ö»ò16x16µãÕóµÄÆäËûÍ¼±ê*/
void display_graphic_16x16(unsigned int page,unsigned int column,const unsigned char *dp);
/*ÏÔÊ¾24x24µãÕóÍ¼Ïñ¡¢ºº×Ö¡¢ÉúÆ§×Ö»ò16x16µãÕóµÄÆäËûÍ¼±ê*/
void display_graphic_24x24(unsigned char page,unsigned char column,unsigned char *dp);
/*ÏÔÊ¾8x16µãÕóÍ¼Ïñ¡¢ASCII, »ò8x16µãÕóµÄ×ÔÔì×Ö·û¡¢ÆäËûÍ¼±ê*/
void display_graphic_8x16(unsigned int page,unsigned char column,unsigned char *dp);
/*ÏÔÊ¾5*7µãÕóÍ¼Ïñ¡¢ASCII, »ò5x7µãÕóµÄ×ÔÔì×Ö·û¡¢ÆäËûÍ¼±ê*/
void display_graphic_5x7(unsigned int page,unsigned char column,unsigned char *dp);
/****ÏÔÊ¾×Ö8x16·û´®***/
void display_string_8x16(unsigned int page,unsigned char column,unsigned char *dp);
/****ÏÔÊ¾×Ö16x16·û´®***/
void display_string_16x16(unsigned int page,unsigned char column,unsigned char *dp);
/****ÏÔÊ¾×Ö16x32·û´®***/
void display_string_16x32(unsigned int page,unsigned char column,unsigned char *dp);
/****ÏÔÊ¾×Ö32x32·û´®***/
void display_string_32x32(unsigned int page,unsigned char column,unsigned char *dp);

void display_graphic_16x32(unsigned char page,unsigned char column,unsigned char *dp);
void display_graphic_32x32(unsigned char page,unsigned char column,unsigned char *dp);
void clear_graphic_16x32(unsigned char page,unsigned char column);
#endif
