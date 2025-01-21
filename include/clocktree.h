
#ifndef CLOCKTREE_H
#define CLOCKTREE_H

// This is largely infomational. Code can use these defines as inputs, 
// but any changes to this file will need code changes elsewhere. 
// Generally, updates will need to be made to the CubeMX ioc, the code
// must be regenerated, and relevent portions of the code will need to 
// be cherry picked and synced. 

#define CLOCKTREE_IN_HSIRC      16000000LL
#define CLOCKTREE_IN_HSI48RC    48000000LL
#define CLOCKTREE_IN_MSIRC      48000000LL
#define CLOCKTREE_IN_LSIRC      32000LL
#define CLOCKTREE_IN_LSE        32768LL
#define CLOCKTREE_IN_HSE        

#define CLOCKTREE_PLLCLK_FREQ   56000000ULL
#define CLOCKTREE_PLLP_FREQ     56000000ULL
#define CLOCKTREE_PLLQ_FREQ     56000000ULL

#define CLOCKTREE_SYSCLK_FREQ   CLOCKTREE_PLLCLK_FREQ
#define CLOCKTREE_HCLK_FREQ     CLOCKTREE_SYSCLK_FREQ
#define CLOCKTREE_CPU_FREQ      CLOCKTREE_HCLK_FREQ
#define CLOCKTREE_SYSTICK_CLK   (CLOCKTREE_HCLK_FREQ / 8)

#define CLOCKTREE_PCLK_FREQ     CLOCKTREE_HCLK_FREQ
#define CLOCKTREE_TPCLK_FREQ    CLOCKTREE_PCLK_FREQ

#define CLOCKTREE_USART1_FREQ   CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_USART2_FREQ   CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_LPUART1_FREQ  CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_LPUART2_FREQ  CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_LPUART3_FREQ  CLOCKTREE_PCLK_FREQ

#define CLOCKTREE_UART1_FREQ    CLOCKTREE_USART1_FREQ
#define CLOCKTREE_UART2_FREQ    CLOCKTREE_USART2_FREQ
#define CLOCKTREE_UART3_FREQ    CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_UART4_FREQ    CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_UART5_FREQ    CLOCKTREE_LPUART1_FREQ
#define CLOCKTREE_UART6_FREQ    CLOCKTREE_LPUART1_FREQ
#define CLOCKTREE_UART7_FREQ    CLOCKTREE_LPUART1_FREQ

#define CLOCKTREE_TIM1_FREQ     CLOCKTREE_TPCLK_FREQ
#define CLOCKTREE_TIM2_FREQ     CLOCKTREE_TPCLK_FREQ
#define CLOCKTREE_TIM3_FREQ     CLOCKTREE_TPCLK_FREQ
#define CLOCKTREE_TIM6_FREQ     CLOCKTREE_TPCLK_FREQ
#define CLOCKTREE_TIM7_FREQ     CLOCKTREE_TPCLK_FREQ

#define CLOCKTREE_LPTIM1_FREQ   CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_LPTIM2_FREQ   CLOCKTREE_PCLK_FREQ
#define CLOCKTREE_LPTIM3_FREQ   CLOCKTREE_PCLK_FREQ

#define CLOCKTREE_ADC_FREQ      CLOCKTREE_SYSCLK_FREQ
#endif
