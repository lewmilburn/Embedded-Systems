// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN, 0);
DigitalOut yellowLED(TRAF_YEL1_PIN, 0);
DigitalOut redLED(TRAF_RED1_PIN, 0);
DigitalOut d1(LED_BLUE_LE_PIN, 1);
DigitalOut d2(LED_GRN_LE_PIN, 1);
DigitalOut d3(LED_RED_LE_PIN, 1);
Buzzer buzz;
Buttons buttons;
LCD_16X2_DISPLAY lcd;

void wait();

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

void wait(float time)
{
    wait_us(time * 1000000);
}

int main()
{
    greenLED = 1;

    lcd.cls();
    lcd.printf("Security System\n    Unarmed");

    while (buttons.BlueButton == 0);

    lcd.cls();
    lcd.printf("Security System\n     Armed");

    greenLED = 0;
    yellowLED = 1;

    buzz.playTone("A", Buzzer::HIGHER_OCTAVE);
    wait(0.2);
    buzz.playTone("D", Buzzer::HIGHER_OCTAVE);
    wait(0.4);
    buzz.playTone("A", Buzzer::HIGHER_OCTAVE);
    wait(0.2);
    buzz.rest();

    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    while (buttons.Button1 == 0)
    {
        yellowLED = 0;
        redLED = 1;

        lcd.cls();
        lcd.printf("Security System\n---- ALARM ----");

        //On for 500ms
        buzz.playTone("C");
        wait(0.5);

        lcd.cls();
        lcd.printf("Security System\n==== ALARM ====");

        //Off for 500ms
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait(0.5);  //500ms

        lcd.cls();
        lcd.printf("Security System\n---- ALARM ----");

        //On for 500ms
        buzz.playTone("C");
        wait(0.5);

        lcd.cls();
        lcd.printf("Security System\n==== ALARM ====");

        //Pause
        buzz.rest();
        wait(0.5);
    }
}