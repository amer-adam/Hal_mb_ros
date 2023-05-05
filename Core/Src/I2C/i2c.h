/************************************************
 * Title   : I2C
 * Author  : Anas Amer
 * Version : 1.0
 * Date    : 10/12/2020
 * **********************************************
 * Descriptions: Send and receive data using I2C
 *
 *
 * Version History:
 * 1.0 - implemented using hal library and changed to callback instead of interrupt
 *
 * Bugs:
 *
 ************************************************/

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

/***************************************
 * 		Include Libraries 			   *
 **************************************/






#include "../BIOS/bios.h"




/**************************************************
 * 		DEFINES								  	  *
 *************************************************/

#define CLOCK_SPEED_100KHz	100000
#define CLOCK_SPEED_400KHz	400000

#define main_board_1						8
#define main_board_2						9
#define main_board_3						10
#define main_board_4						11
#define motor_control_module_1				16
#define motor_control_module_2				17
#define motor_control_module_3				18
#define motor_control_module_4				19
#define robot_navi_system					30

#define I2C_SHORT_TIMEOUT            		((uint32_t)0x10000)
#define I2C_LONG_TIMEOUT             		((uint32_t)(350000 * I2C_SHORT_TIMEOUT))


extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c3;



/**************************************************
 * 		variables							  	  *
 *************************************************/
extern uint8_t I2C1rxlen, I2C1txlen, I2C1slaveadress, I2C1_direction;
extern uint8_t I2C2rxlen, I2C2txlen, I2C2slaveadress, I2C2_direction;
extern uint8_t I2C3rxlen, I2C3txlen, I2C3slaveadress, I2C3_direction;

extern uint8_t I2C1_Master_Flag, I2C2_Master_Flag, I2C3_Master_Flag;

extern uint8_t I2C1_master_snd_buf[256], I2C1_master_rcv_buf[256], I2C1_slave_snd_buf[256], I2C1_slave_rcv_buf[256], I2C1_Txlength, I2C1_Rxlength;
extern uint8_t I2C2_master_snd_buf[256], I2C2_master_rcv_buf[256], I2C2_slave_snd_buf[256], I2C2_slave_rcv_buf[256], I2C2_Txlength, I2C2_Rxlength;
extern uint8_t I2C3_master_snd_buf[256], I2C3_master_rcv_buf[256], I2C3_slave_snd_buf[256], I2C3_slave_rcv_buf[256], I2C3_Txlength, I2C3_Rxlength;


/**************************************************
 * 		Function Prototype			  			  *
 *************************************************/
/*MASTER MODE*/


/*ROBOCON UTM I2C PROTOCOL*/
HAL_StatusTypeDef I2CSend(I2C_HandleTypeDef *hi2cx, uint32_t slave_addr, uint8_t len, const void *data);

/*I2C PERIPHERAL INITIALIZE*/
void I2CxInit(I2C_HandleTypeDef* hi2cx,uint8_t OwnAddress,uint32_t ClockSpeed,int InterruptEnable);



#endif /* I2C_I2C_H_ */
