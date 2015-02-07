/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2012 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

#ifndef _LIBMAPLE_SPI_PRIVATE_H_
#define _LIBMAPLE_SPI_PRIVATE_H_

#define SPI_DEV(num)                              \
    {                                             \
        .regs    = SPI##num##_BASE,               \
        .clk_id  = RCC_SPI##num,                  \
        .irq_num = NVIC_SPI##num,                 \
    }



/* Helper macro for dispatch routines which service multiple interrupts. */
#define handle_irq(dier_sr, irq_mask, handlers, iid, handled_irq) do {  \
        if ((dier_sr) & (irq_mask)) {                                   \
            void (*__handler)(void) = (handlers)[iid];                  \
            if (__handler) {                                            \
                __handler();                                            \
                handled_irq |= (irq_mask);                              \
            }                                                           \
        }                                                               \
    } while (0)


static __always_inline void dispatch_general(spi_dev *dev) {
    /* timer_gen_reg_map *regs = (dev->regs).gen; */
    /* uint32 dsr = regs->DIER & regs->SR; */
    /* void (**hs)(void) = dev->handlers; */
    /* uint32 handled = 0; */

    /* handle_irq(dsr, TIMER_SR_TIF,   hs, TIMER_TRG_INTERRUPT,    handled); */
    /* handle_irq(dsr, TIMER_SR_CC4IF, hs, TIMER_CC4_INTERRUPT,    handled); */
    /* handle_irq(dsr, TIMER_SR_CC3IF, hs, TIMER_CC3_INTERRUPT,    handled); */
    /* handle_irq(dsr, TIMER_SR_CC2IF, hs, TIMER_CC2_INTERRUPT,    handled); */
    /* handle_irq(dsr, TIMER_SR_CC1IF, hs, TIMER_CC1_INTERRUPT,    handled); */
    /* handle_irq(dsr, TIMER_SR_UIF,   hs, TIMER_UPDATE_INTERRUPT, handled); */

    /* regs->SR &= ~handled; */
}


#endif
