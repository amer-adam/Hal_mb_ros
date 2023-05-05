################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SERVO/servo.c 

C_DEPS += \
./Core/Src/SERVO/servo.d 

OBJS += \
./Core/Src/SERVO/servo.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SERVO/%.o Core/Src/SERVO/%.su Core/Src/SERVO/%.cyclo: ../Core/Src/SERVO/%.c Core/Src/SERVO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SERVO

clean-Core-2f-Src-2f-SERVO:
	-$(RM) ./Core/Src/SERVO/servo.cyclo ./Core/Src/SERVO/servo.d ./Core/Src/SERVO/servo.o ./Core/Src/SERVO/servo.su

.PHONY: clean-Core-2f-Src-2f-SERVO

