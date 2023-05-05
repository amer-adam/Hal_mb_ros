/************************************************
 * Title   : UART
 * Author  : Anas Amer
 * Version : 1.0
 * Date    : 10/12/2020
 * **********************************************
 * Descriptions: Send and receive data using UART
 *
 *
 * Version History:
 * 1.0 - implemented using hal library
 *
 * Bugs:
 *
 ************************************************/

#ifndef BIOS_UART_H_
#define BIOS_UART_H_

#ifdef __cplusplus
extern "C" {
#endif
/***************************************
 * 		Include Libraries 			   *
 **************************************/
#include "system.h"

/**************************************************
 * 		STRUCTURE DEFINES					  	  *
 *************************************************/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;


/**************************************************
 * 		Function Prototype					  	  *
 *************************************************/
void UARTInit(UART_HandleTypeDef* huartx, uint32_t baudrate, FunctionalState rxstate, uint16_t preemptionpriority,uint16_t subpriority);
void UARTPrintString(UART_HandleTypeDef* huartx, char s[]);
char ReadUART(UART_HandleTypeDef* huartx);

#ifdef __cplusplus
}
#endif

#endif /* BIOS_UART_H_ */
