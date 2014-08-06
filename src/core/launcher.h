/*
** launcher.h for core in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG/master/src/core
** 
** Made by Samir Ahamada
** Login   <ahamad_s@etna-alternance.net>
** 
** Started on  Wed Aug 06 14:02:45 2014 Samir Ahamada
** Last update Wed Aug 06 14:02:45 2014 Samir Ahamada
*/

/**
 *	@brief	Game mode callback definition
 */
typedef void	(*t_exec)();

/**
 *	@brief	Launcher getter
 */
t_exec	get_launcher();

/**
 *	@brief	Launcher setter
 */
void	set_launcher(t_exec x);
