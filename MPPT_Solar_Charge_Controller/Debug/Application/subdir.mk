################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Analog.cpp \
../Application/ChargeControl.cpp \
../Application/DeviceProtection.cpp \
../Application/SerialMonitor.cpp \
../Application/SystemManager.cpp 

OBJS += \
./Application/Analog.o \
./Application/ChargeControl.o \
./Application/DeviceProtection.o \
./Application/SerialMonitor.o \
./Application/SystemManager.o 

CPP_DEPS += \
./Application/Analog.d \
./Application/ChargeControl.d \
./Application/DeviceProtection.d \
./Application/SerialMonitor.d \
./Application/SystemManager.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../MyDriver/ -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/Analog.cyclo ./Application/Analog.d ./Application/Analog.o ./Application/Analog.su ./Application/ChargeControl.cyclo ./Application/ChargeControl.d ./Application/ChargeControl.o ./Application/ChargeControl.su ./Application/DeviceProtection.cyclo ./Application/DeviceProtection.d ./Application/DeviceProtection.o ./Application/DeviceProtection.su ./Application/SerialMonitor.cyclo ./Application/SerialMonitor.d ./Application/SerialMonitor.o ./Application/SerialMonitor.su ./Application/SystemManager.cyclo ./Application/SystemManager.d ./Application/SystemManager.o ./Application/SystemManager.su

.PHONY: clean-Application

