

#include <application.h>
#include <irq_handlers.h>
#include <iomap.h>

#include "bsp/gpio.h"
#include <blink.h>

#include "ebs/time_if.h"
#include <ucdm/ucdm.h>

#include <hal/uc.h>
#include <modbus/modbus.h>

ucdm_addr_t ucdm_address;

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
    return ucdm_address;
}


static ucdm_addr_t setup_peripherals(ucdm_addr_t ucdm_address) {
    application_gpio_init();
    
    #if APP_ENABLE_ID == 1 
        id_init();
    #endif
    #if APP_ENABLE_ENTROPY == 1 
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
    #if APP_ENABLE_BCIF
        #if APP_BCIF_TYPE == 0
            uart_init(APP_BCIF_INTFNUM);
        #endif
    #endif
    
    gpio_conf_interrupt_handler(GPIO_K0, &button_handler);
    gpio_arm_button_interrupt();

    return ucdm_address;
}

static void setup_time_sync(void) {
    #if APP_ENABLE_RTC
        tm_sync_current_from_rtc();
    #endif
    tm_sync_request_host();
}

ucdm_addr_t setup_system(ucdm_addr_t ucdm_address) {
    ucdm_address = setup_core(ucdm_address);
    ucdm_address = setup_peripherals(ucdm_address);
    return ucdm_address;
}

ucdm_addr_t setup_application(ucdm_addr_t ucdm_address) {
    setup_time_sync();
    #if APP_ENABLE_BLINK
    start_blink_task();
    #endif
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
    
    while (1)
    {
        #if APP_ENABLE_TIME_CRON
        tm_cron_poll();
        #endif
        #if APP_ENABLE_MODBUS
        modbus_state_machine();
        #endif
    }
}

#endif

