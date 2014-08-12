/*
** video_debug.c for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:27:56 2014 AHAMADA Samir
** Last update Mon Jul 14 02:10:08 2014 ENNEBATI Yassine
*/

/**
 *	@file	video_debug.h
 *	@brief	Video debugging
 */

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "log.h"

#include "video_debug.h"

static void		display_modes()
{
  SDL_DisplayMode	mode;
  Uint8			d;
  Uint8			m;

  for (d = 0; d < SDL_GetNumVideoDisplays(); ++d)
  {
    SDL_LogDebug(VID_LCAT, "Available modes for display #%i :", d);
    for (m = 0; m < SDL_GetNumDisplayModes(d); ++m)
    {
      SDL_GetDisplayMode(d, m, &mode);
      SDL_LogDebug(VID_LCAT, "	f=%s, w=%i, h=%i, r=%i",
		   SDL_GetPixelFormatName(mode.format), mode.w, mode.h,
		   mode.refresh_rate);
    }
    SDL_GetDesktopDisplayMode(d, &mode);
    SDL_LogDebug(VID_LCAT, "Desktop mode for display #%i :", d);
    SDL_LogDebug(VID_LCAT, "	f=%s, w=%i, h=%i, r=%i",
		 SDL_GetPixelFormatName(mode.format), mode.w, mode.h,
		 mode.refresh_rate);
    SDL_GetCurrentDisplayMode(d, &mode);
    SDL_LogDebug(VID_LCAT, "Current mode for display #%i :", d);
    SDL_LogDebug(VID_LCAT, "	f=%s, w=%i, h=%i, r=%i",
		 SDL_GetPixelFormatName(mode.format), mode.w, mode.h,
		 mode.refresh_rate);
  }
}

static void		window_mode(SDL_Window *win)
{
  SDL_DisplayMode	mode;

  SDL_GetWindowDisplayMode(win, &mode);
  SDL_LogDebug(VID_LCAT, "Window mode :");
  SDL_LogDebug(VID_LCAT, "	f=%s, w=%i, h=%i, r=%i",
	       SDL_GetPixelFormatName(mode.format), mode.w, mode.h,
	       mode.refresh_rate);
}

void	video_debug(SDL_Window *win)
{
  SDL_LogDebug(VID_LCAT, "- Video debug start -");
  display_modes();
  window_mode(win);
  SDL_LogDebug(VID_LCAT, "- Video debug end -");
}

void			renderer_debug(SDL_Renderer *rdr)
{
  SDL_RendererInfo	info;
  Uint8			i;

  SDL_LogDebug(VID_LCAT, "- Renderer debug start -");
  for (i = 0; i < SDL_GetNumRenderDrivers(); ++i)
  {
    SDL_GetRenderDriverInfo(i, &info);
    SDL_LogDebug(VID_LCAT, "render driver #%i (%s) : flags=%i, fmts=%i, w=%i, h=%i",
		 i, info.name, info.flags, info.num_texture_formats,
		 info.max_texture_width, info.max_texture_height);

  }
  SDL_GetRendererInfo(rdr, &info);
  SDL_LogDebug(VID_LCAT, "renderer (%s) : flags=%i, fmts=%i, w=%i, h=%i",
	       info.name, info.flags, info.num_texture_formats,
	       info.max_texture_width, info.max_texture_height);
  SDL_LogDebug(VID_LCAT, "- Renderer debug end -");
}
