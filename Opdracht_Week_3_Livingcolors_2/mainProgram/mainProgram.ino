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
stateMachine mainState;

void setup()
{
  Serial.begin(9600);
  setupIo();
  colorState = stateSetRedColor;
  mainState = stateDemo;
}


void loop()
{   
  if (readPresetButton())
  {
    mainState = statePreset;
  }
  if ( readMixColorButton())
  {
    mainState = stateMix;
  }
  
  switch (mainState)
  {
  case stateDemo : 
    rgbDemo(true);
    break;
  case statePreset : 
    //pbBaseSelectorBtn.counter = 0;
    pbPresetBtn.button = readPresetButton();
    pbPresetBtn.minValue = 1;
    pbPresetBtn.maxValue = 3;
    pulseCounter(&pbPresetBtn);
    presetSelector(pbPresetBtn.counter);
    break;
  case stateMix :
    pbBaseSelectorBtn.button = readMixColorButton();
    pbBaseSelectorBtn.minValue = 0;
    pbBaseSelectorBtn.maxValue = 3;
    pulseCounter(&pbBaseSelectorBtn);
    baseColorSelector(pbBaseSelectorBtn.counter); 
    break;    
  };


//  // for testing purpose only
//  if (lockPreset)
//    setLED13(HIGH);
//  else
//    setLED13(LOW);
}











