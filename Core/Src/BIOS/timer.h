/************************************************
 * Title   : Timer
 * Author  : Anas Amer
 * Version : 1.0
 * Date    : 10/12/2020
 * **********************************************
 * Descriptions: Initialize timers
 *
 *
 * Version History:
 * 1.0 - implemented using hal library
 *
 * Bugs:
 *
 ************************************************/
#ifndef BIOS_TIMER_H_
#define BIOS_TIMER_H_
#ifdef __cplusplus
extern "C" {
#endif
/***************************************
 * 		Include Libraries 			   *
 **************************************/
#include "system.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim9;
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim12;
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;
/**************************************************
 * 		Function Prototype			  			  *
 *************************************************/
void TIMxInit(TIM_HandleTypeDef* htimx, uint16_t period, uint16_t prescaler,uint16_t preemptionpriority,uint16_t subpriority);
void BIOSTIMx_Delayus(TIM_HandleTypeDef* htimx, uint16_t Delayus);

#ifdef __cplusplus
}
#endif
#endif /* BIOS_TIMER_H_ */
