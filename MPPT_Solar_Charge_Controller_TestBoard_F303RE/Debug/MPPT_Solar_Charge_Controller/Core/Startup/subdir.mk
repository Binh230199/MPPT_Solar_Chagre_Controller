################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.s 

S_DEPS += \
./MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.d 

OBJS += \
./MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.o 


# Each subdirectory must supply rules for building sources it contributes
MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.o: D:/PROJECT_MPPT/MPPT_Solar_Chagre_Controller/MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.s MPPT_Solar_Charge_Controller/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Startup

clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Startup:
	-$(RM) ./MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.d ./MPPT_Solar_Charge_Controller/Core/Startup/startup_stm32f407vgtx.o

.PHONY: clean-MPPT_Solar_Charge_Controller-2f-Core-2f-Startup

