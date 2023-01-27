# AVR_PWM Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/AVR_PWM.svg?)](https://www.ardu-badge.com/AVR_PWM)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/AVR_PWM.svg)](https://github.com/khoih-prog/AVR_PWM/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/AVR_PWM/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/AVR_PWM.svg)](http://github.com/khoih-prog/AVR_PWM/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this AVR_PWM library](#why-do-we-need-this-AVR_PWM-library)
  * [Features](#features)
  * [Why using hardware-based PWM is better](#why-using-hardware-based-pwm-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [More useful Information](#more-useful-information)
  * [1. Timer0](#1-timer0)
  * [2. Timer1](#2-timer1)
  * [3. Timer2](#3-timer2)
  * [4. Timer3, Timer4, Timer5](#4-timer3-timer4-timer5)
  * [5. Important Notes](#5-important-notes)
* [Usage](#usage)
  * [1. Create PWM Instance with Pin, Frequency and dutycycle](#1-Create-PWM-Instance-with-Pin-Frequency-and-dutycycle)
  * [2. Initialize PWM Instance](#2-Initialize-PWM-Instance)
  * [3. Set or change PWM frequency or dutyCycle](#3-set-or-change-PWM-frequency-or-dutyCycle)
  * [4. Set or change PWM frequency and dutyCycle manually and efficiently in waveform creation](#4-Set-or-change-PWM-frequency-and-dutyCycle-manually-and-efficiently-in-waveform-creation)
* [Examples](#examples)
  * [ 1. PWM_Basic](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Basic)
  * [ 2. PWM_DynamicDutyCycle](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicDutyCycle) 
  * [ 3. PWM_DynamicDutyCycle_Int](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicDutyCycle_Int)
  * [ 4. PWM_DynamicFreq](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicFreq)
  * [ 5. PWM_Multi](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Multi)
  * [ 6. PWM_MultiChannel](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_MultiChannel)
  * [ 7. PWM_Waveform](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Waveform)
  * [ 8. PWM_StepperControl](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_StepperControl) **New**
  * [ 9. PWM_manual](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_manual) **New**
  * [10. PWM_SpeedTest](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_SpeedTest) **New**
* [Example PWM_Multi](#example-PWM_Multi)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. PWM_DynamicDutyCycle on Arduino AVR Mega2560](#1-PWM_DynamicDutyCycle-on-Arduino-AVR-Mega2560)
  * [2. PWM_Multi on Arduino AVR Mega2560](#2-PWM_DynamicDutyCycle-on-Arduino-AVR-Mega2560)
  * [3. PWM_DynamicFreq on Arduino AVR Mega2560](#3-PWM_DynamicFreq-on-Arduino-AVR-Mega2560)
  * [4. PWM_Waveform on Arduino AVR Mega2560](#4-PWM_Waveform-on-Arduino-AVR-Mega2560)
  * [5. PWM_Waveform on Arduino AVR ATMega32U4](#5-PWM_Waveform-on-Arduino-AVR-ATMega32U4)
  * [6. PWM_Waveform on Arduino AVR Nano](#6-PWM_Waveform-on-Arduino-AVR-Nano)
  * [7. PWM_manual on Arduino AVR Nano](#7-PWM_manual-on-Arduino-AVR-Nano)
  * [8. PWM_SpeedTest on Arduino AVR Nano](#8-PWM_SpeedTest-on-Arduino-AVR-Nano)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [AVR_PWM library](https://github.com/khoih-prog/AVR_PWM)

### Features

This hardware-based PWM library enables you to use Hardware-PWM on AVR-based boards to create and output PWM. These purely hardware-based PWM channels can generate very high PWM frequencies, depending on CPU clock and acceptable accuracy, due to 8 or 16-bit PWM / Timer registers.

This library is using the **same or similar functions** as other `FastPWM` libraries, as follows, to enable you to **port your PWM code easily between platforms**

 1. [**RP2040_PWM**](https://github.com/khoih-prog/RP2040_PWM)
 2. [**AVR_PWM**](https://github.com/khoih-prog/AVR_PWM)
 3. [**megaAVR_PWM**](https://github.com/khoih-prog/megaAVR_PWM)
 4. [**ESP32_FastPWM**](https://github.com/khoih-prog/ESP32_FastPWM)
 5. [**SAMD_PWM**](https://github.com/khoih-prog/SAMD_PWM)
 6. [**SAMDUE_PWM**](https://github.com/khoih-prog/SAMDUE_PWM)
 7. [**nRF52_PWM**](https://github.com/khoih-prog/nRF52_PWM)
 8. [**Teensy_PWM**](https://github.com/khoih-prog/Teensy_PWM)
 9. [**ATtiny_PWM**](https://github.com/khoih-prog/ATtiny_PWM)
10. [**Dx_PWM**](https://github.com/khoih-prog/Dx_PWM)
11. [**Portenta_H7_PWM**](https://github.com/khoih-prog/Portenta_H7_PWM)
12. [**MBED_RP2040_PWM**](https://github.com/khoih-prog/MBED_RP2040_PWM)
13. [**nRF52_MBED_PWM**](https://github.com/khoih-prog/nRF52_MBED_PWM)
14. [**STM32_PWM**](https://github.com/khoih-prog/STM32_PWM)


---

The most important feature is they're purely hardware-based PWM channels. Therefore, their operations are **not blocked by bad-behaving software functions / tasks**.

This important feature is absolutely necessary for mission-critical tasks. These hardware PWM-channels, still work even if other software functions are blocking. Moreover, they are much more precise (certainly depending on clock frequency accuracy) than other software timers using millis() or micros(). That's necessary if you need to control external systems (Servo, etc.) requiring better accuracy.

New efficient `setPWM_manual()` function enables waveform creation using PWM.

The [**PWM_Multi**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Multi) example will demonstrate the usage of multichannel PWM using multiple Hardware-PWM blocks (slices). The 4 independent Hardware-PWM channels are used **to control 4 different PWM outputs**, with totally independent frequencies and dutycycles on `Arduino Mega`.

Being hardware-based PWM, their executions are not blocked by bad-behaving functions / tasks, such as connecting to WiFi, Internet or Blynk services.

This non-being-blocked important feature is absolutely necessary for mission-critical tasks.


---

#### Why using hardware-based PWM is better

Imagine you have a system with a **mission-critical** function, controlling a robot or doing something much more important. You normally use a software timer to poll, or even place the function in loop(). But what if another function is **blocking** the loop() or setup().

So your function **might not be executed, and the result would be disastrous.**

You'd prefer to have your function called, no matter what happening with other functions (busy loop, bug, etc.).

The correct choice is to use `hardware-based PWM`.

These hardware-based PWM channels still work even if other software functions are blocking. Moreover, they are much more **precise** (certainly depending on clock frequency accuracy) than other software-based PWMs, using millis() or micros().

Functions using normal software-based PWMs, relying on loop() and calling millis(), won't work if the loop() or setup() is blocked by certain operation. For example, certain function is blocking while it's connecting to WiFi or some services.


---

### Currently supported Boards

1. **AVR-based boards** using ATMEGA_328P, ATMEGA_2560, ATMEGA_1280, ATMEGA_640, ATMEGA_16U4, ATMEGA_32U4, etc. boards such as **Mega-2560, UNO, Nano, Leonardo**, etc., using **Arduino, Adafruit or Sparkfun AVR core**


---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.6+`](https://github.com/arduino/ArduinoCore-avr) for Arduino AVR boards. Use Arduino Board Manager to install. [![Latest release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest/)
 3. [`Adafruit AVR core 1.4.15+`](https://github.com/adafruit/Adafruit_Arduino_Boards) for Adafruit AVR boards. Use Arduino Board Manager to install. [![Latest release](https://img.shields.io/github/release/adafruit/Adafruit_Arduino_Boards.svg)](https://github.com/adafruit/Adafruit_Arduino_Boards/releases/latest/)
 4. [`Sparkfun AVR core 1.1.13+`](https://github.com/sparkfun/Arduino_Boards) for Sparkfun AVR boards. Use Arduino Board Manager to install. 
 
 
---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**AVR_PWM**](https://github.com/khoih-prog/AVR_PWM), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/AVR_PWM.svg?)](https://www.ardu-badge.com/AVR_PWM) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**AVR_PWM**](https://github.com/khoih-prog/AVR_PWM) page.
2. Download the latest release `AVR_PWM-main.zip`.
3. Extract the zip file to `AVR_PWM-main` directory 
4. Copy whole `AVR_PWM-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**AVR_PWM** library](https://registry.platformio.org/libraries/khoih-prog/AVR_PWM) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/AVR_PWM/installation). Search for **AVR_PWM** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

## More useful Information

From [Arduino 101: Timers and Interrupts](https://www.robotshop.com/community/forum/t/arduino-101-timers-and-interrupts/13072)

### 1. Timer0:

Timer0 is a 8-bit timer.

In the Arduino world, **Timer0 is been used for the timer functions**, like delay(), millis() and micros(). If you change Timer0 registers, this may influence the Arduino timer function. So you should know what you are doing.

### 2. Timer1:

**Timer1** is a 16-bit timer. In the Arduino world, the Servo library uses Timer1 on Arduino Uno (Timer5 on Arduino Mega).

### 3. Timer2:

**Timer2** is a 8-bit timer like Timer0. This Timer2 is not available for **ATMEGA_16U4, ATMEGA_32U4 boards**, such as Leonardo, YUN, ESPLORA, etc.
In the Arduino world, the **tone() function uses Timer2**.

### 4. Timer3, Timer4, Timer5:

**Timer4** is only available on Arduino **ATMEGA_2560, ATMEGA_1280, ATMEGA_640, ATMEGA_16U4, ATMEGA_32U4 boards**. This Timer4 is 16-bit timer on **ATMEGA_2560, ATMEGA_1280, ATMEGA_640 boards** and 10-bit (but used as 8-bit in this library) Timer on **ATMEGA_16U4, ATMEGA_32U4 boards**

**Timer3 and Timer5** are only available on Arduino Mega boards. These 2 timers are all 16-bit timers.


### 5. Important Notes

Before using any Timer, you have to make sure the **Timer has not been used by any other purpose.**


```cpp
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
```

#### Timer1,3,4 are supported for ATMEGA_16U4, ATMEGA_32U4 boards, such as Leonardo, YUN, ESPLORA, etc.

#### Only Timer1 and Timer2 are supported for Nano, UNO, etc. boards possessing 3 timers.

#### Timer1-Timer5 are available for Arduino Mega boards.


---
---

## Usage

Before using any PWM `Timer` and `channel`, you have to make sure the `Timer` and `channel` has not been used by any other purpose.

#### 1. Create PWM Instance with Pin, Frequency and dutycycle

```cpp
AVR_PWM* PWM_Instance;

PWM_Instance = new AVR_PWM(PWM_Pins, freq, dutyCycle);
```

#### 2. Initialize PWM Instance

```cpp
if (PWM_Instance)
{
  PWM_Instance->setPWM();
}
```

#### 3. Set or change PWM frequency or dutyCycle

To use `float new_dutyCycle`

```cpp
PWM_Instance->setPWM(PWM_Pins, new_frequency, new_dutyCycle);
```

such as 

```cpp
dutyCycle = 10.0f;
  
Serial.print(F("Change PWM DutyCycle to ")); Serial.println(dutyCycle);
PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
```

---

To use `uint32_t new_dutyCycle` = `(real_dutyCycle * 65536) / 100`


```cpp
PWM_Instance->setPWM_Int(PWM_Pins, new_frequency, new_dutyCycle);
```

such as for `real_dutyCycle = 50%`

```cpp
// 50% dutyCycle = (real_dutyCycle * 65536) / 100
dutyCycle = 32768;

Serial.print(F("Change PWM DutyCycle to (%) "));
Serial.println((float) dutyCycle * 100 / 65536);
PWM_Instance->setPWM_Int(pinToUse, frequency, dutyCycle);
```

for `real_dutyCycle = 50%`

```cpp
// 20% dutyCycle = (real_dutyCycle * 65536) / 100
dutyCycle = 13107;

Serial.print(F("Change PWM DutyCycle to (%) "));
Serial.println((float) dutyCycle * 100 / 65536);
PWM_Instance->setPWM_Int(pinToUse, frequency, dutyCycle);
```

#### 4. Set or change PWM frequency and dutyCycle manually and efficiently in waveform creation

Function prototype

```cpp
bool setPWM_manual(const uint8_t& pin, const uint16_t& DCValue);
bool setPWM_DCPercentage_manual(const uint8_t& pin, const float& DCPercentage);
```

Need to call only once for each pin


```cpp
PWM_Instance->setPWM(PWM_Pins, frequency, dutyCycle);
```

after that, if just changing `dutyCycle` / `level`, use the **fastest**

```cpp
// For 50.0f dutycycle
// 8415-8423ns
new_level = 50.0f * PWM_Instance->getPWMPeriod() / 100.0f ;
PWM_Instance->setPWM_manual(PWM_Pins, new_level);
```

or better and much easier to use, but `slowest`

```cpp
// 52745ns
new_DCPercentage = 50.0f;
PWM_Instance->setPWM_DCPercentage_manual(PWM_Pins, new_DCPercentage);
```

or the `faster`

```cpp
// dutycyclePercent = 0-65535 == 0-100%
// Faster, 8863ns
dutycyclePercentInt = 1 << 15;   // 50%
PWM_Instance->setPWM_DCPercentageInt_manual(pinToUse, dutycyclePercentInt);
```

---
---

### Examples: 

 1. [PWM_Basic](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Basic)
 2. [PWM_DynamicDutyCycle](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicDutyCycle)
 3. [PWM_DynamicDutyCycle_Int](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicDutyCycle_Int)
 4. [PWM_DynamicFreq](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicFreq)
 5. [PWM_Multi](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Multi)
 6. [PWM_MultiChannel](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_MultiChannel)
 7. [PWM_Waveform](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Waveform)
 8. [PWM_StepperControl](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_StepperControl) **New**
 9. [PWM_manual](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_manual) **New**
10. [PWM_SpeedTest](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_SpeedTest) **New**
 
---
---

### Example [PWM_Multi](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Multi)

https://github.com/khoih-prog/AVR_PWM/blob/22230c236f4eaf3c4b4ee35f2008e78349acdf11/examples/PWM_Multi/PWM_Multi.ino#L60-L176


---
---

### Debug Terminal Output Samples

### 1. PWM_DynamicDutyCycle on Arduino AVR Mega2560

The following is the sample terminal output when running example [PWM_DynamicDutyCycle](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicDutyCycle) on **AVR Mega2560**, to demonstrate the ability to provide high PWM frequencies and ability to change DutyCycle `on-the-fly`.


```cpp
Starting PWM_DynamicDutyCycle on Arduino AVR Mega2560/ADK
AVR_PWM v1.2.0
[PWM] AVR_PWM: _dutycycle = 32767
[PWM] setPWM_Int: _dutycycle = 32767
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 1600
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 1600
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 799
=====================================================================================
Change PWM DutyCycle to 90.00
[PWM] setPWM: _dutycycle = 58981
[PWM] setPWM_Int: _dutycycle = 58981
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 8000
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 8000
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 7199
=====================================================================================
Actual data: pin = 8, PWM DC = 89.99, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=====================================================================================
Change PWM DutyCycle to 10.00
[PWM] setPWM: _dutycycle = 6553
[PWM] setPWM_Int: _dutycycle = 6553
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 8000
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 8000
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 799
=====================================================================================
Actual data: pin = 8, PWM DC = 9.99, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=====================================================================================
```

---

### 2. PWM_Multi on Arduino AVR Mega2560

The following is the sample terminal output when running example [**PWM_Multi**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Multi) on **AVR Mega2560**, to demonstrate the ability to provide high PWM frequencies on multiple `PWM-capable` pins.

```cpp
Starting PWM_Multi on Arduino AVR Mega2560/ADK
AVR_PWM v1.2.0
=====================================================================================
Index	Pin	PWM_freq	DutyCycle	Actual Freq
=====================================================================================
0	5	2000.00		10.00		2000.0000
1	8	3000.00		30.00		3003.0029
2	9	4000.00		50.00		4000.0000
3	12	8000.00		90.00		8000.0000
=====================================================================================
Actual data: pin = 5, PWM DC = 9.98, PWMPeriod = 4000.00, PWM Freq (Hz) = 2000.0000
=====================================================================================
=====================================================================================
Actual data: pin = 8, PWM DC = 29.99, PWMPeriod = 2664.00, PWM Freq (Hz) = 3003.0029
=====================================================================================
=====================================================================================
Actual data: pin = 9, PWM DC = 49.60, PWMPeriod = 125.00, PWM Freq (Hz) = 4000.0000
=====================================================================================
=====================================================================================
Actual data: pin = 12, PWM DC = 89.90, PWMPeriod = 1000.00, PWM Freq (Hz) = 8000.0000
=====================================================================================
```

---

### 3. PWM_DynamicFreq on Arduino AVR Mega2560

The following is the sample terminal output when running example [**PWM_DynamicFreq**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_DynamicFreq) on **AVR Mega2560**, to demonstrate the ability to change dynamically PWM frequencies.

```cpp
Starting PWM_DynamicFreq on Arduino AVR Mega2560/ADK
AVR_PWM v1.2.0
[PWM] AVR_PWM: _dutycycle = 32767
[PWM] setPWM_Int: _dutycycle = 32767
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 800
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 800
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 399
=====================================================================================
Change PWM Freq to 20000.00
[PWM] setPWM: _dutycycle = 32767
[PWM] setPWM_Int: _dutycycle = 32767
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 400
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 400
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 199
=====================================================================================
Actual data: pin = 8, PWM DC = 49.75, PWMPeriod = 400.00, PWM Freq (Hz) = 20000.0000
=====================================================================================
Change PWM Freq to 10000.00
[PWM] setPWM: _dutycycle = 32767
[PWM] setPWM_Int: _dutycycle = 32767
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 800
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 800
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 399
=====================================================================================
Actual data: pin = 8, PWM DC = 49.88, PWMPeriod = 800.00, PWM Freq (Hz) = 10000.0000
=====================================================================================
Change PWM Freq to 20000.00
[PWM] setPWM: _dutycycle = 32767
[PWM] setPWM_Int: _dutycycle = 32767
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 400
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 400
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 199
=====================================================================================
Actual data: pin = 8, PWM DC = 49.75, PWMPeriod = 400.00, PWM Freq (Hz) = 20000.0000
=====================================================================================
```

---


### 4. PWM_Waveform on Arduino AVR Mega2560

The following is the sample terminal output when running example [**PWM_Waveform**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Waveform) on **AVR Mega2560**, to demonstrate how to use the `setPWM_manual()` function in wafeform creation


```cpp
Starting PWM_Waveform on Arduino AVR Mega2560/ADK
AVR_PWM v1.2.0
[PWM] AVR_PWM: _dutycycle = 0
[PWM] setPWM: _dutycycle = 0
[PWM] setPWM_Int: _dutycycle = 0
[PWM] setPWM_Int:using TIMER4C
[PWM] setPeriod_Timer4: F_CPU = 16000000 , cycles = 8000
[PWM] setPeriod_Timer4: clockSelectBits = 1 , pwmPeriod = 8000
[PWM] setPWM_Int:using TIMER4C, _dutycycle = 0
============================================================================================
Actual data: pin = 8, PWM DutyCycle = 0.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
============================================================================================
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 8000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
```

---

### 5. PWM_Waveform on Arduino AVR ATMega32U4

The following is the sample terminal output when running example [**PWM_Waveform**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Waveform) on **ATMega32U4**, to demonstrate how to use the `setPWM_manual()` function in wafeform creation


```cpp
Starting PWM_Waveform on Arduino AVR ATMega32U4
AVR_PWM v1.2.0
[PWM] AVR_PWM: _dutycycle = 0
[PWM] setPWM: _dutycycle = 0
[PWM] setPWM_Int: _dutycycle = 0
[PWM] setPWM_Int:using TIMER1A
[PWM] setPeriod_Timer1: F_CPU = 16000000 , cycles = 8000
[PWM] setPeriod_Timer1: clockSelectBits = 1 , pwmPeriod = 8000
============================================================================================
Actual data: pin = 9, PWM DutyCycle = 0.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
============================================================================================
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 8000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
```

---

### 6. PWM_Waveform on Arduino AVR Nano

The following is the sample terminal output when running example [**PWM_Waveform**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_Waveform) on **AVR Nano**, to demonstrate how to use the `setPWM_manual()` function in wafeform creation


```cpp
Starting PWM_Waveform on Arduino AVR UNO, Nano, etc.
AVR_PWM v1.2.0
[PWM] AVR_PWM: _dutycycle = 0
[PWM] setPWM: _dutycycle = 0
[PWM] setPWM_Int: _dutycycle = 0
[PWM] setPWM_Int:using TIMER1B
[PWM] setPeriod_Timer1: F_CPU = 16000000 , cycles = 8000
[PWM] setPeriod_Timer1: clockSelectBits = 1 , pwmPeriod = 8000
============================================================================================
Actual data: pin = 10, PWM DutyCycle = 0.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
============================================================================================
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 8000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 7000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 6000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 5000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 4000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 3000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 2000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 1000 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 500 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
[PWM] PWM enabled, DCValue = 0 , pwmPeriod = 8000 , _frequency = 1000.00 , _actualFrequency = 1000.00
```


---

### 7. PWM_manual on Arduino AVR Nano

The following is the sample terminal output when running example [**PWM_manual**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_manual) on **AVR Nano**, to demonstrate how to use the `setPWM_manual()` and `setPWM_DCPercentage_manual()` functions in wafeform creation


```cpp
Starting PWM_manual on Arduino AVR UNO, Nano, etc.
AVR_PWM v1.2.0
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 0.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 1.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 2.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 3.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 4.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 5.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 6.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 7.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 8.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
```

---

### 8. PWM_SpeedTest on Arduino AVR Nano

The following is the sample terminal output when running example [**PWM_SpeedTest**](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_SpeedTest) on **AVR Nano**, to demonstrate how to use new faster `setPWM_DCPercentageInt_manual()` function in wafeform creation, The time is `8863ns` compared to `52745ns` when using `setPWM_DCPercentage_manual()` function. The fastest is `setPWM_manual` with `8423ns`, which is to be used with pre-calculated values in array

```
Starting PWM_SpeedTest on Arduino AVR UNO, Nano, etc.
AVR_PWM v1.2.0
=================================================================================================
Actual data: pin = 10, PWM DutyCycle % = 0.00, PWMPeriod = 8000.00, PWM Freq (Hz) = 1000.0000
=================================================================================================
Average time of setPWM function USING_DC_PERCENT
ns=8863
ns=8854
ns=8863
ns=8854
ns=8863
ns=8854
ns=8863
...
```

---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level `_PWM_LOGLEVEL_` from 0 to 4

```cpp
// Don't define _PWM_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
#define _PWM_LOGLEVEL_     0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

### Issues

Submit issues to: [AVR_PWM issues](https://github.com/khoih-prog/AVR_PWM/issues)

---

## TO DO

1. Search for bug and improvement.
2. Similar features for remaining Arduino boards

---

## DONE

 1. Basic hardware-based multi-channel PWMs for **AVR-based boards** such as Mega-2560, UNO, Nano, Leonardo, etc. using AVR cores, such as 
 - [`Arduino AVR core`](https://github.com/arduino/ArduinoCore-avr)
 - [`Adafruit AVR core`](https://github.com/adafruit/Adafruit_Arduino_Boards)
 - [`Sparkfun AVR core`](https://github.com/sparkfun/Arduino_Boards)
 2. Add example [PWM_StepperControl](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_StepperControl) to demo how to control Stepper Motor using PWM
 3. Add example [PWM_manual](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_manual) to demo how to correctly use PWM to generate waveform
 4. Add function `setPWM_DCPercentage_manual()` to facilitate the setting PWM DC manually by using DCPercentage, instead of absolute DCValue depending on varying PWMPeriod
 5. Catch low frequency error and use lowest permissible frequency
 6. Optimize speed with new `setPWM_DCPercentageInt_manual` function to improve speed almost 85% compared to `setPWM_DCPercentage_manual`
 7. Add example [PWM_SpeedTest](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_SpeedTest) to demo the better speed of new `setPWM_DCPercentageInt_manual` function


---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [Paul van Dinther](https://github.com/dinther) for proposing new way to use PWM to drive Stepper-Motor in [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/RP2040_PWM/issues/16), leading to v1.0.1
2. Thanks to [laflaf3d](https://github.com/laflaf3d) for initiate the Discussion in [About DCValue in setPWM_manual #2](https://github.com/khoih-prog/AVR_PWM/discussions/2), leading to v1.1.0

<table>
  <tr>
    <td align="center"><a href="https://github.com/dinther"><img src="https://github.com/dinther.png" width="100px;" alt="dinther"/><br /><sub><b>Paul van Dinther</b></sub></a><br /></td>
  <td align="center"><a href="https://github.com/laflaf3d"><img src="https://github.com/laflaf3d.png" width="100px;" alt="laflaf3d"/><br /><sub><b>laflaf3d</b></sub></a><br /></td>
</table>

  
---

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/AVR_PWM/blob/main/LICENSE)

---

## Copyright

Copyright (c) 2022- Khoi Hoang


