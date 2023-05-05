/*******************************************************************************
 * Title   : adapter.h
 * Author  : Anas Amer
 * Version : 1.0
 * Date    : 12/10
 *******************************************************************************
 * Description: includes all the important includes and pin definitions
 *
 * Version History:
 *  1.0 - converted to HAL library
 *
 * Bugs:
 *
 ******************************************************************************/

#ifndef SRC_ADAPTER_H_
#define SRC_ADAPTER_H_


/* Private variables ---------------------------------------------------------*/


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "BIOS/bios.h"
#include <math.h>
#include "CAN/can.h"
#include "MODN/MODN.h"
#include "PID/PID.h"
#include "ABT/ABT.h"
#include "I2C/i2c.h"
#include "SPI/SPI.h"
#include "PSx_Interface/PSx_Interface.h"
#include "RNS_interface/RNS_interface.h"
#include <ADC/adc.h>
#include "SERVO/servo.h"
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/


/* Private defines -----------------------------------------------------------*/
#define LED1_PIN			GPIOC, GPIO_PIN_13
#define LED2_PIN			GPIOC, GPIO_PIN_14
#define LED3_PIN			GPIOC, GPIO_PIN_15

#define PB1_PIN				GPIOB, GPIO_PIN_7
#define PB2_PIN				GPIOE, GPIO_PIN_0

#define IP1_PIN				GPIOE, GPIO_PIN_12
#define IP2_PIN				GPIOE, GPIO_PIN_13
#define IP3_PIN				GPIOE, GPIO_PIN_14
#define IP4_PIN				GPIOE, GPIO_PIN_15
#define IP5_PIN				GPIOB, GPIO_PIN_14
#define IP6_PIN				GPIOB, GPIO_PIN_15
#define IP7_PIN				GPIOD, GPIO_PIN_10
#define IP8_PIN				GPIOD, GPIO_PIN_11
#define IP9_PIN				GPIOC, GPIO_PIN_8
#define IP10_PIN			GPIOA, GPIO_PIN_10
#define IP11_PIN			GPIOD, GPIO_PIN_3
#define IP12_PIN			GPIOD, GPIO_PIN_4
#define IP13_PIN			GPIOD, GPIO_PIN_7
#define IP14_PIN			GPIOB, GPIO_PIN_5
#define IP15_PIN			GPIOB, GPIO_PIN_6

#define IP16_Analog1_PIN	GPIOC, GPIO_PIN_0
#define IP17_Analog2_PIN	GPIOC, GPIO_PIN_1
#define IP18_Analog3_PIN	GPIOC, GPIO_PIN_2
#define IP19_Analog4_PIN	GPIOC, GPIO_PIN_3
#define IP20_Analog7_PIN	GPIOC, GPIO_PIN_4
#define IP21_Analog8_PIN	GPIOC, GPIO_PIN_5


#define QEI1_PLUSEA_PIN		GPIOE , GPIO_PIN_9
#define QEI1_PLUSEB_PIN		GPIOE , GPIO_PIN_11

#define QEI2_PLUSEA_PIN		GPIOA , GPIO_PIN_5
#define QEI2_PLUSEB_PIN		GPIOB , GPIO_PIN_3

#define QEI3_PLUSEA_PIN		GPIOA , GPIO_PIN_6
#define QEI3_PLUSEB_PIN		GPIOA , GPIO_PIN_7

#define QEI4_PLUSEA_PIN		GPIOD , GPIO_PIN_12
#define QEI4_PLUSEB_PIN		GPIOD , GPIO_PIN_13

#define QEI5_PLUSEA_PIN		GPIOA , GPIO_PIN_0
#define QEI5_PLUSEB_PIN		GPIOA , GPIO_PIN_1

#define QEI6_PLUSEA_PIN		GPIOC , GPIO_PIN_6
#define QEI6_PLUSEB_PIN		GPIOC , GPIO_PIN_7

#define TIM5_CHANNEL1_PIN	GPIOA, GPIO_PIN_0
#define TIM5_CHANNEL2_PIN	GPIOA, GPIO_PIN_1
#define TIM5_CHANNEL3_PIN	GPIOA, GPIO_PIN_2
#define TIM5_CHANNEL4_PIN	GPIOA, GPIO_PIN_3

#define TIM9_CHANNEL1_PIN	GPIOE, GPIO_PIN_5
#define TIM9_CHANNEL2_PIN	GPIOE, GPIO_PIN_6

#define TIM3_ChANNEL1_PIN   GPIOA, GPIO_PIN_6
#define TIM3_CHANNEL3_PIN	GPIOB, GPIO_PIN_0
#define TIM3_CHANNEL4_PIN	GPIOB, GPIO_PIN_1


#define MUX1_INPUT_PIN 		GPIOE , GPIO_PIN_1
#define MUX1_S0_PIN 		GPIOE , GPIO_PIN_2
#define MUX1_S1_PIN 		GPIOE , GPIO_PIN_3
#define MUX1_S2_PIN 		GPIOE , GPIO_PIN_4

#define SR_SCK_PIN			GPIOE , GPIO_PIN_7
#define SR_RCK_PIN			GPIOE , GPIO_PIN_8
#define SR_SI_PIN			GPIOE , GPIO_PIN_10


extern MUX_t MUX;
extern shiftreg_t SR;
extern RNS_interface_t rns;
extern BDC_t BDC1, BDC2, BDC3, BDC4, BDC5, BDC6, BDC7, BDC8;
extern uint8_t insData_receive[2];
extern PSxBT_t ps4;
extern MODN_t Modn;
extern ABT_t filter;
extern PID_t Pid;
extern ADC_t adc;



#define PB1 		GPIOB_IN->bit7
#define PB2 		GPIOE_IN->bit0

#define led1		GPIOC_OUT->bit13
#define led2		GPIOC_OUT->bit14
#define led3		GPIOC_OUT->bit15

//Global Declarations
extern float v1, v2, v3, v4, wa, xr, yr;                 //MODN variables
extern float xpos, ypos, z;                              //Encoder Values
extern char rcv;
extern int flag;
extern volatile uint16_t  adc1_buf[7];
extern volatile uint16_t  adc2_buf[7];
extern volatile uint16_t  adc3_buf[7];



extern int manual, autoflag;


extern int counter;                                      //global timer variable
extern float speed;                                      //for manual control
extern float laser_dist_f;
extern float laser_dist_l;
extern float L_laser,F_laser;


void CAN_PROCESS(void);
void Initialize (void);
void slave_rcv(unsigned char length, unsigned char *pdata);
void PS4Connect(PSxBT_t* ps4,I2C_HandleTypeDef* hi2cx);
void MX_GPIO_Init(void);



#ifdef __cplusplus
}
#endif
#endif /* SRC_ADAPTER_H_ */
