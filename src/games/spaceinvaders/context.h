/*
** context.h for MASHUG in /Users/ibrahimfofana/Documents/RenduSVN/1/mashug
**
** Made by FOFANA Ibrahim
** Login   <fofana_i@etna-alternance.net>
**
** Started on  Fri Sep  5 13:39:02 2014 FOFANA Ibrahim
** Last update Fri Sep  5 15:51:31 2014 FOFANA Ibrahim
*/

/**
 *@context.h
 *@brief SpaceInvaders game context (Lives, score)
 */

#ifndef CONTEXT_H__
# define CONTEXT_H__

/**
 * @brief Spaceinvaders context structure definition
 */
typedef struct s_spacecontext
{
  Uint8 score;
  Uint8 lives;
} t_spacecontext;

/**
 * @brief Initializes Space Invaders context
 */
void	spacecontext_init();

/**
 * @brief Destroys Space Invaders context
 */
void	spacecontext_destroy();

/**
 * @brief spacecontext getter
 */
t_spacecontext	*get_spacecontext();

#endif /* !CONTEXT_H__ */
