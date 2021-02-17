/****************************************************************************************************/
/*			@FileName		:	display.c															  	*/
/*			@Author			:	zhengbaiqiu															*/
/*			@Version		:	v1.0																*/
/*			@Date			:	2019.11.12  														*/
/****************************************************************************************************/


/* Includes --------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Project ---------------------------------------------------------------------*/
#include "maindef.h"
//#include "font.h"
#include "lcd_driver.h"	
#include "gui.h"	
#include "delay.h"
#include "display.h"
#include "apiLib.h"

/* Variable --------------------------------------------------------------------*/
extern u16 Touch_X;
extern u16 Touch_Y;

/* Function --------------------------------------------------------------------*/
void DrawTestPage(u8 *str);
void Test_Display(void);





/*****************************************************************************
 * @name       :void DrawTestPage(u8 *str)
 * @date       :2018-08-09 
 * @function   :Drawing test interface
 * @parameters :str:the start address of the Chinese and English strings
 * @retvalue   :None
******************************************************************************/ 
void DrawTestPage(u8 *str)
{
	//»æÖÆ¹Ì¶¨À¸up
	//LCD_Clear(WHITE);
	LCD_Clear(GRAY0);
	LCD_Fill(0,0,lcddev.width,20,BLUE);
	//»æÖÆ¹Ì¶¨À¸down
// 	LCD_Fill(0,20,lcddev.width,40,YELLOW);
//	LCD_Fill(0,230,lcddev.width,250,BLUE);
	LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
	POINT_COLOR=WHITE;
	//POINT_COLOR=GRAY0;
	Gui_StrCenter(0,2,WHITE,BLUE,str,16,1);//¾ÓÖÐÏÔÊ¾
// 	Gui_StrCenters(0,22,BLACK,YELLOW,"¼ì²âÀ¸",16,1);//¾ÓÖÐÏÔÊ¾
// 	Gui_StrCenters(241,22,BLACK,YELLOW,"¼ì²âÀ¸",16,1);//¾ÓÖÐÏÔÊ¾
// 	Gui_StrCenters(0,232,WHITE,BLUE,"²âÊÔ×´Ì¬",16,1);//¾ÓÖÐÏÔÊ¾
// 	Gui_StrCenters(241,232,WHITE,BLUE,"Ô¤Áô",16,1);//¾ÓÖÐÏÔÊ¾
//	Gui_DrawLine(240,250,240,300,BLUE);
//	LCD_DrawLine(240,40,240,300);
	//Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.zbq.com",16,1);//¾ÓÖÐÏÔÊ¾
	Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"Çë°´ÌáÊ¾²Ù×÷",16,1);//¾ÓÖÐÏÔÊ¾
	//»æÖÆ²âÊÔÇøÓò
	//LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
}

/*****************************************************************************
 * @name       :void Display_Test(u8 test_mode,u8 test_cmd,u8 test_status)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :display test
 * @parameters :test_cmd ¶ÁÈ¡µ½µÄÃüÁîÂë
 * @retvalue   :None
******************************************************************************/
void Display_Test(u8 test_mode,u8 test_cmd,u8 test_status,u16 dat1,u16 dat2)
{
	if(test_cmd == 1)
	{
		Gui_DrawFont_Num16(116,50,BLACK,GRAY0,dat1);
		Gui_DrawFont_Num16(198,50,BLACK,GRAY0,dat2);
	}
	else if(test_cmd == 2)
	{
		Gui_DrawFont_Num16(116,80,BLACK,GRAY0,dat1);
		Gui_DrawFont_Num16(198,80,BLACK,GRAY0,dat2);
	}
	
	
// 	switch(test_cmd)
// 	{
// 		case TEST_START ://01
// 			if(test_status == 1)
// 			{
// 				//Gui_DrawFont_GBK24(300,245,GREEN,GRAY0,"¼ì²âÖÐ...");
// 			}
// 			break;
// 		case TEST_LEFT_GUIDE ://02
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,44,BLACK,GRAY0,"×óÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,42,BLACK,GRAY0,"×óÒýµ¼PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,44,RED,GRAY0,"×óÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,42,RED,GRAY0,"×óÒýµ¼FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,68,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_TOP_GUIDE ://03
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,68,BLACK,GRAY0,"ÉÏÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,62,BLACK,GRAY0,"ÉÏÒýµ¼PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,68,RED,GRAY0,"ÉÏÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,62,RED,GRAY0,"ÉÏÒýµ¼FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,92,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_GUIDE ://04
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,92,BLACK,GRAY0,"Ç°Òýµ¼");
// 				//Gui_DrawFont_GBK16(0,82,BLACK,GRAY0,"Ç°Òýµ¼PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,92,RED,GRAY0,"Ç°Òýµ¼");
// 				//Gui_DrawFont_GBK16(0,82,RED,GRAY0,"Ç°Òýµ¼FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,116,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_RIGHT_GUIDE ://05
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,116,BLACK,GRAY0,"ÓÒÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,102,BLACK,GRAY0,"ÓÒÒýµ¼PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,116,RED,GRAY0,"ÓÒÒýµ¼");
// 				//Gui_DrawFont_GBK16(0,102,RED,GRAY0,"ÓÒÒýµ¼FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,140,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_LEFT_AVOID_BUMP ://06
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,140,BLACK,GRAY0,"×óÃâÅö×²");
// 				//Gui_DrawFont_GBK16(0,122,BLACK,GRAY0,"×óÃâÅö×²PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,140,RED,GRAY0,"×óÃâÅö×²");
// 				//Gui_DrawFont_GBK16(0,122,RED,GRAY0,"×óÃâÅö×²FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,164,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP0 ://07
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,164,BLACK,GRAY0,"ÖÐÃâÅö×²0");
// 				//Gui_DrawFont_GBK16(0,142,BLACK,GRAY0,"ÖÐÃâÅö×²0PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,164,RED,GRAY0,"ÖÐÃâÅö×²0");
// 				//Gui_DrawFont_GBK16(0,142,RED,GRAY0,"ÖÐÃâÅö×²0FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,188,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP1 ://08
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,188,BLACK,GRAY0,"ÖÐÃâÅö×²1");
// 				//Gui_DrawFont_GBK16(0,162,BLACK,GRAY0,"ÖÐÃâÅö×²1PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,188,RED,GRAY0,"ÖÐÃâÅö×²1");
// 				//Gui_DrawFont_GBK16(0,162,RED,GRAY0,"ÖÐÃâÅö×²1FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,212,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP2 ://09
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,212,BLACK,GRAY0,"ÖÐÃâÅö×²2");
// 				//Gui_DrawFont_GBK16(0,182,BLACK,GRAY0,"ÖÐÃâÅö×²2PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,212,RED,GRAY0,"ÖÐÃâÅö×²2");
// 				//Gui_DrawFont_GBK16(0,182,RED,GRAY0,"ÖÐÃâÅö×²2FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,236,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP3 ://10
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,236,BLACK,GRAY0,"ÖÐÃâÅö×²3");
// 				//Gui_DrawFont_GBK16(0,202,BLACK,GRAY0,"ÖÐÃâÅö×²3PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,236,RED,GRAY0,"ÖÐÃâÅö×²3");
// 				//Gui_DrawFont_GBK16(0,202,RED,GRAY0,"ÖÐÃâÅö×²3FAIL");
// 			}
// 			Gui_DrawFont_GBK24(0,260,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP4 ://11
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(0,260,BLACK,GRAY0,"ÖÐÃâÅö×²4");
// 				//Gui_DrawFont_GBK16(0,222,BLACK,GRAY0,"ÖÐÃâÅö×²4PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(0,260,RED,GRAY0,"ÖÐÃâÅö×²4");
// 				//Gui_DrawFont_GBK16(0,222,RED,GRAY0,"ÖÐÃâÅö×²4FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,44,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP5 ://12
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,44,BLACK,GRAY0,"ÖÐÃâÅö×²5");
// 				//Gui_DrawFont_GBK16(0,242,BLACK,GRAY0,"ÖÐÃâÅö×²5PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,44,RED,GRAY0,"ÖÐÃâÅö×²5");
// 				//Gui_DrawFont_GBK16(0,242,RED,GRAY0,"ÖÐÃâÅö×²5FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,68,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP6 ://13
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,68,BLACK,GRAY0,"ÖÐÃâÅö×²6");
// 				//Gui_DrawFont_GBK16(0,262,BLACK,GRAY0,"ÖÐÃâÅö×²6PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,68,RED,GRAY0,"ÖÐÃâÅö×²6");
// 				//Gui_DrawFont_GBK16(0,262,RED,GRAY0,"ÖÐÃâÅö×²6FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,92,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP7 ://14
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,92,BLACK,GRAY0,"ÖÐÃâÅö×²7");
// 				//Gui_DrawFont_GBK16(0,282,BLACK,GRAY0,"ÖÐÃâÅö×²7PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,92,RED,GRAY0,"ÖÐÃâÅö×²7");
// 				//Gui_DrawFont_GBK16(0,282,RED,GRAY0,"ÖÐÃâÅö×²7FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,116,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP8 ://15
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,116,BLACK,GRAY0,"ÖÐÃâÅö×²8");
// 				//Gui_DrawFont_GBK16(241,42,BLACK,GRAY0,"ÖÐÃâÅö×²8PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,116,RED,GRAY0,"ÖÐÃâÅö×²8");
// 				//Gui_DrawFont_GBK16(241,42,RED,GRAY0,"ÖÐÃâÅö×²8FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,140,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_FRONT_AVOID_BUMP9 ://16
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,140,BLACK,GRAY0,"ÖÐÃâÅö×²9");
// 				//Gui_DrawFont_GBK16(241,62,BLACK,GRAY0,"ÖÐÃâÅö×²9PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,140,RED,GRAY0,"ÖÐÃâÅö×²9");
// 				//Gui_DrawFont_GBK16(241,62,RED,GRAY0,"ÖÐÃâÅö×²9FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,164,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_RIGHT_AVOID_BUMP ://17
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,164,BLACK,GRAY0,"ÓÒÃâÅö×²");
// 				//Gui_DrawFont_GBK16(241,82,BLACK,GRAY0,"ÓÒÃâÅö×²PASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,164,RED,GRAY0,"ÓÒÃâÅö×²");
// 				//Gui_DrawFont_GBK16(241,82,RED,GRAY0,"ÓÒÃâÅö×²FAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,188,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_LEFT_ALONG_SIDE ://18
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,188,BLACK,GRAY0,"×óÑØ±ß");
// 				//Gui_DrawFont_GBK16(241,102,BLACK,GRAY0,"×óÑØ±ßPASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,188,RED,GRAY0,"×óÑØ±ß");
// 				//Gui_DrawFont_GBK16(241,102,RED,GRAY0,"×óÑØ±ßFAIL");
// 			}
// 			Gui_DrawFont_GBK24(242,212,BLACK,GRAY0,"...");
// 			break;
// 		case TEST_RIGHT_ALONG_SIDE ://19
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,212,BLACK,GRAY0,"ÓÒÑØ±ß");
// 				//Gui_DrawFont_GBK16(241,122,BLACK,GRAY0,"ÓÒÑØ±ßPASS");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,212,RED,GRAY0,"ÓÒÑØ±ß");
// 				//Gui_DrawFont_GBK16(241,122,RED,GRAY0,"ÓÒÑØ±ßFAIL");
// 			}
// 			break;
// 		case 0xfe :
// 			if(test_status == 1)
// 			{
// 				Gui_DrawFont_GBK24(242,236,BLACK,GRAY0,"¼ì²âÍê³É");
// 				//Gui_DrawFont_GBK24(300,245,GREEN,GRAY0,"¼ì²âOK");
// 			}
// 			else
// 			{
// 				Gui_DrawFont_GBK24(242,236,RED,GRAY0,"¼ì²âFAIL");
// 			}
// 			break;
// 		default :
// 			break;
// 	}
// 	Gui_DrawPoint(0,0,GRAY0);
}

/*****************************************************************************
 * @name       :void Test_Display(void)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Display(void)
{
//	if(mMaininf.mWork.mWorkInitFlag == 1)//³õÊ¼»¯³É¹¦
	if(1)
	{
// 		if(mMaininf.mWork.mWorkChecking == 0)//Î´ÔÚ¼ì²â×´Ì¬
// 		{
// 			if(mMaininf.mMode.mScreenPressFlag == 1)            //    ÆÁÄ»´¥·¢
// 			{
// 				mMaininf.mMode.mScreenPressFlag = 0;
// 				
// 				if((Touch_X >= 305) && (Touch_X <= 423) && (Touch_Y >= 215) && (Touch_Y <= 278))
// 				{
// 					LCD_Clear_Area(305,215,423,278,GRAY0);
// 					
// 					Gui_DrawFont_GBK24(140,130,BLUE,GRAY0,"¼ì²âÖÐ..              ");
// 					
// 					api_SendCMDData(2,1,1);//¿ªÊ¼¼ì²â
// 					mMaininf.mWork.mWorkChecking = 1;
// 				}
// 			}
// 		}
//		else
		if(1)
		{
			if(mMaininf.mUart1.mReceiveFlag == 1)            //    ½ÓÊÕµ½·´À¡
			{
				mMaininf.mUart1.mReceiveFlag = 0;
				

				if(mMaininf.mUart1.ReceiveBuf[0] == 1)//½ÓÊÕµ½Ö¸Áî
				{
					mMaininf.mWork.mWorkDropDataFar = ((mMaininf.mUart1.ReceiveBuf[3] << 8) | mMaininf.mUart1.ReceiveBuf[4]);
					mMaininf.mWork.mWorkDropDataNear = ((mMaininf.mUart1.ReceiveBuf[5] << 8) | mMaininf.mUart1.ReceiveBuf[6]);
					
					Display_Test(1,mMaininf.mUart1.ReceiveBuf[1],mMaininf.mUart1.ReceiveBuf[2],mMaininf.mWork.mWorkDropDataFar,mMaininf.mWork.mWorkDropDataNear);
					
					api_SendCMDData(1,mMaininf.mUart1.ReceiveBuf[1],1);//·µ»ØÐÅÏ¢
					vTaskDelay(5);
					mMaininf.mWork.mWorkChecking = 0;

				}
			}
			
		}
	}
	Gui_DrawPoint(0,0,GRAY0);
	
}






















