/*
Example for LOAD_CELL Click

    Date          : Apr 2018.
    Author        : Nemanja Medakovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO driver and performs the device reset, after which the next conversion cycle
  will be for channel A with 128 gate value. This function also selects the frequency of internal oscillator to 10Hz.
- Application Task - (code snippet) - Logs the converted results for both channels with different gate value on UART every 500ms.
  Note: The converted results are 24-bit digital value (min - 0x800000, max - 0x7FFFFF), and in this example the results will be shown as decimal value.

*/

#include "Click_LOAD_CELL_types.h"
#include "Click_LOAD_CELL_config.h"

uint32_t results;
char text[ 100 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite( "Initializing...", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    loadcell_gpioDriverInit( (T_LOADCELL_P)&_MIKROBUS1_GPIO );
    Delay_ms( 100 );
    
    loadcell_setMode( _LOADCELL_POWER_UP );
    loadcell_reset();
    loadcell_setRate( _LOADCELL_10HZ_INTERNAL_OSC );
    mikrobus_logWrite( "LOAD CELL is initialized", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 200 );
}

void applicationTask()
{
    loadcell_readResults( _LOADCELL_CHANN_B_GATE_32_NEXT, &results );
    LongWordToStr( results, text );
    mikrobus_logWrite( "Channel A (128 Gain): ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    
    loadcell_readResults( _LOADCELL_CHANN_A_GATE_64_NEXT, &results );
    LongWordToStr( results, text );
    mikrobus_logWrite( "Channel B (32 Gain): ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    
    loadcell_readResults( _LOADCELL_CHANN_A_GATE_128_NEXT, &results );
    LongWordToStr( results, text );
    mikrobus_logWrite( "Channel A (64 Gain): ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    
    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
