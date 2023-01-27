/****************************************************************************************************************************
  AVR_PWM.h
  For AVR-based boards  (UNO, Nano, Mega, 32U4, 16U4, etc. )
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/AVR_PWM
  Licensed under MIT license

  This is pure hardware-based PWM

  Version: 1.2.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K.Hoang      27/10/2022 Initial coding for AVR-based boards  (UNO, Nano, Mega, 32U4, 16U4, etc. )
  1.0.1   K Hoang      22/01/2023 Add `PWM_StepperControl` example
  1.1.0   K Hoang      24/01/2023 Add `PWM_manual` example and function. Catch low frequency error
  1.2.0   K Hoang      27/01/2023 Add `PWM_SpeedTest` example and faster `setPWM_DCPercentageInt_manual` function
*****************************************************************************************************************************/

#pragma once

#ifndef AVR_PWM_H
#define AVR_PWM_H

#if defined(BOARD_NAME)
  #undef BOARD_NAME
#endif

#ifndef _PWM_LOGLEVEL_
  #define _PWM_LOGLEVEL_        1
#endif

#if ( defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || \
      defined(__AVR_ATmega640__) || defined(__AVR_ATmega641__))
#if defined(PWM_USING_ATMEGA2560)
  #undef PWM_USING_ATMEGA2560
#endif
#define PWM_USING_ATMEGA2560      true
#define BOARD_NAME    F("Arduino AVR Mega2560/ADK")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Arduino AVR Mega, Mega640(P), Mega2560/ADK. Timer1-5 available
#endif

#elif ( defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)  || \
        defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_MINI) ||    defined(ARDUINO_AVR_ETHERNET) || \
        defined(ARDUINO_AVR_FIO) || defined(ARDUINO_AVR_BT)   || defined(ARDUINO_AVR_LILYPAD) || defined(ARDUINO_AVR_PRO)      || \
        defined(ARDUINO_AVR_NG) || defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) || defined(ARDUINO_AVR_DUEMILANOVE) )
#define BOARD_NAME    "Arduino AVR UNO, Nano, etc."

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Aduino AVR ATMega644(P), ATMega328(P) such as UNO, Nano. Only Timer1,2 available
#endif

#elif ( defined(ARDUINO_AVR_FEATHER328P) || defined(ARDUINO_AVR_METRO) || defined(ARDUINO_AVR_PROTRINKET5) || \
        defined(ARDUINO_AVR_PROTRINKET3) || defined(ARDUINO_AVR_PROTRINKET5FTDI) || defined(ARDUINO_AVR_PROTRINKET3FTDI) )
#define BOARD_NAME    F("Adafruit AVR ATMega328(P)")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Adafruit ATMega328(P), such as AVR_FEATHER328P or AVR_METRO. Only Timer1,2 available
#endif

#elif ( defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_LEONARDO_ETH) || defined(ARDUINO_AVR_YUN) || \
        defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_ESPLORA)  || defined(ARDUINO_AVR_LILYPAD_USB)  || \
        defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || defined(ARDUINO_AVR_CIRCUITPLAY) || \
        defined(ARDUINO_AVR_YUNMINI) || defined(ARDUINO_AVR_INDUSTRIAL101) || defined(ARDUINO_AVR_LININO_ONE) )
#if defined(PWM_USING_ATMEGA_32U4)
  #undef PWM_USING_ATMEGA_32U4
#endif
#define PWM_USING_ATMEGA_32U4      true
#define BOARD_NAME    F("Arduino AVR ATMega32U4")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Arduino ATMega32U4, such as Leonardo or Leonardo ETH. Only Timer1,3,4 available
#endif

#elif ( defined(ARDUINO_AVR_FLORA8 ) || defined(ARDUINO_AVR_FEATHER32U4) || defined(ARDUINO_AVR_CIRCUITPLAY) || \
        defined(ARDUINO_AVR_ITSYBITSY32U4_5V) || defined(ARDUINO_AVR_ITSYBITSY32U4_3V)  || defined(ARDUINO_AVR_BLUEFRUITMICRO) || \
        defined(ARDUINO_AVR_ADAFRUIT32U4) )
#if defined(PWM_USING_ATMEGA_32U4)
  #undef PWM_USING_ATMEGA_32U4
#endif
#define PWM_USING_ATMEGA_32U4      true
#define BOARD_NAME    F("Adafruit AVR ATMega32U4")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Adafruit ATMega32U4, such as Feather_32u4, AVR_CIRCUITPLAY, etc.. Only Timer1,3,4 available
#endif

#elif ( defined(__AVR_ATmega32U4__) || defined(ARDUINO_AVR_MAKEYMAKEY ) || defined(ARDUINO_AVR_PROMICRO) || \
        defined(ARDUINO_AVR_FIOV3) || defined(ARDUINO_AVR_QDUINOMINI) || defined(ARDUINO_AVR_LILYPAD_ARDUINO_USB_PLUS_BOARD ) )
#if defined(PWM_USING_ATMEGA_32U4)
  #undef PWM_USING_ATMEGA_32U4
#endif
#define PWM_USING_ATMEGA_32U4      true
#define BOARD_NAME    F("Generic or Sparkfun AVR ATMega32U4")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Generic ATMega32U4, such as Sparkfun AVR_MAKEYMAKEY, AVR_PROMICRO, etc. Only Timer1,3,4 available
#endif

#elif ( defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_DIGITAL_SANDBOX ) || defined(ARDUINO_REDBOT) || \
        defined(ARDUINO_AVR_SERIAL_7_SEGMENT) )
#define BOARD_NAME    F("Generic or Sparkfun AVR ATMega328P")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Generic ATMega328P, such as Sparkfun AVR_DIGITAL_SANDBOX, REDBOT, etc.
#endif

#elif ( defined(__AVR_ATmega128RFA1__) || defined(ARDUINO_ATMEGA128RFA1_DEV_BOARD) )
#define BOARD_NAME    F("Generic or Sparkfun AVR ATMega128RFA1")

#if (_PWM_LOGLEVEL_ > 3)
  #warning Using Generic ATMega128RFA1, such as Sparkfun ATMEGA128RFA1_DEV_BOARD, etc.
#endif

#elif ( defined(ARDUINO_AVR_GEMMA) || defined(ARDUINO_AVR_TRINKET3) || defined(ARDUINO_AVR_TRINKET5) )
#error These AVR boards are not supported! Please check your Tools->Board setting.

#else
#error This is designed only for Arduino or Adafruit AVR board! Please check your Tools->Board setting.
#endif

////////////////////////////////////////

#ifndef AVR_PWM_VERSION
  #define AVR_PWM_VERSION           F("AVR_PWM v1.2.0")

  #define AVR_PWM_VERSION_MAJOR     1
  #define AVR_PWM_VERSION_MINOR     2
  #define AVR_PWM_VERSION_PATCH     0

  #define AVR_PWM_VERSION_INT      1002000
#endif

////////////////////////////////////////

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "Arduino.h"
#include "pins_arduino.h"

#include "PWM_Generic_Debug.h"

////////////////////////////////////////

#define MAX_COUNT_8BIT            255
#define MAX_COUNT_10BIT           1023
#define MAX_COUNT_16BIT           65535

////////////////////////////////////////

/*
  Pins can be used for hardware-PWM
  // For UNO / Nano
  Timer0 ( 8-bit) used by delay(), millis() and micros(), and PWM generation on pins 5 and 6
  Timer1 (16-bit) used by the Servo.h library and PWM generation on pins 9 and 10
  Timer2 ( 8-bit) used by Tone() and PWM generation on pins 3 and 11
  // For Mega
  Timer0 ( 8-bit) used by delay(), millis() and micros(), and PWM generation on pins 4 and 13
  Timer1 (16-bit) used by the Servo.h library and PWM generation on pins 11, 12
  Timer2 ( 8-bit) used by Tone() and PWM generation on pins 9 and 10
  Timer3 (16-bit) used by PWM generation on pins  2,  3 and  5
  Timer4 (??-bit) used by PWM generation on pins  6,  7 and  8
  Timer5 (??-bit) used by PWM generation on pins 44, 45 and 46
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
*/

// #define digitalPinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )

#if defined (__AVR_ATtiny85__)

  #define TIMER0_RESOLUTION 256UL     // Timer0 is 8 bit
  #define TIMER1_RESOLUTION 256UL     // Timer1 is 8 bit
  #define TIMER2_RESOLUTION 256UL     // Timer2 is 8 bit

#elif defined(__AVR__)

  #define TIMER0_RESOLUTION 256UL     // Timer0 is 8 bit
  #define TIMER1_RESOLUTION 65536UL   // Timer1 is 16 bit
  #define TIMER2_RESOLUTION 256UL     // Timer2 is 8 bit

  #if ( PWM_USING_ATMEGA2560  || PWM_USING_ATMEGA_32U4 )
    #define TIMER3_RESOLUTION 65536UL   // Timer3 is 16 bit
    #define TIMER4_RESOLUTION 65536UL   // Timer3 is 16 bit
    #define TIMER5_RESOLUTION 65536UL   // Timer3 is 16 bit
  #endif

#else
  #define TIMER1_RESOLUTION 65536UL  // assume 16 bits for non-AVR chips
#endif

////////////////////////////////////////

#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega128__)
  #define TCCR2A              TCCR2
  #define TCCR2B              TCCR2
  #define COM2A1              COM21
  #define COM2A0              COM20
  #define OCR2A               OCR2
  #define TIMSK2              TIMSK
  #define OCIE2A              OCIE2
  #define TIMER2_COMPA_vect   TIMER2_COMP_vect
  #define TIMSK1              TIMSK
#endif

////////////////////////////////////////

class AVR_PWM
{
  public:

    AVR_PWM(const uint8_t& pin, const float& frequency, const float& dutycycle)
    {        
      _pin        = pin;

      _timer      = digitalPinToTimer(pin);
      
      checkFrequency(pin, frequency);
      
      _dutycycle  = map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT);

      PWM_LOGDEBUG1("AVR_PWM: _dutycycle =", _dutycycle);

      pinMode(pin, OUTPUT);
    }

    ///////////////////////////////////////////

    ~AVR_PWM();

    ///////////////////////////////////////////
    ///////////////////////////////////////////

  private:
  
    float checkFrequency(const uint8_t& pin, const float& frequency)
    {
      float minFrequency;
      
      _frequency  = frequency;
      _timer      = digitalPinToTimer(pin);
      
      if ( (_timer == TIMER0A) || (_timer == TIMER0B) || \
           (_timer == TIMER2) || (_timer == TIMER2A) || (_timer == TIMER2B) )
      { 
        minFrequency = (float) F_CPU / TIMER0_RESOLUTION;
        
        // 8-bit timer
        if (frequency < minFrequency)
        {
          PWM_LOGERROR3("AVR_PWM:Too low frequency =", frequency, ", min = ", minFrequency);
          _frequency  = minFrequency;
        }
      }
      else
      {
        // 8-bit timer for Timer 1
        minFrequency = (float) F_CPU / TIMER1_RESOLUTION;
        
        if (frequency < minFrequency)
        {
          PWM_LOGERROR3("AVR_PWM:Too low frequency =", frequency, ", min = ", minFrequency);
          _frequency  = minFrequency;
        }  
      }
      
      return _frequency;
    }

    ///////////////////////////////////////////

    void setPeriod_Timer0(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 20 );

      PWM_LOGDEBUG3("setPeriod_Timer0: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER0_RESOLUTION)
      {
        clockSelectBits = _BV(CS00);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER0_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS01);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER0_RESOLUTION * 32)
      {
        clockSelectBits = _BV(CS01) | _BV(CS00);
        pwmPeriod = cycles / 32;
      }
      else if (cycles < TIMER0_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS02);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER0_RESOLUTION * 128)
      {
        clockSelectBits = _BV(CS02) | _BV(CS00);
        pwmPeriod = cycles / 128;
      }
      else if (cycles < TIMER0_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS02) | _BV(CS01);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER0_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS02) | _BV(CS01) | _BV(CS00);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer0: Error, min freq (Hz) =", (float) F_CPU / TIMER0_RESOLUTION );

        clockSelectBits = _BV(CS02) | _BV(CS01) | _BV(CS00);
        pwmPeriod = TIMER0_RESOLUTION - 1;
      }

      TCCR0B |= clockSelectBits;

      OCR0A = pwmPeriod;      // set pwm period

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 32);

      PWM_LOGDEBUG3("setPeriod_Timer0: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }

    ///////////////////////////////////////////

    void setPeriod_Timer1(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 20 );

      PWM_LOGDEBUG3("setPeriod_Timer1: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER1_RESOLUTION)
      {
        clockSelectBits = _BV(CS10);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER1_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS11);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER1_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS11) | _BV(CS10);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER1_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS12);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER1_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS12) | _BV(CS10);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer1: Error, min freq (Hz) =", (float) F_CPU / TIMER1_RESOLUTION );

        clockSelectBits = _BV(CS12) | _BV(CS10);
        pwmPeriod = TIMER1_RESOLUTION - 1;
      }

      ICR1 = pwmPeriod;     // set pwm period

      TCCR1B |= clockSelectBits;

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 2);

      PWM_LOGDEBUG3("setPeriod_Timer1: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }

    ///////////////////////////////////////////

#if !( PWM_USING_ATMEGA_32U4 )

    void setPeriod_Timer2(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 10 );

      PWM_LOGDEBUG3("setPeriod_Timer2: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER2_RESOLUTION)
      {
        clockSelectBits = _BV(CS20);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER2_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS21);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER2_RESOLUTION * 32)
      {
        clockSelectBits = _BV(CS21) | _BV(CS20);
        pwmPeriod = cycles / 32;
      }
      else if (cycles < TIMER2_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS22);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER2_RESOLUTION * 128)
      {
        clockSelectBits = _BV(CS22) | _BV(CS20);
        pwmPeriod = cycles / 128;
      }
      else if (cycles < TIMER2_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS22) | _BV(CS21);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER2_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS22) | _BV(CS21) | _BV(CS20);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer2: Error, min freq (Hz) =", (float) F_CPU / TIMER2_RESOLUTION );

        clockSelectBits = _BV(CS22) | _BV(CS21) | _BV(CS20);
        pwmPeriod = TIMER2_RESOLUTION - 1;
      }

      TCCR2B |= clockSelectBits;

      OCR2A = pwmPeriod;    // set pwm period

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 32);

      PWM_LOGDEBUG3("setPeriod_Timer2: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }
#endif

    ///////////////////////////////////////////

#if ( PWM_USING_ATMEGA2560  || PWM_USING_ATMEGA_32U4 )
    void setPeriod_Timer3(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 20 );

      PWM_LOGDEBUG3("setPeriod_Timer3: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER3_RESOLUTION)
      {
        clockSelectBits = _BV(CS30);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER3_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS31);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER3_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS31) | _BV(CS30);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER3_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS32);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER3_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS32) | _BV(CS30);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer3: Error, min freq (Hz) =", (float) F_CPU / TIMER3_RESOLUTION );

        clockSelectBits = _BV(CS32) | _BV(CS30);
        pwmPeriod = TIMER3_RESOLUTION - 1;
      }

      ICR3 = pwmPeriod;     // set pwm period

      TCCR3B |= clockSelectBits;

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 2);

      PWM_LOGDEBUG3("setPeriod_Timer3: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }
#endif

    ///////////////////////////////////////////

#if ( PWM_USING_ATMEGA2560 )

    void setPeriod_Timer4(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 20 );

      PWM_LOGDEBUG3("setPeriod_Timer4: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER4_RESOLUTION)
      {
        clockSelectBits = _BV(CS40);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER4_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS41);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER4_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS41) | _BV(CS40);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER4_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS42);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER4_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS42) | _BV(CS40);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer4: Error, min freq (Hz) =", (float) F_CPU / TIMER4_RESOLUTION );

        clockSelectBits = _BV(CS42) | _BV(CS40);
        pwmPeriod = TIMER4_RESOLUTION - 1;
      }

      ICR4 = pwmPeriod;     // set pwm period

      TCCR4B |= clockSelectBits;

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 2);

      PWM_LOGDEBUG3("setPeriod_Timer4: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }

    ///////////////////////////////////////////

    void setPeriod_Timer5(unsigned long microseconds) __attribute__((always_inline))
    {
      const unsigned long cycles = ( ( (F_CPU / 100000) * microseconds ) / 20 );

      PWM_LOGDEBUG3("setPeriod_Timer5: F_CPU =", F_CPU, ", cycles =", cycles);

      if (cycles < TIMER5_RESOLUTION)
      {
        clockSelectBits = _BV(CS50);
        pwmPeriod = cycles;
      }
      else if (cycles < TIMER5_RESOLUTION * 8)
      {
        clockSelectBits = _BV(CS51);
        pwmPeriod = cycles / 8;
      }
      else if (cycles < TIMER5_RESOLUTION * 64)
      {
        clockSelectBits = _BV(CS51) | _BV(CS50);
        pwmPeriod = cycles / 64;
      }
      else if (cycles < TIMER5_RESOLUTION * 256)
      {
        clockSelectBits = _BV(CS52);
        pwmPeriod = cycles / 256;
      }
      else if (cycles < TIMER5_RESOLUTION * 1024)
      {
        clockSelectBits = _BV(CS52) | _BV(CS50);
        pwmPeriod = cycles / 1024;
      }
      else
      {
        PWM_LOGERROR1("setPeriod_Timer5: Error, min freq (Hz) =", (float) F_CPU / TIMER5_RESOLUTION );

        clockSelectBits = _BV(CS52) | _BV(CS50);
        pwmPeriod = TIMER5_RESOLUTION - 1;
      }

      ICR5 = pwmPeriod;     // set pwm period

      TCCR5B |= clockSelectBits;

      _actualFrequency = (float) F_CPU / ( pwmPeriod * 2);

      PWM_LOGDEBUG3("setPeriod_Timer5: clockSelectBits =", clockSelectBits, ", pwmPeriod =", pwmPeriod);
    }
#endif

    ///////////////////////////////////////////
    ///////////////////////////////////////////

  public:

    // dutycycle from 0-65536 for 0%-100% to make use of 16-bit top register
    bool setPWM_Int(const uint8_t& pin, const float& frequency, const uint16_t& dutycycle)
    {
      uint16_t MAX_COUNT = MAX_COUNT_16BIT;

      pinMode(pin, OUTPUT);
      
      float new_frequency = checkFrequency(pin, frequency);

      if ( (_timer == TIMER0A) || (_timer == TIMER0B) || \
           (_timer == TIMER2) || (_timer == TIMER2A) || (_timer == TIMER2B) )
      {
        // Convert to 8-bit
        _dutycycle = map(dutycycle, 0, MAX_COUNT_16BIT, 0, MAX_COUNT_8BIT);
        MAX_COUNT = MAX_COUNT_8BIT;
      }
      else
      {
        // Keep 16 bit dutycycle
        MAX_COUNT = MAX_COUNT_16BIT;
      }

      PWM_LOGDEBUG1("setPWM_Int: _dutycycle =", _dutycycle);

      if (_dutycycle == 0)
      {
        digitalWrite(pin, LOW);
      }
      else if (_dutycycle >= MAX_COUNT)
      {
        PWM_LOGERROR1("Error, exceeded _dutycycle, reset to ", MAX_COUNT);

        digitalWrite(pin, HIGH);
      }

      switch (_timer)
      {
          //////////////////////////////////////
          //////////////////////////////////////

          // TODO To check for atmega8
#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
        case TIMER0A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER0A");

          // connect pwm to pin on timer 0, channel A
          // Set frequency
          TCCR0B = _BV(WGM02);              // set mode as phase correct pwm, stop the timer
          TCCR0A = 0;                       // clear control register A

          setPeriod_Timer0(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER2B, _dutycycle =", _dutycycle);

          // connect Fast PWM to pin on timer 0, channel A
          TCCR0A |= _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);

          OCR0B = _dutycycle;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER0A, TCCR0A =", TCCR0A, ", TCCR0B =", TCCR0B);

          break;

#endif

          //////////////////////////////////////

#if 0
          // Not usable
#if defined(TCCR0A) && defined(COM0A1)

        case TIMER0A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER0A");

          // connect pwm to pin on timer 0, channel A
          // Set frequency
          TCCR0B = _BV(WGM02);              // set mode as phase correct pwm, stop the timer
          TCCR0A = 0;                       // clear control register A

          setPeriod_Timer0(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER0A, _dutycycle =", _dutycycle);

          // connect Fast PWM to pin on timer 0, channel A
          TCCR0A |= _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);

          OCR0B = _dutycycle;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER0A, TCCR0A =", TCCR0A, ", TCCR0B =", TCCR0B);

          break;
#endif
#endif

          //////////////////////////////////////

#if defined(TCCR0A) && defined(COM0B1)

        case TIMER0B:
          PWM_LOGDEBUG("setPWM_Int:using TIMER0B");

          // connect pwm to pin on timer 0, channel B
          // Set frequency
          TCCR0B = _BV(WGM02);              // set mode as phase correct pwm, stop the timer
          TCCR0A = 0;                       // clear control register A

          setPeriod_Timer0(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER2B, _dutycycle =", _dutycycle);

          // connect Fast PWM to pin on timer 0, channel B
          TCCR0A |= _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);

          OCR0B = _dutycycle;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER0B, TCCR0A =", TCCR0A, ", TCCR0B =", TCCR0B);

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1A1)

        case TIMER1A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER1A");

          // connect pwm to pin on timer 1, channel A
          // Set frequency
          TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR1A = 0;                 // clear control register A

          setPeriod_Timer1(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          TCCR1A |= _BV(COM1A1);

          OCR1A = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1B1)

        case TIMER1B:
          PWM_LOGDEBUG("setPWM_Int:using TIMER1B");

          // connect pwm to pin on timer 1, channel B
          // Set frequency
          TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR1A = 0;                 // clear control register A

          setPeriod_Timer1(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          TCCR1A |= _BV(COM1B1);

          OCR1B = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1C1)

        case TIMER1C:
          PWM_LOGDEBUG("setPWM_Int:using TIMER1C");

          // connect pwm to pin on timer 1, channel C
          // Set frequency
          TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR1A = 0;                 // clear control register A

          setPeriod_Timer1(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          TCCR1A |= _BV(COM1C1);

          OCR1C = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR2) && defined(COM21)

        case TIMER2:
          PWM_LOGDEBUG("setPWM_Int:using TIMER2");

          // connect pwm to pin on timer 0, channel A
          // Set frequency
          TCCR2B = _BV(WGM20);  // set mode as phase correct pwm, stop the timer
          TCCR2A = 0;                       // clear control register A

          setPeriod_Timer2(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER2, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 2
          TCCR2 |= _BV(COM21);
          OCR2 = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if 0
          // TODO, Somehow not usable
#if defined(TCCR2A) && defined(COM2A1)

        case TIMER2A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER2A");

          // connect pwm to pin on timer 2, channel A
          // Set frequency
          TCCR2B = _BV(WGM22);  // set mode as phase correct pwm, stop the timer
          TCCR2A = 0;                       // clear control register A

          setPeriod_Timer2(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER2A, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 2, channel A
          TCCR2A |= _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);

          OCR2B = _dutycycle;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER2A, TCCR2A =", TCCR2A, ", TCCR2B =", TCCR2B);

          break;
#endif
#endif
          //////////////////////////////////////

#if defined(TCCR2A) && defined(COM2B1)

        case TIMER2B:
          PWM_LOGDEBUG("setPWM_Int:using TIMER2B");

          // connect pwm to pin on timer 2, channel B
          // Set frequency
          TCCR2B = _BV(WGM22);              // set mode as phase correct pwm, stop the timer
          TCCR2A = 0;                       // clear control register A

          setPeriod_Timer2(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 8;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER2B, _dutycycle =", _dutycycle);

          // connect Fast PWM to pin on timer 2, channel B
          TCCR2A |= _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);

          OCR2B = _dutycycle;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER2B, TCCR2A =", TCCR2A, ", TCCR2B =", TCCR2B);

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if ( PWM_USING_ATMEGA2560  || PWM_USING_ATMEGA_32U4 )

#if defined(TCCR3A) && defined(COM3A1)

        case TIMER3A:

          TCCR3B = _BV(WGM33);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR3A = 0;                 // clear control register A

          setPeriod_Timer3(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER3A, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 3, channel A
          TCCR3A |= _BV(COM3A1);

          OCR3A = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR3A) && defined(COM3B1)

        case TIMER3B:

          TCCR3B = _BV(WGM33);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR3A = 0;                 // clear control register A

          setPeriod_Timer3(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER3B, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 3, channel B
          TCCR3A |= _BV(COM3B1);

          OCR3B = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR3A) && defined(COM3C1)

        case TIMER3C:


          TCCR3B = _BV(WGM33);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR3A = 0;                 // clear control register A

          setPeriod_Timer3(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER3C, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 3, channel C
          TCCR3A |= _BV(COM3C1);

          OCR3C = _dutycycle; // set pwm duty

          break;
#endif
#endif    // #if ( PWM_USING_ATMEGA2560 || PWM_USING_ATMEGA_32U4 )

          //////////////////////////////////////
          //////////////////////////////////////

#if ( PWM_USING_ATMEGA2560 )

#if defined(TCCR4A)

        case TIMER4A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER4A");

          TCCR4B = _BV(WGM43);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR4A = 0;                 // clear control register A

          setPeriod_Timer4(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER4A, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 4, channel A
          TCCR4A |= _BV(COM4A1);

#if defined(COM4A0)   // only used on 32U4
          TCCR4A &= ~_BV(COM4A0);
#endif

          OCR4A = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4A) && defined(COM4B1)

        case TIMER4B:
          PWM_LOGDEBUG("setPWM_Int:using TIMER4B");

          TCCR4B = _BV(WGM43);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR4A = 0;                 // clear control register A

          setPeriod_Timer4(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER4B, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 4, channel B
          TCCR4A |= _BV(COM4B1);

          OCR4B = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4A) && defined(COM4C1)

        case TIMER4C:
          PWM_LOGDEBUG("setPWM_Int:using TIMER4C");

          TCCR4B = _BV(WGM43);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR4A = 0;                 // clear control register A

          setPeriod_Timer4(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER4C, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 4, channel C
          TCCR4A |= _BV(COM4C1);

          OCR4C = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4C) && defined(COM4D1)

        case TIMER4D:
          PWM_LOGDEBUG("setPWM_Int:using TIMER4D");
          TCCR4B = _BV(WGM43);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR4A = 0;                 // clear control register A

          setPeriod_Timer4(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER4D, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 4, channel D
          TCCR4A |= _BV(COM4D1);

          OCR4D = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5A1)

        case TIMER5A:
          PWM_LOGDEBUG("setPWM_Int:using TIMER5A");

          TCCR5B = _BV(WGM53);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR5A = 0;                 // clear control register A

          setPeriod_Timer5(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER5A, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 5, channel A
          TCCR5A |= _BV(COM5A1);

          OCR5A = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5B1)

        case TIMER5B:
          PWM_LOGDEBUG("setPWM_Int:using TIMER5B");

          TCCR5B = _BV(WGM53);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR5A = 0;                 // clear control register A

          setPeriod_Timer5(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER5B, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 5, channel B
          TCCR5A |= _BV(COM5B1);

          OCR5B = _dutycycle; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5C1)

        case TIMER5C:
          PWM_LOGDEBUG("setPWM_Int:using TIMER5C");

          TCCR5B = _BV(WGM53);        // set mode as phase and frequency correct pwm, stop the timer
          TCCR5A = 0;                 // clear control register A

          setPeriod_Timer5(1000000UL / new_frequency);

          _dutycycle = ((uint32_t) pwmPeriod * dutycycle) >> 16;

          PWM_LOGDEBUG1("setPWM_Int:using TIMER5C, _dutycycle =", _dutycycle);

          // connect pwm to pin on timer 5, channel C
          TCCR5A |= _BV(COM5C1);

          OCR5C = _dutycycle; // set pwm duty

          break;
#endif

#endif    // #if ( PWM_USING_ATMEGA2560 )

        //////////////////////////////////////
        //////////////////////////////////////

        case NOT_ON_TIMER:
        default:

          PWM_LOGERROR1("Error, not usable for PWM, pin =", pin);

          if (_dutycycle < MAX_COUNT / 2)
          {
            digitalWrite(pin, LOW);
          }
          else
          {
            digitalWrite(pin, HIGH);
          }

          return false;
      }

      return true;
    }

    ///////////////////////////////////////////

    bool setPWM()
    {
      return setPWM_Int(_pin, _frequency, _dutycycle);
    }

    ///////////////////////////////////////////

    bool setPWM(const uint8_t& pin, const float& frequency, const float& dutycycle)
    {
      _dutycycle = map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT);
      PWM_LOGDEBUG1("setPWM: _dutycycle =", _dutycycle);

      return setPWM_Int(pin, frequency, _dutycycle);
    }

    ///////////////////////////////////////////

    bool setPWM_Period(const uint8_t& pin, const float& period_us, const float& dutycycle)
    {
      _dutycycle = map(dutycycle, 0, 100.0f, 0, MAX_COUNT_16BIT);

      PWM_LOGDEBUG1("setPWM_Period: _dutycycle =", _dutycycle);

      return setPWM_Int(pin, 1000000.0f / period_us, _dutycycle);
    }

    ///////////////////////////////////////////

    // Must have same frequency
    bool setPWM_manual(const uint8_t& pin, const uint16_t& DCValue)
    {
      // Not the same pin or overvalue
      if ( (_pin != pin) || (DCValue > pwmPeriod) )
        return false;
               
      switch (_timer)
      {
          //////////////////////////////////////
          //////////////////////////////////////

          // TODO To check for atmega8
#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
        case TIMER0A:
          OCR0B = DCValue;   // set pwm duty

          break;

#endif

          //////////////////////////////////////

#if 0
          // Not usable
#if defined(TCCR0A) && defined(COM0A1)

        case TIMER0A:
          OCR0B = DCValue;   // set pwm duty

          PWM_LOGDEBUG3("setPWM_Int:using TIMER0A, TCCR0A =", TCCR0A, ", TCCR0B =", TCCR0B);

          break;
#endif
#endif

          //////////////////////////////////////

#if defined(TCCR0A) && defined(COM0B1)

        case TIMER0B:
          OCR0B = DCValue;   // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1A1)

        case TIMER1A:
          OCR1A = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1B1)

        case TIMER1B:
          OCR1B = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR1A) && defined(COM1C1)

        case TIMER1C:
          OCR1C = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR2) && defined(COM21)

        case TIMER2:
          OCR2 = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if 0
          // TODO, Somehow not usable
#if defined(TCCR2A) && defined(COM2A1)

        case TIMER2A:
          OCR2B = DCValue;   // set pwm duty

          break;
#endif
#endif
          //////////////////////////////////////

#if defined(TCCR2A) && defined(COM2B1)

        case TIMER2B:
          OCR2B = DCValue;   // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if ( PWM_USING_ATMEGA2560  || PWM_USING_ATMEGA_32U4 )

#if defined(TCCR3A) && defined(COM3A1)

        case TIMER3A:
          OCR3A = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR3A) && defined(COM3B1)

        case TIMER3B:
          OCR3B = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR3A) && defined(COM3C1)

        case TIMER3C:
          OCR3C = DCValue; // set pwm duty

          break;
#endif
#endif    // #if ( PWM_USING_ATMEGA2560 || PWM_USING_ATMEGA_32U4 )

          //////////////////////////////////////
          //////////////////////////////////////

#if ( PWM_USING_ATMEGA2560 )

#if defined(TCCR4A)

        case TIMER4A:
          OCR4A = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4A) && defined(COM4B1)

        case TIMER4B:
          OCR4B = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4A) && defined(COM4C1)

        case TIMER4C:
          OCR4C = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR4C) && defined(COM4D1)

        case TIMER4D:
          OCR4D = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////
          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5A1)

        case TIMER5A:
          OCR5A = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5B1)

        case TIMER5B:
          OCR5B = DCValue; // set pwm duty

          break;
#endif

          //////////////////////////////////////

#if defined(TCCR5A) && defined(COM5C1)

        case TIMER5C:
          OCR5C = DCValue; // set pwm duty

          break;
#endif

#endif    // #if ( PWM_USING_ATMEGA2560 )

        //////////////////////////////////////
        //////////////////////////////////////

        case NOT_ON_TIMER:
        default:

          PWM_LOGERROR1("Error, not usable for PWM, pin =", pin);

          return false;
      }

      _dutycycle = DCValue;
      
       PWM_LOGINFO7("PWM enabled, DCValue =", DCValue, ", pwmPeriod =", pwmPeriod,
                   ", _frequency =", _frequency, ", _actualFrequency =", _actualFrequency);

      return true;
    }
    
    ///////////////////////////////////////////
    
    // Faster than setPWM_DCPercentage_manual by not using float
    // DCPercentage from 0-65535 for 0.0f - 100.0f
    bool setPWM_DCPercentageInt_manual(const uint8_t& pin, const uint16_t& DCPercentage)
    {
      //PWM_LOGERROR3("DCPercentage =", DCPercentage, ", DC =", ( DCPercentage >> 8 ) * ( pwmPeriod >> 8) );
      // Convert to DCValue based on pwmPeriod
      return setPWM_manual(pin, ( DCPercentage >> 8 ) * ( pwmPeriod >> 8) );
    }

    ///////////////////////////////////////////
    
    // DCPercentage from 0.0f - 100.0f
    bool setPWM_DCPercentage_manual(const uint8_t& pin, const float& DCPercentage)
    {
      // Convert to DCValue based on pwmPeriod
      return setPWM_manual(pin, (DCPercentage * pwmPeriod) / 100.0f);
    }

    ///////////////////////////////////////////

    inline float getActualDutyCycle()
    {
      return ( (float) _dutycycle * 100 / pwmPeriod);
    }

    ///////////////////////////////////////////

    inline float getActualFreq()
    {
      return _frequency;
    }

    ///////////////////////////////////////////

    inline float getPWMPeriod()
    {
      return pwmPeriod;
    }

    ///////////////////////////////////////////

    inline uint32_t get_freq_CPU()
    {
      return freq_CPU;
    }

    ///////////////////////////////////////////

    inline uint32_t getPin()
    {
      return _pin;
    }

    ///////////////////////////////////////////////////////////////////

  private:

    uint32_t    freq_CPU;

    float       _actualFrequency = 0;
    float       _frequency;

    // dutycycle from 0-65535 for 0%-100% to make use of 16-bit top register
    // _dutycycle = map(dutycycle, 0, 100.0f, 0, 65535) for better accuracy
    uint16_t    _dutycycle;
    //////////

    uint8_t     _pin;

#define INVALID_TIMER     255

    uint8_t     _timer = INVALID_TIMER;

    uint8_t     clockSelectBits;
    uint16_t    pwmPeriod;

    ///////////////////////////////////////////
};

///////////////////////////////////////////


#endif    // AVR_PWM_H

