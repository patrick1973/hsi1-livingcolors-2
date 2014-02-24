/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* Main program module                                */
/*----------------------------------------------------*/
#include "Types.h"

RGBcolor color;    // maak een instantie aan van de struct
pulseButton pbPresetBtn, pbBaseSelectorBtn;
state colorState;  // maak een instantie aan van de Enum
boolean demo;
boolean lockPreset;
void setup()
{
  Serial.begin(9600);
  setupIo();
  colorState=stateSetRedColor;
  demo=true;
  lockPreset = false;
}


void loop()
{   
  rgbDemo(demo);
  if (readPresetButton() == HIGH || readMixColorButton() == HIGH)
  {
    demo = false; 
  } 
  
  if (readPresetButton() == HIGH)
  {
    pbBaseSelectorBtn.counter = 0;
    lockPreset = false;
  }
  
  if ( readMixColorButton() == HIGH )
  {
    lockPreset = true;
    Serial.println( lockPreset );
    color.red = 255;
    color.green = 255;
    color.blue = 255;
    
  }
  pbPresetBtn.button = readPresetButton();
  pbPresetBtn.minValue = 1;
  pbPresetBtn.maxValue = 3;
  pulseCounter(&pbPresetBtn);
  presetSelector(pbPresetBtn.counter, lockPreset);
  
  pbBaseSelectorBtn.button = readMixColorButton();
  pbBaseSelectorBtn.minValue = 0;
  pbBaseSelectorBtn.maxValue = 3;
  pulseCounter(&pbBaseSelectorBtn);
  baseColorSelector(pbBaseSelectorBtn.counter);
  
  // for testing purpose only
  if (lockPreset)
    setLED13(HIGH);
  else
    setLED13(LOW);
}








