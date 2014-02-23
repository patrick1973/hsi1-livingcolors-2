#include "Types.h"

RGBcolor color;    // maak een instantie aan van de struct
state colorState;  // maak een instantie aan van de Enum

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTONPIN,INPUT);
  colorState=stateSetRedColor;
}

void loop()
{  
  rgbDemo();
}
void rgbDemo()
{
  if (toggleButton(BUTTONPIN))
  {
    if (colorState==stateSetRedColor)
    {
     color.red=0;
     color.green=255;
     color.blue=255;
      writeAnalogOutputs(&color);
      colorState=stateGoToYellow;
      Serial.println(colorState);
    }
    else if(colorState==stateGoToYellow)
    {
      if (color.green >0)
      {
        color.green--;
        writeAnalogOutputs(&color);
      }
      else
      {
        colorState=stateGoToGreen;
      }
    }
    else if(colorState==stateGoToGreen)
    {
      if(color.red < 255)
      {
        color.red++;
        writeAnalogOutputs(&color);
      }
      else 
      {
        colorState=stateGoToCyane;
      }
    }
    else if(colorState==stateGoToCyane)
    {
      if (color.blue >0)
      {
        color.blue--;
        writeAnalogOutputs(&color);
      }
      else
      {
        colorState=stateGoToBLue;
      }
    }
    else if(colorState==stateGoToBLue)
    {
      if(color.green < 255)
      {
        color.green++;
        writeAnalogOutputs(&color);
      }
      else
      {
        colorState=stateGoToMagenta;
      }
    }
    else if(colorState==stateGoToMagenta)
    {
      if (color.red >0)
      {
        color.red--;
        writeAnalogOutputs(&color);
      }
      else
      {
        colorState=stateGoToRed;
      }
    }
    else if(colorState==stateGoToRed)
    {
      if(color.blue < 255)
      {
        color.blue++;
        writeAnalogOutputs(&color);
      }
      else
      {
        colorState=stateGoToYellow;
      }
    }
  } 
  
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

