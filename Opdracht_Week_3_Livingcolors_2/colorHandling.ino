/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the ColorHandling    */
/* Demo mode is a sepperate tab                       */
/*----------------------------------------------------*/

/**
************************************************************************************************************
* function presetSelector will be used to select an predefined color.\n
* value 1 = Yellow \n
* value 2 = Cyan\n
* value 3 = Magenta \n
*@param int presetValue 
************************************************************************************************************
*/
void presetSelector ( int presetValue )
{
  switch (presetValue)
  {
    case 1 :  setYellow();
              break;
    case 2 :  setCyan();
              break; 
    case 3 :  setMagenta();
              break;           
  }
}

/**
************************************************************************************************************
* function setYellow will be used to set the RGB color to yellow.
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
* function setCyan will be used to set the RGB color to Cyan.
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
* function setMagenta will be used to set the RGB color to Magenta.
************************************************************************************************************
*/
void setMagenta() 
{
  color.red = 0;
  color.green = 255;
  color.blue = 0;
  writeAnalogOutputs(&color);
}
