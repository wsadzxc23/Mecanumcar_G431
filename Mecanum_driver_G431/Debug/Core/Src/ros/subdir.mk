################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
CPP_SRCS += \
../Core/Src/ros/rosserial.cpp 

OBJS += \
./Core/Src/ros/rosserial.o 

CPP_DEPS += \
./Core/Src/ros/rosserial.d 


# 每个子目录必须为构建它所贡献的源提供规则
Core/Src/ros/%.o Core/Src/ros/%.su Core/Src/ros/%.cyclo: ../Core/Src/ros/%.cpp Core/Src/ros/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/home/wang/workspace/Mecanum_Car/workspace/Mecanumcar_G431/Mecanum_driver_G431/Core/Inc/rosserial" -I"/home/wang/workspace/Mecanum_Car/workspace/Mecanumcar_G431/Mecanum_driver_G431/Core/Inc/roslib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ros

clean-Core-2f-Src-2f-ros:
	-$(RM) ./Core/Src/ros/rosserial.cyclo ./Core/Src/ros/rosserial.d ./Core/Src/ros/rosserial.o ./Core/Src/ros/rosserial.su

.PHONY: clean-Core-2f-Src-2f-ros

