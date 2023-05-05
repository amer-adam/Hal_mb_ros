################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ADC/adc.c 

C_DEPS += \
./Core/Src/ADC/adc.d 

OBJS += \
./Core/Src/ADC/adc.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ADC/%.o Core/Src/ADC/%.su Core/Src/ADC/%.cyclo: ../Core/Src/ADC/%.c Core/Src/ADC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ADC

clean-Core-2f-Src-2f-ADC:
	-$(RM) ./Core/Src/ADC/adc.cyclo ./Core/Src/ADC/adc.d ./Core/Src/ADC/adc.o ./Core/Src/ADC/adc.su

.PHONY: clean-Core-2f-Src-2f-ADC

