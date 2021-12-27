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
#include "tare.h"

/*** VARIABLES ***/
uint8 tare_measure = 0;

/*** FUNCTIONS ***/

/*** INTERRUPTS ***/
CY_ISR(tareMeasure){
    tare_measure = 1;
}

/* [] END OF FILE */
