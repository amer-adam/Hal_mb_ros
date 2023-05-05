
/*********************************************/
/*          Include Header                   */
/*********************************************/
#include "uart.h"

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart6;

/*
 * Function Name		: UART1Init
 * Function Description : This function is called to initialize USART1 only.
 * Function Remarks		:
 * Function Arguments	: huartx                ,Pointer to uart handle type
 * 						  baudrate				,normally set to 115200 according to UTM ROBOCON UART COMMUNICATION PROTOCOL.
 * 						  rxstate				,can be ENABLE (enable USART1 receive interrupt) or DISBALE
 * 						  preemptionpriority    ,interrupt with higher preemption priority executed first
 * 						  subpriority			,when 2 interrupts have similar preemption priorities, interrupt with higher
 * 						  						 priority will be executed first. If 2 interrupts have similar preemption
 * 						  						 subpriority, then the one comes first in the program will be executed first.
 * Function Return		: None
 * Function Example		: UARTxInit(&huart1, 115200, ENABLE, 0, 0);
 */
void UARTInit(UART_HandleTypeDef* huartx, uint32_t baudrate, FunctionalState rxstate, uint16_t preemptionpriority,uint16_t subpriority)
{
	IRQn_Type nvic;

	if (huartx == &huart1){
		huartx->Instance = USART1;
		nvic = USART1_IRQn;
	}else if(huartx == &huart2){
		huartx->Instance = USART2;
		nvic = USART2_IRQn;
	}else if(huartx == &huart3){
		huartx->Instance = USART3;
		nvic = USART3_IRQn;
	}else if(huartx == &huart4){
		huartx->Instance = UART4;
		nvic = UART4_IRQn;
	}else if(huartx == &huart5){
		huartx->Instance = UART5;
		nvic = UART5_IRQn;
	}else{
		huartx->Instance = USART6;
		nvic = USART6_IRQn;
	}


	huartx->Init.BaudRate = baudrate;
	huartx->Init.WordLength = UART_WORDLENGTH_8B;
	huartx->Init.StopBits = UART_STOPBITS_1;
	huartx->Init.Parity = UART_PARITY_NONE;
	huartx->Init.Mode = UART_MODE_TX_RX;
	huartx->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huartx->Init.OverSampling = UART_OVERSAMPLING_16;



	if (HAL_UART_Init(huartx) != HAL_OK)
	{
		Error_Handler();
	}

	if(rxstate == ENABLE){
    HAL_NVIC_SetPriority(nvic, preemptionpriority, subpriority);
    HAL_NVIC_EnableIRQ(nvic);
    __HAL_UART_ENABLE_IT(huartx, UART_IT_RXNE);
	}



}

/*
 * Function Name		: UARTPrintString
 * Function Description : This function is called to print string to desired huartx, x can be 1 to 6.
 * Function Remarks		: None
 * Function Arguments	: huartx	,x can be 1 to 6.
 * 						  s			,buffer or string
 * Function Return		: None
 * Function Example		: UARTPrintString(huart4, buffer);
 */
void UARTPrintString(UART_HandleTypeDef* huartx, char s[])
{
	HAL_UART_Transmit(huartx, (uint8_t *)s, strlen(s), 10);
}




