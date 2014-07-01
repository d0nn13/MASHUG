/*
** log.h for SpaceInvaders in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/SpaceInvaders
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 14:05:34 2014 AHAMADA Samir
** Last update Mon Jun 30 01:18:40 2014 AHAMADA Samir
*/

/**
 *	@file	log.h
 *	@brief	Log engine
 */

#ifndef CORE_LOG_H
# define CORE_LOG_H

# include <SDL2/SDL_error.h>
# include <SDL2/SDL_log.h>

/**
 *	@cond
 */
# define APP_LCAT	SDL_LOG_CATEGORY_APPLICATION
# define ERR_LCAT	SDL_LOG_CATEGORY_ERROR
# define SYS_LCAT	SDL_LOG_CATEGORY_SYSTEM
# define AUD_LCAT	SDL_LOG_CATEGORY_AUDIO
# define VID_LCAT	SDL_LOG_CATEGORY_VIDEO
# define RDR_LCAT	SDL_LOG_CATEGORY_RENDER
# define INP_LCAT	SDL_LOG_CATEGORY_INPUT
enum {
  GFX_LCAT = SDL_LOG_CATEGORY_CUSTOM,
  SPR_LCAT,
  FNT_LCAT,
  OPT_LCAT,
  NB_LCAT
};
/**
 *	@endcond
 */

/**
 *	@brief	Initializes Log engine
 */
void	log_init();

/**
 *	@brief	Checks if a pointer is NULL
 *
 *	Convinience function that checks a pointer and outputs log error
 *	with caller function and symbol names when a NULL pointer is given
 *
 *	@param	p The pointer to check
 *	@param	s The pointer symbol used in code as a NULL-terminated string
 *	@param	c The log category to be used for the log output
 *	@param	f The function symbol used in code as a NULL-terminated string
 *	@return 0 if the pointer is NULL, -1 otherwise
 */
Uint8	ptr_chk(const void *p, const char *psym, Uint32 cat, const char *fsym);

#endif /* !CORE_LOG_H */
