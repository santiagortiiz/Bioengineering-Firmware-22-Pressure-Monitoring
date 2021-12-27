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
#include "mpx10.h"

/*** VARIABLES ***/
uint32 V_offset = 0;
uint32 pressure = 0;

/*** FUNCTIONS ***/
void MPX10_TarePressure(void){
    uint32 ADC_value = 0;
    ADC_value = ADC_DelSig_Read32();                    // Convert the ADC value into microvolts     
    V_offset = ADC_DelSig_CountsTo_uVolts(ADC_value);   // Set the read voltage to the offset
}

uint32 MPX10_GetPressure(void){
    uint32 ADC_value = 0;
    uint32 pressure = 0;
    uint32 V_sensor = 0;
    
    ADC_value = ADC_DelSig_Read32();                    // Convert the ADC value into microvolts    
    V_sensor = ADC_DelSig_CountsTo_uVolts(ADC_value);   // Set the read voltage to the sensor voltage
    if (V_sensor > V_offset){
        pressure = (V_sensor - V_offset)*2/7;           // Pressure [Pa] Calculation
    }
    return pressure;
}

/*** INTERRUPTS ***/

/* [] END OF FILE */
