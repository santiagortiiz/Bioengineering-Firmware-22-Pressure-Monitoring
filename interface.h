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

#ifndef INTERFACE_H
    #define INTERFACE_H
    
    #include "project.h"

    /*** MACROS ***/
    #define SHOW_PREASSURE 0
    #define SHOW_TEMPERATURE 1
    #define SHOW_TIME 2
    #define SHOW_PY_STATE 3
    
    #define CONFIRM_TIME_RECEPTION 0
    #define SEND_TIME 1
    #define SEND_DATE 2
    #define SEND_PREASSURE 3
    #define SEND_TEMPERATURE 4
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    
    /*** FUNCTION PROTOTYPES ***/
    void MenuLCD(uint8);
    void MenuUART(uint8);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
