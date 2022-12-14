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

#ifndef _SDL_ps4audio_h
#define _SDL_ps4audio_h


#include "SDL_config_ps4.h"

#include "../SDL_sysaudio.h"

//#ifdef _THIS
//#undef _THIS
#define _THIS SDL_AudioDevice *this
//#endif

#define NUM_BUFFERS 2

struct SDL_PrivateAudioData
{
	int32_t h_aout;

	/* The raw allocated mixing buffer. */
	Uint8   *rawbuf;
	/* Individual mixing buffers. */
	Uint8   *mixbufs[NUM_BUFFERS];
	/* Index of the next available mixing buffer. */
	int     next_buffer;
};



#ifndef SCE_AUDIO_OUT_PARAM_FORMAT_S16_MONO
#define SCE_AUDIO_OUT_PARAM_FORMAT_S16_MONO ORBIS_AUDIO_OUT_PARAM_FORMAT_S16_MONO
#endif

#ifndef SCE_AUDIO_OUT_PARAM_FORMAT_S16_STEREO
#define SCE_AUDIO_OUT_PARAM_FORMAT_S16_STEREO ORBIS_AUDIO_OUT_PARAM_FORMAT_S16_STEREO
#endif

#ifndef SCE_AUDIO_OUT_PARAM_FORMAT_FLOAT_MONO
#define SCE_AUDIO_OUT_PARAM_FORMAT_FLOAT_MONO ORBIS_AUDIO_OUT_PARAM_FORMAT_FLOAT_MONO
#endif

#ifndef SCE_AUDIO_OUT_PARAM_FORMAT_FLOAT_STEREO
#define SCE_AUDIO_OUT_PARAM_FORMAT_FLOAT_STEREO ORBIS_AUDIO_OUT_PARAM_FORMAT_FLOAT_STEREO
#endif

#ifndef SCE_AUDIO_OUT_PARAM_ATTR_SHIFT
#define SCE_AUDIO_OUT_PARAM_ATTR_SHIFT (16)
#endif

#ifndef SCE_USER_SERVICE_USER_ID_SYSTEM
#define SCE_USER_SERVICE_USER_ID_SYSTEM ORBIS_USER_SERVICE_USER_ID_SYSTEM
#endif

#ifndef SCE_AUDIO_OUT_PORT_TYPE_MAIN
#define SCE_AUDIO_OUT_PORT_TYPE_MAIN ORBIS_AUDIO_OUT_PORT_TYPE_MAIN
#endif


#endif // _SDL_ps4audio_h