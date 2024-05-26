################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
CPP_SRCS += \
../Core/Src/roslib/duration.cpp \
../Core/Src/roslib/time.cpp 

OBJS += \
./Core/Src/roslib/duration.o \
./Core/Src/roslib/time.o 

CPP_DEPS += \
./Core/Src/roslib/duration.d \
./Core/Src/roslib/time.d 


# 每个子目录必须为构建它所贡献的源提供规则
Core/Src/roslib/%.o Core/Src/roslib/%.su Core/Src/roslib/%.cyclo: ../Core/Src/roslib/%.cpp Core/Src/roslib/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"/home/wang/workspace/Mecanum_Car/workspace/Mecanumcar_G431/Mecanum_driver_G431/Core/Inc/rosserial" -I"/home/wang/workspace/Mecanum_Car/workspace/Mecanumcar_G431/Mecanum_driver_G431/Core/Inc/roslib" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-roslib

clean-Core-2f-Src-2f-roslib:
	-$(RM) ./Core/Src/roslib/duration.cyclo ./Core/Src/roslib/duration.d ./Core/Src/roslib/duration.o ./Core/Src/roslib/duration.su ./Core/Src/roslib/time.cyclo ./Core/Src/roslib/time.d ./Core/Src/roslib/time.o ./Core/Src/roslib/time.su

.PHONY: clean-Core-2f-Src-2f-roslib

