/*
** log.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Mon Apr 21 14:05:34 2014 AHAMADA Samir
** Last update Tue Jul 15 12:29:09 2014 ENNEBATI Yassine
*/

/**
 *	@file	log.h
 *	@brief	Log engine
 */

#ifndef CORE_LOG_H_
# define CORE_LOG_H_

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
  XML_LCAT,
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
 *	@brief Sets ALL (SDL + custom) category priorities
 */
void	log_set_all_priority(SDL_LogPriority priority);

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
Uint8	ptr_chk(void const *p, char const *psym, Uint32 cat, char const *fsym);

#endif /* !CORE_LOG_H_ */
