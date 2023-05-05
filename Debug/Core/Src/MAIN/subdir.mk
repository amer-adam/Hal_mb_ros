################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/MAIN/main.cpp 

OBJS += \
./Core/Src/MAIN/main.o 

CPP_DEPS += \
./Core/Src/MAIN/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MAIN/%.o Core/Src/MAIN/%.su Core/Src/MAIN/%.cyclo: ../Core/Src/MAIN/%.cpp Core/Src/MAIN/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MAIN

clean-Core-2f-Src-2f-MAIN:
	-$(RM) ./Core/Src/MAIN/main.cyclo ./Core/Src/MAIN/main.d ./Core/Src/MAIN/main.o ./Core/Src/MAIN/main.su

.PHONY: clean-Core-2f-Src-2f-MAIN

