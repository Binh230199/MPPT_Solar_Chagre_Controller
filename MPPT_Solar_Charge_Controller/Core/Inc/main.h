/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUT_LEFT_Pin GPIO_PIN_0
#define BUT_LEFT_GPIO_Port GPIOC
#define BUT_RIGHT_Pin GPIO_PIN_1
#define BUT_RIGHT_GPIO_Port GPIOC
#define BUT_BACK_Pin GPIO_PIN_2
#define BUT_BACK_GPIO_Port GPIOC
#define BUT_SELECT_Pin GPIO_PIN_3
#define BUT_SELECT_GPIO_Port GPIOC
#define VIN_Pin GPIO_PIN_0
#define VIN_GPIO_Port GPIOA
#define IIN_Pin GPIO_PIN_1
#define IIN_GPIO_Port GPIOA
#define VOUT_Pin GPIO_PIN_2
#define VOUT_GPIO_Port GPIOA
#define IOUT_Pin GPIO_PIN_3
#define IOUT_GPIO_Port GPIOA
#define TEMP_Pin GPIO_PIN_4
#define TEMP_GPIO_Port GPIOA
#define PWM_OUT_Pin GPIO_PIN_5
#define PWM_OUT_GPIO_Port GPIOA
#define LOAD_Pin GPIO_PIN_6
#define LOAD_GPIO_Port GPIOA
#define ENA_INVERTER_Pin GPIO_PIN_7
#define ENA_INVERTER_GPIO_Port GPIOA
#define LED_INDICATE_Pin GPIO_PIN_12
#define LED_INDICATE_GPIO_Port GPIOD
#define FAN_Pin GPIO_PIN_13
#define FAN_GPIO_Port GPIOD
#define BUCK_ENABLE_Pin GPIO_PIN_14
#define BUCK_ENABLE_GPIO_Port GPIOD
#define ANTI_BACKFLOW_Pin GPIO_PIN_15
#define ANTI_BACKFLOW_GPIO_Port GPIOD
#define GPIO2_Pin GPIO_PIN_6
#define GPIO2_GPIO_Port GPIOC
#define GPIO15_Pin GPIO_PIN_7
#define GPIO15_GPIO_Port GPIOC
#define BCCU_Pin GPIO_PIN_8
#define BCCU_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
