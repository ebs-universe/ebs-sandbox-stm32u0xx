

#include <time/cron.h>
#include <hal/uc.h>


int8_t test_value = 0;
cron_job_t uart_bare_job;
tm_system_t uart_bare_start;
tm_sdelta_t uart_bare_period = 100;


void uart_bare_send(void) {
    if (*(HAL_SFR_t *)(uart_if[DEBUG_TRANSPORT_INTFNUM]->hwif->base + OFS_UART_ISR) & USART_ISR_TXE_TXFNF) {
        uart_putc_bare(DEBUG_TRANSPORT_INTFNUM, 'a');
    }
}

void uart_buffered_send(void) {
    if (uart_reqlock(DEBUG_TRANSPORT_INTFNUM, 1, 0x00)){
        uart_putc(DEBUG_TRANSPORT_INTFNUM, 'a', 0x00, 0x00);
    } else {
        uart_send_trigger(DEBUG_TRANSPORT_INTFNUM);
    }
}

void uart_printf_send(void){
    test_value ++;
    uart_printf(DEBUG_TRANSPORT_INTFNUM, "|%5d|%10.2f|\n", test_value, (float)test_value / 100);
}

void start_uart_demo(void) {
    tm_current_time(&uart_bare_start);
    tm_cron_create_job_abs(&uart_bare_job, &uart_printf_send, &uart_bare_start, &uart_bare_period);
}
