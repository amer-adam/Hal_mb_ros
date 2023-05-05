
/*********************************************/
/*          Include Header                   */
/*********************************************/
#include "i2c.h"


I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
I2C_HandleTypeDef hi2c3;

/**************************************************
 * 		variables							  	  *
 *************************************************/
uint8_t I2C1rxlen, I2C1txlen, I2C1slaveadress, I2C1_direction;
uint8_t I2C2rxlen, I2C2txlen, I2C2slaveadress, I2C2_direction;
uint8_t I2C3rxlen, I2C3txlen, I2C3slaveadress, I2C3_direction;

uint8_t I2C1_Master_Flag, I2C2_Master_Flag, I2C3_Master_Flag;

uint8_t I2C1_master_snd_buf[256], I2C1_master_rcv_buf[256], I2C1_slave_snd_buf[256], I2C1_slave_rcv_buf[256], I2C1_Txlength, I2C1_Rxlength;
uint8_t I2C2_master_snd_buf[256], I2C2_master_rcv_buf[256], I2C2_slave_snd_buf[256], I2C2_slave_rcv_buf[256], I2C2_Txlength, I2C2_Rxlength;
uint8_t I2C3_master_snd_buf[256], I2C3_master_rcv_buf[256], I2C3_slave_snd_buf[256], I2C3_slave_rcv_buf[256], I2C3_Txlength, I2C3_Rxlength;

/************************************************/
/*		 	 	Functions		       		  	*/
/************************************************/
/* Function Name		: I2CxInit
 * Function Description : This function is called to initialise I2C.
 * Function Remarks		:
 * Function Arguments	:
 *
 *						  hi2cx                         Pointer to I2C handle
 * 						  OwnAdress						address of this device
 * 						  ClockSpeed					Speed of transmission can be CLOCK_SPEED_100KHz or CLOCK_SPEED_400KHz
 * 						  InterruptEnable				interrupt enable for I2C can be ENABLE or DISABLE
 * Function Return		: NONE
 * Function Example		: I2CxInit (&hi2c1,main_board_1, CLOCK_SPEED_400KHz,ENABLE);
 */
void I2CxInit(I2C_HandleTypeDef* hi2cx,uint8_t OwnAddress,uint32_t ClockSpeed,int InterruptEnable)
{

	IRQn_Type nvicER;
	IRQn_Type nvicEV;

	if(hi2cx == &hi2c1){
		hi2cx->Instance = I2C1;
		nvicER = I2C1_ER_IRQn;
		nvicEV = I2C1_EV_IRQn;
	}else if(hi2cx == &hi2c2){
		hi2cx->Instance = I2C2;
		nvicER = I2C2_ER_IRQn;
		nvicEV = I2C2_EV_IRQn;
	}else{
		hi2cx->Instance = I2C3;
		nvicER = I2C3_ER_IRQn;
		nvicEV = I2C3_EV_IRQn;
	}

	hi2cx->Init.ClockSpeed = ClockSpeed;
	hi2cx->Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2cx->Init.OwnAddress1 = OwnAddress<<1;
	hi2cx->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2cx->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2cx->Init.OwnAddress2 = 0;
	hi2cx->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2cx->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;



	//if(InterruptEnable){
		/* I2C1_ER_IRQn interrupt configuration */
		HAL_NVIC_SetPriority(nvicER, 0, 0);
		HAL_NVIC_EnableIRQ(nvicER);
		/* I2C1_EV_IRQn interrupt configuration */
		HAL_NVIC_SetPriority(nvicEV, 0, 0);
		HAL_NVIC_EnableIRQ(nvicEV);
	//}


		if (HAL_I2C_Init(hi2cx) != HAL_OK)
		{
			Error_Handler();
		}

}






/*
 * Function Name		: I2CSend
 * Function Description : Send data in the packet defined by the RBC protocol.
 * Function Remarks		: The data pointed by data can be char, int, long, float, struct, union, array, etc.
 * Function Arguments	: hi2cx 		Pointer to I2C handle
 *						  slave_addr 	receiver�s or target�s address
 *						  len 	 		length of data to be sent
 *						  data 			pointer to data to be sent
 * Function Return		: HAL_StatusTypeDef will return the status of transmission.
 * 											can be HAL_OK, HAL_ERROR, HAL_BUSY or HAL_TIMEOUT.
 * Function Example		: float speed = 123.45;
 *						  I2CSend(I2C1, main_board_1, sizeof(speed), &speed);
 */
HAL_StatusTypeDef I2CSend(I2C_HandleTypeDef* hi2cx,uint32_t slave_addr, uint8_t len, const void *data){

	uint8_t master_snd_buf[256];
	uint8_t index = 0;
	uint8_t tmp_len = len;

	while (tmp_len--) {
		master_snd_buf[index++] = *(uint8_t *)data++;
	}

	return HAL_I2C_Master_Transmit(hi2cx,slave_addr, master_snd_buf,len,I2C_LONG_TIMEOUT);
}

/*
 * Function Name		: I2CSendV
 * Function Description : Send data in the packet defined by the RBC protocol.
 * Function Remarks		: The data in the argument list must have the size of a single char.
 * 						  Longer data must be separated into byte-sized argument as input to the function,
 * 						  and its length must correspond to the second parameter len.
 * Function Arguments	: hi2cx 	Pointer to I2C handle
 *						  addr 		receiver�s or target�s address
 *						  len 		length of data to be sent
 *						  ... 		data to be sent
 * Function Return		: HAL_StatusTypeDef will return the status of transmission.
 * 											can be HAL_OK, HAL_ERROR, HAL_BUSY or HAL_TIMEOUT.
 * Function Example		: long output = 0x90ABCDEF;
 *						  I2CSendV (I2C1, main_board_1, sizeof(long),
 *						  (char)(output&0xff), (char)(output >> 8 & 0xff), (char)(output >> 16 & 0xff), (char)(output >> 24 & 0xff));
 */
HAL_StatusTypeDef I2CSendV(I2C_HandleTypeDef *hi2cx, uint8_t slave_addr, uint8_t len, ...){

	uint8_t master_snd_buf[256];
	uint8_t tmp_len = len;
	uint8_t index = 0;
	va_list vdata;

	va_start(vdata, len);
	while (tmp_len--) {
		master_snd_buf[index++] =  (uint8_t)va_arg(vdata, int);
	}
	va_end(vdata);


	return HAL_I2C_Master_Transmit(hi2cx,slave_addr, master_snd_buf, len, I2C_LONG_TIMEOUT);

}




/*
 * Function Name		: I2C1_EV_IRQHandler
 * Function Description : I2C1 event interrupt handler.
 * Function Remarks		: This interrupt handle slave receive mode, master receive mode and slave transmit mode.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C1_EV_IRQHandler(void){

	HAL_I2C_EV_IRQHandler(&hi2c1);

}

/*
 * Function Name		: I2C1_ER_IRQHandler
 * Function Description : I2C1 Error interrupt handler.
 * Function Remarks		: This interrupt handle the error event of I2C1.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C1_ER_IRQHandler(void){

	HAL_I2C_ER_IRQHandler(&hi2c1);

}

/*
 * Function Name		: I2C2_EV_IRQHandler
 * Function Description : I2C2 event interrupt handler.
 * Function Remarks		: This interrupt handle slave receive mode, master receive mode and slave transmit mode.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C2_EV_IRQHandler(void){


	HAL_I2C_EV_IRQHandler(&hi2c2);


}

/*
 * Function Name		: I2C2_ER_IRQHandler
 * Function Description : I2C2 Error interrupt handler.
 * Function Remarks		: This interrupt handle the error event of I2C2.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C2_ER_IRQHandler(void){

	HAL_I2C_ER_IRQHandler(&hi2c2);


}

/*
 * Function Name		: I2C3_EV_IRQHandler
 * Function Description : I2C3 event interrupt handler.
 * Function Remarks		: This interrupt handle slave receive mode, master receive mode and slave transmit mode.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C3_EV_IRQHandler(void){


	HAL_I2C_EV_IRQHandler(&hi2c3);


}

/*
 * Function Name		: I2C3_ER_IRQHandler
 * Function Description : I2C3 Error interrupt handler.
 * Function Remarks		: This interrupt handle the error event of I2C3.
 * Function Arguments	: None
 * Function Return		: None
 * Function Example		: None
 */
void I2C3_ER_IRQHandler(void){

	HAL_I2C_ER_IRQHandler(&hi2c1);

}




