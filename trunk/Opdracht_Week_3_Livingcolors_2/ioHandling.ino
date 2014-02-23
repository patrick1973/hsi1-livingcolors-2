/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the IO               */
/*----------------------------------------------------*/

void setupIo()
{
  pinMode(BUTTONPIN_PRESET,INPUT);
  pinMode(BUTTONPIN_MIX,INPUT);
}
int readPotMeter (int pin)
{
  return analogRead(pin);
}

boolean readPresetButton()
{
  return debounceButton(BUTTONPIN_PRESET);
}

boolean readMixColorButton()
{
  return debounceButton(BUTTONPIN_MIX);
}
void writeAnalogOutputs( RGBcolor *c) // *c is een verwijzing naar c van het type RGBcolor.
{
  if (DEBUG==1)
  {
    Serial.print("-");
    Serial.print(c->red);
    Serial.print("-");
    Serial.print(c->green);
    Serial.print("-");
    Serial.println(c->blue); 
  }
  analogWrite(RGBPINRED,c->red);
  analogWrite(RGBPINGREEN,c->green);
  analogWrite(RGBPINBLUE,c->blue);
  delay(DELAYTIME); 
}

boolean toggleButton (int buttonPinNumber )
{
  static boolean buttonState = HIGH;
  static boolean buttonStatePrevious =LOW;
  long time = 0;         
  long debounce = 200; 
  boolean button = digitalRead(buttonPinNumber); 
  if (button==HIGH && buttonStatePrevious == LOW && millis() - time > debounce)
  {
    if(buttonState==HIGH)
    {
      buttonState=LOW;
    }
    else
    {
      buttonState=HIGH;
    }
    time = millis();
  }
  buttonStatePrevious = button;
  return buttonState;
}

boolean debounceButton( int buttonPinNumber )
{
  static boolean buttonStatePrevious = LOW;
  boolean button = digitalRead(buttonPinNumber); 
  if (button != buttonStatePrevious)
  {
    delay(DELAYTIME);
    buttonStatePrevious = button;
  }
  return buttonStatePrevious;
}

int pulseCounter ( boolean button ,int minCounter, int maxCounter )
{
  static boolean buttonState = HIGH;
  static int counter;
  if ( button != buttonState )
  {
    delay(DELAYTIME);
    if ( button == HIGH )
    {
      counter++;
      if (counter > maxCounter)
      {
        counter = minCounter;
      }
    }
   }
  buttonState = button;
  return counter;
  }

