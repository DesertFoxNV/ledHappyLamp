void frame1()
{
  fill_solid(leds, NUM_LEDS, CRGB(50,0,200));
  FastLED.show();
  delay(1000);
}

void frame2()
{
    int blendDelay = 1;
    
    blendPattern(center, 52, CRGB(50,0,200), CRGB(255,0,0), 100, blendDelay, true);
    blendPattern(secondLayer, 38, CRGB(50,0,200), CRGB(255,0,0), 85, blendDelay, true);
    blendPattern(thirdLayer, 40, CRGB(50,0,200), CRGB(255,0,0), 70, blendDelay, true);
    blendPattern(thirdLayer, 40, CRGB(255,0,0), CRGB(50, 0, 200), 70, blendDelay, true);
    blendPattern(secondLayer, 38, CRGB(255,0,0), CRGB(50, 0, 200), 85, blendDelay, true);
    blendPattern(center, 52, CRGB(255,0,0), CRGB(50, 0, 200), 100, blendDelay, true);
}

void frame3()
{
    int blendDelay = 1;
    
    blendPattern(center, 52, CRGB(50,0,200), CRGB(255,0,0), 5, blendDelay, false);
    blendPattern(secondLayer, 38, CRGB(50,0,200), CRGB(255,0,0), 5, blendDelay, false);
    blendPattern(thirdLayer, 40, CRGB(50,0,200), CRGB(255,0,0), 5, blendDelay, false);
    blendPattern(thirdLayer, 40, CRGB(255,0,0), CRGB(50, 0, 200), 5, blendDelay, false);
    blendPattern(secondLayer, 38, CRGB(255,0,0), CRGB(50, 0, 200), 5, blendDelay, false);
    blendPattern(center, 52, CRGB(255,0,0), CRGB(50, 0, 200), 5, blendDelay, false);
}


