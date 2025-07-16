/**
  ******************************************************************************
  * @file    sys_sensors.c
  * @author  GPM Application Team
  * @brief   Manages the sensors on the application
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "main.h"
#include "sys_sensors.h"
#include "RTE_Components.h"
#include "logging.h"

#if defined (SENSOR_ENABLED) && (SENSOR_ENABLED == 1)
#if defined (IKS01A3)
#include "iks01a3_env_sensors.h"
#include "iks01a3_motion_sensors.h"
#elif defined (IKS4A1)
#include "iks4a1_env_sensors.h"
#include "iks4a1_motion_sensors.h"
#include "iks4a1_motion_sensors_ex.h"
#include "lis2duxs12_motion_intensity.h" /* MLC Config file */

#else  /* not IKSxx */
#error "user to include its sensor drivers"
#endif  /* IKSxx */
#elif !defined (SENSOR_ENABLED)
#error SENSOR_ENABLED not defined
#endif  /* SENSOR_ENABLED */

/* External variables ---------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  uint32_t Instance;
  uint32_t Functions;
} Sys_Sensors_Object_t;

/* Private define ------------------------------------------------------------*/
#define STSOP_LATTITUDE           ((float) 43.618622 )  /*!< default latitude position */
#define STSOP_LONGITUDE           ((float) 7.051415  )  /*!< default longitude position */
#define MAX_GPS_POS               ((int32_t) 8388607 )  /*!< 2^23 - 1 */
#define HUMIDITY_DEFAULT_VAL      50.0f                 /*!< default humidity */
#define TEMPERATURE_DEFAULT_VAL   18.0f                 /*!< default temperature */
#define PRESSURE_DEFAULT_VAL      1000.0f               /*!< default pressure */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#if defined (SENSOR_ENABLED) && (SENSOR_ENABLED == 1)
#if defined (IKS01A3)
static IKS01A3_MOTION_SENSOR_Capabilities_t MotionCapabilities[IKS01A3_MOTION_INSTANCES_NBR];
static IKS01A3_ENV_SENSOR_Capabilities_t EnvCapabilities[IKS01A3_ENV_INSTANCES_NBR];
Sys_Sensors_Object_t MotionSensors_def[] =
{
  {IKS01A3_LSM6DSO_0, MOTION_GYRO},
  {IKS01A3_LIS2DW12_0, MOTION_ACCELERO},
  {IKS01A3_LIS2MDL_0, MOTION_MAGNETO},
};

Sys_Sensors_Object_t EnvSensors_def[] =
{
  {IKS01A3_HTS221_0, ENV_HUMIDITY},
  {IKS01A3_LPS22HH_0, ENV_PRESSURE},
  {IKS01A3_STTS751_0, ENV_TEMPERATURE},
};

#elif defined (IKS4A1)
static IKS4A1_MOTION_SENSOR_Capabilities_t MotionCapabilities[IKS4A1_MOTION_INSTANCES_NBR];
static IKS4A1_ENV_SENSOR_Capabilities_t EnvCapabilities[IKS4A1_ENV_INSTANCES_NBR];
Sys_Sensors_Object_t MotionSensors_def[] =
{
  {IKS4A1_LSM6DSV16X_0, MOTION_GYRO},
  {IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO},
  {IKS4A1_LIS2MDL_0, MOTION_MAGNETO},
};

Sys_Sensors_Object_t EnvSensors_def[] =
{
  {IKS4A1_SHT40AD1B_0, ENV_HUMIDITY},
  {IKS4A1_LPS22DF_0, ENV_PRESSURE},
  {IKS4A1_STTS22H_0, ENV_TEMPERATURE},
};
#else  /* not IKSxx */
#error "user to include its sensor drivers"
#endif  /* IKSxx */
#elif !defined (SENSOR_ENABLED)
#error SENSOR_ENABLED not defined
#endif  /* SENSOR_ENABLED */

/* Private function prototypes -----------------------------------------------*/
static int32_t Sys_Sensors_IKS01A3_Init(void);
static int32_t Sys_Sensors_IKS4A1_Init(void);
static int32_t MLC_Init(void);

/* Exported functions --------------------------------------------------------*/
int32_t Sys_Sensors_Init(void)
{
#if defined (SENSOR_ENABLED) && (SENSOR_ENABLED == 1)
  if (Sys_Sensors_IKS01A3_Init() != BSP_ERROR_NONE)
  {
    goto _err;
  }

  if (Sys_Sensors_IKS4A1_Init() != BSP_ERROR_NONE)
  {
    goto _err;
  }

#elif !defined (SENSOR_ENABLED)
#error SENSOR_ENABLED not defined
#endif /* SENSOR_ENABLED  */

  return BSP_ERROR_NONE;
_err:
  return BSP_ERROR_PERIPH_FAILURE;
}

int32_t Sys_Sensors_Read(Sys_Sensors_Data_t *data)
{
#if defined (SENSOR_ENABLED) && (SENSOR_ENABLED == 1)
  memset(data, 0, sizeof(Sys_Sensors_Data_t));
#if defined (IKS01A3)
  /* Set default values to prevent GetValue failure */
  data->humidity = HUMIDITY_DEFAULT_VAL;
  data->temperature = TEMPERATURE_DEFAULT_VAL;
  data->pressure = PRESSURE_DEFAULT_VAL;

  /* Get the values of environmental sensors */
  IKS01A3_ENV_SENSOR_GetValue(IKS01A3_HTS221_0, ENV_HUMIDITY, &data->humidity);
  IKS01A3_ENV_SENSOR_GetValue(IKS01A3_STTS751_0, ENV_TEMPERATURE, &data->temperature);
  IKS01A3_ENV_SENSOR_GetValue(IKS01A3_LPS22HH_0, ENV_PRESSURE, &data->pressure);

  /* Get the values of motion sensors */
  IKS01A3_MOTION_SENSOR_GetAxes(IKS01A3_LSM6DSO_0, MOTION_GYRO,
                                (IKS01A3_MOTION_SENSOR_Axes_t *)&data->angular_velocity);
  IKS01A3_MOTION_SENSOR_GetAxes(IKS01A3_LIS2DW12_0, MOTION_ACCELERO,
                                (IKS01A3_MOTION_SENSOR_Axes_t *)&data->acceleration);
  IKS01A3_MOTION_SENSOR_GetAxes(IKS01A3_LIS2MDL_0, MOTION_MAGNETO,
                                (IKS01A3_MOTION_SENSOR_Axes_t *)&data->magnetic_field);

#elif defined (IKS4A1)
  /* Set default values to prevent GetValue failure */
  data->humidity = HUMIDITY_DEFAULT_VAL;
  data->temperature = TEMPERATURE_DEFAULT_VAL;
  data->pressure = PRESSURE_DEFAULT_VAL;

  /* Get the values of environmental sensors */
  IKS4A1_ENV_SENSOR_GetValue(IKS4A1_SHT40AD1B_0, ENV_HUMIDITY, &data->humidity);
  IKS4A1_ENV_SENSOR_GetValue(IKS4A1_STTS22H_0, ENV_TEMPERATURE, &data->temperature);
  IKS4A1_ENV_SENSOR_GetValue(IKS4A1_LPS22DF_0, ENV_PRESSURE, &data->pressure);

  /* Get the values of motion sensors */
  IKS4A1_MOTION_SENSOR_GetAxes(IKS4A1_LSM6DSV16X_0, MOTION_GYRO,
                               (IKS4A1_MOTION_SENSOR_Axes_t *)&data->angular_velocity);
  IKS4A1_MOTION_SENSOR_GetAxes(IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO,
                               (IKS4A1_MOTION_SENSOR_Axes_t *)&data->acceleration);
  IKS4A1_MOTION_SENSOR_GetAxes(IKS4A1_LIS2MDL_0, MOTION_MAGNETO,
                               (IKS4A1_MOTION_SENSOR_Axes_t *)&data->magnetic_field);

#ifdef USE_MLC
  /* Get mlc outputs */
    (void)IKS4A1_MOTION_SENSOR_Write_Register(IKS4A1_LIS2DUXS12_0, LIS2DUXS12_FUNC_CFG_ACCESS, 0x80);
    (void)IKS4A1_MOTION_SENSOR_Read_Register(IKS4A1_LIS2DUXS12_0, LIS2DUXS12_MLC1_SRC, &data->motion_intensity);
    (void)IKS4A1_MOTION_SENSOR_Write_Register(IKS4A1_LIS2DUXS12_0, LIS2DUXS12_FUNC_CFG_ACCESS, 0x00);
#endif

#endif /* */
#endif /* SENSOR_ENABLED */

  return 0;
}

/* Private Functions Definition -----------------------------------------------*/
static int32_t Sys_Sensors_IKS01A3_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;
#if defined (IKS01A3)
  uint32_t count;

  for (count = 0; count < sizeof(MotionSensors_def) / sizeof(Sys_Sensors_Object_t); count++)
  {
    ret = IKS01A3_MOTION_SENSOR_Init(MotionSensors_def[count].Instance, MotionSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS01A3_MOTION_SENSOR_GetCapabilities(MotionSensors_def[count].Instance,
                                                &MotionCapabilities[MotionSensors_def[count].Instance]);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS01A3_MOTION_SENSOR_Enable(MotionSensors_def[count].Instance, MotionSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
  }

  for (count = 0; count < sizeof(EnvSensors_def) / sizeof(Sys_Sensors_Object_t); count++)
  {
    ret = IKS01A3_ENV_SENSOR_Init(EnvSensors_def[count].Instance, EnvSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS01A3_ENV_SENSOR_GetCapabilities(EnvSensors_def[count].Instance,
                                             &EnvCapabilities[EnvSensors_def[count].Instance]);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS01A3_ENV_SENSOR_Enable(EnvSensors_def[count].Instance, EnvSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
  }

_err:
#endif /* IKS01A3 */
  return ret;
}

static int32_t Sys_Sensors_IKS4A1_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;
#if defined (IKS4A1)
  uint32_t count;

  for (count = 0; count < sizeof(MotionSensors_def) / sizeof(Sys_Sensors_Object_t); count++)
  {
    ret = IKS4A1_MOTION_SENSOR_Init(MotionSensors_def[count].Instance, MotionSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS4A1_MOTION_SENSOR_GetCapabilities(MotionSensors_def[count].Instance,
                                               &MotionCapabilities[MotionSensors_def[count].Instance]);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS4A1_MOTION_SENSOR_Enable(MotionSensors_def[count].Instance, MotionSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
  }

  for (count = 0; count < sizeof(EnvSensors_def) / sizeof(Sys_Sensors_Object_t); count++)
  {
    ret = IKS4A1_ENV_SENSOR_Init(EnvSensors_def[count].Instance, EnvSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS4A1_ENV_SENSOR_GetCapabilities(EnvSensors_def[count].Instance,
                                            &EnvCapabilities[EnvSensors_def[count].Instance]);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
    ret = IKS4A1_ENV_SENSOR_Enable(EnvSensors_def[count].Instance, EnvSensors_def[count].Functions);
    if (ret != BSP_ERROR_NONE)
    {
      goto _err;
    }
  }

#ifdef USE_MLC
  /* Initialize the MLC */
  ret = MLC_Init();
#endif

_err:
#endif /* IKS4A1 */
  return ret;
}

int32_t MLC_Init(void)
{
  int i = 0;
  int length = 0;
  float acc_odr_before_ucf = 0;
  int32_t acc_fs_before_ucf = 0;
  int32_t ret = BSP_ERROR_NONE;
  float acc_odr_after_ucf = 0;
  int32_t acc_fs_after_ucf = 0;

  ret = IKS4A1_MOTION_SENSOR_GetOutputDataRate(IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO, &acc_odr_before_ucf);
  if(BSP_ERROR_NONE == ret)
  {
	  ret = IKS4A1_MOTION_SENSOR_GetFullScale(IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO, &acc_fs_before_ucf);
  }

  length = MEMS_CONF_ARRAY_LEN(MLC_CONFIGURATION);
  i = 0;
  while ((i < length) & (ret == BSP_ERROR_NONE))
  {

	  if (MLC_CONFIGURATION[i].type == MEMS_CONF_OP_TYPE_DELAY)
	  {
		HAL_Delay(MLC_CONFIGURATION[i].data);
	  }
	  else if (MLC_CONFIGURATION[i].type == MEMS_CONF_OP_TYPE_WRITE)
	  {
		ret = IKS4A1_MOTION_SENSOR_Write_Register(IKS4A1_LIS2DUXS12_0, MLC_CONFIGURATION[i].address, MLC_CONFIGURATION[i].data);
	  }
	  else
	  {
		/* Unsupported opcode */
		ret = BSP_ERROR_FEATURE_NOT_SUPPORTED;
	  }
	  i++;
  }

  if (ret == BSP_ERROR_NONE)
  {
	  ret = IKS4A1_MOTION_SENSOR_GetOutputDataRate(IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO, &acc_odr_after_ucf);
  }

  if (ret == BSP_ERROR_NONE)
  {
	ret = IKS4A1_MOTION_SENSOR_GetFullScale(IKS4A1_LIS2DUXS12_0, MOTION_ACCELERO, &acc_fs_after_ucf);
  }

  if(ret == BSP_ERROR_NONE)
  {
	  if (acc_odr_after_ucf != acc_odr_before_ucf)
	  {
		LogInfo("WARNING: Accelerometer ODR changed during MLC Config: before %.02fHz, after %.02fHz\n", acc_odr_before_ucf, acc_odr_after_ucf);
	  }
	  if (acc_fs_after_ucf != acc_fs_before_ucf)
	  {
		LogInfo("WARNING: Accelerometer Full Scale changed during MLC Config: before %d, after %d\n", acc_fs_before_ucf, acc_fs_after_ucf);
	  }
  }

  return ret;
}
