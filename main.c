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
#include "project.h"

#include "chronometer.h"
#include "tare.h"
#include "interface.h"
#include "uart_communication.h"

#include "mcp7940.h"    
#include "mpx10.h"
#include "lm75bd.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_counter_StartEx(msCounter);
    isr_tare_StartEx(tareMeasure);
    isr_rx_StartEx(uartRx);

    /* COMPONENT INITIALIZATION */
    LCD_Start();
    UART_Start();
    Counter_Start();
    I2C_Start();
    ADC_DelSig_Start();
    
    for(;;)
    {
        /* Tare Pressure */
        if (tare_measure){
            tare_measure = 0;
            MPX10_TarePressure();
        }
        
        /* Time Update Routine */
        if (receivedTime){                                  
            receivedTime = 0;
            MenuUART(CONFIRM_TIME_RECEPTION);                       
            MCP7940_TimeUpdate(SECONDS, MINUTES, FORMAT, AM_PM, HOUR, 
                                WKDAY, DATE, MONTH, LEAP_YEAR, YEAR);
        }
        
        /* Data Adquisition Routine per Second*/
        if (ms%1000 == 0){                       
            time.hour       =   MCP7940_GetHour();                  
            time.minutes    =   MCP7940_GetMinutes();
            time.seconds    =   MCP7940_GetSeconds();
            time.weekday    =   MCP7940_GetWeekDay();
            time.date       =   MCP7940_GetDate();
            time.month      =   MCP7940_GetMonth();
            time.year       =   MCP7940_GetYear();
            
            pressure = MPX10_GetPressure(); 
            temperature = LM75BD_GetTemperature();
            
            if (pressure > 8000){
                Buzzer_Write(1);
            }
            else Buzzer_Write(0);
            
            /* Data Display Routine */
            MenuLCD(SHOW_PREASSURE);
            MenuLCD(SHOW_TEMPERATURE);
            MenuLCD(SHOW_TIME);
            
            /* Computer Communication Routine */
            if (python_sync_up){
                MenuUART(SEND_TIME);
                MenuUART(SEND_DATE);
                MenuUART(SEND_PREASSURE);
                MenuUART(SEND_TEMPERATURE);
            }
        }
    }
}

/* [] END OF FILE */
