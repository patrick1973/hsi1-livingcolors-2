/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the IO               */
/*----------------------------------------------------*/

/**
************************************************************************************************************
*setupIo function\n 
*Function to combine all the setup actions.\n
*This function will be calles in the setup().
************************************************************************************************************
*/
void setupIo()
{
  pinMode(BUTTONPIN_PRESET,INPUT);
  pinMode(BUTTONPIN_MIX,INPUT);
  pinMode(LEDPINOUT,OUTPUT);
}
/**
************************************************************************************************************
*This function is used to switch on or off led number 13\n 
*used for testing purpose\n
*@param state this can be HIGH or LOW
************************************************************************************************************
*/
void setLED13( int state )
{
  digitalWrite(LEDPINOUT,state);
}
/**
************************************************************************************************************
*readPotMeter function 
*@param int pin
*@return the actual value of the analog pin
************************************************************************************************************
*/
int readPotMeter (int pin)
{
  return analogRead(pin);
}
/**
************************************************************************************************************
*readPotMeter function with mapping functionality
*@param int pin
*@param int minValue
*@param int maxValue
*@return a mapped value of the analog pin
************************************************************************************************************
*/
int readPotMeter (int pin , int minValue, int maxValue)
{
  return map(analogRead(pin),0, 1023, minValue , maxValue);
}

/**
************************************************************************************************************
*readPresetButton function 
*@return the debounced boolean value of the button to select the preset color.
************************************************************************************************************
*/
boolean readPresetButton()
{
  static boolean buttonStatePrevious = LOW;
  boolean button = digitalRead(BUTTONPIN_PRESET); 
  if (button != buttonStatePrevious)
  {
    if ( button == HIGH )
    {
      delay(50);
      return true;
    }
    buttonStatePrevious = button;
   }
   return false;
}
/**
************************************************************************************************************
*readMixColorButton function 
*@return the debounced boolean value of the button to select the mix color.
************************************************************************************************************
*/
boolean readMixColorButton()
{
  static boolean buttonStatePrevious = LOW;
  boolean button = digitalRead(BUTTONPIN_MIX); 
  if (button != buttonStatePrevious)
  {
    if ( button == HIGH )
    {
    delay(50);
    return true;
    }
    buttonStatePrevious = button;
  }  
  return false;
}
/**
************************************************************************************************************
*The writeAnalogOutputs function is used to write the 3 RGB colors by means of a struct to the PWM outputus
*@param RGBcolor *c c is a pointer of the type RGBcolor.
************************************************************************************************************
*/
void writeAnalogOutputs( RGBcolor *c)
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
}
/**
***********************************************************************************************************************************************
*The toggleButton function is used to toggle a boolean as an on / off switch.\n
*Press one time to set the return value high and press another time to set the return value low.
*@param int buttonPinNumber of the input
*@return the output as true or as false depending on the buttonsState.
***********************************************************************************************************************************************
*/
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
/**
***********************************************************************************************************************************************
*The debounceButton function is used to read an input with a time delay to prevent bouncing of the signal
*@param int buttonPinNumber of the input
*@param int delayTime in Ms
*@return the debounced input
***********************************************************************************************************************************************
*/
boolean debounceButton( int buttonPinNumber, int delayTime )
{
  static boolean buttonStatePrevious = LOW;
  boolean button = digitalRead(buttonPinNumber); 
  if (button != buttonStatePrevious)
  {
    delay(delayTime);
    buttonStatePrevious = button;
  }
  return buttonStatePrevious;
}
/**
***********************************************************************************************************************************************
* This function is used to count the amount of times that the "button" gets high.\n
* COMMENT IS UNDER CONSTRUCTION. COMPLETE FUNCTION HAS CHANGED!!!!!!
***********************************************************************************************************************************************
*/
void pulseCounter ( pulseButton *pb )
{
  if ( pb->button != pb->lastButtonState )
  {
    delay(DELAYTIME);
    if ( pb->button == HIGH )
    {
      pb->counter++;
      if (pb->counter > pb->maxValue)
      {
        pb->counter = pb->minValue;
      }
    }
  }
  pb->lastButtonState = pb->button;
}

