#include "Types.h"

RGBcolor color;    // maak een instantie aan van de struct
state colorState;  // maak een instantie aan van de Enum

boolean Button;

void setup()
{
}

void loop()
{
  if (!Button)
  {
    if (colorState==stateSetRedColor)
    {
      if (color.red <255)
      {
        color.red++;
        writeAnalogOutputs(&color);
      }
    }
    else if(colorState==stateGoToYellow)
    {
    }
    else if(colorState==stateGoToGreen)
    {
    }
    else if(colorState==stateGoToCyane)
    {
    }
    else if(colorState==stateGoToBLue)
    {
    }
    else if(colorState==stateGoToMagenta)
    {
    }
    else if(colorState==stateGoToRed)
    {
    }
  } 
}
void writeAnalogOutputs( RGBcolor *c) // *c is een verwijzing naar c van het type RGBcolor.
{
  button = digitalRead(BUTTONPIN);  // pauze button

    if( button != buttonState)
  {
    delay(DELAYTIME);
    if ( button == HIGH)
    {
      pauze ++;
    }
  }
  buttonState = button;

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
