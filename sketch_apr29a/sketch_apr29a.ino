#include <Adafruit_NeoPixel.h>

// Pin to use to send signals to WS2812B
#define LED_PIN 6
#define BTN_PIN 2

// Number of WS2812B LEDs attached to the Arduino
#define LED_COUNT1 17
#define LED_COUNT2 35

int gr_bl_delay = 20;
int wait1 = 1000;
int wait2 = 2000;


bool switcher = false;

// Setting up the NeoPixel library
Adafruit_NeoPixel strip(LED_COUNT2, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // Initialize NeoPixel object
  strip.setBrightness(255); // Set BRIGHTNESS to about 4% (max = 255)
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //Serial.println(digitalRead(2));
  if (digitalRead(2) == false && switcher == false)
  {
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to pure green:
      strip.setPixelColor(i, 0, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to pure green:
      strip.setPixelColor(i, 0, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = true;
    delay(wait2);
  }

  if (digitalRead(2) == false && switcher == true)
  {
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to pure green:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to pure green:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = false;
    delay(wait2);
  }

  else
  {
  //strip.clear(); // Set all pixel colors to 'off'
  //strip.show();   // Send the updated pixel colors to the hardware.
  strip.setBrightness(50); // Set BRIGHTNESS (max = 255)
  for(int i=0; i<LED_COUNT2; i++) 
      {
        // Set the i-th LED to pure green:
        strip.setPixelColor(i, 128, 128, 128);
        strip.show();   // Send the updated pixel colors to the hardware.
        //delay(10); // Pause before next pass through loop
      }
  }
}