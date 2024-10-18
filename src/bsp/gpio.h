

#ifndef BSP_GPIO_H
#define BSP_GPIO_H

void application_gpio_init(void);

void gpio_arm_button_interrupt(void);
void gpio_disarm_button_interrupt(void);

void gpio_init_bcif(void);

#endif
