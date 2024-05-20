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
#define BUT_UP_Pin GPIO_PIN_0
#define BUT_UP_GPIO_Port GPIOC
#define BUT_UP_EXTI_IRQn EXTI0_IRQn
#define BUT_DOWN_Pin GPIO_PIN_1
#define BUT_DOWN_GPIO_Port GPIOC
#define BUT_DOWN_EXTI_IRQn EXTI1_IRQn
#define BUT_BACK_Pin GPIO_PIN_2
#define BUT_BACK_GPIO_Port GPIOC
#define BUT_BACK_EXTI_IRQn EXTI2_IRQn
#define BUT_SEL_Pin GPIO_PIN_3
#define BUT_SEL_GPIO_Port GPIOC
#define BUT_SEL_EXTI_IRQn EXTI3_IRQn
#define I_BATTERY_Pin GPIO_PIN_0
#define I_BATTERY_GPIO_Port GPIOA
#define TEMPERATURE_Pin GPIO_PIN_1
#define TEMPERATURE_GPIO_Port GPIOA
#define V_SOLAR_Pin GPIO_PIN_2
#define V_SOLAR_GPIO_Port GPIOA
#define I_SOLAR_Pin GPIO_PIN_3
#define I_SOLAR_GPIO_Port GPIOA
#define V_BATTERY_Pin GPIO_PIN_4
#define V_BATTERY_GPIO_Port GPIOA
#define PWM_Pin GPIO_PIN_5
#define PWM_GPIO_Port GPIOA
#define INVERTER_CTRL_Pin GPIO_PIN_6
#define INVERTER_CTRL_GPIO_Port GPIOC
#define LOAD_CTRL_Pin GPIO_PIN_8
#define LOAD_CTRL_GPIO_Port GPIOC
#define BFC_Pin GPIO_PIN_8
#define BFC_GPIO_Port GPIOA
#define BUCK_EN_Pin GPIO_PIN_10
#define BUCK_EN_GPIO_Port GPIOC
#define FAN_Pin GPIO_PIN_11
#define FAN_GPIO_Port GPIOC
#define LED_GRE_Pin GPIO_PIN_0
#define LED_GRE_GPIO_Port GPIOD
#define LED_YEL_Pin GPIO_PIN_2
#define LED_YEL_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_4
#define LED_RED_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
