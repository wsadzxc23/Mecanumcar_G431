################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
CPP_SRCS += \
../Core/Inc/duration.cpp \
../Core/Inc/time.cpp 

OBJS += \
./Core/Inc/duration.o \
./Core/Inc/time.o 

CPP_DEPS += \
./Core/Inc/duration.d \
./Core/Inc/time.d 


# 每个子目录必须为构建它所贡献的源提供规则
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.cpp Core/Inc/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/home/wang/workspace/Mecanum_Car/workspace/Mecanumcar_G431/Mecanum_driver_G431/Core/Inc/ros" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/duration.cyclo ./Core/Inc/duration.d ./Core/Inc/duration.o ./Core/Inc/duration.su ./Core/Inc/time.cyclo ./Core/Inc/time.d ./Core/Inc/time.o ./Core/Inc/time.su

.PHONY: clean-Core-2f-Inc

