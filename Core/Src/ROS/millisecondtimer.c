#ifdef __cplusplus
extern "C" {
#endif

#include "millisecondtimer.h"
#include "../interrupt.h"

//volatile uint32_t _counter;

//void initialise()
//{
//	_counter = 0;
//	SysTick_Config(SystemCoreClock / 1000);
//}

void delay(uint32_t millis) 
{
	uint32_t target;

	target = _counter + millis;
	while(_counter < target);
} 

//#ifdef __cplusplus
//extern "C" {
//#endif
//
//void SysTick_Handler(void)
//{
//	  HAL_IncTick();
//	  MUXUpdate(&MUX);
//	  SHIFTREGShift(&SR);
//	  counter++;
//
//}
//
//#ifdef __cplusplus
//}
//#endif

uint32_t millis() 
{
	return _counter;
}

void reset() 
{
	_counter = 0;
}

#ifdef __cplusplus
}
#endif

