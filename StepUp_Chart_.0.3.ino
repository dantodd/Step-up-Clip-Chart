/**************************************************************************
This is a short sketch to drive a series of APA102 LEDs

We use these LEDs as a behavior charting tool for our kids. 

Each LED has 2 buttons the kids push as they Step their behavior up or down 
over the day. Rewards are given for ending on the top Step and also for accumulating
a set number of top behavior days.

This was developed based on the examples in the FastLED library repository along
with information on Adafruit.

Please, if you like it - use it - do more - make it better. But link people back
the original code.  

http://www.dantodd.com/projects/arduino/StepChart/


**************************************************************************/

#include <FastLED.h>

#define LED_PIN     4
#define CLOCK_PIN   5
#define NUM_LEDS    2
#define BRIGHTNESS  255
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define UPDATES_PER_SECOND 100


// setup LED initial levels
int StepLevel_1 = 3;
int StepLevel_2 = 3;
CRGB leds[NUM_LEDS];  

// Set up Array with hex values for the following FastLED colors { "Red", "DarkOrange", "Yellow", "Green", "Blue", "Indigo", "DeepPink" }
const float StepColors[7] = { 0xFF0000, 0xFF8C00, 0xFFFF00, 0x00FF00, 0x0000FF, 0x4B0082, 0xFF1493 };

void setup() {
  delay( 3000 ); // power-up safety delay
  
  // LED setup
  FastLED.addLeds<LED_TYPE, LED_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
  

  // Input switch setup stuff
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);

// set initial light
  leds[0] = CRGB(StepColors[StepLevel_1]);
  leds[1] = CRGB(StepColors[StepLevel_2]);
  FastLED.show();

}


void loop()
{
  
  // Create a variable to record each pushbutton
  int button2_Val = digitalRead(2);
  int button3_Val = digitalRead(3);
  int button6_Val = digitalRead(6);
  int button7_Val = digitalRead(7);
  
  
  // setup buttonstate tracking variables
  int debounce2 = digitalRead(2);
  int debounce3 = digitalRead(3);
  int debounce6 = digitalRead(6);
  int debounce7 = digitalRead(7);

  // LED 1 color control
  
  if (button2_Val == LOW && StepLevel_1 < 6) { 
    StepLevel_1++;  
    leds[0] = CRGB(StepColors[StepLevel_1]);
    FastLED.show();
    delay(500);
    
  }  
  
  
  if (button3_Val == LOW && StepLevel_1 > 0) {
    StepLevel_1-- ;
    leds[0] = CRGB(StepColors[StepLevel_1]);
    FastLED.show();
    delay(500);
  }
  
 
// LED 2 color control 

  if (button6_Val == LOW && StepLevel_2 < 6) {
    delay(10);
    if (button6_Val == LOW){
      StepLevel_2++ ;
      leds[1] = CRGB(StepColors[StepLevel_2]);
      FastLED.show();
      delay(500);
    }
  }  
if (button7_Val == LOW && StepLevel_2 > 0) {
    delay(10);
    if (button7_Val == LOW){
      StepLevel_2-- ;
      leds[1] = CRGB(StepColors[StepLevel_2]);
      FastLED.show();
      delay(500);
    }
  }
  
}
