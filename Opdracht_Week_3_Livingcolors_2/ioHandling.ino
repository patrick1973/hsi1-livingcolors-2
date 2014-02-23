/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the IO               */
/*----------------------------------------------------*/
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
