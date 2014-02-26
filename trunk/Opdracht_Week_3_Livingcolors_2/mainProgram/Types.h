/*----------------------------------------------------*/
/* aut.     :  Patrick & Nikita                       */
/* datum    :  20-02-2014                             */
/* Project  :  Living Colors part 2                   */
/* definition of constants and types                  */
/*----------------------------------------------------*/

#include <arduino.h> // this library is needed, A0 is defined in arduino.h. (A0 is not a native type)

#ifndef TYPES_H   
#define TYPES_H

/**
 ************************************************************************************************************
 * The macro Debug is used for debugging purpose.\n
 * When this macro is set to 1 the actual RGB values will be displayed in the serial monitor.
 ************************************************************************************************************
 */
#define DEBUG 1

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

typedef enum selectedState
{
  stateDemo,
  statePreset,
  stateMix
}stateMachine;

typedef struct RGB
{
  int red;
  int green;
  int blue;
}RGBcolor;

typedef struct pulseBut
{
  boolean button;
  int     counter;
  boolean lastButtonState;
  int     minValue;
  int     maxValue;
}pulseButton;

const int POTMETERIN  = A0; // Analog
const int RGBPINRED   = 9;  //PWM
const int RGBPINGREEN = 10; //PWM
const int RGBPINBLUE  = 11; //PWM
const int LEDPINOUT   = 13; // used for testing

const int BUTTONPIN_PRESET = 2;  
const int BUTTONPIN_MIX    = 4;
const int DELAYTIME        = 40;

#endif TYPES_H
