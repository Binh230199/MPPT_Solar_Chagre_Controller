################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Monitor.cpp 

OBJS += \
./Application/Monitor.o 

CPP_DEPS += \
./Application/Monitor.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.cpp Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../MyDriver/ -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/Monitor.cyclo ./Application/Monitor.d ./Application/Monitor.o ./Application/Monitor.su

.PHONY: clean-Application

