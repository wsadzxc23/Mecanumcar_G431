################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
C_SRCS += \
../Core/Src/chassis/motor.c 

OBJS += \
./Core/Src/chassis/motor.o 

C_DEPS += \
./Core/Src/chassis/motor.d 


# 每个子目录必须为构建它所贡献的源提供规则
Core/Src/chassis/%.o Core/Src/chassis/%.su Core/Src/chassis/%.cyclo: ../Core/Src/chassis/%.c Core/Src/chassis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-chassis

clean-Core-2f-Src-2f-chassis:
	-$(RM) ./Core/Src/chassis/motor.cyclo ./Core/Src/chassis/motor.d ./Core/Src/chassis/motor.o ./Core/Src/chassis/motor.su

.PHONY: clean-Core-2f-Src-2f-chassis

