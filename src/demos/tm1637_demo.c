

#include "tm1637_demo.h"
#include <hal/uc/qdelay.h>
#include <time/time.h>
#include <time/cron.h>

#if APP_ENABLE_TM1637

static inline void reverse_block(uint8_t * buffer, uint8_t len) {
    uint8_t i = 0;
    while (i < len / 2) {
        char temp = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = temp;
        i++;
    }
}

// Remap for black 6 digit lcd display 
// https://thinkrobotics.com/products/6-digit-7-segment-display
void tm1637_remap(uint8_t content[]) {
    reverse_block(&content[0], 3);
    reverse_block(&content[3], 3);
}


#if !TM1637_SINGLETON

tm1637_t tm1637_demo = {
    .hwif = {
        .has_display = 1,
        .has_keys = 0,
        .len = TM1637_NUM_DIGITS,
        .gpio_clk = {
            .pin = TM1637_CLK_PIN,
            .port = TM1637_CLK_PORT
        },
        .gpio_dio = {
            .pin = TM1637_DAT_PIN,
            .port = TM1637_DAT_PORT
        },
        .remap = tm1637_remap,
    },
    .state = {
        .brightness = TM1637_DISP_BR10,
        .display_on = true
    }
};

#endif

cron_job_t tm1637_demo_job;
tm_system_t tm1637_demo_start;
tm_sdelta_t tm1637_demo_period = 500;
int8_t num = INT8_MIN;
seg7_pos_spec_t pos_spec = SEG7_POSSPEC_RIGHTALIGN | SEG7_POSSPEC_PUNCTUATE | (0x01);
tm1637_brightness_t brightness = 0;

void tm1637_demo_step(void) {
    #if TM1637_SINGLETON
    tm1637_set_display_number(num, pos_spec);
    #else  
    tm1637_set_display_number(&tm1637_demo, num, pos_spec);
    #endif
    num ++;

    if (!num) {
        pos_spec ^= SEG7_POSSPEC_LEFTALIGN;
    }

    #if TM1637_SINGLETON
    tm1637_set_display_brightness(brightness);
    #else
    tm1637_set_display_brightness(&tm1637_demo, brightness);
    #endif
    brightness ++;
    if (brightness == 8) { 
        brightness = 0;
    }
}

void start_tm1637_demo(void) {
    #if TM1637_SINGLETON
    tm1637_init();
    #else
    tm1637_init(&tm1637_demo);
    #endif
    tm_current_time(&tm1637_demo_start);
    tm_cron_create_job_abs(&tm1637_demo_job, &tm1637_demo_step, &tm1637_demo_start, &tm1637_demo_period);
}

#endif
