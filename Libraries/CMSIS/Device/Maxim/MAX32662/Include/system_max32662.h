/**
 * @file    system_max32662.h
 * @brief   System-specific header file
 */

/******************************************************************************
 * Copyright (C) 2023 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 ******************************************************************************/

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32662_INCLUDE_SYSTEM_MAX32662_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32662_INCLUDE_SYSTEM_MAX32662_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/

/*  This define is included to prevent build errors in existing code.
    New code should update HF_EXTCLK_FREQ to match the frequency of the external clock. */
#ifndef EXTCLK_FREQ
#define EXTCLK_FREQ 75000000
#endif

/* NOTE: HF_EXTCLK_FREQ needs to be defined by user based on the clock they supply */
#ifndef HF_EXTCLK_FREQ
#define HF_EXTCLK_FREQ EXTCLK_FREQ
#endif

/* NOTE: LP_EXTCLK_FREQ needs to be defined by user based on the clock they supply */
#ifndef LP_EXTCLK_FREQ
#define LP_EXTCLK_FREQ 12500000
#endif

/* NOTE: This is the nominal value for INRO. The actual value may vary from chip to chip. 
         Update if use of this oscillator requires precise timing.*/
/* NOTE: INRO was previously named NANORING */
#ifndef INRO_FREQ
#define INRO_FREQ 8000
#endif

#ifndef IPO_FREQ
#define IPO_FREQ 100000000
#endif

#ifndef ERFO_FREQ
#define ERFO_FREQ 24576000
#endif

#ifndef IBRO_FREQ
#define IBRO_FREQ 7372800
#endif

#ifndef ERTCO_FREQ
#define ERTCO_FREQ 32768
#endif

#ifndef HIRC_FREQ
#define HIRC_FREQ IPO_FREQ
#endif

#ifndef HFX_FREQ
#define HFX_FREQ 32768
#endif

/* NOTE: This is the nominal value for NANORING. The actual value may vary from chip to chip. 
         Update if use of this oscillator requires precise timing.*/
#ifndef NANORING_FREQ
#define NANORING_FREQ 8000
#endif

#ifndef HIRC96_FREQ
#define HIRC96_FREQ 96000000
#endif

extern uint32_t SystemCoreClock; /*!< System Clock Frequency (Core Clock)  */
#ifndef PeripheralClock
#define PeripheralClock (SystemCoreClock / 2) /*!< Peripheral Clock Frequency */
#endif

/*
 * Initialize the system
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void);

/*
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32662_INCLUDE_SYSTEM_MAX32662_H_
