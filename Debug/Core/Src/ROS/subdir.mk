################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ROS/millisecondtimer.c 

CPP_SRCS += \
../Core/Src/ROS/hardwareserial.cpp 

C_DEPS += \
./Core/Src/ROS/millisecondtimer.d 

OBJS += \
./Core/Src/ROS/hardwareserial.o \
./Core/Src/ROS/millisecondtimer.o 

CPP_DEPS += \
./Core/Src/ROS/hardwareserial.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ROS/%.o Core/Src/ROS/%.su Core/Src/ROS/%.cyclo: ../Core/Src/ROS/%.cpp Core/Src/ROS/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/ROS/%.o Core/Src/ROS/%.su Core/Src/ROS/%.cyclo: ../Core/Src/ROS/%.c Core/Src/ROS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ROS

clean-Core-2f-Src-2f-ROS:
	-$(RM) ./Core/Src/ROS/hardwareserial.cyclo ./Core/Src/ROS/hardwareserial.d ./Core/Src/ROS/hardwareserial.o ./Core/Src/ROS/hardwareserial.su ./Core/Src/ROS/millisecondtimer.cyclo ./Core/Src/ROS/millisecondtimer.d ./Core/Src/ROS/millisecondtimer.o ./Core/Src/ROS/millisecondtimer.su

.PHONY: clean-Core-2f-Src-2f-ROS

