/*
    DISCLAIMER:
    CODE WILL CREATE INFINITE LOOP
    NO SENSORS CONNECTED =
    NO CHANGE IN FLAG
*/

#include <Stdio.h>

// Sensor struct with data and flag
// already type def
// so can just use SENSOR
typedef struct SENSOR{
    int sensor_flag;
    int data;
} SENSOR;

int main(){
    // volatile means the compiler doesn't change or
    // modify the code in any way
    // this only applies to code with SENSOR
    volatile SENSOR *sensor;
    
    // while there are no values
    while(!(sensor->sensor_flag)){
        // doesn't do anything
    }

    // while(1){
    //     if(sensor->sensor_flag) break;
    // }
    
    printf("Data : %d\n", sensor->data);
}