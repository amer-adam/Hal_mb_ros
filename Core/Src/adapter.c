

/*********************************************/
/*          Include Header                   */
/*********************************************/
#include <adapter.h>


char uartbuff[500];
uint8_t mailbox = 0, buf2_flag = 0, buf2_flagC2 = 0;

MUX_t MUX;
shiftreg_t SR;
RNS_interface_t rns;
BDC_t BDC1, BDC2, BDC3, BDC4, BDC5, BDC6, BDC7, BDC8;
uint8_t insData_receive[2];
PSxBT_t ps4;
MODN_t Modn;
ABT_t filter;
PID_t Pid;
ADC_t adc;



float v1, v2, v3, v4, wa, xr, yr;                 //MODN variables
float xpos, ypos, z;                              //Encoder Values
char rcv;
int flag;
volatile uint16_t  adc1_buf[7];
volatile uint16_t  adc2_buf[7];
volatile uint16_t  adc3_buf[7];

union{
	float data;
	struct{
		char byte1;
		char byte2;
		char byte3;
		char byte4;
	};
}buf1_receive[2];
union{
	float data;
	struct{
		char byte1;
		char byte2;
		char byte3;
		char byte4;
	};
}buf2_receive[2];

int manual, autoflag;


int counter;                                      //global timer variable
float speed;                                      //for manual control
float laser_dist_f;
float laser_dist_l;
float L_laser,F_laser;

/************************************************/
/*		 	 	Functions		       		  	*/
/************************************************/
void Initialize(){
	/* MCU Configuration--------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */

	GPIOPinsInit (LED1_PIN, GPIO_MODE_OUTPUT_PP,GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP);
	GPIOPinsInit (LED2_PIN, GPIO_MODE_OUTPUT_PP,GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP);
	GPIOPinsInit (LED3_PIN, GPIO_MODE_OUTPUT_PP,GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP);

	GPIOPinsInit (PB1_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP);
	GPIOPinsInit (PB2_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP);

	//	/*Normal IOs*/
	GPIOPinsInit (IP1_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP2_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP3_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP4_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP5_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP6_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP7_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP8_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP9_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP10_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP11_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP12_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP13_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP14_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP15_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);

	/*IOs with ADC*/
	//	GPIOPinsInit (IP16_Analog3_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_NOPULL);
	//	GPIOPinsInit (IP16_Analog3_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_NOPULL);
	GPIOPinsInit (IP18_Analog3_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP19_Analog4_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP20_Analog7_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	GPIOPinsInit (IP21_Analog8_PIN, GPIO_MODE_INPUT,GPIO_SPEED_FREQ_MEDIUM, GPIO_PULLUP);
	//
	MUXInit(&MUX, MUX1_INPUT_PIN, MUX1_S0_PIN, MUX1_S1_PIN, MUX1_S2_PIN);
	SHIFTREGInit (&SR, CASCADE_1, SR_SCK_PIN, SR_RCK_PIN, SR_SI_PIN);
	//
//	I2CxInit (&hi2c1,main_board_1, CLOCK_SPEED_400KHz,ENABLE);
	//		I2CxInit (&hi2c2,main_board_1, CLOCK_SPEED_400KHz,DISABLE);
	//		I2CxInit (&hi2c3,main_board_1, CLOCK_SPEED_400KHz,DISABLE);


	//
//	CANxInit(&hcan1,4,CAN_FILTER_FIFO0,0,0,13,0,0);
	//		CANxInit(&hcan2,4,CAN_FILTER_FIFO1,0,0,27,1,2);
	//
	UARTInit(&huart2,115200, ENABLE, 0,0);
//	UARTInit(&huart3,115200, DISABLE, 0,0);
//	UARTInit(&huart4,115200, DISABLE, 0,0);
//	UARTInit(&huart5,115200, DISABLE, 0,0);

	//
//	QEIInit(&htim1,5,5);
	//		QEIInit(&htim4,5,5);
	//		QEIInit(&htim8,5,5);

	PWMTimeBaseInit(&htim3, 20000, 84);//50Hz PWM
	PWMChannelConfig(&htim3, TIM_CHANNEL_3, TIM3_CHANNEL3_PIN);
	PWMChannelConfig(&htim3, TIM_CHANNEL_4 , TIM3_CHANNEL4_PIN);

	PWMTimeBaseInit(&htim5, 20000, 84);//50Hz
	PWMChannelConfig(&htim5, TIM_CHANNEL_1, TIM5_CHANNEL1_PIN);
	PWMChannelConfig(&htim5, TIM_CHANNEL_2, TIM5_CHANNEL2_PIN);
	PWMChannelConfig(&htim5, TIM_CHANNEL_3, TIM5_CHANNEL3_PIN);
	PWMChannelConfig(&htim5, TIM_CHANNEL_4, TIM5_CHANNEL4_PIN);

	PWMTimeBaseInit(&htim9, 20000, 168);//50Hz PWM
	PWMChannelConfig(&htim9, TIM_CHANNEL_1, TIM9_CHANNEL1_PIN);
	PWMChannelConfig(&htim9, TIM_CHANNEL_2, TIM9_CHANNEL2_PIN);

	BDCInit(&BDC1, &htim3, TIM_CHANNEL_4, SHIFTREG, &(SR.cast[1]), Bit6, Bit7);
	BDCInit(&BDC2, &htim3, TIM_CHANNEL_3, SHIFTREG, &(SR.cast[1]), Bit4, Bit5);
	BDCInit(&BDC3, &htim9, TIM_CHANNEL_1, SHIFTREG, &(SR.cast[1]), Bit2, Bit3);
	BDCInit(&BDC4, &htim9, TIM_CHANNEL_2, SHIFTREG, &(SR.cast[1]), Bit0, Bit1);
	BDCInit(&BDC5, &htim5, TIM_CHANNEL_4, SHIFTREG, &(SR.cast[0]), Bit6, Bit7);
	BDCInit(&BDC6, &htim5, TIM_CHANNEL_3, SHIFTREG, &(SR.cast[0]), Bit4, Bit5);
	BDCInit(&BDC7, &htim5, TIM_CHANNEL_2, SHIFTREG, &(SR.cast[0]), Bit2, Bit3);
	BDCInit(&BDC8, &htim5, TIM_CHANNEL_1, SHIFTREG, &(SR.cast[0]), Bit0, Bit1);

	ADC_DMAxInit(&adc,&hadc1,&hdma_adc1,2,1,2);
	ADC_Channel_Config(&adc,ADC_CHANNEL_10,IP16_Analog1_PIN);
	ADC_Channel_Config(&adc,ADC_CHANNEL_11,IP17_Analog2_PIN);
	ADC_Channel_Config(&adc,ADC_CHANNEL_12,IP18_Analog3_PIN);
	ADC_Channel_Config(&adc,ADC_CHANNEL_13,IP19_Analog4_PIN);
	ADC_Channel_Config(&adc,ADC_CHANNEL_14,IP20_Analog7_PIN);
	ADC_Channel_Config(&adc,ADC_CHANNEL_15,IP21_Analog8_PIN);




}



void CAN1_RX0_IRQHandler()
{

	HAL_CAN_IRQHandler(&hcan1);

}

void CAN2_RX1_IRQHandler()
{

	HAL_CAN_IRQHandler(&hcan2);

}

void CAN_PROCESS(void){
	if(insData_receive[0] == 1){
		rns.RNS_data.common_instruction = insData_receive[1];
		insData_receive[0]=2;
	}
	if(insData_receive[0] == 17){
		if(buf2_flag == 1){
			rns.RNS_data.common_instruction = insData_receive[1];
			rns.RNS_data.common_buffer[0].data = buf1_receive[0].data;
			rns.RNS_data.common_buffer[1].data = buf1_receive[1].data;
			rns.RNS_data.common_buffer[2].data = buf2_receive[0].data;
			rns.RNS_data.common_buffer[3].data = buf2_receive[1].data;
			insData_receive[0]=3;
		}
	}
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)

{
	uint8_t aData[8];

	if(hcan == &hcan1){
		HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0 , &CAN1RxMessage, aData);
		//	sprintf(data,"%d %d %d %d %d %d %d %d \r\n",aData[0],aData[1],aData[2],aData[3],aData[4],aData[5],aData[6],aData[7]);
		switch(CAN1RxMessage.StdId){
		case RNS_TO_mainboard:
			memcpy(&insData_receive, &aData, CAN1RxMessage.DLC);
			buf2_flag = 0;

			break;
		case RNS_TO_mainboard_buf1:
			memcpy(&buf1_receive, &aData, CAN1RxMessage.DLC);

			break;
		case RNS_TO_mainboard_buf2:
			memcpy(&buf2_receive, &aData, CAN1RxMessage.DLC);
			buf2_flag = 1;
			break;
		case XY_feedback_state :
			break;
		default:
			break;
		}
		CAN_PROCESS();
		HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
	}else{
		HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0 , &CAN2RxMessage, aData);
		//sprintf(data,"%d %d %d %d %d %d %d %d \r\n",aData[0],aData[1],aData[2],aData[3],aData[4],aData[5],aData[6],aData[7]);
		switch(CAN1RxMessage.StdId){
		case RNS_TO_mainboard:
			memcpy(&insData_receive, &aData, CAN2RxMessage.DLC);
			buf2_flag = 0;

			break;
		case RNS_TO_mainboard_buf1:
			memcpy(&buf1_receive, &aData, CAN2RxMessage.DLC);

			break;
		case RNS_TO_mainboard_buf2:
			memcpy(&buf2_receive, &aData, CAN2RxMessage.DLC);
			buf2_flag = 1;
			break;
		case XY_feedback_state :
			break;
		default:
			break;
		}
		CAN_PROCESS();
		HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
	}
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)

{
	uint8_t aData[8];

	if(hcan == &hcan1){

		HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1 , &CAN1RxMessage, aData);
		//sprintf(data,"%d %d %d %d %d %d %d %d \r\n",aData[0],aData[1],aData[2],aData[3],aData[4],aData[5],aData[6],aData[7]);
		switch(CAN2RxMessage.StdId){
		case RNS_TO_mainboard:
			memcpy(&insData_receive, &aData, CAN1RxMessage.DLC);
			buf2_flag = 0;

			break;
		case RNS_TO_mainboard_buf1:
			memcpy(&buf1_receive, &aData, CAN1RxMessage.DLC);

			break;
		case RNS_TO_mainboard_buf2:
			memcpy(&buf2_receive, &aData, CAN1RxMessage.DLC);
			buf2_flag = 1;
			break;
		case XY_feedback_state :
			break;
		default:
			break;
		}
		CAN_PROCESS();
		HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);

	}else{

		HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1 , &CAN2RxMessage, aData);
		//sprintf(data,"%d %d %d %d %d %d %d %d \r\n",aData[0],aData[1],aData[2],aData[3],aData[4],aData[5],aData[6],aData[7]);
		switch(CAN2RxMessage.StdId){
		case RNS_TO_mainboard:
			memcpy(&insData_receive, &aData, CAN2RxMessage.DLC);
			buf2_flag = 0;

			break;
		case RNS_TO_mainboard_buf1:
			memcpy(&buf1_receive, &aData, CAN2RxMessage.DLC);

			break;
		case RNS_TO_mainboard_buf2:
			memcpy(&buf2_receive, &aData, CAN2RxMessage.DLC);
			buf2_flag = 1;
			break;
		case XY_feedback_state :
			break;
		default:
			break;
		}
		CAN_PROCESS();
		HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
	}

}
