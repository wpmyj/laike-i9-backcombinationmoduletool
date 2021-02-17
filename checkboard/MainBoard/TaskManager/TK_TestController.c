/****************************************************************************************************/
/*			@FileName		:	TK_TestController.c												  	*/
/*			@Author			:	zhengbaiqiu															*/
/*			@Version		:	v1.0																*/
/*			@Date			:	2019.11.12  														*/
/****************************************************************************************************/


/* Includes --------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Project ---------------------------------------------------------------------*/
#include "maindef.h"
#include "bsp.h"
#include "apiLib.h"
#include "TK_TestController.h"


/* Variable --------------------------------------------------------------------*/
/* Function --------------------------------------------------------------------*/
void TK_TestController( void *pvParameters );
void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status,u16 dat1,u16 dat2, u16 waittime,u8 count);
u8 api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime,u8 type,u8 num);
u8 iiiiiiiii;

u8 str[15];


/*****************************************************************************
 * @name       :void TK_TestController( void *pvParameters )
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :时间控制任务
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void TK_TestController( void *pvParameters )
{
	//api_MachinePowerOn();
	for(;;)
	{
		IWDG_ReloadCounter();
// 		api_Send_Signal(1,1);
// 		api_Send_Signal(2,1);
// 		api_Led_Status_Set(LED_B0,1);
//		api_Led_Status_Set(LED_B1,2);
// 		api_Led_Status_Set(LED_B2,1);
// 		api_Control_Motor(0,1);
// 		api_Control_Motor(1,1);
// 		
// 		
// 		if(iiiiiii == 0)
// 		{
// 			api_Send_Signal(1,1);
// 			api_Send_Signal(2,1);
// 			api_Receive_Signal(2,1);
// 			iiiiiii = 1;
// 		}
// 		api_Send_Signal(1,1);
// 		api_UART1_SendData(11,"Drop_Front:");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[1]);
// 		api_UART1_SendData(5,str);
// 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);
// 		
// 		api_UART1_SendData(10,"Drop_Back:");
// 		vTaskDelay(50);
// 		api_ShortToStr(str,mMaininf.mWork.mWorkSensorDataAvl[0]);
// 		api_UART1_SendData(5,str);
// 		//api_UART1_MainBoard_SendCMDData(9,mMaininf.mWork.mWorkSensorDataAvl[9] >> 8,mMaininf.mWork.mWorkSensorDataAvl[9] & 0xff);
// 		vTaskDelay(50);
// 		api_UART1_SendData(2,"\r\n");
// 		vTaskDelay(50);

// 		api_Send_Signal(1,1);
// 		mdata[0] = mMaininf.mWork.mWorkSensorDataAvl[1] >> 8;
// 		mdata[1] = mMaininf.mWork.mWorkSensorDataAvl[1] & 0xff;
// 		api_SendCMD_To_Display(1,mdata[0],mdata[1],1000,3);//前下视
// 		mdata[0] = mMaininf.mWork.mWorkSensorDataAvl[0] >> 8;
// 		mdata[1] = mMaininf.mWork.mWorkSensorDataAvl[0] & 0xff;
// 		api_SendCMD_To_Display(2,mdata[0],mdata[1],1000,3);//后下视

// 		api_Send_Signal(1,1);
		
		
							
		if(mMaininf.mUart1.mReceiveFlag == 1)   //调试
		{
			mMaininf.mUart1.mReceiveFlag = 0;
			//api_UART2_Display_SendCMDData(2,1,1);
 			vTaskDelay(1000);
			mMaininf.mWork.mWorkChecking = 1;
			PAout(12) = 1;
			PAout(15) = 1;
			PEout(1) = 0;
			vTaskDelay(10000);
			api_SendCMD_To_MainBoard(0,1,1,100,1,5);
			mMaininf.mWork.mWorkStep = mMaininf.mUart1.ReceiveBuf[2];
		}
		
		if((mMaininf.mWork.mWorkKeyPressFlag == 1) && (mMaininf.mWork.mWorkChecking == 0))
		{
			mMaininf.mWork.mWorkKeyPressFlag = 0;
			mMaininf.mWork.mWorkKeyPressFlag1 = 0;
			//api_UART2_Display_SendCMDData(2,1,1);
 			vTaskDelay(1000);
			mMaininf.mWork.mWorkChecking = 1;
			mMaininf.mWork.mWorkStep = TEST_START;
			api_Led_Status_Set(LED_ALL,0);
		}
		
		
		if(mMaininf.mWork.mWorkChecking == 1)
		{
			
			if(mMaininf.mWork.mWorkStep != mMaininf.mWork.mWorkStepOld)
			{
				mMaininf.mWork.mWorkStepOld = mMaininf.mWork.mWorkStep;
				
				switch(mMaininf.mWork.mWorkStep)
				{

					case TEST_START :
 						mMaininf.mWork.mWorkStep = TEST_BACK_GUIDE;
						break;
					case TEST_BACK_GUIDE :
						api_Send_Signal(2,1);
						api_Receive_Signal(2,1);
						vTaskDelay(1000);
						//if(api_Check_PWM(GPIOA,GPIO_Pin_11,200,40) == 1)
						if(api_GetGuideFlag(ENUM_GUIDE_BACK) == 1)
						{
							api_Led_Status_Set(LED_B0,1);
						}
						else
						{
							api_Led_Status_Set(LED_B0,2);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
						}
						api_Send_Signal(2,0);
						api_Receive_Signal(2,0);
						mMaininf.mWork.mWorkStep = TEST_BACK_DROP;
						break;
					case TEST_BACK_DROP :
						api_Send_Signal(1,1);
						vTaskDelay(500);
						mMaininf.mWork.mWorkDropDataFar = mMaininf.mWork.mWorkSensorDataAvl[0];
						if(mMaininf.mWork.mWorkDropDataFar < 300)
						{
							api_Control_Motor(1,1);
							vTaskDelay(2000);
							mMaininf.mWork.mWorkDropDataNear = mMaininf.mWork.mWorkSensorDataAvl[0];
							if(mMaininf.mWork.mWorkDropDataNear > 400)
							{
								api_Led_Status_Set(LED_B1,1);
								api_UART2_Display_SendCMDData(1,1,0,mMaininf.mWork.mWorkDropDataFar,mMaininf.mWork.mWorkDropDataNear);
							}
							else
							{
								api_Led_Status_Set(LED_B1,2);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
								api_UART2_Display_SendCMDData(1,1,0,mMaininf.mWork.mWorkDropDataFar,mMaininf.mWork.mWorkDropDataNear);
							}
						}
						else
						{
							api_Led_Status_Set(LED_B1,2);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
							api_UART2_Display_SendCMDData(1,1,0,mMaininf.mWork.mWorkDropDataFar,0);
						}
						api_Send_Signal(1,0);
						api_Control_Motor(1,0);
						mMaininf.mWork.mWorkStep = TEST_FRONT_DROP;
						break;
					case TEST_FRONT_DROP :
						api_Send_Signal(1,1);
						vTaskDelay(500);
						mMaininf.mWork.mWorkDropDataFar = mMaininf.mWork.mWorkSensorDataAvl[1];
						if(mMaininf.mWork.mWorkDropDataFar < 300)
						{
							api_Control_Motor(0,1);
							vTaskDelay(2000);
							mMaininf.mWork.mWorkDropDataNear = mMaininf.mWork.mWorkSensorDataAvl[1];
							if(mMaininf.mWork.mWorkDropDataNear > 400)
							{
								api_Led_Status_Set(LED_B2,1);
								api_UART2_Display_SendCMDData(1,2,0,mMaininf.mWork.mWorkDropDataFar,mMaininf.mWork.mWorkDropDataNear);
							}
							else
							{
								api_Led_Status_Set(LED_B2,2);
								mMaininf.mWork.mWorkCheckErrorFlag = 1;
								api_UART2_Display_SendCMDData(1,2,0,mMaininf.mWork.mWorkDropDataFar,mMaininf.mWork.mWorkDropDataNear);
							}
						}
						else
						{
							api_Led_Status_Set(LED_B2,2);
							mMaininf.mWork.mWorkCheckErrorFlag = 1;
							api_UART2_Display_SendCMDData(1,2,0,mMaininf.mWork.mWorkDropDataFar,0);
						}
						api_Send_Signal(1,0);
						api_Control_Motor(0,0);
						mMaininf.mWork.mWorkStep = TEST_LAST;
						break;
					
					
					case TEST_LAST ://last
//  						mMaininf.mWork.mWorkSensorSendAvoidBumpFlag = 0;
// 						mMaininf.mWork.mWorkSensorSendAlongSideFlag = 0;
						vTaskDelay(100);
						mMaininf.mWork.mWorkCheckStatus = 0;
						mMaininf.mWork.mWorkFileStep = 0;
						mMaininf.mWork.mWorkChecking = 0;
						mMaininf.mWork.mWorkStep = 0;
						mMaininf.mWork.mWorkCheckErrorFlag = 0;
						break;
					default :
						break;
				}
			}
		}
	
	}
}

/*****************************************************************************
 * @name       :void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status, u16 waittime,u8 count)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :send data
 * @parameters :cmd
 * @retvalue   :None
******************************************************************************/
void api_SendCMD_To_Display(u8 mode,u8 cmd,u8 status,u16 dat1,u16 dat2, u16 waittime,u8 count)
{
	u8 mCont = 0;
	u8 mStatus = 0;
	
	do
	{
		if(++mCont > 3)
		{
			return;
		}
		
		api_UART2_Display_SendCMDData(mode,cmd,status,dat1,dat2);
		mMaininf.mSystem.mDisplayStartTime = api_GetCurrentSystemTime();
		
		while(api_GetSystemTimePeriod(mMaininf.mSystem.mDisplayStartTime) < waittime)
		{
			if((mMaininf.mUart2.mReceiveFlag == 1) && (mMaininf.mUart2.ReceiveBuf[0] == mode) && 
				(mMaininf.mUart2.ReceiveBuf[1] == cmd) && (mMaininf.mUart2.ReceiveBuf[2] == 1))
			{
				mStatus = 1;
				break;
			}
		}
		
		mMaininf.mUart2.mReceiveFlag = 0;
	}while(mStatus == 0);
	
}

/*****************************************************************************
 * @name       :void api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime)
 * @date       :2020-09-19 
 * @author     :zhengbaiqiu 
 * @function   :发送命令到主板
 * @parameters :testtype : 0:读取数据   1:检测发射    2:检测接收   waittime:单次检查时间  
				type:类型0：状态  1：数据     num:重发次数
 * @retvalue   :0:主板无数据返回     1：主板有数据返回
******************************************************************************/
u8 api_SendCMD_To_MainBoard(u8 seq,u8 mode,u8 cmd,u16 waittime,u8 type,u8 num)
{
	u8 mCont = 0;
	
	mMaininf.mUart1.ReceiveBuf[4] = 0;
	
	if(type == 0)
	{
		do{
			if(++mCont > num) return 0;//未接收到数据
			api_UART1_MainBoard_SendCMDData(seq,mode,cmd);
			vTaskDelay(waittime);
		}while((mMaininf.mUart1.mReceiveFlag == 0) || ((mMaininf.mUart1.mReceiveFlag == 1) && (mMaininf.mUart1.ReceiveBuf[4] == 0)));
		
	}
	else
	{
		do{
			if(++mCont > num) return 0;//未接收到数据
			api_UART1_MainBoard_SendCMDData(seq,mode,cmd);
			vTaskDelay(waittime);
		}while(mMaininf.mUart1.mReceiveFlag == 0);
		
	}
	
	mMaininf.mUart1.mReceiveFlag = 0;
	
	return 1;//接收到数据
}

