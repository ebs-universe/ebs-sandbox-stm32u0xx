/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32u0xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
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
#ifndef __STM32U0xx_IT_H
#define __STM32U0xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif


// These are inlineable handlers defined by application code. We 
// include them here for later inlining into the actual IRQ Handlers.
#include <time/systick_handler.h>


// These IRQ handlers are defined by the HAL. These are included 
// here to:
//  - provide inlineable ISR blocks to the actual ISRs  
//  - bring the inclusion variable into scope
#include <hal_platform/shared_handlers.h>
#include <hal_platform/core_handlers.h>
#include <hal_platform/exti_handlers.h>
#include <hal_platform/entropy_handlers.h>
#include <hal_platform/crypto_handlers.h>
#include <hal_platform/rtc_handlers.h>
#include <hal_platform/uart_handlers.h>


/**
 * @name Core IRQ Handlers
 */
/**@{*/   
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
/**@}*/

/**
 * @name GPIO EXTI IRQ Handlers
 */
/**@{*/   
void EXTI0_1_IRQHandler(void);
void EXTI2_3_IRQHandler(void);
void EXTI4_15_IRQHandler(void);
/**@}*/ 

/**
 * @name UART IRQ Handlers
 */
/**@{*/   
void USART1_IRQHandler(void);
void USART2_LPUART2_IRQHandler(void);
void USART3_LPUART1_IRQHandler(void);
void USART4_LPUART3_IRQHandler(void);
/**@}*/ 


/**
 * @name Shared IRQ Handlers
 */
/**@{*/   
void RNG_CRYP_IRQHandler(void);
void RTC_TAMP_IRQHandler(void);
/**@}*/ 

/**
 * @name Other Handlers
 * 
 * This is not an IRQ, but needed by the HAL. Since there isn't a better 
 * place to put it, we put here for now. These are implemented with the shared
 * handlers.
 */
/**@{*/    
void Error_Handler(void);
/**@}*/ 

#ifdef __cplusplus
}
#endif

#endif /* __STM32U0xx_IT_H */
