/****************************************************************************************************************************
  PWM_Generic_Debug.h
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

#ifndef PWM_GENERIC_DEBUG_H
#define PWM_GENERIC_DEBUG_H

#ifdef PWM_GENERIC_DEBUG_PORT
  #define PWM_DBG_PORT      PWM_GENERIC_DEBUG_PORT
#else
  #define PWM_DBG_PORT      Serial
#endif

// Change _PWM_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _PWM_LOGLEVEL_
  #define _PWM_LOGLEVEL_       1
#endif

///////////////////////////////////////

const char PWM_MARK[]  = "[PWM] ";
const char PWM_SPACE[] = " ";

#define PWM_PRINT        PWM_DBG_PORT.print
#define PWM_PRINTLN      PWM_DBG_PORT.println

#define PWM_PRINT_MARK   PWM_PRINT(PWM_MARK)
#define PWM_PRINT_SP     PWM_PRINT(PWM_SPACE)
#define PWM_PRINT_LINE   PWM_PRINT(PWM_LINE)

///////////////////////////////////////

#define PWM_LOGERROR0(x)        if(_PWM_LOGLEVEL_>0) { PWM_PRINT(x); }
#define PWM_LOGERROR(x)         if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINTLN(x); }
#define PWM_LOGERROR1(x,y)      if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINTLN(y); }
#define PWM_HEXLOGERROR1(x,y)   if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT(" 0x"); PWM_PRINTLN(y, HEX); }
#define PWM_LOGERROR2(x,y,z)    if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINTLN(z); }
#define PWM_LOGERROR3(x,y,z,w)  if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINTLN(w); }
#define PWM_LOGERROR5(x,y,z,w,xx,yy) if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINTLN(yy); }
#define PWM_LOGERROR7(x,y,z,w,xx,yy,zz,ww) if(_PWM_LOGLEVEL_>0) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINT(yy); PWM_PRINT_SP; PWM_PRINT(zz); PWM_PRINT_SP; PWM_PRINTLN(ww); }

//////////////////////////////////////////

#define PWM_LOGWARN0(x)         if(_PWM_LOGLEVEL_>1) { PWM_PRINT(x); }
#define PWM_LOGWARN(x)          if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINTLN(x); }
#define PWM_LOGWARN1(x,y)       if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINTLN(y); }
#define PWM_HEXLOGWARN1(x,y)    if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT(" 0x"); PWM_PRINTLN(y, HEX); }
#define PWM_LOGWARN2(x,y,z)     if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINTLN(z); }
#define PWM_LOGWARN3(x,y,z,w)   if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINTLN(w); }
#define PWM_LOGWARN5(x,y,z,w,xx,yy) if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINTLN(yy); }
#define PWM_LOGWARN7(x,y,z,w,xx,yy,zz,ww) if(_PWM_LOGLEVEL_>1) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINT(yy); PWM_PRINT_SP; PWM_PRINT(zz); PWM_PRINT_SP; PWM_PRINTLN(ww); }

//////////////////////////////////////////

#define PWM_LOGINFO0(x)         if(_PWM_LOGLEVEL_>2) { PWM_PRINT(x); }
#define PWM_LOGINFO(x)          if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINTLN(x); }
#define PWM_LOGINFO1(x,y)       if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINTLN(y); }
#define PWM_HEXLOGINFO1(x,y)    if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT(" 0x"); PWM_PRINTLN(y, HEX); }
#define PWM_LOGINFO2(x,y,z)     if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINTLN(z); }
#define PWM_LOGINFO3(x,y,z,w)   if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINTLN(w); }
#define PWM_LOGINFO5(x,y,z,w,xx,yy) if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINTLN(yy); }
#define PWM_LOGINFO7(x,y,z,w,xx,yy,zz,ww) if(_PWM_LOGLEVEL_>2) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINT(yy); PWM_PRINT_SP; PWM_PRINT(zz); PWM_PRINT_SP; PWM_PRINTLN(ww); }

//////////////////////////////////////////

#define PWM_LOGDEBUG0(x)        if(_PWM_LOGLEVEL_>3) { PWM_PRINT(x); }
#define PWM_LOGDEBUG(x)         if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINTLN(x); }
#define PWM_LOGDEBUG1(x,y)      if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINTLN(y); }
#define PWM_HEXLOGDEBUG1(x,y)   if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT(" 0x"); PWM_PRINTLN(y, HEX); }
#define PWM_LOGDEBUG2(x,y,z)    if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINTLN(z); }
#define PWM_LOGDEBUG3(x,y,z,w)  if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINTLN(w); }
#define PWM_LOGDEBUG5(x,y,z,w,xx,yy) if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINTLN(yy); }
#define PWM_LOGDEBUG7(x,y,z,w,xx,yy,zz,ww) if(_PWM_LOGLEVEL_>3) { PWM_PRINT_MARK; PWM_PRINT(x); PWM_PRINT_SP; PWM_PRINT(y); PWM_PRINT_SP; PWM_PRINT(z); PWM_PRINT_SP; PWM_PRINT(w); PWM_PRINT_SP; PWM_PRINT(xx); PWM_PRINT_SP; PWM_PRINT(yy); PWM_PRINT_SP; PWM_PRINT(zz); PWM_PRINT_SP; PWM_PRINTLN(ww); }

//////////////////////////////////////////

///////////////////////////////////////

#endif    //PWM_GENERIC_DEBUG_H
