#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 192

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

CRGB DisplayColor = CRGB(0,128,128);

//Define PIR State
int pirState = 1; 

//Digital pin for the PIR Sensor
int PIRinputPin = 2;               // choose the input pin (for PIR sensor)

void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  	  // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

  //SEQUENCE 1: Random Noise/FLickering
  //SEQUENCE 2: Random Noise/Flickering changes
  //SEQUENCE 3: A Double line runs down the tv / Random Noise
  //SEQUENCE 4: A Doublec line runs down the tv / Rnadom Noise
  //SEQUENCE 5: Random Noise/Flickering changes

  //SEQUENCE 1 - Random Noise/Flickering********* (4 seconds)


void loop(){
  Start:

   //Check if motion detected
   pirState = digitalRead(PIRinputPin);

   if(pirState == 1){
  
    //SEQUENCE 1 - Random Noise/Flickering********* (4 seconds)
  
      for(int i=0; i<132; i++){ //I = 33 is bassed upon 1 second/30 milliseconds.  This may need to be adjusted, as their is some delay that is not accounted for.
        
        //Check if motion detected
        pirState = digitalRead(PIRinputPin);
  
        //If motion detected GoTo start
        if(pirState == 0){
         goto Start;
        }
        
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(120); //selects 90 leds to be white
      
        //Update LED state
        FastLED.show();
        
        //Delay for 30 milliseconds
        delay(30);
      }

    //SEQUENCE 2 - Random Noise/Flickering (Changes)******** (4 seconds)
    
      for(int i=0; i<132; i++){ //I = 132 is bassed upon 1 second/30 milliseconds * 4 seconds.  This may need to be adjusted, as their is some delay that is not accounted for.
        
        //Check if motion detected
        pirState = digitalRead(PIRinputPin);
  
        //If motion detected GoTo start
        if(pirState == 0){
         goto Start;
        }
        
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(90); //selects 60 leds to be white
      
        //Update LED state
        FastLED.show();
        
        //Delay for 30 milliseconds
        delay(30);
      }

    //SEQUENCE 3 DOUBLE LINE RUNS DOWN THE 3:4 TV / RANDOM NOISE***********
    
      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 0-15 to white
        setLEDSToWhite(0,15);
        //change LEDs 32-47 to white
        setLEDSToWhite(32,47);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }
      
      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 0-15 to Black
        setLEDSToBlack(0,15);
        //change LEDs 32-47 to Black
        setLEDSToBlack(32,47);
      
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 16-31 to white
        setLEDSToWhite(16,31);
        //change LEDs 48-63 to white
        setLEDSToWhite(48,63);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }
      
      for(int i=0; i<7; i++){
        //change LEDs 16-31 to black
        setLEDSToBlack(16,31);
        //change LEDs 48-63 to black
        setLEDSToBlack(48,63);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 32-47 to white
        setLEDSToWhite(32,47);
        //change LEDs 64-79 to white
        setLEDSToWhite(64,79);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }
      
      for(int i=0; i<7; i++){
        //change LEDs 32-47 to black
        setLEDSToBlack(32,47);
        //change LEDs 64-79 to black
        setLEDSToBlack(64,79);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }
      
      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 48-63 to white
        setLEDSToWhite(48,63);
        //change LEDs 80-95 to white
        setLEDSToWhite(80,95);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 48-63 to white
        setLEDSToBlack(48,63);
        //change LEDs 80-95 to white
        setLEDSToBlack(80,95);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 64-79 to white
        setLEDSToWhite(64,79);
        //change LEDs 96-111 to white
        setLEDSToWhite(96,111);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){     
        //change LEDs 64-79 to black
        setLEDSToBlack(64,79);
        //change LEDs 96-111 to black
        setLEDSToBlack(96,111);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 80-95 to white
        setLEDSToWhite(80,95);
        //change LEDs 112-127 to white
        setLEDSToWhite(112,127);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 80-95 to black
        setLEDSToBlack(80,95);
        //change LEDs 112-127 to black
        setLEDSToBlack(112,127);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 96-111 to white
        setLEDSToWhite(96,111);
        //change LEDs 128-143 to white
        setLEDSToWhite(128,143);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 96-111 to black
        setLEDSToBlack(96,111);
        //change LEDs 128-143 to black
        setLEDSToBlack(128,143);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 112-127 to white
        setLEDSToWhite(112,127);
        //change LEDs 144-159 to white
        setLEDSToWhite(144,159);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 112-127 to black
        setLEDSToBlack(112,127);
        //change LEDs 144-159 to black
        setLEDSToBlack(144,159);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 128-143 to white
        setLEDSToWhite(128,143);
        //change LEDs 160-175 to white
        setLEDSToWhite(160,175);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 128-143 to black
        setLEDSToBlack(128,143);
        //change LEDs 160-175 to black
        setLEDSToBlack(160,175);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 144-159 to white
        setLEDSToWhite(144,159);
        //change LEDs 176-191 to white
        setLEDSToWhite(176,191);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 144-159 to black
        setLEDSToBlack(144,159);
        //change LEDs 176-191 to black
        setLEDSToBlack(176,191);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 160-175 to white
        setLEDSToWhite(160,175);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 160-175 to black
        setLEDSToBlack(160,175);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 176-191 to white
        setLEDSToWhite(176,191);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 176-191 to black
        setLEDSToBlack(176,191);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      

  //SEQUENCE 4 DOUBLE LINE RUNS DOWN THE 3:4 TV / RANDOM NOISE***********

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 0-15 to white
        setLEDSToWhite(0,15);
        //change LEDs 32-47 to white
        setLEDSToWhite(32,47);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }
      
      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 0-15 to Black
        setLEDSToBlack(0,15);
        //change LEDs 32-47 to Black
        setLEDSToBlack(32,47);
      
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 16-31 to white
        setLEDSToWhite(16,31);
        //change LEDs 48-63 to white
        setLEDSToWhite(48,63);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }
      
      for(int i=0; i<7; i++){
        //change LEDs 16-31 to black
        setLEDSToBlack(16,31);
        //change LEDs 48-63 to black
        setLEDSToBlack(48,63);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 32-47 to white
        setLEDSToWhite(32,47);
        //change LEDs 64-79 to white
        setLEDSToWhite(64,79);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }
      
      for(int i=0; i<7; i++){
        //change LEDs 32-47 to black
        setLEDSToBlack(32,47);
        //change LEDs 64-79 to black
        setLEDSToBlack(64,79);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }
      
      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 48-63 to white
        setLEDSToWhite(48,63);
        //change LEDs 80-95 to white
        setLEDSToWhite(80,95);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 48-63 to white
        setLEDSToBlack(48,63);
        //change LEDs 80-95 to white
        setLEDSToBlack(80,95);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 64-79 to white
        setLEDSToWhite(64,79);
        //change LEDs 96-111 to white
        setLEDSToWhite(96,111);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){     
        //change LEDs 64-79 to black
        setLEDSToBlack(64,79);
        //change LEDs 96-111 to black
        setLEDSToBlack(96,111);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 80-95 to white
        setLEDSToWhite(80,95);
        //change LEDs 112-127 to white
        setLEDSToWhite(112,127);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 80-95 to black
        setLEDSToBlack(80,95);
        //change LEDs 112-127 to black
        setLEDSToBlack(112,127);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 96-111 to white
        setLEDSToWhite(96,111);
        //change LEDs 128-143 to white
        setLEDSToWhite(128,143);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 96-111 to black
        setLEDSToBlack(96,111);
        //change LEDs 128-143 to black
        setLEDSToBlack(128,143);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 112-127 to white
        setLEDSToWhite(112,127);
        //change LEDs 144-159 to white
        setLEDSToWhite(144,159);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 112-127 to black
        setLEDSToBlack(112,127);
        //change LEDs 144-159 to black
        setLEDSToBlack(144,159);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 128-143 to white
        setLEDSToWhite(128,143);
        //change LEDs 160-175 to white
        setLEDSToWhite(160,175);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 128-143 to black
        setLEDSToBlack(128,143);
        //change LEDs 160-175 to black
        setLEDSToBlack(160,175);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 144-159 to white
        setLEDSToWhite(144,159);
        //change LEDs 176-191 to white
        setLEDSToWhite(176,191);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 144-159 to black
        setLEDSToBlack(144,159);
        //change LEDs 176-191 to black
        setLEDSToBlack(176,191);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 160-175 to white
        setLEDSToWhite(160,175);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 160-175 to black
        setLEDSToBlack(160,175);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //change LEDs 176-191 to white
        setLEDSToWhite(176,191);
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }

      //Check if motion detected
      pirState = digitalRead(PIRinputPin);

      //If motion detected GoTo start
      if(pirState == 0){
       goto Start;
      }

      for(int i=0; i<7; i++){
        //change LEDs 176-191 to black
        setLEDSToBlack(176,191);

        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(50); //selects 50 leds to be white
        
        //Update LED states
        FastLED.show();
        //Delay for 30 ms
        delay(30);
      }
      
  //Sequence 5 Noise / Flickering Lights***************** (6 seconds)

    for(int i=0; i<198; i++){ //I = 33 is bassed upon 1 second/30 milliseconds * 6 seconds.  This may need to be adjusted, as their is some delay that is not accounted for.
        
        //Check if motion detected
        pirState = digitalRead(PIRinputPin);
  
        //If motion detected GoTo start
        if(pirState == 0){
         goto Start;
        }
        
        //Randomize Select Number of LEDs to White
        randomizeLEDsOnByNumber(90); //selects 90 leds to be white
      
        //Update LED state
        FastLED.show();
        
        //Delay for 30 milliseconds
        delay(30);
      }
   
   }//End of if statement PIRCheck
}
 

  //TURN OFF/ON Light Selection FUNCTION*******
    
void setLEDSToWhite(int LEDStart, int LEDend){
  // Set select LEDS to display White color
  for(int i=LEDStart; i< LEDend; i++){
    leds[i] = CRGB::White;
  }
}
void setLEDSToBlack(int LEDStart, int LEDend){
  // Set select LEDS to display Black color
  for(int i=LEDStart; i< LEDend; i++){
    leds[i] = CRGB::Black;
  }
}

  //RANDOMIZE FUNCTION********

void randomizeLEDsOnByNumber(int desiredLEDs){
  int ledAssignmentState[NUM_LEDS];
  long randNumber;
  int nextLed;
  
  for(int i=0; i<NUM_LEDS; i++){
    ledAssignmentState[i] = 0;
  }
  
  
  for(int i=0; i<desiredLEDs; i++){
    randNumber = random(0, NUM_LEDS);
    if(ledAssignmentState[randNumber] == 0){
      ledAssignmentState[randNumber] = 1;
      leds[randNumber] = DisplayColor;
    }else{
      for(int j = 0; j<NUM_LEDS; j++){
        if(ledAssignmentState[j] == 0){
          nextLed = j;
          break;
        }
      }
      leds[nextLed] = 1;
      ledAssignmentState[nextLed] = 1;
    }
  }
  
  for(int i = 0; i<NUM_LEDS-desiredLEDs; i++){
    for(int j=0; j<NUM_LEDS; j++){
      if(ledAssignmentState[j] == 0){
        nextLed = j;
        break;
      }
    }
    leds[nextLed] = CRGB::Black;
    ledAssignmentState[nextLed] = 1;
    
  }
}
