/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* funtion that controls the demo mode                */
/*----------------------------------------------------*/
void rgbDemo(boolean demoMode)
{
  if(demoMode)
  {
    if (colorState==stateSetRedColor)
    {
      color.red=0;
      color.green=255;
      color.blue=255;
      writeAnalogOutputs(&color);
      delay(DELAYTIME); 
      colorState=stateGoToYellow;
    }
    else if(colorState==stateGoToYellow)
    {
      if (color.green >0)
      {
        color.green--;
        writeAnalogOutputs(&color);
        delay(DELAYTIME); 
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
        delay(DELAYTIME); 
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
        delay(DELAYTIME); 
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
        delay(DELAYTIME); 
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
        delay(DELAYTIME); 
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
        delay(DELAYTIME); 
      }
      else
      {
        colorState=stateGoToYellow;
      }
    }
  }
} 

