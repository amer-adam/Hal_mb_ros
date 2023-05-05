
/*********************************************/
/*          Include Header                   */
/*********************************************/
#include <adapter.h>
#include "interrupt.h"
/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
#define USED_QEI1
#define USED_QEI2
#define USED_QEI3
#define USED_QEI4
#define USED_QEI5
#define USED_QEI6

int count = 0;
int count2 = 0;
int count3 = 0;
//int _counter=0;
/**
 * * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{

}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{


}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{

}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{


}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{

}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{

}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{

}

/**
  * @brief This function handles System tick timer.
//  */
void SysTick_Handler(void)
{

  HAL_IncTick();
  MUXUpdate(&MUX);
  SHIFTREGShift(&SR);
  _counter++;

}


void TIM1_UP_TIM10_IRQHandler(void)
{
#ifdef USED_QEI1
	if (htim1.Instance -> CR1 == 129)
		{
			BIOS_QEI1.signbit += 1;
		}
	else if (htim1.Instance ->CR1 == 145)
	{
		BIOS_QEI1.signbit -= 1;
	}
	htim1.Instance -> SR = 0;
	QEIDelay(200);
#else
	HAL_TIM_IRQHandler(&htim1);
#endif
	HAL_TIM_IRQHandler(&htim10);
   return;
}


void TIM2_IRQHandler(void)
{
#ifdef USED_QEI2
	if (htim2.Instance -> CR1 == 129)
	{
		BIOS_QEI2.signbit += 1;
	}
	else if (htim2.Instance ->CR1 == 145)
	{
		BIOS_QEI2.signbit -= 1;
	}
	htim2.Instance -> SR = 0;
	QEIDelay(100);
#else
	 HAL_TIM_IRQHandler(&htim2);
   return;
#endif
}


void TIM3_IRQHandler(void)
{
#ifdef USED_QEI3
	if (htim3.Instance -> CR1 == 129)
	{
		BIOS_QEI3.signbit += 1;
	}
	else if (htim3.Instance ->CR1 == 145)
	{
		BIOS_QEI3.signbit -= 1;
	}
	htim3.Instance -> SR = 0;
	QEIDelay(100);
#else
	 HAL_TIM_IRQHandler(&htim3);
   return;
#endif
}

void TIM4_IRQHandler(void)
{
#ifdef USED_QEI4
  if (htim4.Instance -> CR1 == 129)
  {
		BIOS_QEI4.signbit += 1;
  }
  else if (htim4.Instance ->CR1 == 145)
  {
		BIOS_QEI4.signbit -= 1;
  }
  htim4.Instance -> SR = 0;
  QEIDelay(100);
#else
      HAL_TIM_IRQHandler(&htim4);
   return;
#endif
}

void TIM5_IRQHandler(void)
{
#ifdef USED_QEI5
   if (htim5.Instance -> CR1 == 129)
	  {
			BIOS_QEI5.signbit += 1;
	  }
	  else if (htim5.Instance ->CR1 == 145)
	  {
			BIOS_QEI5.signbit -= 1;
	  }
	  htim5.Instance -> SR = 0;
	  QEIDelay(100);
#else
	  HAL_TIM_IRQHandler(&htim5);
   return;
#endif
}

void TIM8_UP_TIM13_IRQHandler(void)
{
#ifdef USED_QEI6
	if (htim8.Instance -> CR1 == 129)
	{
		BIOS_QEI6.signbit += 1;
	}
	else if (htim8.Instance ->CR1 == 145)
	{
		BIOS_QEI6.signbit -= 1;
	}
	htim8.Instance -> SR = 0;
	QEIDelay(200);
#else
	HAL_TIM_IRQHandler(&htim8);
#endif
	HAL_TIM_IRQHandler(&htim8);
}


//Callback for I2C RXBuffer
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
//	 PSxConnect(&ps4);
}

//Callback for ADC Buffer
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

}

/*
 * Function Name		: DMA2_Stream2_IRQHandler
 * Function Description : DMA2_Stream2 event interrupt handler.
 * Function Remarks		: None
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void DMA2_Stream2_IRQHandler(void)
{

//	HAL_DMA_IRQHandler(&hdma_adc1);

}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
