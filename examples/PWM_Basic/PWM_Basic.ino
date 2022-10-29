/****************************************************************************************************************************
  PWM_Basic.ino

  For AVR-based boards  (UNO, Nano, Mega, 32U4, 16U4, etc. )
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/AVR_PWM
  Licensed under MIT license

  This is pure hardware-based PWM
*****************************************************************************************************************************/
/******************************************************************************************************************************
  // For UNO / Nano
  Timer0 ( 8-bit) used by delay(), millis() and micros(), and PWM generation on pins 5 (6 not usable)
  Timer1 (16-bit) used by the Servo.h library and PWM generation on pins 9 and 10
  Timer2 ( 8-bit) used by Tone() and PWM generation on pins 3 and 11
  // For Mega
  Timer0 ( 8-bit) used by delay(), millis() and micros(), and PWM generation on pins 4 (13 not usable)
  Timer1 (16-bit) used by the Servo.h library and PWM generation on pins 11, 12
  Timer2 ( 8-bit) used by Tone() and PWM generation on pins 9 and 10
  Timer3 (16-bit) used by PWM generation on pins  2,  3 and  5
  Timer4 (16-bit) used by PWM generation on pins  6,  7 and  8
  Timer5 (16-bit) used by PWM generation on pins 44, 45 and 46

  ////////////////////////////////////////////
  // For Mega (2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 44, 45, 46)
  Pin  2 => TIMER3B   // PE 4 ** 2  ** PWM2
  Pin  3 => TIMER3C   // PE 5 ** 3  ** PWM3
  Pin  4 => TIMER0B   // PG 5 ** 4  ** PWM4
  Pin  5 => TIMER3A   // PE 3 ** 5  ** PWM5
  Pin  6 => TIMER4A   // PH 3 ** 6  ** PWM6
  Pin  7 => TIMER4B   // PH 4 ** 7  ** PWM7
  Pin  8 => TIMER4C   // PH 5 ** 8  ** PWM8
  Pin  9 => TIMER2B   // PH 6 ** 9  ** PWM9
  Pin 10 => TIMER2A   // PB 4 ** 10 ** PWM10
  Pin 11 => TIMER1A   // PB 5 ** 11 ** PWM11
  Pin 12 => TIMER1B   // PB 6 ** 12 ** PWM12
  Pin 13 => TIMER0A   // PB 7 ** 13 ** PWM13
  Pin 44 => TIMER5C   // PL 5 ** 44 ** D44
  Pin 45 => TIMER5B   // PL 4 ** 45 ** D45
  Pin 46 => TIMER5A   // PL 3 ** 46 ** D46
  ////////////////////////////////////////////
  // For 32u4 (3, 5, 6, 9, 10, 11, 13)
  Pin  3 => TIMER0B
  Pin  5 => TIMER3A
  Pin  6 => TIMER4D
  Pin  9 => TIMER1A
  Pin 10 => TIMER1B
  Pin 11 => TIMER0A
  Pin 13 => TIMER4A
  ////////////////////////////////////////////
  // For UNO, Nano (3, 5, 6, 9, 10, 11)
  Pin  3 => TIMER2B,
  Pin  5 => TIMER0B
  Pin  6 => TIMER0A
  Pin  9 => TIMER1A
  Pin 10 => TIMER1B
  Pin 11 => TIMER2(A)
******************************************************************************************************************************/

#define _PWM_LOGLEVEL_       4

#include "AVR_PWM.h"

#if ( PWM_USING_ATMEGA2560 )
  // Pins tested OK in Mega
  //#define pinToUse      12            // Timer1B on Mega
  //#define pinToUse      11            // Timer1A on Mega
  //#define pinToUse       9            // Timer2B on Mega
  //#define pinToUse       2            // Timer3B on Mega
  //#define pinToUse       3            // Timer3C on Mega
  //#define pinToUse       5            // Timer3A on Mega
  //#define pinToUse       6            // Timer4A on Mega
  //#define pinToUse       7            // Timer4B on Mega
  #define pinToUse       8            // Timer4C on Mega
  //#define pinToUse      46            // Timer5A on Mega
  //#define pinToUse      45            // Timer5B on Mega
  //#define pinToUse      44            // Timer5C on Mega

#elif ( PWM_USING_ATMEGA_32U4  )
  // Pins tested OK on 32u4
  //#define pinToUse      5            // Timer3A on 32u4
  #define pinToUse      9            // Timer1A on 32u4
  //#define pinToUse      10            // Timer1B on 32u4

#else

  // Pins tested OK on Nano / UNO
  //#define pinToUse      9            // Timer1A on UNO, Nano, etc
  #define pinToUse     10            // Timer1B on UNO, Nano, etc
  //#define pinToUse      5               // Timer0B on UNO, Nano, e
  //#define pinToUse       3            // Timer2B on UNO, Nano, etc
#endif

//creates pwm instance
AVR_PWM* PWM_Instance;

float frequency;
float dutyCycle;

void setup()
{
  Serial.print(F("\nStarting PWM_Basic on "));
  Serial.println(BOARD_NAME);
  Serial.println(AVR_PWM_VERSION);

  //assigns PWM frequency of 20 KHz and a duty cycle of 0%
  PWM_Instance = new AVR_PWM(pinToUse, 20000, 0);
}

void loop()
{
  //delay(10000);
  frequency = 200;    //20000;
  dutyCycle = 20;     //90;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);

  delay(10000);
  dutyCycle = 90;

  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);

  delay(10000);
}
