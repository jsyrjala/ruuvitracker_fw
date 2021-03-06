#ifndef __STM32F4xx_CONF_H
#define __STM32F4xx_CONF_H

#if defined HSE_VALUE
#undef HSE_VALUE
#endif

#ifdef ELUA_BOARD_STM32F4DSCY
/* Undefine previous HSE value */
/* Define new (for STM32F4-DISCOVERY Kit) */
#define HSE_VALUE    (8000000)
#elif defined(ELUA_BOARD_RUUVIA)
#define HSE_VALUE	(12000000)
#endif

/* Include all headers from STM library */
#include "stm32f4xx_adc.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_crc.h"
#include "stm32f4xx_cryp.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dbgmcu.h"
#include "stm32f4xx_dcmi.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_flash.h"
#include "stm32f4xx_fsmc.h"
#include "stm32f4xx_hash.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_iwdg.h"
#include "stm32f4xx_pwr.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_rng.h"
#include "stm32f4xx_rtc.h"
#include "stm32f4xx_sdio.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_wwdg.h"
#include "misc.h"

#define assert_param(e) ((void)0)

#endif /* __STM32F4xx_CONF_H */
