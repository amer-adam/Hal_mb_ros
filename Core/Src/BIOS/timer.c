/*********************************************/
/*          Include Header                   */
/*********************************************/
#include "timer.h"

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim8;
TIM_HandleTypeDef htim9;
TIM_HandleTypeDef htim10;
TIM_HandleTypeDef htim11;
TIM_HandleTypeDef htim12;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim14;
/************************************************/
/*		 	 	Functions		       		  	*/
/************************************************/

/*
 * Function Name		: BIOSTIMx_Init
 * Function Description : This function is called to configure the TIMx's interrupt duration.
 * Function Remarks		: TIM2 - TIM7 & TIM 12 - 14 -> Tclk = 84Mhz
 * 						  TIM1, TIM8, TIM9, TIM10, TIM11 -> Tclk = 168MHz
 *
 * 						  ***************TO FIND Tout********************
 *
 * 						     Tout = ((period)*(prescaler))/Tclk
 *
 * 						  ***********************************************
 *
 * Function Arguments	: htimx					htimx can be TIM1 to TIM14
 * 						  period				period value (1 to 65535)
 * 						  prescaler 			prescaler value to divide TIM clock (1 to 65535)
 * 						  preemptionpriority    interrupt with higher preemption priority executed first
 * 						  subpriority			when 2 interrupts have similar preemption priorities, interrupt with higher
 * 						  						priority will be executed first. If 2 interrupts have similar preemption
 * 						  						subpriority, then the one comes first in the program will be executed first.
 * Function Return		: None
 * Function Example		: BIOSTIMx_Init (&htim1, 1000, 168, 1, 0); //1ms  interrupt
 * 						  BIOSTIMx_Init (&htim2, 1000, 84, 2, 0);  //1ms  interrupt
 * 						  BIOSTIMx_Init (&htim3, 20000, 84, 2, 1); //20ms interrupt
 */

void TIMxInit(TIM_HandleTypeDef* htimx, uint16_t period, uint16_t prescaler,uint16_t preemptionpriority,uint16_t subpriority)
{

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  int nvic = 0;

  if(htimx == &htim1){
  		htimx->Instance = TIM1;
  		nvic = TIM1_UP_TIM10_IRQn;
  	}
  	else if(htimx == &htim2)	{
  		htimx->Instance = TIM2;
  		nvic = TIM2_IRQn;
  	}
  	else if(htimx == &htim3)	{
  		htimx->Instance = TIM3;
  		nvic = TIM3_IRQn;
  	}
  	else if(htimx == &htim4)	{
  		htimx->Instance = TIM4;
  		nvic = TIM4_IRQn;
  	}
  	else if(htimx == &htim5)	{
  		htimx->Instance = TIM5;
  		nvic = UART5_IRQn;
  	}
  	else if(htimx == &htim6)	{
  		htimx->Instance = TIM6;
  		nvic = TIM6_DAC_IRQn;
  	}
  	else if(htimx == &htim7)	{
  		htimx->Instance = TIM7;
  		nvic = TIM7_IRQn;
  	}
  	else if(htimx == &htim8)	{
  		htimx->Instance = TIM8;
  		nvic = TIM8_CC_IRQn;
  	}
  	else if(htimx == &htim9)	{
  		htimx->Instance = TIM9;
  		nvic = TIM1_BRK_TIM9_IRQn;
  	}
  	else if(htimx == &htim10)	{
  		htimx->Instance = TIM10;
  		nvic = TIM1_UP_TIM10_IRQn;
  	}
  	else if(htimx == &htim11)	{
  		htimx->Instance = TIM11;
  		nvic = TIM1_TRG_COM_TIM11_IRQn;
  	}
  	else if(htimx == &htim12)	{
  		htimx->Instance = TIM12;
  		nvic = TIM8_BRK_TIM12_IRQn;
  	}
  	else if(htimx == &htim13)	{
  		htimx->Instance = TIM13;
  		nvic = TIM8_UP_TIM13_IRQn;
  		}
  	else if(htimx == &htim14)	{
  		htimx->Instance = TIM14;
  		nvic = TIM8_TRG_COM_TIM14_IRQn;
  		}


  htimx->Init.Prescaler = prescaler;
  htimx->Init.CounterMode = TIM_COUNTERMODE_UP;
  htimx->Init.Period = period;
  htimx->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(htimx) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(htimx, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }


  HAL_NVIC_SetPriority(nvic, preemptionpriority, subpriority);
  HAL_NVIC_EnableIRQ(nvic);

  HAL_TIM_Base_Start(htimx);
  HAL_TIM_Base_Start_IT(htimx);

}



/*
 * Function Name		: BIOSTIMx_Delayus
 * Function Description : Delay using timer to produce a delay in microseconds
 * Function Remarks		: More accurate than BIOSDelay() and BIOSDelayLoop()
 * 						  htimx				htimx can be TIM1 to TIM14
 * 						  					Take note than TIM2 and TIM15 are 32 bits Timer,
 * 						  					can produces longer delay.
 * Function Arguments	: Delayus 			time length of delay in microseconds (1 to 65535)
 * Function Return		: None
 * Function Example		: BIOSTIMx_Delayus (hitm2, 2); //Delay 2us
 */

void BIOSTIMx_Delayus(TIM_HandleTypeDef* htimx, uint16_t Delayus)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
    uint16_t  TIMCounter = Delayus;


    if(htimx == &htim1){
      		htimx->Instance = TIM1;
      	  htimx->Init.Prescaler = 168;
      	}
      	else if(htimx == &htim2)	{
      		htimx->Instance = TIM2;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim3)	{
      		htimx->Instance = TIM3;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim4)	{
      		htimx->Instance = TIM4;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim5)	{
      		htimx->Instance = TIM5;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim6)	{
      		htimx->Instance = TIM6;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim7)	{
      		htimx->Instance = TIM7;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim8)	{
      		htimx->Instance = TIM8;
      		 htimx->Init.Prescaler = 168;
      	}
      	else if(htimx == &htim9)	{
      		htimx->Instance = TIM9;
      		 htimx->Init.Prescaler = 168;
      	}
      	else if(htimx == &htim10)	{
      		htimx->Instance = TIM10;
      		 htimx->Init.Prescaler = 168;
      	}
      	else if(htimx == &htim11)	{
      		htimx->Instance = TIM11;
      		 htimx->Init.Prescaler = 168;
      	}
      	else if(htimx == &htim12)	{
      		htimx->Instance = TIM12;
      		 htimx->Init.Prescaler = 84;
      	}
      	else if(htimx == &htim13)	{
      		htimx->Instance = TIM13;
      		 htimx->Init.Prescaler = 84;
      		}
      	else if(htimx == &htim14)	{
      		htimx->Instance = TIM14;
      		 htimx->Init.Prescaler = 84;
      		}

      htimx->Init.CounterMode = TIM_COUNTERMODE_UP;
      htimx->Init.Period = 20000;
      htimx->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
      if (HAL_TIM_Base_Init(htimx) != HAL_OK)
      {
        Error_Handler();
      }
      sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
      sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
      if (HAL_TIMEx_MasterConfigSynchronization(htimx, &sMasterConfig) != HAL_OK)
      {
        Error_Handler();
      }

    __HAL_TIM_SetCounter(htimx,65535 - TIMCounter );

	while (TIMCounter < 65535)
	{
		TIMCounter = __HAL_TIM_GetCounter(htimx);
	}
	HAL_TIM_Base_DeInit(htimx);
}


