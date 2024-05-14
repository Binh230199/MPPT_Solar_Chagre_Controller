################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Monitor.cpp 

OBJS += \
./MPPT_Solar_Charge_Controller/Application/Monitor.o 

CPP_DEPS += \
./MPPT_Solar_Charge_Controller/Application/Monitor.d 


# Each subdirectory must supply rules for building sources it contributes
MPPT_Solar_Charge_Controller/Application/Monitor.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application/Monitor.cpp MPPT_Solar_Charge_Controller/Application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MPPT_Solar_Charge_Controller-2f-Application

clean-MPPT_Solar_Charge_Controller-2f-Application:
	-$(RM) ./MPPT_Solar_Charge_Controller/Application/Monitor.cyclo ./MPPT_Solar_Charge_Controller/Application/Monitor.d ./MPPT_Solar_Charge_Controller/Application/Monitor.o ./MPPT_Solar_Charge_Controller/Application/Monitor.su

.PHONY: clean-MPPT_Solar_Charge_Controller-2f-Application

