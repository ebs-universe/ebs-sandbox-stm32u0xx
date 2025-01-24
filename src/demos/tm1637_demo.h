

#ifndef TM1637_DEMO_H
#define TM1637_DEMO_H

#include <application.h>

#if APP_ENABLE_TM1637

#include <tm1637/tm1637.h>

extern tm1637_t tm1637_demo;
void start_tm1637_demo(void);

#endif
#endif