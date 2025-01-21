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
#ifndef __IOMAP_H
#define __IOMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32u0xx_hal.h"
#include "clocktree.h"
#include "memmap.h"
#include "priorities.h"

/**
 * @name GPIOs for User Buttons
 */
/**@{*/ 
#define K0_PIN              13  
#define K0_PORT             GPIOC_BASE
#define GPIO_K0             K0_PORT, K0_PIN  
/**@}*/ 

/**
 * @name GPIOs for User LEDs
 */
/**@{*/ 
#define LED1_PIN            5   
#define LED1_PORT           GPIOA_BASE
#define GPIO_LED1           LED1_PORT, LED1_PIN 
/**@}*/ 

/**
 * @name GPIOs associated with crystal oscillators
 * 
 * The nucleo does not have a high speed crystal installed. 
 */
/**@{*/ 
#define OSC32IN_PIN         14   
#define OSC32IN_PORT        GPIOC_BASE
#define GPIO_OSC32IN        OSC32IN_PORT, OSC32IN_PIN 

#define OSC32OUT_PIN        15   
#define OSC32OUT_PORT       GPIOC_BASE
#define GPIO_OSC32OUT       OSC32OUT_PORT, OSC32OUT_PIN 

#define OSCIN_PIN           0   
#define OSCIN_PORT          GPIOF_BASE
#define GPIO_OSCIN          OSCIN_PORT, OSCIN_PIN 

#define OSCOUT_PIN          1   
#define OSCOUT_PORT         GPIOF_BASE
#define GPIO_OSCOUT         OSCOUT_PORT, OSCOUT_PIN 
/**@}*/ 

/**
 * @name GPIOs associated with the Backchannel UART Interface
 * 
 * This is connected to the VCP on the on-board stlink of the 
 * nucleo board
 * 
 */
/**@{*/ 
#define BCTX_PIN            2
#define BCTX_PORT           GPIOA_BASE
#define GPIO_BCTX           BCTX_PORT, BCTX_PIN

#define BCRX_PIN            3
#define BCRX_PORT           GPIOA_BASE
#define GPIO_BCRX           BCRX_PORT, BCRX_PIN
/**@}*/ 

/**
 * @name GPIOs associated with the SWD Debug Interface
 * 
 * This is connected to the on-board stlink of the 
 * nucleo board
 * 
 */
/**@{*/ 
#define SWDIO_PIN           13
#define SWDIO_PORT          GPIOA_BASE
#define GPIO_SWDIO          SWDIO_PORT, SWDIO_PIN

#define SWCLK_PIN           14
#define SWCLK_PORT          GPIOA_BASE
#define GPIO_SWCLK          SWCLK_PORT, SWCLK_PIN
/**@}*/ 

/**
 * @name GPIOs associated I2C1 Interface
 * 
 * CubeMX decided this needed to be defined, as yet unclear why.
 * 
 */
/**@{*/ 
#define I2C1_SCL_PIN        8
#define I2C1_SCL_PORT       GPIOB_BASE
#define GPIO_I2C1_SCL       I2C1_SCL_PORT, I2C1_SCL_PIN

#define I2C1_SDA_PIN        9
#define I2C1_SDA_PORT       GPIOB_BASE
#define GPIO_I2C1_SDA       I2C1_SDA_PORT, I2C1_SDA_PIN
/**@}*/ 

/**
 * @name GPIOs associated with the RTC
 * 
 */
/**@{*/ 
#define RTC_1HZ_OUT_PIN     2
#define RTC_1HZ_OUT_PORT    GPIOB_BASE
#define RTC_1HZ_OUT         RTC_1HZ_OUT_PORT, RTC_1HZ_OUT_PIN
/**@}*/ 

/**
 * @name GPIOs associated with the TM1637 7 segment driver
 * 
 */
/**@{*/ 
#define TM1637_CLK_PIN      2
#define TM1637_CLK_PORT     GPIOC_BASE
#define GPIO_TM1637_CLK     TM1637_CLK_PORT, TM1637_CLK_PIN

#define TM1637_DAT_PIN      3
#define TM1637_DAT_PORT     GPIOC_BASE
#define GPIO_TM1637_DAT     TM1637_DAT_PORT, TM1637_DAT_PIN
/**@}*/

/**
 * @name Application Specific GPIOs
 */
/**@{*/
#define DBG_SCOPE1_PIN       10
#define DBG_SCOPE1_PORT      GPIOC_BASE
#define GPIO_DBG_SCOPE1      DBG_SCOPE1_PORT, DBG_SCOPE1_PIN
/**@}*/

#ifdef __cplusplus
}         
#endif

#endif
