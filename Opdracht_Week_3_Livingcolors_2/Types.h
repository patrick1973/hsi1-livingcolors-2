/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  20-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* definition of constants and types                  */
/*----------------------------------------------------*/

#include <arduino.h> // this library is needed, A0 is defined in arduino.h. (A0 is not a native type)

#ifndef TYPES_H   
#define TYPES_H

#define DEBUG 0

typedef enum RGBstate
{
  stateSetRedColor,
  stateGoToYellow,
  stateGoToGreen,
  stateGoToCyane,
  stateGoToBLue,
  stateGoToMagenta,
  stateGoToRed
}state;

typedef struct RGB
{
  int red;
  int green;
  int blue;
}RGBcolor;

const int POTMETERIN  = A0; // Analog
const int RGBPINRED   = 9;  //PWM
const int RGBPINGREEN = 10; //PWM
const int RGBPINBLUE  = 11; //PWM
const int LEDPINOUT   = 13; // used for testing the toggle function of the push button

const int BUTTONPIN_PRESET = 2;  
const int BUTTONPIN_MIX    = 3;
const int DELAYTIME        = 40;

#endif TYPES_H
