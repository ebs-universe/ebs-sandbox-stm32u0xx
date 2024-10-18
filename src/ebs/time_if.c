

#include <hal/uc.h>
#include <stdint.h>
#include "time_if.h"


uint32_t HAL_GetTick(void)
{
    // This needs to return a uint32_t, but actually 
    // returns an int64_t. This is a big problem. 

    tm_system_t current;
    tm_current_time(&current);
    return current;
}
