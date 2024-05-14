################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.c \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.c \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/syscalls.c \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/sysmem.c \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.c 

CPP_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/main.cpp 

C_DEPS += \
./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.d \
./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.d \
./MPPT_Solar_Charge_Controller/Core/Src/syscalls.d \
./MPPT_Solar_Charge_Controller/Core/Src/sysmem.d \
./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.d 

OBJS += \
./MPPT_Solar_Charge_Controller/Core/Src/main.o \
./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.o \
./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.o \
./MPPT_Solar_Charge_Controller/Core/Src/syscalls.o \
./MPPT_Solar_Charge_Controller/Core/Src/sysmem.o \
./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.o 

CPP_DEPS += \
./MPPT_Solar_Charge_Controller/Core/Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
MPPT_Solar_Charge_Controller/Core/Src/main.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/main.cpp MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.c MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.c MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/Core/Src/syscalls.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/syscalls.c MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/Core/Src/sysmem.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/sysmem.c MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.c MPPT_Solar_Charge_Controller/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Application" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/Singleton" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/DesignPattern/StateMachine" -I"D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/MyDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Src

clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Src:
	-$(RM) ./MPPT_Solar_Charge_Controller/Core/Src/main.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/main.d ./MPPT_Solar_Charge_Controller/Core/Src/main.o ./MPPT_Solar_Charge_Controller/Core/Src/main.su ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.d ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.o ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_hal_msp.su ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.d ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.o ./MPPT_Solar_Charge_Controller/Core/Src/stm32f4xx_it.su ./MPPT_Solar_Charge_Controller/Core/Src/syscalls.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/syscalls.d ./MPPT_Solar_Charge_Controller/Core/Src/syscalls.o ./MPPT_Solar_Charge_Controller/Core/Src/syscalls.su ./MPPT_Solar_Charge_Controller/Core/Src/sysmem.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/sysmem.d ./MPPT_Solar_Charge_Controller/Core/Src/sysmem.o ./MPPT_Solar_Charge_Controller/Core/Src/sysmem.su ./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.cyclo ./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.d ./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.o ./MPPT_Solar_Charge_Controller/Core/Src/system_stm32f4xx.su

.PHONY: clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Src

