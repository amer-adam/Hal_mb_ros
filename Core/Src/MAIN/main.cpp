#include "main.h"
#include "ROS/bot1_mb_core.h"


/******************************************************************************
******************************************************************************/
uint32_t t;
uint32_t prev_update_time = 0;
int counter = 0;

/*******************************************************************************
* ROS NodeHandle
*******************************************************************************/
ros::NodeHandle nh;
ros::Time current_time;
uint32_t current_offset;

/*******************************************************************************
* Subscriber
*******************************************************************************/
ros::Subscriber<adam_msg::LEd> led_sub("led", LEDCallback);

/*******************************************************************************
* Publisher
*******************************************************************************/
char buffer[200];
std_msgs::String info_msg;
ros::Publisher info_pub("mb/info", &info_msg);

/*******************************************************************************
* SoftwareTimer
*******************************************************************************/
//static uint32_t tTime[10];


int main(void){
	set();
	ROS_Init();


	while(1){

		t = millis();
		if ((t - prev_update_time) >= 1000/PUBLISH_FREQUENCY )
			ROS_Update();
		nh.spinOnce();

	}
}

#ifdef __cplusplus
extern "C" {
#endif

void TIM6_DAC_IRQHandler(void)
{
	led1 = !led1;
//	UARTPrintString(&huart5,data);
	HAL_TIM_IRQHandler(&htim6);
}

#ifdef __cplusplus
}
#endif

void ROS_Init()
{
	nh.initNode();
	nh.getHardware()->setBaud(115200);

	nh.subscribe(led_sub);

	nh.advertise(info_pub);

	prev_update_time = millis();
}

void ROS_Update()
{
	updateTime();
//	publishDigitalInput();

	prev_update_time = t;
}

/*******************************************************************************
* Callback functions
*******************************************************************************/
void LEDCallback(const adam_msg::LEd &led_msg)
{
	int32_t led = led_msg.led;
	bool status= led_msg.status;

	switch (led)
	{
	case 1:
		led1 = status ? 1 : 0;
		break;
	case 2:
		led2 = status ? 1 : 0;
		break;
	case 3:
		led3 = status ? 1 : 0;
		break;
	}

	sprintf(buffer, "led: %ld, status: %d", led, status);
	info_msg.data = buffer;
	info_pub.publish(&info_msg);
}


/*******************************************************************************
* Publish functions
*******************************************************************************/


/*******************************************************************************
* Update the base time for interpolation
*******************************************************************************/
void updateTime()
{
	current_offset = millis();
	current_time = nh.now();
}

/*******************************************************************************
* ros::Time::now() implementation
*******************************************************************************/
ros::Time rosNow()
{
	return nh.now();
}

/**
 * @brief  This function is executed in case of error occurrence.
 */
void Error_Handler(void)
{

	/* User can add his own implementation to report the HAL error return state */

}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
