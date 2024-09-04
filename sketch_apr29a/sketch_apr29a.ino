#include <Adafruit_NeoPixel.h>

// Pin to use to send signals to WS2812B
#define LED_PIN 6
#define BTN_PIN 2
#define BTN2_PIN A0

// Number of WS2812B LEDs attached to the Arduino
#define LED_COUNT1 5
#define LED_COUNT2 9

int gr_bl_delay = 30;
int wait1 = 4000;
int wait2 = 10000;

int switcher = 0;

// Setting up the NeoPixel library
Adafruit_NeoPixel strip(LED_COUNT2, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // Initialize NeoPixel object
  pinMode(2, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Hello, Shukai 3 project. For downloading a sketch - find yoshi42 GitHub account");
}

void loop()
{
program_main();
}

void program_main()
{
  //Serial.println(digitalRead(2));
  if (digitalRead(2) == false && switcher == 0)
  {
    delay(20);
    Serial.println("button pushed");
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    //strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to BLUE:
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    Serial.println("BLUE");
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to BLUE:
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 1;
    delay(wait2);
  }

  if (digitalRead(2) == false && switcher == 1)
  {
    delay(20);
    Serial.println("button pushed");
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
   // strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to GREEN:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    Serial.println("GREEN");
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to GREEN:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 2;
    delay(wait2);
  }

  if (digitalRead(2) == false && switcher == 2)
  {
    delay(20);
    Serial.println("button pushed");
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    //strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to PURPLE:
      strip.setPixelColor(i, 200, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    Serial.println("PURPLE");
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to PURPLE:
      strip.setPixelColor(i, 200, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 0;
    delay(wait2);
  }

  else
  {
    //strip.clear(); // Set all pixel colors to 'off'
    //strip.show();   // Send the updated pixel colors to the hardware.
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    for(int i=0; i<9; i++) 
        {
          // Set the i-th LED to white:
          strip.setPixelColor(i, 30, 30, 30);
          strip.show();   // Send the updated pixel colors to the hardware.
          //delay(10); // Pause before next pass through loop
        }
  }
}

void program_main_analogue()
{
  //Serial.println(digitalRead(2));
  //erial.println(analogRead(BTN2_PIN));
  //delay(200);
  if (analogRead(BTN2_PIN) <= 500 && switcher == 0)
  {
    delay(20);
    int temp = analogRead(BTN2_PIN);
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to BLUE:
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    //Serial.print("BLUE ");
    //Serial.println(temp);
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to BLUE:
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 1;
    delay(wait2);
  }

  if (analogRead(BTN2_PIN) <= 500 && switcher == 1)
  {
    delay(20);
    int temp = analogRead(BTN2_PIN);
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to GREEN:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    //Serial.print("GREEN ");
    //Serial.println(temp);
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to GREEN:
      strip.setPixelColor(i, 0, 0, 255);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 2;
    delay(wait2);
  }

  if (analogRead(BTN2_PIN) <= 500 && switcher == 2)
  {
    delay(20);
    int temp = analogRead(BTN2_PIN);
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to PURPLE:
      strip.setPixelColor(i, 200, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    //Serial.print("PURPLE ");
    //Serial.println(temp);
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to PURPLE:
      strip.setPixelColor(i, 200, 255, 0);
      strip.show();   // Send the updated pixel colors to the hardware.
      delay(gr_bl_delay); // Pause before next pass through loop
    }
    switcher = 0;
    delay(wait2);
  }

  else
  {
    //strip.clear(); // Set all pixel colors to 'off'
    //strip.show();   // Send the updated pixel colors to the hardware.
    strip.setBrightness(100); // Set BRIGHTNESS (max = 255)
    for(int i=0; i<9; i++) 
        {
          // Set the i-th LED to white:
          strip.setPixelColor(i, 255, 255, 255);
          strip.show();   // Send the updated pixel colors to the hardware.
          //delay(10); // Pause before next pass through loop
        }
  }
}

void program1()
{
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for (int j=0; j<255; j+=1)
    {
      for(int i=0; i<LED_COUNT1; i++) 
      {
        // Set the i-th LED to BLUE:
        strip.setPixelColor(i, j, 0, 0);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait1);

    for (int j=0; j<255; j+=1)
    {
      for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
      {
        // Set the i-th LED to BLUE:
        strip.setPixelColor(i, j, 0, 0);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait2);

    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for (int j=0; j<255; j+=1)
    {
      for(int i=0; i<LED_COUNT1; i++) 
      {
        // Set the i-th LED to PURP:
        strip.setPixelColor(i, j-100, j, 0);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait1);

    for (int j=0; j<255; j+=1)
    {
      for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
      {
        // Set the i-th LED to PURP:
        strip.setPixelColor(i, j-100, j, 0);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait2);

    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    strip.clear(); // Set all pixel colors to 'off'
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for (int j=0; j<255; j+=1)
    {
      for(int i=0; i<LED_COUNT1; i++) 
      {
        // Set the i-th LED to GREEN:
        strip.setPixelColor(i, 0, 0, j);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait1);

    for (int j=0; j<255; j+=1)
    {
      for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
      {
        // Set the i-th LED to GREEN:
        strip.setPixelColor(i, 0, 0, j);
      }
      strip.show();   // Send the updated pixel colors to the hardware
      delay(5);
    }
    delay(wait2);
}

void program2()
{
    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to BLUE:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, j, 0, 0);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to BLUE:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, j, 0, 0);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait2);


    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to PURP:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, j-100, j, 0);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to PURP:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, j-100, j, 0);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait2);

    strip.setBrightness(255); // Set BRIGHTNESS (max = 255)
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<LED_COUNT1; i++) 
    {
      // Set the i-th LED to GREEN:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, 0, 0, j);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait1);
    for(int i=LED_COUNT1; i<LED_COUNT2; i++) 
    {
      // Set the i-th LED to GREEN:
       for(int j=0; j<255; j+=10)
       { 
        strip.setPixelColor(i, 0, 0, j);
        strip.show();   // Send the updated pixel colors to the hardware.
        delay(2);
       }
    }
    delay(wait2);
}