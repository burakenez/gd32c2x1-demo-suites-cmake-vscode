/*!
    \file    main.c
    \brief   sleep wakeup through USRAT interrupt demo

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

#include "gd32c2x1.h"
#include "systick.h"
#include <stdio.h>
#include "gd32c231c_eval.h"

void led_config(void);
void led_flash(void);
void soft_delay(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* configure EVAL_COM */
    gd_eval_com_init(EVAL_COM);
    /* enable PMU clock */
    rcu_periph_clock_enable(RCU_PMU);
    /* configure led */
    led_config();
    /* USART interrupt configuration */
    nvic_irq_enable(USART0_IRQn, 0);
    /* enable EVAL_COM receive interrupt */
    usart_interrupt_enable(EVAL_COM, USART_INT_RBNE);
    /* led flash */
    led_flash();
    /* enter sleep mode */
    pmu_to_sleepmode(WFI_CMD);

    while(1) {
        led_flash();
    }
}

/*!
    \brief      configure led
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_config(void)
{
    gd_eval_led_init(LED1);
    gd_eval_led_init(LED2);
}

/*!
    \brief      toggle the led
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_flash(void)
{
    /* set all the LEDs on */
    gd_eval_led_on(LED1);
    gd_eval_led_on(LED2);

    soft_delay();
    /* set all the LEDs off */
    gd_eval_led_off(LED1);
    gd_eval_led_off(LED2);

    soft_delay();
}

/*!
    \brief      soft delay
    \param[in]  none
    \param[out] none
    \retval     none
*/
void soft_delay(void)
{
    volatile uint32_t i = 0xfffff;

    while(i--) {
    }
}
