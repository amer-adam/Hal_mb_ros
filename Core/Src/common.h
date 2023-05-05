/*******************************************************************************
 * Title   : common.h
 * Author  : Anas Amer
 * Version : 1.0
 * Date    : 12/10
 *******************************************************************************
 * Description: Sensor and function definitions
 *
 * Version History:
 *  1.0 - converted to hal library
 *
 * Bugs:
 *
 ******************************************************************************/

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

/*********************************************/
/*          Include Header                   */
/*********************************************/
#include "adapter.h"



#define IP1  			HAL_GPIO_ReadPin(IP1_PIN)
#define IP2  			HAL_GPIO_ReadPin(IP2_PIN)
#define IP3  			HAL_GPIO_ReadPin(IP3_PIN)
#define IP4  			HAL_GPIO_ReadPin(IP4_PIN)
#define IP5  			HAL_GPIO_ReadPin(IP5_PIN)
#define IP6 			HAL_GPIO_ReadPin(IP6_PIN)
#define IP7				HAL_GPIO_ReadPin(IP7_PIN)
#define IP8 			HAL_GPIO_ReadPin(IP8_PIN)
#define IP9  			HAL_GPIO_ReadPin(IP9_PIN)
#define IP10  			HAL_GPIO_ReadPin(IP10_PIN)
#define IP11  			HAL_GPIO_ReadPin(IP11_PIN)
#define IP12  			HAL_GPIO_ReadPin(IP12_PIN)
#define IP13  			HAL_GPIO_ReadPin(IP13_PIN)
#define IP14  			HAL_GPIO_ReadPin(IP14_PIN)
#define IP15			HAL_GPIO_ReadPin(IP15_PIN)



//ANALOG PIN//
#define IP16	HAL_GPIO_ReadPin(IP16_Analog1_PIN)
#define IP17	HAL_GPIO_ReadPin(IP17_Analog2_PIN)
#define IP18	HAL_GPIO_ReadPin(IP18_Analog3_PIN)
#define IP19	HAL_GPIO_ReadPin(IP19_Analog4_PIN)
#define IP20	HAL_GPIO_ReadPin(IP20_Analog7_PIN)
#define IP21	HAL_GPIO_ReadPin(IP21_Analog8_PIN)


#define hspm1s2			SR.cast[1].bit7
#define hspm1s1			SR.cast[1].bit6
#define hspm2s2			SR.cast[1].bit5
#define hspm2s1			SR.cast[1].bit4
#define hspm3s2			SR.cast[1].bit3
#define hspm3s1			SR.cast[1].bit2
#define hspm4s2			SR.cast[1].bit1
#define hspm4s1			SR.cast[1].bit0

#define hspm5s2			SR.cast[0].bit7
#define hspm5s1			SR.cast[0].bit6
#define hspm6s2			SR.cast[0].bit5
#define hspm6s1			SR.cast[0].bit4
#define hspm7s2			SR.cast[0].bit3
#define hspm7s1			SR.cast[0].bit2
#define hspm8s2			SR.cast[0].bit1
#define hspm8s1			SR.cast[0].bit0

#define Mux1		 MUX.mux_data.bit0
#define Mux2		 MUX.mux_data.bit1
#define Mux3		 MUX.mux_data.bit2
#define Mux4		 MUX.mux_data.bit3
#define Mux5		 MUX.mux_data.bit4
#define Mux6		 MUX.mux_data.bit5
#define Mux7		 MUX.mux_data.bit6
#define Mux8		 MUX.mux_data.bit7


#define FLASH_SECTOR_BASE_ADDRESS 0x8000000

typedef union{
	uint16_t flags;
	struct{
		unsigned manual   	:1;
		unsigned testingcrv :1;
		unsigned testingstrt:1;
		unsigned flag4	    :1;
		unsigned flag5      :1;
		unsigned flag6	    :1;
		unsigned flag7 	    :1;
		unsigned flag8    	:1;
		unsigned flag9	    :1;
		unsigned flag10		:1;
		unsigned flag11		:1;
		unsigned flag12		:1;
		unsigned flag13		:1;
		unsigned flag14		:1;
		unsigned flag15		:1;
		unsigned flag16		:1;
	};
}sys_t;


typedef union{
	uint16_t flags;
	struct{
		unsigned flag1  	:1;
		unsigned flag2      :1;
		unsigned flag3	    :1;
		unsigned flag4	    :1;
		unsigned flag5      :1;
		unsigned flag6	    :1;
		unsigned flag7      :1;
		unsigned flag8   	:1;
		unsigned flag9		:1;
		unsigned flag10		:1;
		unsigned flag11		:1;
		unsigned flag12		:1;
		unsigned flag13		:1;
		unsigned flag14		:1;
		unsigned flag15		:1;
		unsigned flag16		:1;
	};
}pp_f;



sys_t sys;
pp_f ppflag;
char receive;
float FL,BL,BR,FR,ppx,ppy,ppz;



void RNS_config(CAN_HandleTypeDef* hcanx);
void set(void);
void manual_mode(void);
void Reset(void);
void testing_straight(void);
void testing_curve(void);

#endif /* INC_COMMON_H_ */
