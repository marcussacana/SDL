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

#include <orbis/_types/kernel.h>
#include <orbis/_types/errors.h>
#include <orbis/_types/video.h>

#ifndef SceKernelEqueue
#define SceKernelEqueue OrbisKernelEqueue
#endif

#ifndef SceVideoOutBufferAttribute
#define SceVideoOutBufferAttribute OrbisVideoOutBufferAttribute
#endif

#ifndef SceKernelEvent
#define SceKernelEvent OrbisKernelEvent
#endif

#ifndef SCE_OK
#define SCE_OK ORBIS_OK
#endif

#ifndef SCE_VIDEO_OUT_FLIP_MODE_VSYNC
#define SCE_VIDEO_OUT_FLIP_MODE_VSYNC ORBIS_VIDEO_OUT_FLIP_VSYNC
#endif

#ifndef SCE_KERNEL_MAIN_DMEM_SIZE
#define SCE_KERNEL_MAIN_DMEM_SIZE ORBIS_KERNEL_MAIN_DMEM_SIZE
#endif

#ifndef SCE_KERNEL_WC_GARLIC
#define SCE_KERNEL_WC_GARLIC ORBIS_KERNEL_WC_GARLIC
#endif

#ifndef SCE_KERNEL_PROT_CPU_RW
#define SCE_KERNEL_PROT_CPU_RW ORBIS_KERNEL_PROT_CPU_RW
#endif

#ifndef SCE_KERNEL_PROT_GPU_RW
#define SCE_KERNEL_PROT_GPU_RW ORBIS_KERNEL_PROT_GPU_RW
#endif

#ifndef SCE_USER_SERVICE_USER_ID_SYSTEM
#define SCE_USER_SERVICE_USER_ID_SYSTEM ORBIS_USER_SERVICE_USER_ID_SYSTEM
#endif

#ifndef SceVideoOutResolutionStatus
#define SceVideoOutResolutionStatus OrbisVideoOutResolutionStatus
#endif

#ifndef SCE_VIDEO_OUT_PIXEL_FORMAT_A8R8G8B8_SRGB
#define SCE_VIDEO_OUT_PIXEL_FORMAT_A8R8G8B8_SRGB ORBIS_VIDEO_OUT_PIXEL_FORMAT_A8B8G8R8_SRGB
#endif

#ifndef SCE_VIDEO_OUT_TILING_MODE_LINEAR
#define SCE_VIDEO_OUT_TILING_MODE_LINEAR ORBIS_VIDEO_OUT_TILING_MODE_LINEAR
#endif

typedef enum SceVideoOutBusType {
	SCE_VIDEO_OUT_BUS_TYPE_MAIN = 0,
} SceVideoOutBusType;

typedef enum SceVideoOutAspectRatio {
	SCE_VIDEO_OUT_ASPECT_RATIO_16_9=0,
} SceVideoOutAspectRatio;

typedef enum SceVideoOutTilingMode {
	SCE_VIDEO_OUT_TILING_MODE_TILE=0,
	SCE_VIDEO_OUT_TILING_MODE_LINEAR=1,
} SceVideoOutTilingMode;


#ifndef SDL_ps4video_h_
#define SDL_ps4video_h_


#include "../../SDL_internal.h"
#include "../SDL_sysvideo.h"

#include <orbis/VideoOut.h>

#define VOUT_NUM_BUFFERS 2

typedef struct SDL_VideoData
{
	int h_vout;		// VideoOut handle
	uint32_t width, height;

	SceKernelEqueue flipQueue;
	SceVideoOutBufferAttribute attr;

	uint32_t currBuffer;
	uint8_t * addrList[VOUT_NUM_BUFFERS];

	off_t phyAddr;
	uint8_t * mapAddr;
	uint32_t bufSize, memSize;

#if PS4_VIDEO_GL
	SDL_bool egl_initialized;   /* OpenGL ES device initialization status */
	uint32_t egl_refcount;      /* OpenGL ES reference count              */
#endif


} SDL_VideoData;


typedef struct SDL_DisplayData
{

} SDL_DisplayData;


typedef struct SDL_WindowData
{
	SDL_Surface *surface;

#if PS4_VIDEO_GL
	SDL_bool uses_gles;         /* if true window must support OpenGL ES */
#endif

} SDL_WindowData;




/****************************************************************************/
/* SDL_VideoDevice functions declaration                                    */
/****************************************************************************/

void PS4_PumpEvents(_THIS);

/* Display and window functions */
int PS4_VideoInit(_THIS);
void PS4_VideoQuit(_THIS);
void PS4_GetDisplayModes(_THIS, SDL_VideoDisplay * display);
int PS4_SetDisplayMode(_THIS, SDL_VideoDisplay * display, SDL_DisplayMode * mode);
int PS4_CreateWindow(_THIS, SDL_Window * window);
int PS4_CreateWindowFrom(_THIS, SDL_Window * window, const void *data);
void PS4_SetWindowTitle(_THIS, SDL_Window * window);
void PS4_SetWindowIcon(_THIS, SDL_Window * window, SDL_Surface * icon);
void PS4_SetWindowPosition(_THIS, SDL_Window * window);
void PS4_SetWindowSize(_THIS, SDL_Window * window);
void PS4_ShowWindow(_THIS, SDL_Window * window);
void PS4_HideWindow(_THIS, SDL_Window * window);
void PS4_RaiseWindow(_THIS, SDL_Window * window);
void PS4_MaximizeWindow(_THIS, SDL_Window * window);
void PS4_MinimizeWindow(_THIS, SDL_Window * window);
void PS4_RestoreWindow(_THIS, SDL_Window * window);
void PS4_SetWindowGrab(_THIS, SDL_Window * window, SDL_bool grabbed);
void PS4_DestroyWindow(_THIS, SDL_Window * window);

int  PS4_CreateWindowFramebuffer(_THIS, SDL_Window * window, Uint32 * format, void ** pixels, int *pitch);
int  PS4_UpdateWindowFramebuffer(_THIS, SDL_Window * window, const SDL_Rect * rects, int numrects);
void PS4_DestroyWindowFramebuffer(_THIS, SDL_Window * window);


/* Window manager function */
SDL_bool PS4_GetWindowWMInfo(_THIS, SDL_Window * window, struct SDL_SysWMinfo *info);

#if PS4_VIDEO_GL
/* OpenGL/OpenGL ES functions */
int PS4_GL_LoadLibrary(_THIS, const char *path);
void *PS4_GL_GetProcAddress(_THIS, const char *proc);
void PS4_GL_UnloadLibrary(_THIS);
SDL_GLContext PS4_GL_CreateContext(_THIS, SDL_Window * window);
int PS4_GL_MakeCurrent(_THIS, SDL_Window * window, SDL_GLContext context);
int PS4_GL_SetSwapInterval(_THIS, int interval);
int PS4_GL_GetSwapInterval(_THIS);
int PS4_GL_SwapWindow(_THIS, SDL_Window * window);
void PS4_GL_DeleteContext(_THIS, SDL_GLContext context);
#endif

/* PS4 on screen keyboard */
SDL_bool PS4_HasScreenKeyboardSupport(_THIS);
void PS4_ShowScreenKeyboard(_THIS, SDL_Window *window);
void PS4_HideScreenKeyboard(_THIS, SDL_Window *window);
SDL_bool PS4_IsScreenKeyboardShown(_THIS, SDL_Window *window);

#endif /* SDL_ps4video_h_ */

/* vi: set ts=4 sw=4 expandtab: */