################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/X_CUBE_ST67W61_V1.0.0/Projects/NUCLEO-U575ZI-Q/Demonstrations/ST67W6X/ST67W6X_MQTT_MLC/App_MQTT/App/main_app.c 

OBJS += \
./Application/User/App_MQTT/App/main_app.o 

C_DEPS += \
./Application/User/App_MQTT/App/main_app.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/App_MQTT/App/main_app.o: C:/X_CUBE_ST67W61_V1.0.0/Projects/NUCLEO-U575ZI-Q/Demonstrations/ST67W6X/ST67W6X_MQTT_MLC/App_MQTT/App/main_app.c Application/User/App_MQTT/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DconfigTASK_NOTIFICATION_ARRAY_ENTRIES=8 '-DLFS_CONFIG=lfs_util_config.h' -DUSE_HAL_DRIVER -DSTM32U575xx -DUSE_MLC -c -I../../Core/Inc -I../../X-CUBE-MEMS1/Target -I../../App_MQTT/App -I../../App_MQTT/Target -I../../ST67W6X/Target -I../../littlefs/Target -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../../../../../../../Drivers/CMSIS/RTOS2/Include/ -I../../../../../../../Middlewares/Third_Party/cJSON -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_at -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Driver/W61_bus -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Api -I../../../../../../../Middlewares/ST/ST67W6X_Network_Driver/Core -I../../../../../../../Middlewares/Third_Party/littlefs -I../../../../../../../Drivers/BSP/Components/lsm6dsv16x -I../../../../../../../Drivers/BSP/Components/lis2duxs12 -I../../../../../../../Drivers/BSP/Components/lis2mdl -I../../../../../../../Drivers/BSP/Components/lsm6dso16is -I../../../../../../../Drivers/BSP/Components/sht40ad1b -I../../../../../../../Drivers/BSP/Components/lps22df -I../../../../../../../Drivers/BSP/Components/stts22h -I../../../../../../../Drivers/BSP/IKS4A1 -I../../../../../../../Drivers/BSP/Components/Common -I../../X-CUBE-MEMS1/App -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-App_MQTT-2f-App

clean-Application-2f-User-2f-App_MQTT-2f-App:
	-$(RM) ./Application/User/App_MQTT/App/main_app.cyclo ./Application/User/App_MQTT/App/main_app.d ./Application/User/App_MQTT/App/main_app.o ./Application/User/App_MQTT/App/main_app.su

.PHONY: clean-Application-2f-User-2f-App_MQTT-2f-App

