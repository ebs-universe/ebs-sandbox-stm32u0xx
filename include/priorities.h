

#define uC_NVIC_PRIORITY_CONF   NVIC_PRIORITYGROUP_2

#define PRIO_INT_HIGHEST        0
#define PRIO_INT_HIGH           1
#define PRIO_INT_NORMAL         2
#define PRIO_INT_LOW            3
#define PRIO_NONE               0xFF

typedef enum {
    _PRIO_INT_HIGHEST = PRIO_INT_HIGHEST,
    _PRIO_INT_HIGH    = PRIO_INT_HIGH,
    _PRIO_INT_NORMAL  = PRIO_INT_NORMAL,
    _PRIO_INT_LOW     = PRIO_INT_LOW,
    _PRIO_NONE        = PRIO_NONE
} EBS_PRIORITY_t;

#define PRIO_SYSTICK            PRIO_INT_LOW
#define PRIO_ADC                PRIO_INT_HIGHEST
#define PRIO_ENTROPY            PRIO_INT_LOW

#define PRIO_GPIO0_1            PRIO_INT_NORMAL         
#define PRIO_GPIO2_3            PRIO_INT_NORMAL
#define PRIO_GPIO4_15           PRIO_INT_NORMAL

#define PRIO_TIMER15            PRIO_INT_LOW

#define PRIO_USART1             PRIO_INT_NORMAL
#define PRIO_USART2             PRIO_INT_NORMAL
#define PRIO_USART3             PRIO_INT_NORMAL
#define PRIO_USART4             PRIO_INT_NORMAL
#define PRIO_USART5             PRIO_INT_NORMAL
#define PRIO_USART6             PRIO_INT_NORMAL
#define PRIO_USART7             PRIO_INT_NORMAL

#define PRIO_USB                PRIO_INT_NORMAL

