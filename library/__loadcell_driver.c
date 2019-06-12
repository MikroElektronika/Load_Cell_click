/*
    __loadcell_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__loadcell_driver.h"
#include "__loadcell_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LOADCELL_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _LOADCELL_CHANN_A_GATE_128_NEXT = 0;
const uint8_t _LOADCELL_CHANN_B_GATE_32_NEXT = 1;
const uint8_t _LOADCELL_CHANN_A_GATE_64_NEXT = 2;

const uint8_t _LOADCELL_10HZ_INTERNAL_OSC = 0;
const uint8_t _LOADCELL_80HZ_INTERNAL_OSC = 1;

const uint8_t _LOADCELL_POWER_UP = 0;
const uint8_t _LOADCELL_POWER_DOWN = 1;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LOADCELL_DRV_SPI__

void loadcell_spiDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LOADCELL_DRV_I2C__

void loadcell_i2cDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LOADCELL_DRV_UART__

void loadcell_uartDriverInit(T_LOADCELL_P gpioObj, T_LOADCELL_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

void loadcell_gpioDriverInit(T_LOADCELL_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );
}

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t loadcell_readResults( uint8_t inputSel, uint32_t *dataOut )
{
    uint8_t count;
    uint8_t i;
    uint32_t retVal = 0;
    uint32_t temp = 0;
    
    switch (inputSel)
    {
        case 0 :
        {
            count = 25;
        break;
        }
        case 1 :
        {
            count = 26;
        break;
        }
        case 2 :
        {
            count = 27;
        break;
        }
        default :
        {
            return 1;
        }
    }
    
    while (loadcell_checkOut());
    Delay_1us();
    
    for (i = 24; i > 0; i--)
    {
        hal_gpio_pwmSet( 1 );
        Delay_1us();
        temp = loadcell_checkOut();
        temp <<= i - 1;
        retVal |= temp;
        hal_gpio_pwmSet( 0 );
        Delay_1us();
    }
    count -= 24;
    while (count)
    {
        hal_gpio_pwmSet( 1 );
        Delay_1us();
        hal_gpio_pwmSet( 0 );
        Delay_1us();
        count--;
    }
    *dataOut = retVal;
    
    return 0;
}

void loadcell_setRate( uint8_t rateSel )
{
    if (rateSel)
        hal_gpio_csSet( 1 );
    else
        hal_gpio_csSet( 0 );
}

uint8_t loadcell_checkOut( void )
{
    if (hal_gpio_intGet())
        return 1;
    else
        return 0;
}

void loadcell_reset( void )
{
    hal_gpio_pwmSet( 1 );
    Delay_50us();
    Delay_50us();
    hal_gpio_pwmSet( 0 );
    Delay_50us();
}

void loadcell_setMode( uint8_t powerMode )
{
    if (powerMode)
        hal_gpio_pwmSet( 1 );
    else
        hal_gpio_pwmSet( 0 );
    Delay_50us();
    Delay_50us();
}

/* -------------------------------------------------------------------------- */
/*
  __loadcell_driver.c

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