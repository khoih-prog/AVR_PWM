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

* [Changelog](#changelog)
  * [Releases v1.2.0](#Releases-v120)
  * [Releases v1.1.0](#Releases-v110)
  * [Releases v1.0.1](#Releases-v101)
  * [Initial Releases v1.0.0](#Initial-Releases-v100)

---
---

## Changelog

### Releases v1.2.0

1. Optimize speed with new `setPWM_DCPercentageInt_manual` function to improve speed almost 85% compared to `setPWM_DCPercentage_manual`
2. Add example [PWM_SpeedTest](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_SpeedTest) to demo the better speed of new `setPWM_DCPercentageInt_manual` function
3. Improve `README.md` so that links can be used in other sites, such as PIO

### Releases v1.1.0

1. Add example [PWM_manual](https://github.com/khoih-prog/AVR_PWM/tree/main/examples/PWM_manual) to demo how to correctly use PWM to generate waveform. Check [About DCValue in setPWM_manual #2](https://github.com/khoih-prog/AVR_PWM/discussions/2)
2. Add function `setPWM_DCPercentage_manual()` to facilitate the setting PWM DC manually by using DCPercentage, instead of absolute DCValue depending on varying PWMPeriod
3. Catch low frequency error and use lowest permissible frequency

### Releases v1.0.1

1. Add example [PWM_StepperControl](https://github.com/khoih-prog/AVR_PWM/examples/PWM_StepperControl) to demo how to control Stepper Motor using PWM. Check [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/RP2040_PWM/issues/16)

### Initial Releases v1.0.0

1. Initial coding to support **AVR boards, such as Mega-2560, UNO, Nano, Leonardo, etc.**, using AVR cores
2. The hardware-based PWM channels can generate very high frequencies.

---
---

## Copyright

Copyright 2022- Khoi Hoang


