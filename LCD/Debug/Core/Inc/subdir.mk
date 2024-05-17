################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/Analog.cpp \
../Core/Inc/Button.cpp \
../Core/Inc/ChargeControl.cpp \
../Core/Inc/Lcd.cpp \
../Core/Inc/Log.cpp \
../Core/Inc/Monitor.cpp \
../Core/Inc/SerialMonitor.cpp \
../Core/Inc/SystemManager.cpp 

OBJS += \
./Core/Inc/Analog.o \
./Core/Inc/Button.o \
./Core/Inc/ChargeControl.o \
./Core/Inc/Lcd.o \
./Core/Inc/Log.o \
./Core/Inc/Monitor.o \
./Core/Inc/SerialMonitor.o \
./Core/Inc/SystemManager.o 

CPP_DEPS += \
./Core/Inc/Analog.d \
./Core/Inc/Button.d \
./Core/Inc/ChargeControl.d \
./Core/Inc/Lcd.d \
./Core/Inc/Log.d \
./Core/Inc/Monitor.d \
./Core/Inc/SerialMonitor.d \
./Core/Inc/SystemManager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.cpp Core/Inc/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/Analog.cyclo ./Core/Inc/Analog.d ./Core/Inc/Analog.o ./Core/Inc/Analog.su ./Core/Inc/Button.cyclo ./Core/Inc/Button.d ./Core/Inc/Button.o ./Core/Inc/Button.su ./Core/Inc/ChargeControl.cyclo ./Core/Inc/ChargeControl.d ./Core/Inc/ChargeControl.o ./Core/Inc/ChargeControl.su ./Core/Inc/Lcd.cyclo ./Core/Inc/Lcd.d ./Core/Inc/Lcd.o ./Core/Inc/Lcd.su ./Core/Inc/Log.cyclo ./Core/Inc/Log.d ./Core/Inc/Log.o ./Core/Inc/Log.su ./Core/Inc/Monitor.cyclo ./Core/Inc/Monitor.d ./Core/Inc/Monitor.o ./Core/Inc/Monitor.su ./Core/Inc/SerialMonitor.cyclo ./Core/Inc/SerialMonitor.d ./Core/Inc/SerialMonitor.o ./Core/Inc/SerialMonitor.su ./Core/Inc/SystemManager.cyclo ./Core/Inc/SystemManager.d ./Core/Inc/SystemManager.o ./Core/Inc/SystemManager.su

.PHONY: clean-Core-2f-Inc

