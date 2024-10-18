

#include <time/cron.h>
#include <hal/uc.h>


cron_job_t uart_bare_job;
tm_system_t uart_bare_start;
tm_sdelta_t uart_bare_period = 100;


void uart_bare_send(void) {
    if (*(HAL_SFR_t *)(uart2_if.hwif->base + OFS_UART_ISR) & USART_ISR_TXE_TXFNF) {
            uart_putc_bare(APP_BCIF_INTFNUM, 'a');
    }
}

void uart_buffered_send(void) {
    if (uart_reqlock(APP_BCIF_INTFNUM, 1, 0x00)){
        uart_putc(APP_BCIF_INTFNUM, 'a', 0x00, 0x00);
    } else {
        uart_send_trigger(APP_BCIF_INTFNUM);
    }
}


void start_uart_bare_task(void) {
    tm_current_time(&uart_bare_start);
    tm_cron_create_job_abs(&uart_bare_job, &uart_bare_send, &uart_bare_start, &uart_bare_period);
}
