/*
** log.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 14:05:34 2014 AHAMADA Samir
** Last update Tue Jun 24 18:06:57 2014 AHAMADA Samir
*/

/**
 *	@file	log.h
 *	@brief	Log engine
 */

#ifndef CORE_LOG_H
#define CORE_LOG_H

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>

/**
 *	@cond
 */
#define APP_LCAT	SDL_LOG_CATEGORY_APPLICATION
#define ERR_LCAT	SDL_LOG_CATEGORY_ERROR
#define SYS_LCAT	SDL_LOG_CATEGORY_SYSTEM
#define AUD_LCAT	SDL_LOG_CATEGORY_AUDIO
#define VID_LCAT	SDL_LOG_CATEGORY_VIDEO
#define RDR_LCAT	SDL_LOG_CATEGORY_RENDER
#define INP_LCAT	SDL_LOG_CATEGORY_INPUT
enum {
  GFX_LCAT = SDL_LOG_CATEGORY_CUSTOM,
  SPR_LCAT,
  FNT_LCAT,
  NB_LCAT
};
/**
 *	@endcond
 */

/**
 *	@brief	Initializes Log engine
 */
void	log_init();

#endif /* !CORE_LOG_H */
