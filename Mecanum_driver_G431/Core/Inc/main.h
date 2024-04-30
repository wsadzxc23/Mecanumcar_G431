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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "strings.h"
#include "stdlib.h"

#include "chassis/motor.h"
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MotorD_DIR1_Pin GPIO_PIN_13
#define MotorD_DIR1_GPIO_Port GPIOC
#define MotorD_DIR2_Pin GPIO_PIN_14
#define MotorD_DIR2_GPIO_Port GPIOC
#define MotorA_PWM_Pin GPIO_PIN_0
#define MotorA_PWM_GPIO_Port GPIOC
#define MotorB_PWM_Pin GPIO_PIN_1
#define MotorB_PWM_GPIO_Port GPIOC
#define MotorC_PWM_Pin GPIO_PIN_2
#define MotorC_PWM_GPIO_Port GPIOC
#define MotorD_PWM_Pin GPIO_PIN_3
#define MotorD_PWM_GPIO_Port GPIOC
#define EncodeA_B_Pin GPIO_PIN_1
#define EncodeA_B_GPIO_Port GPIOA
#define SPI_CS_Pin GPIO_PIN_4
#define SPI_CS_GPIO_Port GPIOA
#define EncodeA_A_Pin GPIO_PIN_5
#define EncodeA_A_GPIO_Port GPIOA
#define EncodeB_A_Pin GPIO_PIN_6
#define EncodeB_A_GPIO_Port GPIOA
#define EncodeB_B_Pin GPIO_PIN_7
#define EncodeB_B_GPIO_Port GPIOA
#define SYS_LED_Pin GPIO_PIN_4
#define SYS_LED_GPIO_Port GPIOC
#define EncodeD_A_Pin GPIO_PIN_6
#define EncodeD_A_GPIO_Port GPIOC
#define EncodeD_B_Pin GPIO_PIN_7
#define EncodeD_B_GPIO_Port GPIOC
#define IMU_INT_Pin GPIO_PIN_8
#define IMU_INT_GPIO_Port GPIOA
#define EncodeC_A_Pin GPIO_PIN_11
#define EncodeC_A_GPIO_Port GPIOA
#define EncodeC_B_Pin GPIO_PIN_12
#define EncodeC_B_GPIO_Port GPIOA
#define MotorA_DIR1_Pin GPIO_PIN_2
#define MotorA_DIR1_GPIO_Port GPIOD
#define MotorA_DIR2_Pin GPIO_PIN_3
#define MotorA_DIR2_GPIO_Port GPIOB
#define MotorB_DIR1_Pin GPIO_PIN_4
#define MotorB_DIR1_GPIO_Port GPIOB
#define MotorB_DIR2_Pin GPIO_PIN_5
#define MotorB_DIR2_GPIO_Port GPIOB
#define MotorC_DIR1_Pin GPIO_PIN_6
#define MotorC_DIR1_GPIO_Port GPIOB
#define MotorC_DIR2_Pin GPIO_PIN_7
#define MotorC_DIR2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
