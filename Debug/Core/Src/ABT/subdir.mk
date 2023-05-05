################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ABT/ABT.c 

C_DEPS += \
./Core/Src/ABT/ABT.d 

OBJS += \
./Core/Src/ABT/ABT.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ABT/%.o Core/Src/ABT/%.su Core/Src/ABT/%.cyclo: ../Core/Src/ABT/%.c Core/Src/ABT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ABT

clean-Core-2f-Src-2f-ABT:
	-$(RM) ./Core/Src/ABT/ABT.cyclo ./Core/Src/ABT/ABT.d ./Core/Src/ABT/ABT.o ./Core/Src/ABT/ABT.su

.PHONY: clean-Core-2f-Src-2f-ABT

