#pragma once

// STM32F4-Discovery green led - PD12
#define LED_PORT                GPIOD
#define LED_PIN                 GPIO_PIN_12
#define LED_PORT_CLK_ENABLE     __HAL_RCC_GPIOD_CLK_ENABLE
