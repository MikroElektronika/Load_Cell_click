/*
    __loadcell_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __loadcell_driver.h
@brief    LOAD_CELL Driver
@mainpage LOAD_CELL Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   LOADCELL
@brief      LOAD_CELL Click Driver
@{

| Global Library Prefix | **LOADCELL** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Apr 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LOADCELL_H_
#define _LOADCELL_H_

/** 
 * @macro T_LOADCELL_P
 * @brief Driver Abstract type 
 */
#define T_LOADCELL_P    const uint8_t*

/** @defgroup LOADCELL_COMPILE Compilation Config */              /** @{ */

//  #define   __LOADCELL_DRV_SPI__                            /**<     @macro __LOADCELL_DRV_SPI__  @brief SPI driver selector */
//  #define   __LOADCELL_DRV_I2C__                            /**<     @macro __LOADCELL_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LOADCELL_DRV_UART__                           /**<     @macro __LOADCELL_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LOADCELL_VAR Variables */                           /** @{ */

extern const uint8_t _LOADCELL_CHANN_A_GATE_128_NEXT;
extern const uint8_t _LOADCELL_CHANN_B_GATE_32_NEXT;
extern const uint8_t _LOADCELL_CHANN_A_GATE_64_NEXT;

extern const uint8_t _LOADCELL_10HZ_INTERNAL_OSC;
extern const uint8_t _LOADCELL_80HZ_INTERNAL_OSC;

extern const uint8_t _LOADCELL_POWER_UP;
extern const uint8_t _LOADCELL_POWER_DOWN;

                                                                       /** @} */
/** @defgroup LOADCELL_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LOADCELL_INIT Driver Initialization */              /** @{ */

#ifdef   __LOADCELL_DRV_SPI__
void loadcell_spiDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P spiObj);
#endif
#ifdef   __LOADCELL_DRV_I2C__
void loadcell_i2cDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P i2cObj, uint8_t slave);
#endif
#ifdef   __LOADCELL_DRV_UART__
void loadcell_uartDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P uartObj);
#endif

void loadcell_gpioDriverInit(T_LOADCELL_P gpioObj);
                                                                       /** @} */
/** @defgroup LOADCELL_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Results Read function
 *
 * @param[in] inputSel         Selects witch channel with determined gate will be converted next
 * @param[out] dataOut         Buffer where results be stored
 *
 * @returns 0 - OK, 1 - Wrong input selection parameter
 *
 * Function reads the converted results from desired channel with determined gate value.
 */
uint8_t loadcell_readResults( uint8_t inputSel, uint32_t *dataOut );

/**
 * @brief Rate Set function
 *
 * @param[in] rateSel      0 - 10Hz, 1 - 80Hz
 *
 * Function selects the frequency of internal oscillator.
 */
void loadcell_setRate( uint8_t rateSel );

/**
 * @brief Output Check function
 *
 * @returns The state of output pin
 *
 * Function checks the state of output pin (gets one bit of the converted results or checks is output data ready for retrieval).
 */
uint8_t loadcell_checkOut( void );

/**
 * @brief Reset function
 *
 * Function performs the device reset and puts the device back in normal operating mode.
 */
void loadcell_reset( void );

/**
 * @brief Power Mode Set function
 *
 * @param[in] powerMode          0 - Power Up Mode, 1 - Power Down Mode
 *
 * Function puts the device in Power Up or Power Down Mode.
 */
void loadcell_setMode( uint8_t powerMode );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_LOAD_CELL_STM.c
    @example Click_LOAD_CELL_TIVA.c
    @example Click_LOAD_CELL_CEC.c
    @example Click_LOAD_CELL_KINETIS.c
    @example Click_LOAD_CELL_MSP.c
    @example Click_LOAD_CELL_PIC.c
    @example Click_LOAD_CELL_PIC32.c
    @example Click_LOAD_CELL_DSPIC.c
    @example Click_LOAD_CELL_AVR.c
    @example Click_LOAD_CELL_FT90x.c
    @example Click_LOAD_CELL_STM.mbas
    @example Click_LOAD_CELL_TIVA.mbas
    @example Click_LOAD_CELL_CEC.mbas
    @example Click_LOAD_CELL_KINETIS.mbas
    @example Click_LOAD_CELL_MSP.mbas
    @example Click_LOAD_CELL_PIC.mbas
    @example Click_LOAD_CELL_PIC32.mbas
    @example Click_LOAD_CELL_DSPIC.mbas
    @example Click_LOAD_CELL_AVR.mbas
    @example Click_LOAD_CELL_FT90x.mbas
    @example Click_LOAD_CELL_STM.mpas
    @example Click_LOAD_CELL_TIVA.mpas
    @example Click_LOAD_CELL_CEC.mpas
    @example Click_LOAD_CELL_KINETIS.mpas
    @example Click_LOAD_CELL_MSP.mpas
    @example Click_LOAD_CELL_PIC.mpas
    @example Click_LOAD_CELL_PIC32.mpas
    @example Click_LOAD_CELL_DSPIC.mpas
    @example Click_LOAD_CELL_AVR.mpas
    @example Click_LOAD_CELL_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __loadcell_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */