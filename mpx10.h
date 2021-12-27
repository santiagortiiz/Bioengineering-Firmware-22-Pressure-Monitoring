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

#ifndef MPX10_H
    #define MPX10_H
    
    #include "project.h"

    /*** MACROS ***/
    #define MICROVOLTS 0
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern uint32 V_offset;
    extern uint32 pressure;
    
    /*** FUNCTION PROTOTYPES ***/
    void MPX10_TarePressure(void);
    uint32 MPX10_GetPressure(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */
