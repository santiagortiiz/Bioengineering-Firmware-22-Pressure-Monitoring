/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*** INCLUDED COMPONENTS ***/
#include "uart_communication.h"
#include "mcp7940.h"

/*** VARIABLES ***/
static volatile uint8 i;
uint8 python_sync_up = 0;

uint8 receivedTime = 0;
uint8 buffer[10];                       // Store the parameters of the time when it
                                        // will be configured
/*** FUNCTIONS ***/

/*** INTERRUPTS ***/
CY_ISR(uartRx){
    if (python_sync_up){                // When communication is ON:
        if (UART_GetChar() == 0x00){    // it will stop if the UART get 0x00
            python_sync_up = 0;
        }
    }
    else{                               // Whe communication is OFF:
        buffer[i] = UART_GetChar();     // Store each received byte into the buffer
        i++;
        if (i == 10){                   // When the buffer is full, a flag that
            i = 0;                      // indicates that the time has received
            receivedTime = 1;           // is activated
            python_sync_up = 1;
        }
    }
}

/* [] END OF FILE */
