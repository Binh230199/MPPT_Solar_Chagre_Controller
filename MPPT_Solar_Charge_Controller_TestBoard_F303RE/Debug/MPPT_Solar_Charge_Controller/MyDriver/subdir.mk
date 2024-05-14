################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver/Button.cpp \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver/Log.cpp 

OBJS += \
./MPPT_Solar_Charge_Controller/MyDriver/Button.o \
./MPPT_Solar_Charge_Controller/MyDriver/Log.o 

CPP_DEPS += \
./MPPT_Solar_Charge_Controller/MyDriver/Button.d \
./MPPT_Solar_Charge_Controller/MyDriver/Log.d 


# Each subdirectory must supply rules for building sources it contributes
MPPT_Solar_Charge_Controller/MyDriver/Button.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver/Button.cpp MPPT_Solar_Charge_Controller/MyDriver/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/MyDriver/Log.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver/Log.cpp MPPT_Solar_Charge_Controller/MyDriver/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MPPT_Solar_Charge_Controller-2f-MyDriver

clean-MPPT_Solar_Charge_Controller-2f-MyDriver:
	-$(RM) ./MPPT_Solar_Charge_Controller/MyDriver/Button.cyclo ./MPPT_Solar_Charge_Controller/MyDriver/Button.d ./MPPT_Solar_Charge_Controller/MyDriver/Button.o ./MPPT_Solar_Charge_Controller/MyDriver/Button.su ./MPPT_Solar_Charge_Controller/MyDriver/Log.cyclo ./MPPT_Solar_Charge_Controller/MyDriver/Log.d ./MPPT_Solar_Charge_Controller/MyDriver/Log.o ./MPPT_Solar_Charge_Controller/MyDriver/Log.su

.PHONY: clean-MPPT_Solar_Charge_Controller-2f-MyDriver

