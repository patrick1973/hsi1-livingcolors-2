/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the ColorHandling    */
/* Demo mode is a sepperate tab                       */
/*----------------------------------------------------*/

RGBcolor baseColor, mixColor, presetColor;
/**
 ************************************************************************************************************
 * function presetSelector will be used to select an predefined color.\n
 * UNDER CONSTRUCTION
 *@param int presetValue  this value represents the selected color (1)
 *@param boolean lock
 ************************************************************************************************************
 */
void presetSelector ( int presetValue )
{

  if ( presetValue == 1 )
  {
    setYellow();
  }
  else if ( presetValue == 2 )
  {
    setCyan();
  }
  else if ( presetValue == 3 )
  {
    setMagenta();
  }

}

void baseColorSelector( int baseColorValue )
{
  //lockPreset = true; 
  static int previous ;                                   // static int for storing the previous selected value
  if ( baseColorValue != 0)                               // if the mixColor loop is not locked (0) is locked
  {
    if ( baseColorValue == 1)                             // mixColor Red is selected
    { 
      if ( baseColorValue != previous )                   // check if it its the first time that red is selected.
      {
        showBaseRed();                                    // show the red mixcolor function after the function: attach the potmeter 
      }
      mixColor.red = readPotMeter( POTMETERIN, 0, 255 );  // after the function: attach the potmeter 
      writeAnalogOutputs(&mixColor);                      // and write the value to the RGB led pin 
    }
    else if ( baseColorValue == 2)
    {
      if ( baseColorValue != previous )                   
      {
        showBaseGreen();                                    
      }
      mixColor.green = readPotMeter( POTMETERIN, 0, 255 );
      writeAnalogOutputs(&mixColor);     
    }
    else if ( baseColorValue == 3)
    {
      if ( baseColorValue != previous )                   
      {
        showBaseBlue();                                    
      }
      mixColor.blue = readPotMeter( POTMETERIN, 0, 255 );
      writeAnalogOutputs(&mixColor);  
    }
  }
  else  if ( baseColorValue == 0 )
  {
    if ( baseColorValue != previous )                // after startup both values are 0  the function will be evaltuated after 3 "clicks" 
    {
      showBaseOff();
    }
  }

  if (baseColorValue != previous)                      
  {
    previous = baseColorValue;                              // updatew previous state to actual state
  }
}

/**
 ************************************************************************************************************
 * function setYellow will be used to set the RGB color to yellow\n
 * When the preset color button is pressed the yellow color will be displayed
 ************************************************************************************************************
 */
void setYellow()
{
  color.red = 0;
  color.green = 0;
  color.blue = 255;
  writeAnalogOutputs(&color);
}
/**
 ************************************************************************************************************
 * function setCyan will be used to set the RGB color to Cyan.\n
 *When the preset color button is pressed the cyan color will be displayed
 ************************************************************************************************************
 */
void setCyan()
{
  color.red = 255;
  color.green = 0;
  color.blue = 0;
  writeAnalogOutputs(&color);
}
/**
 ************************************************************************************************************
 * function setMagenta will be used to set the RGB color to Magenta.\n
 *When the preset color button is pressed the magenta color will be displayed
 ************************************************************************************************************
 */
void setMagenta() 
{
  presetColor.red = 0;
  presetColor.green = 255;
  presetColor.blue = 0;
  writeAnalogOutputs(&presetColor);
}

/**
 ************************************************************************************************************
 * function showBaseRed will be used to show the baseColor Red before mixing.\n
 * then wait 1 sec 
 ************************************************************************************************************
 */
void showBaseRed()
{
  baseColor.red = 0;
  baseColor.green = 255;
  baseColor.blue = 255;
  writeAnalogOutputs(&baseColor);
  delay(1000);
}
/**
 ************************************************************************************************************
 * function showBaseGreen will be used to show the baseColor Green before mixing.\n
 * then wait 1 sec 
 ************************************************************************************************************
 */
void showBaseGreen()
{
  baseColor.red = 255;
  baseColor.green = 0;
  baseColor.blue = 255;
  writeAnalogOutputs(&baseColor);
  delay(1000);
}
/**
 ************************************************************************************************************
 * function showBaseBlue will be used to show the baseColor Blue before mixing.\n
 * then wait 1 sec 
 ************************************************************************************************************
 */
void showBaseBlue()
{
  baseColor.red = 255;
  baseColor.green = 255;
  baseColor.blue = 0;
  writeAnalogOutputs(&baseColor);
  delay(1000);
}
/**
 ************************************************************************************************************
 * function showBaseOff will be used to show the baseColor OFF before mixing.\n
 * then wait 1 sec 
 * after the 1 sec the function showMixedColors will be called
 ************************************************************************************************************
 */
void showBaseOff()
{
  baseColor.red = 255;
  baseColor.green = 255;
  baseColor.blue = 255;
  writeAnalogOutputs(&baseColor);
  delay(1000);
  showMixedColors();
}
/**
 ************************************************************************************************************
 * function showMixedColors will be used to set the RGB color to the mixed color.
 ************************************************************************************************************
 */
void showMixedColors()
{
  writeAnalogOutputs(&mixColor);  
}














