################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/stm32L053xx_gpio_driver.c 

OBJS += \
./Driver/Src/stm32L053xx_gpio_driver.o 

C_DEPS += \
./Driver/Src/stm32L053xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DNUCLEO_L053R8 -DSTM32 -DSTM32L0 -DSTM32L053R8Tx -c -I"C:/Users/kadam/Desktop/nucleo-L053R8/nucleo-L053R8_Driver/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/stm32L053xx_gpio_driver.d ./Driver/Src/stm32L053xx_gpio_driver.o

.PHONY: clean-Driver-2f-Src

