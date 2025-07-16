################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/subdir.mk
-include Middlewares/cJSON/Data\ Exchange/cJSON/subdir.mk
-include Middlewares/ST67W6X_Network_Driver/Network/Utilities/Logging/subdir.mk
-include Middlewares/ST67W6X_Network_Driver/Network/ServiceAPI/subdir.mk
-include Middlewares/ST67W6X_Network_Driver/Network/Driver/W61_at_and_bus/subdir.mk
-include Middlewares/RTOS2/CMSIS/RTOS2/Heap/Heap_4/subdir.mk
-include Middlewares/RTOS2/CMSIS/RTOS2/Core/TZ_Non_Supported/subdir.mk
-include Middlewares/LittleFS/File\ System/LittleFS/subdir.mk
-include Drivers/STM32U5xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/IKS4A1/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/littlefs/Target/subdir.mk
-include Application/User/X-CUBE-MEMS1/App/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/ST67W6X/Target/subdir.mk
-include Application/User/Core/subdir.mk
-include Application/User/App_MQTT/Target/subdir.mk
-include Application/User/App_MQTT/App/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ST67W6X_MQTT
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ST67W6X_MQTT.elf \

MAP_FILES += \
ST67W6X_MQTT.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ST67W6X_MQTT.list \

OBJCOPY_BIN += \
ST67W6X_MQTT.bin \


# All Target
all: main-build

# Main-build Target
main-build: ST67W6X_MQTT.elf secondary-outputs

# Tool invocations
ST67W6X_MQTT.elf ST67W6X_MQTT.map: $(OBJS) $(USER_OBJS) C:\X_CUBE_ST67W61_V1.0.0\Projects\NUCLEO-U575ZI-Q\Demonstrations\ST67W6X\ST67W6X_MQTT_MLC\STM32CubeIDE\STM32U575ZITXQ_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ST67W6X_MQTT.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\X_CUBE_ST67W61_V1.0.0\Projects\NUCLEO-U575ZI-Q\Demonstrations\ST67W6X\ST67W6X_MQTT_MLC\STM32CubeIDE\STM32U575ZITXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="ST67W6X_MQTT.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ST67W6X_MQTT.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ST67W6X_MQTT.list"
	@echo 'Finished building: $@'
	@echo ' '

ST67W6X_MQTT.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ST67W6X_MQTT.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ST67W6X_MQTT.bin ST67W6X_MQTT.elf ST67W6X_MQTT.list ST67W6X_MQTT.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
