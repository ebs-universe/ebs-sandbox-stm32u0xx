

#include "qdelay_demo.h"

qdelay_t delay;


void qdelay_demo(void) {
   
    while (1)
    {
        gpio_set_output_high(GPIO_DBG_SCOPE1);
        
        qdelay_start(&delay, 10);
        while (!qdelay_check_done(&delay)) { ; }
        
        gpio_set_output_low(GPIO_DBG_SCOPE1);

        qdelay_us(1);
    }
    
}