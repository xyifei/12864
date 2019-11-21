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
#include "string.h"

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


void Delay(__IO u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 
