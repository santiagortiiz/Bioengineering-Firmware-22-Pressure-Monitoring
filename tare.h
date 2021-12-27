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

#ifndef TARE_H
    #define TARE_H
    
    #include "project.h"

    /*** MACROS ***/
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern uint8 tare_measure;
    
    /*** FUNCTION PROTOTYPES ***/
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(tareMeasure);
    
#endif

/* [] END OF FILE */
