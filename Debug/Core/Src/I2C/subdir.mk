################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/I2C/i2c.c 

C_DEPS += \
./Core/Src/I2C/i2c.d 

OBJS += \
./Core/Src/I2C/i2c.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/I2C/%.o Core/Src/I2C/%.su Core/Src/I2C/%.cyclo: ../Core/Src/I2C/%.c Core/Src/I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-I2C

clean-Core-2f-Src-2f-I2C:
	-$(RM) ./Core/Src/I2C/i2c.cyclo ./Core/Src/I2C/i2c.d ./Core/Src/I2C/i2c.o ./Core/Src/I2C/i2c.su

.PHONY: clean-Core-2f-Src-2f-I2C

