################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/X_CUBE_ST67W61_V1.0.0/Middlewares/Third_Party/littlefs/lfs.c \
C:/X_CUBE_ST67W61_V1.0.0/Middlewares/Third_Party/littlefs/lfs_util.c 

OBJS += \
./Middlewares/LittleFS/File\ System/LittleFS/lfs.o \
./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.o 

C_DEPS += \
./Middlewares/LittleFS/File\ System/LittleFS/lfs.d \
./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LittleFS/File\ System/LittleFS/lfs.o: C:/X_CUBE_ST67W61_V1.0.0/Middlewares/Third_Party/littlefs/lfs.c Middlewares/LittleFS/File\ System/LittleFS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DconfigTASK_NOTIFICATION_ARRAY_ENTRIES=8 '-DLFS_CONFIG=lfs_util_config.h' -DUSE_HAL_DRIVER -DSTM32U575xx -DUSE_MLC -c -I../../Core/Inc -I../../X-CUBE-MEMS1/Target -I../../App_MQTT/App -I../../App_MQTT/Target -I../../ST67W6X/Target -I../../littlefs/Target -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../../../../../../Drivers/CMSIS/RTOS2/Include/ -I../../../../../../../Middlewares/Third_Party/cJSON -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_at -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_bus -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Api -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Core -I../../../../../../../Middlewares/Third_Party/littlefs -I../../../../../../../Drivers/BSP/Components/lsm6dsv16x -I../../../../../../../Drivers/BSP/Components/lis2duxs12 -I../../../../../../../Drivers/BSP/Components/lis2mdl -I../../../../../../../Drivers/BSP/Components/lsm6dso16is -I../../../../../../../Drivers/BSP/Components/sht40ad1b -I../../../../../../../Drivers/BSP/Components/lps22df -I../../../../../../../Drivers/BSP/Components/stts22h -I../../../../../../../Drivers/BSP/IKS4A1 -I../../../../../../../Drivers/BSP/Components/Common -I../../X-CUBE-MEMS1/App -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LittleFS/File System/LittleFS/lfs.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/LittleFS/File\ System/LittleFS/lfs_util.o: C:/X_CUBE_ST67W61_V1.0.0/Middlewares/Third_Party/littlefs/lfs_util.c Middlewares/LittleFS/File\ System/LittleFS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DconfigTASK_NOTIFICATION_ARRAY_ENTRIES=8 '-DLFS_CONFIG=lfs_util_config.h' -DUSE_HAL_DRIVER -DSTM32U575xx -DUSE_MLC -c -I../../Core/Inc -I../../X-CUBE-MEMS1/Target -I../../App_MQTT/App -I../../App_MQTT/Target -I../../ST67W6X/Target -I../../littlefs/Target -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../../../../../../Drivers/CMSIS/RTOS2/Include/ -I../../../../../../../Middlewares/Third_Party/cJSON -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_at -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_bus -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Api -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Core -I../../../../../../../Middlewares/Third_Party/littlefs -I../../../../../../../Drivers/BSP/Components/lsm6dsv16x -I../../../../../../../Drivers/BSP/Components/lis2duxs12 -I../../../../../../../Drivers/BSP/Components/lis2mdl -I../../../../../../../Drivers/BSP/Components/lsm6dso16is -I../../../../../../../Drivers/BSP/Components/sht40ad1b -I../../../../../../../Drivers/BSP/Components/lps22df -I../../../../../../../Drivers/BSP/Components/stts22h -I../../../../../../../Drivers/BSP/IKS4A1 -I../../../../../../../Drivers/BSP/Components/Common -I../../X-CUBE-MEMS1/App -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/LittleFS/File System/LittleFS/lfs_util.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-LittleFS-2f-File-20-System-2f-LittleFS

clean-Middlewares-2f-LittleFS-2f-File-20-System-2f-LittleFS:
	-$(RM) ./Middlewares/LittleFS/File\ System/LittleFS/lfs.cyclo ./Middlewares/LittleFS/File\ System/LittleFS/lfs.d ./Middlewares/LittleFS/File\ System/LittleFS/lfs.o ./Middlewares/LittleFS/File\ System/LittleFS/lfs.su ./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.cyclo ./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.d ./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.o ./Middlewares/LittleFS/File\ System/LittleFS/lfs_util.su

.PHONY: clean-Middlewares-2f-LittleFS-2f-File-20-System-2f-LittleFS

