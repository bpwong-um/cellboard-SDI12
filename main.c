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
#include <device.h>
#include "SDI12.h"
    
/*========== #BEGIN Define SDI12 sensors ==========//
//----------   SDI12 Array   ----------//
SDI12_sensor sensors[2];   

//----------  (1/2) Solinst  ----------//
char* labels[] = {"solinst_T","solinst_P"};
float values[] = {-99.0, -98.0};
SDI12_sensor solinst = { 
    .nvars   = 2,
    .address = "0",
    .labels  = labels,
    .values  = values
    // additional metadata should initialize to 0 or '\0' //
}; 

//----------  (2/2) Decagon  ----------//
char* GS3_labels[] = {"GS3_1","GS3_2","GS3_3"};
float GS3_values[] = {-99.0, -98.0, -99.9};
SDI12_sensor GS3 = {
    .nvars   = 3,
    .address = "1",
    .labels  = GS3_labels,
    .values  = GS3_values        
    // additional metadata should initialize to 0 or '\0' //
};  
// ========== #END   Define SDI12 sensors ==========//*/


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    

    /*
    uint8 nvars    =  2;
    char* address  = "0";
    char* labels[] = {"solinst_T","solinst_P"};
    float values[] = {-99.0, -98.0};
    SDI12_sensor solinst = { 
        .nvars   = nvars,
        .address = address,
        .labels  = labels,
        .values  = values,
        // additional metadata should initialize to 0 //
    }; 

    uint8 GS3_nvars    =  3;
    char* GS3_address  = "1";
    char* GS3_labels[] = {"GS3_1","GS3_2","GS3_3"};
    float GS3_values[] = {-99.0, -98.0, -99.9};
    SDI12_sensor GS3 = {
        .nvars   = GS3_nvars,
        .address = GS3_address,
        .labels  = GS3_labels,
        .values  = GS3_values        
        // additional metadata should initialize to 0 //
    };  

    SDI12_sensor sensors[2];    
    sensors[0] = solinst;
    sensors[1] = GS3;    
    //*/
    
    
    /*/
    sensors[0] = solinst;
    sensors[1] = GS3;
    
    char output[100] = {'\0'};
    uint8 i, j, k, valid;
    float M[ (sensors[1]).nvars ];
    //*/
    
    for(;;)
    {
        /*
        SDI12_start();
        SDI12_Power_Write(1u);
        
        
        // Iterate through each SDI12 sensor
        // Currently, this is set for debugging a single sensor at a time
        for (k = 0; k < 2;  k++) {
            
            valid = 0; // Reinitialize sensor status
            
            // Let the sensor power up max 10000 ms = 10 * 1000 ms
            for (i = 0; i < 10; i++) {
                CyDelay(1000u);
                
                if (SDI12_is_active(&sensors[k])){  
                    
                    
                    //valid = SDI12_change_address(&sensors[0],"0");
                    valid = SDI12_info(&sensors[k]); CyDelay(500u);

                    if (SDI12_take_measurement(&sensors[k])) {
                        valid = 1; // Successfully took a measurement
                        break;                    
                    } else {
                        valid = -2; // SDI12 sensor powered on, but unable to parse response
                    }            
                                            
                } else {
                    valid = -1; // SDI12 sensor not responding. It may be powered off or have a different address
                }
            }
            
            clear_str(output);
            
            for (j = 0; j < (sensors[k]).nvars; j++) {
                M[j] = (sensors[k]).values[j];
                sprintf(output,"%s %s %f", output, (sensors[k]).labels[j], (sensors[k]).values[j]);
            }            
        }
                    
        SDI12_Power_Write(0u);
        SDI12_stop(); 
        //*/
        
        zip_SDI12(3);
        CyDelay(5000u);
        
    }
}

/* [] END OF FILE */
