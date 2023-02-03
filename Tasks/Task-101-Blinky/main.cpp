// Task 101 Blinky - Lewis Milburn
// [COMPLETED] 03/02/2023

#include "mbed.h"

// LED objects
DigitalOut greenLED(LED1);
DigitalOut blueLED(LED2);
DigitalOut redLED(LED3);

//The main function - all executable C / C++ applications have a main function. This is our entry point in the software
int main() 
{
    // ALL the repeating code is contained in a  “while loop”
    while(true) 
    { 
        //The code between the { curly braces } is the code that is repeated forever

        // Sequence 1 - Red and green
        redLED = 1; 
        greenLED = 1; 
        blueLED = 0;

        // Wait 0.2 second (1 million microseconds)
        wait_us(500000);

        // Sequence 2 - Blue
        redLED = 0; 
        greenLED = 0; 
        blueLED = 1;

        // Wait 0.2 second
        wait_us(500000);
    }
}