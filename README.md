![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# LOAD_CELL Click

- **CIC Prefix**  : LOADCELL
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Apr 2018.

---


### Software Support

We provide a library for the LOAD_CELL Click on our [LibStock](https://libstock.mikroe.com/projects/view/2410/load-cell-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library reads 24-bit digital converted results from the desired channel with determined rate value (which determines the frequency of internal oscillator).
For more details check documentation.

Key functions :

- ``` uint8_t loadcell_readResults( uint8_t inputSel, uint32_t *dataOut ) ``` - Function reads the converted results from desired channel with determined gate value.
- ``` void loadcell_setRate( uint8_t rateSel ) ``` - Function selects the frequency of internal oscillator.
- ``` void loadcell_setMode( uint8_t powerMode ) ``` - Function puts the device in Power Up or Power Down Mode.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO driver and performs the device reset, after which the next conversion cycle
  will be for channel A with 128 gate value. This function also selects the frequency of internal oscillator to 10Hz.
- Application Task - (code snippet) - Logs the converted results for both channels with different gate value on UART every 500ms.
  Note: The converted results are 24-bit digital value (min - 0x800000, max - 0x7FFFFF), and in this example the results will be shown as decimal value.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2410/load-cell-click) page.

Other mikroE Libraries used in the example:

- Conversions
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
