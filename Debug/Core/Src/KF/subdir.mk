################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/KF/KF.c 

C_DEPS += \
./Core/Src/KF/KF.d 

OBJS += \
./Core/Src/KF/KF.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/KF/%.o Core/Src/KF/%.su Core/Src/KF/%.cyclo: ../Core/Src/KF/%.c Core/Src/KF/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-KF

clean-Core-2f-Src-2f-KF:
	-$(RM) ./Core/Src/KF/KF.cyclo ./Core/Src/KF/KF.d ./Core/Src/KF/KF.o ./Core/Src/KF/KF.su

.PHONY: clean-Core-2f-Src-2f-KF

