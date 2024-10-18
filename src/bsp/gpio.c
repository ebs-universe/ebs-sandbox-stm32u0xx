

#include "iomap.h"
#include <hal/uc/gpio.h>


static void gpio_init_board_leds(void){
    gpio_set_output_high(GPIO_LED1);
    gpio_conf_output(GPIO_LED1);
    gpio_conf_outmode_pp(GPIO_LED1);
    gpio_conf_speed(GPIO_LED1, GPIO_SPEED_FREQ_LOW);
}

static void gpio_init_board_buttons(void){
    gpio_conf_input(GPIO_K0);
    gpio_conf_pullup(GPIO_K0);
    gpio_conf_interrupt(GPIO_K0, GPIO_INT_EDGE_FALLING);
}

void gpio_arm_button_interrupt(void){
    gpio_interrupt_arm(GPIO_K0);
}

void gpio_disarm_button_interrupt(void){
    gpio_interrupt_disarm(GPIO_K0);
}

void gpio_init_bcif(void) {
    gpio_conf_periph(GPIO_BCTX, GPIO_AF7_USART2);
    gpio_conf_periph(GPIO_BCRX, GPIO_AF7_USART2);
}

void application_gpio_init (void){
    gpio_init();
    gpio_init_board_leds();
    gpio_init_board_buttons();
    #if APP_ENABLE_BCIF
    gpio_init_bcif();
    #endif
    #if APP_ENABLE_PRIF
    gpio_init_prif();
    #endif
}
