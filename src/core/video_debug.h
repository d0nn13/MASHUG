/*
** video_debug.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Sun Apr 27 11:22:47 2014 AHAMADA Samir
** Last update Tue Jul 15 12:35:54 2014 ENNEBATI Yassine
*/

/**
 *	@file	video_debug.h
 *	@brief	Video debugging
 */

#ifndef CORE_VIDEO_DEBUG_H_
# define CORE_VIDEO_DEBUG_H_

#include "window.h"

/**
 *	@brief	Debugs video
 */
void	video_debug(SDL_Window *win);
void	renderer_debug(SDL_Renderer *rdr);

#endif /* !CORE_VIDEO_DEBUG_H_ */
