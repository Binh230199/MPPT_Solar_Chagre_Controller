################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Analog.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/ChargeControl.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/DeviceProtection.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Monitor.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/SerialMonitor.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/SystemManager.cpp 

OBJS += \
./Application/Analog.o \
./Application/ChargeControl.o \
./Application/DeviceProtection.o \
./Application/Monitor.o \
./Application/SerialMonitor.o \
./Application/SystemManager.o 

CPP_DEPS += \
./Application/Analog.d \
./Application/ChargeControl.d \
./Application/DeviceProtection.d \
./Application/Monitor.d \
./Application/SerialMonitor.d \
./Application/SystemManager.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Analog.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Analog.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/ChargeControl.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/ChargeControl.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/DeviceProtection.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/DeviceProtection.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Monitor.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Monitor.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/SerialMonitor.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/SerialMonitor.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/SystemManager.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/SystemManager.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/Analog.cyclo ./Application/Analog.d ./Application/Analog.o ./Application/Analog.su ./Application/ChargeControl.cyclo ./Application/ChargeControl.d ./Application/ChargeControl.o ./Application/ChargeControl.su ./Application/DeviceProtection.cyclo ./Application/DeviceProtection.d ./Application/DeviceProtection.o ./Application/DeviceProtection.su ./Application/Monitor.cyclo ./Application/Monitor.d ./Application/Monitor.o ./Application/Monitor.su ./Application/SerialMonitor.cyclo ./Application/SerialMonitor.d ./Application/SerialMonitor.o ./Application/SerialMonitor.su ./Application/SystemManager.cyclo ./Application/SystemManager.d ./Application/SystemManager.o ./Application/SystemManager.su

.PHONY: clean-Application

