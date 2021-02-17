/****************************************************************************************************/
/*			@FileName		:	apiLib.h																																    	*/
/*			@Author			:	zhengbaiqiu																																		*/
/*			@Version		:	v1.0																																					*/
/*			@Date				:	2019.11.12  																																	*/
/****************************************************************************************************/

#ifndef	__APILIB_H__
#define	__APILIB_H__
#include "stm32f10x.h"
//#include <stdint.h>
#include "gpioredef.h"

#ifdef __cplusplus
extern "C" {
#endif

// #include "ff.h"	
// #include "diskio.h"
#include "maindef.h"

	

	
u32 api_GetSystemTimePeriod(u32 StartTime);
u32 api_GetCurrentSystemTime(void);
void api_UART1_SendData(u16 vCont, u8 *pData);
void api_UART1_MainBoard_SendCMDData(u8 seq,u8 mode,u8 cmd);
void api_UART1_ReceiveData(u8 vData);
void api_UART4_DEBUG_SendCMDData(u8 seq,u8 mode,u8 cmd);
void api_UART4_ReceiveData(u8 vData);
void api_UART2_Display_SendCMDData(u8 mode,u8 cmd,u8 status,u16 dat1,u16 dat2);
void api_UART2_ReceiveData(u8 vData);
void api_MachinePowerOn(void);
u8 api_ReadGpioInputStauts(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,u8 Val,uint8_t Cont);
u8 api_Check_PWM(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,u8 cycle,u8 differ);
u8 api_Test_ADC(__IO uint16_t *adcval,uint16_t detectval,uint16_t diffval);
void api_Send_Signal(u8 mCmd,u8 OpenFlag);
void api_Receive_Signal(u8 mCmd,u8 OpenFlag);
void api_Control_Motor(u8 mCmd,u8 OpenFlag);
void api_Led_Status_Set(u8 led,u8 status);
void api_Led_Control(u8 Led,u8 OpenFlag);
void api_Guide_Send(u8 mStatus);
u8 api_GetAnalyzePeriod(u8 mValue,u8 ParamMin,u8 ParamMax);
void api_GetAnalyzeGuideSignal(enum_GUIDE eGuide);
void api_JudgeGuideSignal(enum_GUIDE eGuide);
u8 api_GetGuideFlag(enum_GUIDE eGuide);
void api_ShortToStr(u8* str,u16 data);

	
#ifdef _cplusplus
extern }
#endif

#endif /*__APILIB_H__*/	

