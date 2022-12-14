/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2019 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#undef USING_GENERATED_CONFIG_H

#ifndef SDL_config_ps4_h_
#define SDL_config_ps4_h_
#define SDL_config_h_

#include "SDL_platform.h"



#ifdef __GNUC__
#define HAVE_GCC_SYNC_LOCK_TEST_AND_SET 1
#endif

#define HAVE_GCC_ATOMICS    1

#define STDC_HEADERS    1
#define HAVE_ALLOCA_H	1
#define HAVE_CTYPE_H    1
#define HAVE_INTTYPES_H 1
#define HAVE_LIMITS_H   1
#define HAVE_MATH_H		1
#define HAVE_STDINT_H   1
#define HAVE_STDIO_H    1
#define HAVE_STRING_H   1
#define HAVE_SYS_TYPES_H    1
//#define HAVE_SIGNAL_H   0

/* C library functions */
#define HAVE_MALLOC 1
#define HAVE_CALLOC 1
#define HAVE_REALLOC    1
#define HAVE_FREE   1
#define HAVE_ALLOCA 1
//#define HAVE_GETENV 1
//#define HAVE_SETENV 1
//#define HAVE_PUTENV 1
//#define HAVE_SETENV 1
//#define HAVE_UNSETENV   1
#define HAVE_QSORT  1
#define HAVE_ABS    1
#define HAVE_BCOPY  1
#define HAVE_MEMSET 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE    1
#define HAVE_MEMCMP 1
#define HAVE_STRLEN 1
#define HAVE_STRLCPY    1
#define HAVE_STRLCAT    1
#define HAVE_STRCHR 1
#define HAVE_STRRCHR    1
#define HAVE_STRSTR 1
#define HAVE_STRTOL 1
#define HAVE_STRTOUL    1
#define HAVE_STRTOLL    1
#define HAVE_STRTOULL   1
#define HAVE_STRTOD 1
#define HAVE_ATOI   1
#define HAVE_ATOF   1
#define HAVE_STRCMP 1
#define HAVE_STRNCMP    1
#define HAVE_STRCASECMP 1
#define HAVE_STRNCASECMP 1
#define HAVE_VSSCANF 1
#define HAVE_VSNPRINTF  1
#define HAVE_M_PI   1
#define HAVE_ACOS   1
#define HAVE_ACOSF  1
#define HAVE_ASIN   1
#define HAVE_ASINF  1
#define HAVE_ATAN   1
#define HAVE_ATANF  1
#define HAVE_ATAN2  1
#define HAVE_ATAN2F 1
#define HAVE_CEIL   1
#define HAVE_CEILF  1
#define HAVE_COPYSIGN   1
#define HAVE_COPYSIGNF  1
#define HAVE_COS    1
#define HAVE_COSF   1
#define HAVE_EXP    1
#define HAVE_EXPF   1
#define HAVE_FABS   1
#define HAVE_FABSF  1
#define HAVE_FLOOR  1
#define HAVE_FLOORF 1
#define HAVE_FMOD   1
#define HAVE_FMODF  1
#define HAVE_LOG    1
#define HAVE_LOGF   1
#define HAVE_LOG10  1
#define HAVE_LOG10F 1
#define HAVE_POW    1
#define HAVE_POWF   1
#define HAVE_SCALBN 1
#define HAVE_SCALBNF    1
#define HAVE_SIN    1
#define HAVE_SINF   1
#define HAVE_SQRT   1
#define HAVE_SQRTF  1
#define HAVE_TAN    1
#define HAVE_TANF   1
#define HAVE_SETJMP 1
#define HAVE_NANOSLEEP  1
/* #define HAVE_SYSCONF  1 */
/* #define HAVE_SIGACTION    1 */


//#define LACKS_SYS_MMAN_H 1

// Try to use C++ <thread>
#define SDL_THREAD_PTHREAD 1
//#define SDL_THREAD_STDCPP 1

/* Enable the PS4 timer support (src/timer/ps4/\*.c) */
//#define SDL_TIMERS_PS4  1
#define SDL_TIMER_UNIX 1

/* Enable the PS4 joystick driver (src/joystick/ps4/\*.c) */
#define SDL_JOYSTICK_PS4        1

/* Enable the dummy sensor driver */
#define SDL_SENSOR_DUMMY  1


#define SDL_AUDIO_DRIVER_PS4	1		// PS4 audio driver (src/audio/ps4/\*.c)
#define SDL_VIDEO_DRIVER_PS4	1
#define SDL_VIDEO_RENDER_PS4	1

/* !!! FIXME: use std or wrap */
#define SDL_FILESYSTEM_DUMMY   1

/* (src/haptic/dummy/\*.c) */
#define SDL_HAPTIC_DISABLED    1

/*  (src/loadso/dummy/\*.c) */
#define SDL_LOADSO_DISABLED    1

#ifdef _DEBUG
#define D_FN()		\
	printf(">>>>>>>>>>> %s() <<<<<<<<<<<< \n", __FUNCTION__)

#define D_MSG(m)	\
	printf("@@>>>>> %s(): %s <<<<<<<<<<<< \n", __FUNCTION__, m)
#else

// If your compiler wants __noop you'll have to add //

#define D_FN()
#define D_MSG(m)

#endif


#endif /* SDL_config_ps4_h_ */

#define SIGHUP    1
#define SIGINT    2
#define SIGQUIT   3
#define SIGILL    4
#define SIGTRAP   5
#define SIGABRT   6
#define SIGIOT    SIGABRT
#define SIGEMT    7
#define SIGFPE    8
#define SIGKILL   9
#define SIGBUS    10
#define SIGSEGV   11
#define SIGSYS    12
#define SIGPIPE   13
#define SIGALRM   14
#define SIGTERM   15
#define SIGURG    16
#define SIGSTOP   17
#define SIGSTP    18
#define SIGCONT   19
#define SIGCHLD   20
#define SIGTTIN   21
#define SIGTTOU   22
#define SIGIO     23
#define SIGVTALRM 26
#define SIGPROF   27
#define SIGWINCH  28
