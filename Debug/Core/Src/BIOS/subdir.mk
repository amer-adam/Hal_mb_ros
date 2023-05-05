################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BIOS/bdc.c \
../Core/Src/BIOS/gpio.c \
../Core/Src/BIOS/multiplexer.c \
../Core/Src/BIOS/pwm.c \
../Core/Src/BIOS/qei.c \
../Core/Src/BIOS/shiftreg.c \
../Core/Src/BIOS/system.c \
../Core/Src/BIOS/timer.c \
../Core/Src/BIOS/uart.c 

C_DEPS += \
./Core/Src/BIOS/bdc.d \
./Core/Src/BIOS/gpio.d \
./Core/Src/BIOS/multiplexer.d \
./Core/Src/BIOS/pwm.d \
./Core/Src/BIOS/qei.d \
./Core/Src/BIOS/shiftreg.d \
./Core/Src/BIOS/system.d \
./Core/Src/BIOS/timer.d \
./Core/Src/BIOS/uart.d 

OBJS += \
./Core/Src/BIOS/bdc.o \
./Core/Src/BIOS/gpio.o \
./Core/Src/BIOS/multiplexer.o \
./Core/Src/BIOS/pwm.o \
./Core/Src/BIOS/qei.o \
./Core/Src/BIOS/shiftreg.o \
./Core/Src/BIOS/system.o \
./Core/Src/BIOS/timer.o \
./Core/Src/BIOS/uart.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BIOS/%.o Core/Src/BIOS/%.su Core/Src/BIOS/%.cyclo: ../Core/Src/BIOS/%.c Core/Src/BIOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Src -O0 -ffunction-sections -fdata-sections -Wall -fcommon -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-BIOS

clean-Core-2f-Src-2f-BIOS:
	-$(RM) ./Core/Src/BIOS/bdc.cyclo ./Core/Src/BIOS/bdc.d ./Core/Src/BIOS/bdc.o ./Core/Src/BIOS/bdc.su ./Core/Src/BIOS/gpio.cyclo ./Core/Src/BIOS/gpio.d ./Core/Src/BIOS/gpio.o ./Core/Src/BIOS/gpio.su ./Core/Src/BIOS/multiplexer.cyclo ./Core/Src/BIOS/multiplexer.d ./Core/Src/BIOS/multiplexer.o ./Core/Src/BIOS/multiplexer.su ./Core/Src/BIOS/pwm.cyclo ./Core/Src/BIOS/pwm.d ./Core/Src/BIOS/pwm.o ./Core/Src/BIOS/pwm.su ./Core/Src/BIOS/qei.cyclo ./Core/Src/BIOS/qei.d ./Core/Src/BIOS/qei.o ./Core/Src/BIOS/qei.su ./Core/Src/BIOS/shiftreg.cyclo ./Core/Src/BIOS/shiftreg.d ./Core/Src/BIOS/shiftreg.o ./Core/Src/BIOS/shiftreg.su ./Core/Src/BIOS/system.cyclo ./Core/Src/BIOS/system.d ./Core/Src/BIOS/system.o ./Core/Src/BIOS/system.su ./Core/Src/BIOS/timer.cyclo ./Core/Src/BIOS/timer.d ./Core/Src/BIOS/timer.o ./Core/Src/BIOS/timer.su ./Core/Src/BIOS/uart.cyclo ./Core/Src/BIOS/uart.d ./Core/Src/BIOS/uart.o ./Core/Src/BIOS/uart.su

.PHONY: clean-Core-2f-Src-2f-BIOS

