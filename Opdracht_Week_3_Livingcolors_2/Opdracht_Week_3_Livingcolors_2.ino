/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* Main program module                                */
/*----------------------------------------------------*/
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
  if (toggleButton(BUTTONPIN))
  {
    rgbDemo();
  }
}







