#include "hardwareserial.h"

UART_HandleTypeDef*  SERIAL_USART[SERIALn] = {&huart2, &huart3, &huart4};

static uint8_t rxbuf[RXBUF_SIZE];
static ring_buffer rb1_recv;
static ring_buffer rb2_recv;
static ring_buffer rb3_recv;

void HardwareSerial::begin(uint32_t baud)
{
	/** init ringbuf **/
	if(this->Serial == SERIAL2)
		rb_init(&rb1_recv, sizeof(rxbuf), rxbuf);
	if(this->Serial == SERIAL3)
		rb_init(&rb2_recv, sizeof(rxbuf), rxbuf);
	if(this->Serial == SERIAL4)
		rb_init(&rb3_recv, sizeof(rxbuf), rxbuf);
}

uint32_t HardwareSerial::available(void)
{
	if(this->Serial == SERIAL2)
		return rb_full_count(&rb1_recv);
	if(this->Serial == SERIAL3)
		return rb_full_count(&rb2_recv);
	if(this->Serial == SERIAL4)
		return rb_full_count(&rb3_recv);

	return 0;

}

uint8_t HardwareSerial::read(void)
{
	while(!this->available())
		;
	if(this->Serial == SERIAL2)
		return rb_remove(&rb1_recv);
	if(this->Serial == SERIAL3)
		return rb_remove(&rb2_recv);
	if(this->Serial == SERIAL4)
		return rb_remove(&rb3_recv);

	return 0;
}

void UU_PutChar(UART_HandleTypeDef* huartx, uint8_t ch)
{
	while(!(huartx->Instance->SR & USART_SR_TXE));
	huartx->Instance->DR = ch;
}

uint16_t USART_ReceiveData(UART_HandleTypeDef* huartx)
{
	/* Receive Data */
	return (uint16_t)(huartx->Instance->DR & (uint16_t)0x01FF);
}

uint32_t HardwareSerial::write(uint8_t ch)
{
	//	USART_SendData(SERIAL_USART[this->Serial], ch);
	//	while(USART_GetFlagStatus(SERIAL_USART[this->Serial], USART_FLAG_TXE) == RESET);

	UU_PutChar(SERIAL_USART[this->Serial],ch);

	return 1;
}

void HardwareSerial::flush()
{
	if(this->Serial == SERIAL2)
		rb_reset(&rb1_recv);
	if(this->Serial == SERIAL3)
		rb_reset(&rb2_recv);
	if(this->Serial == SERIAL4)
		rb_reset(&rb3_recv);
}

void HardwareSerial::print(const char *format, ...)
{
	va_list args;
	char buf[256];
	va_start (args, format);
	vsprintf (buf, format, args);
	va_end (args);
	putstr(buf);

}

void HardwareSerial::putstr(const char *str)
{
	//	for(int i = 0; i < strlen(str); i++){
	//		write(str[i]);
	//	}
}

#ifdef __cplusplus
extern "C" {
#endif

void USART2_IRQHandler(void)
{
	unsigned char data;

	data = USART_ReceiveData(&huart2);
	rb_push_insert(&rb1_recv, data);
	HAL_UART_IRQHandler(&huart2);


}
void USART3_IRQHandler(void)
{
	unsigned char data;

	data = USART_ReceiveData(&huart3);
	rb_push_insert(&rb2_recv, data);
	HAL_UART_IRQHandler(&huart3);

}

void UART4_IRQHandler(void)
{
	unsigned char data;
	data = USART_ReceiveData(&huart4);
	rb_push_insert(&rb3_recv, data);
	HAL_UART_IRQHandler(&huart4);

}

#ifdef __cplusplus
}
#endif

