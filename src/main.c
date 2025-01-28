

#include <string.h>
#include <application.h>
#include <irq_handlers.h>
#include <iomap.h>
#include <hal/uc.h>

#include "bsp/gpio.h"

#include <ucdm/ucdm.h>
#include "ebs/time_if.h"
#include <modbus/modbus.h>

#include <blink.h>

#include <demos/uart_demo.h>
#include <demos/qdelay_demo.h>
#include <demos/tm1637_demo.h>

ucdm_addr_t next_address;

static void setup_handlers(void) {
    __core_handler_inclusion = 1;
    __exti_handler_inclusion = 1;
    __shared_handler_inclusion = 1;
    __uart_handler_inclusion = 1;
}

void button_handler(uint8_t line);

void button_handler(uint8_t line) {
    gpio_set_output_toggle(GPIO_LED1);
}

static ucdm_addr_t setup_core(ucdm_addr_t ucdm_address) {
    setup_handlers();
    core_init();
    ucdm_init();
    ucdm_address = tm_init(ucdm_address);
    clock_set_default();
    #if APP_ENABLE_QDELAY
        qdelay_init();
    #endif
    return ucdm_address;
}


static ucdm_addr_t setup_peripherals(ucdm_addr_t ucdm_address) {
    application_gpio_init();
    
    #if APP_ENABLE_ID 
        id_init();
    #endif
    #if APP_ENABLE_ENTROPY
        entropy_init();
    #endif
    #if APP_ENABLE_EEPROM
        eeprom_init();
    #endif
    #if APP_ENABLE_CRYPTO
        crypto_init();
    #endif 
    #if APP_ENABLE_RTC
        rtc_init();
    #endif
    #if APP_ENABLE_TIME_SYNC
        setup_time_sync();
    #endif
    #if APP_ENABLE_OUTPUT_BLINK
        start_blink_task();
    #endif
    #if APP_ENABLE_BCIF
        #if APP_BCIF_TYPE == 0
            uart_init(APP_BCIF_INTFNUM);
        #endif
    #endif
    #if APP_ENABLE_PRIF
        #if APP_PRIF_TYPE == 0
            uart_init(APP_PRIF_INTFNUM);
        #endif
    #endif
    
    gpio_conf_interrupt_handler(GPIO_K0, &button_handler);
    gpio_arm_button_interrupt();

    return ucdm_address;
}

ucdm_addr_t setup_system(ucdm_addr_t ucdm_address) {
    ucdm_address = setup_core(ucdm_address);
    ucdm_address = setup_peripherals(ucdm_address);
    return ucdm_address;
}

ucdm_addr_t setup_application(ucdm_addr_t ucdm_address) {
    #if APP_ENABLE_MODBUS
        ucdm_address = modbus_init(ucdm_address, MODBUS_DEFAULT_DEVICE_ADDRESS);
    #endif
    return ucdm_address;
}

#ifndef PIO_UNIT_TESTING

int main(void) {
    ucdm_addr_t ucdm_address = 1;
    ucdm_address = setup_system(ucdm_address);
    ucdm_address = setup_application(ucdm_address);    

    // TODO Enabling uart_demo and tm1637_demo together causes 
    // a serious cron crash around when LCD output hits 9.2 
    // with tm1637 in the SM+MU tm1637 configuration. This needs 
    // to be debugged in priority.
    start_uart_demo();
    // start_tm1637_demo();

    while (1)
    {
        #if APP_ENABLE_TIME_CRON
        tm_cron_poll();
        #endif
        #if APP_ENABLE_MODBUS
        modbus_state_machine();
        #endif
        #if APP_ENABLE_TM1637 && TM1637_IMPL_SM 
            #if TM1637_SINGLETON 
            tm1637_state_machine();
            #else
            tm1637_state_machine(&tm1637_demo);
            #endif
        #endif
    }
}

#endif

