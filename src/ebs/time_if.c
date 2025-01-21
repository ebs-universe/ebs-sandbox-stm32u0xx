

#include <time/time.h>
#include <time/sync.h>


uint32_t HAL_GetTick(void)
{
    // This needs to return a uint32_t, but actually 
    // returns an int64_t. This is a big problem. 

    tm_system_t current;
    tm_current_time(&current);
    return current;
}

void setup_time_sync(void) {
    // TODO Move this into libtime
    #if APP_ENABLE_RTC
        tm_sync_current_from_rtc();
    #endif
    tm_sync_request_host();
}
