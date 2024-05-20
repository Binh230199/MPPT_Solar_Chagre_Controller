################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Libraries/Analog.cpp \
../Libraries/Button.cpp \
../Libraries/ChargeControl.cpp \
../Libraries/DeviceProtection.cpp \
../Libraries/Lcd.cpp \
../Libraries/Log.cpp \
../Libraries/SerialMonitor.cpp \
../Libraries/SystemManager.cpp 

OBJS += \
./Libraries/Analog.o \
./Libraries/Button.o \
./Libraries/ChargeControl.o \
./Libraries/DeviceProtection.o \
./Libraries/Lcd.o \
./Libraries/Log.o \
./Libraries/SerialMonitor.o \
./Libraries/SystemManager.o 

CPP_DEPS += \
./Libraries/Analog.d \
./Libraries/Button.d \
./Libraries/ChargeControl.d \
./Libraries/DeviceProtection.d \
./Libraries/Lcd.d \
./Libraries/Log.d \
./Libraries/SerialMonitor.d \
./Libraries/SystemManager.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/%.o Libraries/%.su Libraries/%.cyclo: ../Libraries/%.cpp Libraries/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Libraries/ -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libraries

clean-Libraries:
	-$(RM) ./Libraries/Analog.cyclo ./Libraries/Analog.d ./Libraries/Analog.o ./Libraries/Analog.su ./Libraries/Button.cyclo ./Libraries/Button.d ./Libraries/Button.o ./Libraries/Button.su ./Libraries/ChargeControl.cyclo ./Libraries/ChargeControl.d ./Libraries/ChargeControl.o ./Libraries/ChargeControl.su ./Libraries/DeviceProtection.cyclo ./Libraries/DeviceProtection.d ./Libraries/DeviceProtection.o ./Libraries/DeviceProtection.su ./Libraries/Lcd.cyclo ./Libraries/Lcd.d ./Libraries/Lcd.o ./Libraries/Lcd.su ./Libraries/Log.cyclo ./Libraries/Log.d ./Libraries/Log.o ./Libraries/Log.su ./Libraries/SerialMonitor.cyclo ./Libraries/SerialMonitor.d ./Libraries/SerialMonitor.o ./Libraries/SerialMonitor.su ./Libraries/SystemManager.cyclo ./Libraries/SystemManager.d ./Libraries/SystemManager.o ./Libraries/SystemManager.su

.PHONY: clean-Libraries

