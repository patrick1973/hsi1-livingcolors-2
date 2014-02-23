/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  22-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* functions that are related to the ColorHandling    */
/* Demo mode is a sepperate tab                       */
/*----------------------------------------------------*/

void presetSelector ( int presetWaarde )
{
  switch (presetWaarde)
  {
    case 1 :  setYellow();
              break;
    case 2 :  setCyan();
              break; 
    case 3 :  setMagenta();
              break;           
  }
}

void setYellow()
{
  color.red = 0;
  color.green = 0;
  color.blue = 255;
  writeAnalogOutputs(&color);
}
void setCyan()
{
  color.red = 255;
  color.green = 0;
  color.blue = 0;
  writeAnalogOutputs(&color);
}
void setMagenta() 
{
  color.red = 0;
  color.green = 255;
  color.blue = 0;
  writeAnalogOutputs(&color);
}
