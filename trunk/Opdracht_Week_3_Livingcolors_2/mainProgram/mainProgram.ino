/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* Main program module                                */
/*----------------------------------------------------*/
#include "Types.h"

RGBcolor color;    // maak een instantie aan van de struct
state colorState;  // maak een instantie aan van de Enum
boolean demo;
void setup()
{
  Serial.begin(9600);
  setupIo();
  colorState=stateSetRedColor;
  demo=true;
}


void loop()
{   
  Serial.println( readPotMeter( POTMETERIN, 0, 255 ));
  rgbDemo(demo);
  if (readPresetButton() == HIGH || readMixColorButton() == HIGH)
  {
    demo = false;  
  } 
  presetSelector( pulseCounter( readMixColorButton(),1, 3 ));
}








