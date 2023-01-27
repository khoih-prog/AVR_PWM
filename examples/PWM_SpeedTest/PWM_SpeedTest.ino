/****************************************************************************************************************************
  PWM_SpeedTest.ino
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

#define _PWM_LOGLEVEL_        1

#include "AVR_PWM.h"

#define UPDATE_INTERVAL       1000L

#define pinToUse      10

AVR_PWM* PWM_Instance;

// If frequency < 244.1406Hz => forced using 244.1406Hz
//float frequency = 60.0f;
float    frequency = 1000.0f;

// Using setPWM_DCPercentage_manual if true
//#define USING_DC_PERCENT      false
#define USING_DC_PERCENT      true

#if USING_DC_PERCENT
  float    dutycyclePercent = 0.0f;
  float    DCStepPercent    = 5.0f;

  // dutycyclePercentInt = dutycyclePercent * 65535 / 100
  uint16_t    dutycyclePercentInt = 0;
#else
  uint16_t dutycycle = 0;
  uint16_t DCStep;
#endif

uint16_t PWMPeriod;

char dashLine[] = "=================================================================================================";

void printPWMInfo(AVR_PWM* PWM_Instance)
{
  Serial.println(dashLine);
  Serial.print("Actual data: pin = ");
  Serial.print(PWM_Instance->getPin());
  Serial.print(", PWM DutyCycle % = ");
  Serial.print(PWM_Instance->getActualDutyCycle());
  Serial.print(", PWMPeriod = ");
  Serial.print(PWM_Instance->getPWMPeriod());
  Serial.print(", PWM Freq (Hz) = ");
  Serial.println(PWM_Instance->getActualFreq(), 4);
  Serial.println(dashLine);
}

void setup()
{
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(100);

  Serial.print(F("\nStarting PWM_SpeedTest on "));
  Serial.println(BOARD_NAME);
  Serial.println(AVR_PWM_VERSION);

  // Create a dummy instance
  PWM_Instance = new AVR_PWM(pinToUse, frequency, 0);

  if (PWM_Instance)
  {
    // setPWM_manual(uint8_t pin, uint16_t level)
    PWM_Instance->setPWM(pinToUse, frequency, 0);

    PWMPeriod = PWM_Instance->getPWMPeriod();

#if USING_DC_PERCENT
    dutycyclePercent = 50.0f;
    
    // dutycyclePercentInt = dutycyclePercent * 65535 / 100
    dutycyclePercentInt = 1 << 15;
#else
    // 5% steps
    DCStep = round( PWMPeriod / 20.0f);
    
    // 50%
    dutycycle = PWMPeriod / 2;
#endif

    printPWMInfo(PWM_Instance);
  }

  Serial.print(F("Average time of setPWM function"));

#if USING_DC_PERCENT  
  Serial.println(F(" USING_DC_PERCENT"));
#else
  Serial.println(F(" not USING_DC_PERCENT"));
#endif
}

void loop()
{
  static unsigned long update_timeout = UPDATE_INTERVAL + millis();
  static uint64_t count = 0;

#if USING_DC_PERCENT
    // 52745ns
    //PWM_Instance->setPWM_DCPercentage_manual(pinToUse, dutycyclePercent);

    // dutycyclePercent = 0-65535 == 0-100%
    // Faster, 8863ns
    PWM_Instance->setPWM_DCPercentageInt_manual(pinToUse, dutycyclePercentInt);
#else
    // 8415-8423ns
    PWM_Instance->setPWM_manual(pinToUse, dutycycle);   
#endif

  count++;

  // Update DC every UPDATE_INTERVAL (1000) milliseconds
  if (millis() > update_timeout)
  {
    Serial.print(F("ns="));
    Serial.println( (uint32_t) (UPDATE_INTERVAL * 1000000 / count));

    count = 0;
    update_timeout = millis() + UPDATE_INTERVAL;
  }
}
