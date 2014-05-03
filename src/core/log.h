/*
** log.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
** 
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Mon Apr 21 14:05:34 2014 AHAMADA Samir
** Last update Sat May  3 17:15:38 2014 AHAMADA Samir
*/

#ifndef LOG_H
#define LOG_H

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>

/**
 *	Log categories definitions
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
 *	Initializes Log System
 */
void	log_init();

#endif /* !LOG_H */
