//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : LCD_ZK.H
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : �ֿ�� OLED SPI�ӿ���ʾ����(STM32ϵ��)
//              ˵��: 
//              ------------------------����ΪOLED��ʾ���õ��Ľӿ----------------------------------------
//              GND    ��Դ��
//              VCC   ��5V��3.3v��Դ
//              SCL   PA8��CLK��
//              SDA   PA9��DIN��
//              RES   PA10
//              DC   PA11
//              FSO   PA4                
//              CS   PA12
//							CS2		PA5
//
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//******************************************************************************/
#include "stm32f10x.h"
#include "led.h"
#include "LCD_ZK.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
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
		display_GB2312_string(0,1,"12864,�������ֿ�");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8x16��ASCII��*/
		display_GB2312_string(2,1,"16X16���庺�ֿ�,");  /*��ʾһ��16x16�����ֻ�8x16��ASCII��.������ͬ*/
		display_GB2312_string(4,1,"��8X16����ASCII,");
		display_GB2312_string(6,1,"��5X7����ASCII��");			
		delay(2000);
		delay(2000);
		delay(2000);
		/************************************���������������Ĵ�������ԵĻ����԰�ע��ȥ��********
		transfer_command_lcd(0x29);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x00);
    transfer_command_lcd(0x07);
    transfer_command_lcd(0x01);
    transfer_command_lcd(0x2F);	
		
		************************************���������������Ĵ�������ԵĻ����԰�ע��ȥ��***********************/
		clear_screen();
		display_GB2312_string(0,16,"�о�԰����");	
		display_GB2312_string(2,1,"��Ҫ����OLEDģ��");	
		display_GB2312_string(4,1,"�˿�������Ϸ���");	
		display_GB2312_string(6,1,"������������һ��");	
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
		display_GB2312_string(0,1,"GB2312�����ֿ⼰");	
		display_GB2312_string(2,1,"��ͼ�͹��ܣ�����");	
		display_GB2312_string(4,1,"����ֻ�ͼ�����");	
		display_GB2312_string(6,1,"Ƨ�֣����磺");
		
		display_graphic_16x16(6,97,jiong1);					/*�ڵ�7ҳ����81����ʾ�����Ա���Ƨ���֡��塱*/
		display_graphic_16x16(6,113,lei1);					/*��ʾ�����Ա���Ƨ����"����*/
		delay(2000);	
delay(2000);
delay(2000);
		
		clear_screen();			
		display_GB2312_string(0,1,"<!@#$%^&*()_-+]/");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8*16��ASCII��*/
		display_string_5x7(3,1,"<!@#$%^&*()_-+]/;.,?[");/*�ڵ�3ҳ����1�У���ʾһ��5x7�����ASCII��*/
		display_string_5x7(4,1,"XY electronics Co.,  ");/*��ʾһ��5x7�����ASCII��*/
		display_string_5x7(5,1,"Ltd. established at  ");/*��ʾһ��5x7�����ASCII��*/	
		display_string_5x7(6,1,"year 2010.Focus OLED ");/*��ʾһ��5x7�����ASCII��*/
		display_string_5x7(7,1,"Mobile:13265585975");/*��ʾһ��5x7�����ASCII��*/
		display_string_5x7(8,1,"Tel:0755-32910715   ");/*��ʾһ��5x7�����ASCII��*/
		delay(2000);
		display_GB2312_string(0,1,"����������������");	/*�ڵ�1ҳ����1�У���ʾһ��16x16�����ֻ�8x16��ASCII��*/
		display_GB2312_string(2,1,"����������������");  /*��ʾһ��16x16�����ֻ�8x16��ASCII��.������ͬ*/
		display_GB2312_string(4,1,"����������������");
		display_GB2312_string(6,1,"����������������");		        
		delay(2000);	
		display_GB2312_string(0,1,"����������������");
		display_GB2312_string(2,1,"����������������");
		display_GB2312_string(4,1,"����������������");
		display_GB2312_string(6,1,"����������������");		        
		delay(2000);
		delay(2000);
		delay(2000);
		#else

		display_string_5x7(0,0,"123456789012345678901");/*��ʾһ��5x7�����ASCII��*/			
		#endif
		
	}
}


void Delay(__IO u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 


/******************* 2013                          ������ӿƼ� *****END OF FILE************/
