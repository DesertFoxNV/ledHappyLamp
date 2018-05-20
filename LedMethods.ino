void setLedsToRgb(int *pattern, int patternLength, const struct CRGB &color)
{
  int led;
  
  for(int i = 0; i < patternLength; i++)
  {
    led = pattern[i] - 1;
    leds[led] = color;
  }
}

void blendPattern(int *pattern, int patternLength, const struct CRGB &colorOld, const struct CRGB &colorNew, long loops, long blendDelay, boolean checkPir)
{
  int redValue;
  int blueValue;
  int greenValue;
  int diffRed = 0;
  int diffBlue = 0;
  int diffGreen = 0;

  if (checkPir)
  {
    pirState = digitalRead(pirPin);

    if (pirState)
    {
      loops = 5;  
    }
  }
  

  if (colorOld.red != colorNew.red){
    diffRed = colorNew.red - colorOld.red;
    Serial.print("diffRed ");
    Serial.println(diffRed);
  }

  if (colorOld.green != colorNew.green){
    diffGreen = colorNew.green - colorOld.green;
    Serial.print("diffGreen ");
    Serial.println(diffGreen);
  }

  if (colorOld.blue != colorNew.blue){
    diffBlue = colorNew.blue - colorOld.blue;
    Serial.print("diffBlue ");
    Serial.println(diffBlue);
  }

  for (int pos=0; pos<loops; pos++){
    redValue = Easing::linearTween(pos, colorOld.red, diffRed, loops);
    blueValue = Easing::linearTween(pos, colorOld.blue, diffBlue, loops);
    greenValue = Easing::linearTween(pos, colorOld.green, diffGreen, loops);

    setLedsToRgb(pattern, patternLength, CRGB(redValue,greenValue,blueValue));
    FastLED.show();
    delay(blendDelay);
  }
  
}

