/*!
    \file    gd32c233c_eval.h
    \brief   definitions for gd32c2x1_EVAL's leds, keys and COM ports hardware resources

    \version 2025-06-03, V1.0.0, firmware for gd32c2x1
*/

/*
    Copyright (c) 2025, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#ifndef GD32C231C_EVAL_H
#define GD32C231C_EVAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gd32c2x1.h"
#include <stdio.h>

/* exported types */
typedef enum {
    LED1 = 0,
    LED2 = 1,
} led_typedef_enum;

typedef enum {
    KEY_WAKEUP = 0,
    KEY_USER = 1,
} key_typedef_enum;

typedef enum {
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;

#define LEDn                             2U

#define LED1_PIN                         GPIO_PIN_6
#define LED1_GPIO_PORT                   GPIOB
#define LED1_GPIO_CLK                    RCU_GPIOB

#define LED2_PIN                         GPIO_PIN_7
#define LED2_GPIO_PORT                   GPIOB
#define LED2_GPIO_CLK                    RCU_GPIOB


/* start board low layer button */
#define KEYn                             1U

/* wakeup push-button */
#define K1_KEY_PIN                   GPIO_PIN_0
#define K1_KEY_GPIO_PORT             GPIOA
#define K1_KEY_GPIO_CLK              RCU_GPIOA
#define K1_KEY_EXTI_LINE             EXTI_0
#define K1_KEY_EXTI_PORT_SOURCE      EXTI_SOURCE_GPIOA
#define K1_KEY_EXTI_PIN_SOURCE       EXTI_SOURCE_PIN0
#define K1_KEY_EXTI_IRQn             EXTI0_IRQn

/* eval board low layer COM */
#define COMn                             1U

/* definition for COM, connected to USART0 */
#define EVAL_COM                         USART1
#define EVAL_COM_CLK                     RCU_USART1

#define EVAL_COM_TX_PIN                  GPIO_PIN_2
#define EVAL_COM_RX_PIN                  GPIO_PIN_3

#define EVAL_COM_GPIO_PORT               GPIOA
#define EVAL_COM_GPIO_CLK                RCU_GPIOA
#define EVAL_COM_AF                      GPIO_AF_1

/* function declarations */
/* configure led GPIO */
void gd_eval_led_init(led_typedef_enum lednum);
/* turn on selected led */
void gd_eval_led_on(led_typedef_enum lednum);
/* turn off selected led */
void gd_eval_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void gd_eval_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_eval_key_init(key_typedef_enum keynum, keymode_typedef_enum keymode);
/* return the selected key state */
uint8_t gd_eval_key_state_get(key_typedef_enum keynum);
/* configure COM port */
void gd_eval_com_init(uint32_t com);

#ifdef __cplusplus
}
#endif

#endif /* GD32C231C_EVAL_H */
