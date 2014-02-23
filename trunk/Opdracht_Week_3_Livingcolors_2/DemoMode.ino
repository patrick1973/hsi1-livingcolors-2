/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* funtion that controls the demo mode                */
/*----------------------------------------------------*/
void rgbDemo()
{
  if (colorState==stateSetRedColor)
  {
    color.red=0;
    color.green=255;
    color.blue=255;
    writeAnalogOutputs(&color);
    colorState=stateGoToYellow;
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
