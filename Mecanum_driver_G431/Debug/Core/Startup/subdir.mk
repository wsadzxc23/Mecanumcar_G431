################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
S_SRCS += \
../Core/Startup/startup_stm32g431rbtx.s 

OBJS += \
./Core/Startup/startup_stm32g431rbtx.o 

S_DEPS += \
./Core/Startup/startup_stm32g431rbtx.d 


# 每个子目录必须为构建它所贡献的源提供规则
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g431rbtx.d ./Core/Startup/startup_stm32g431rbtx.o

.PHONY: clean-Core-2f-Startup

