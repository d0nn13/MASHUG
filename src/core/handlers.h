/*
** handlers.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Tue Jun 24 22:56:13 2014 AHAMADA Samir
** Last update Fri Sep 26 05:57:17 2014 ENNEBATI Yassine
*/

/**
 *	@file	handlers.h
 *	@brief	Handlers protoypes
 */

#ifndef CORE_HANLDERS_H_
# define CORE_HANLDERS_H_

# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL_render.h>
# include <libxml/parser.h>
# include "launcher.h"
# include "graphics.h"
# include "audio.h"

/**
 * ==================== M E N U S ====================
 */
typedef struct	s_menuentry
{
  char const	*text;
  SDL_Point	orig;
  SDL_Color	sel_color;
  SDL_Color	uns_color;
  t_exec	callback;
  Uint8		enabled;
}		t_menuentry;

/**
 * ==================== F O N T S ====================
 */
/**
 *	@brief	Allocates a new surface with 'text' printed with given
 *		font 'f' and color 'c'.
 *
 *	@param	text The string to be printed on the surface
 *	@param	f A pointer to the font to render the text with
 *	@param	c The color to render the text in
 *	@return	A pointer to the surface allocated with "text" printed
 *		with given font "f"and color "c"
 */
SDL_Surface	*get_text_surface(char const *text,
				  TTF_Font const *f,
				  SDL_Color const *c);

/**
 *	@brief	Draws some text at a given origin point, font and color.
 *
 *	@param	text The string to be drawn on the surface
 *	@param	orig A SDL_Point that defines the x and y coordinates of
 *		the text to be drawn
 *	@param	f A poiner to the font to render the text with
 *	@param	c The color to render the text in
 */
void		draw_text(char const *text,
			  SDL_Point const *orig,
			  TTF_Font const *f,
			  SDL_Color const *c);

/**
 * ==================== G R A P H I C S ====================
 */
/**
 *	@brief	Create a texture for a rendering context.
 *
 *	@param	r The rendering context
 *	@param	a One of the enumerated values in SDL_TextureAccess
 *	@param	w The width of the texture in pixels
 *	@param	h The height of the texture in pixels
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_texture(SDL_Renderer const *r, Sint32 a, Sint32 w, Sint32 h);

/**
 *	@brief	Create a texture from an existing surface.
 *
 *	@param	r The rendering context
 *	@param	s The structure containing pixel data used to fill the texture
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_texture_from_surface(SDL_Renderer const *r,
					   SDL_Surface const *s);

/**
 *	@brief	Deallocates a texture.
 *
 *	@param	t The texture to deallocate
 */
void		free_texture(t_texture *t);

/**
 * ==================== S O U N D  F X ====================
 */
/**
 *	@brief	Plays a sound effect.
 *
 *	@param	s The audio chunk to play
 */
void		play_sfx(t_chunk *s);

/*
** ==================== S P R I T E S ====================
*/

/**
 *	@brief	XML Spritesheet parsing callback
 *
 *	Pass a reference to this function to 'xml_parse()' function
 *	to parse a Spritesheet XML file
 *
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8		xml_spritesheet_callback(xmlNodePtr node, void *container);

/**
 *	@brief	XML Animation parsing callback
 *
 *	Pass a reference to this function to 'xml_parse()' function
 *	to parse an Animation XML file
 *
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8		xml_animation_callback(xmlNodePtr node, void *container);

/**
 *	@brief	Allocates a new spritesheet wrapper from a spritesheet file.
 *
 *	@param	img The filename of the sprites sheet image
 *	@param	xml The filename of the sprites sheet XML file
 *	@return	A pointer to a newly heap allocated spritesheet
 */
t_spritesheet	*make_spritesheet(char const *img, char const *xml);

/**
 *	@brief	Deallocates a spritesheet
 *
 *	@param	ss The desired spritesheet to deallocate
 */
void		free_spritesheet(t_spritesheet *ss);

/**
 *	@brief	Draws a sprite from a spritesheet to a given zone on the renderer.
 *
 *	This function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit renderer size
 *
 *	@param	s The desired sprite holder
 *	@param	zone The zone to fill with the desired sprite
 */
void		draw_sprite(t_spriteholder const *s,
			    SDL_Rect const *zone);

/**
 *	@brief	Draws a sprite from a spritesheet to a given zone on the renderer.
 *		with some extra parameters to the rendering
 *
 *	This function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit renderer size
 *
 *	@param	s The desired sprite holder
 *	@param	zone The zone to fill with the desired sprite
 *	@param	angle an angle in degrees that indicates the rotation
 *	@param	flip a SDL_RendererFlip value stating which flipping actions should be performed on the texture
 */
void		draw_sprite_ex(t_spriteholder const *s,
			       SDL_Rect const *zone,
			       double angle,
			       SDL_RendererFlip flip);

/**
 *	@brief	Draws a sprite from a spritesheet at a given point on the renderer without applying scaling.
 *
 *	@param	s The desired sprite holder
 *	@param	orig A SDL_Point that defines the x and y coordinates of the sprite to be drawn
 */
void		draw_sprite_raw(t_spriteholder const *s,
				SDL_Point const *orig);

/**
 *	@brief Get a sprite within a spritesheet with a given name
 *
 *	@param ss The spritesheet
 *	@param name The name of the sprite to find
 *
 *	@return a pointer to the found sprite
 *	@return NULL if not found
 */
t_spriteholder const	*get_sprite(t_spritesheet const *ss, char const *name);

/*
** ==================== H I S C O R E S ====================
*/
/**
 *	@brief	Hiscore holder structure
 *	@todo	Use proper date type for "date" member
 */
typedef struct	s_hiscoreholder
{
  char		*nickname;
  Uint16	score;
}		t_hiscoreholder;

typedef struct		s_hiscores
{
  t_hiscoreholder	*entries;
  Uint8       		count;
  char			*game_name;
}			t_hiscores;

/**
 *	@brief	XML Hiscore parsing callback
 *
 *	Pass a reference to this function to 'xml_parse()' function to parse a Hiscore XML file
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8		xml_hiscore_callback(xmlNodePtr node, void *container);

/**
 *	@brief	Game filter setter
 *
 *	Use this function if you need to retrieve Hiscores of a specific game
 *
 *	@param	name Name of the 'game' XML element to filter
 */
void		xml_hiscore_set_game_filter(char const *name);

/**
 *	@brief	Rewrite hiscores XML files
 *
 *	Use this functions to save all hiscores
 *
 *	@param	all_hiscores contains a singlelist with hiscores for each games
 *
 *	@return 1
 */
Uint8		hiscores_rewrite(t_hiscores *all_hiscores, Uint8 nb_games);

/*
** ==================== X M L ====================
*/
/**
 *	@brief	XML Callback signature
 */
typedef	Uint8	(*t_xmlcallback)(xmlNodePtr, void *);

typedef struct	s_xml_typeholder
{
  t_xmlcallback	call;
  char const	*dtd_file;
  char const	*dtd_str;
}		t_xml_typeholder;

typedef enum
{
  HISCORES_XML = 0,
  SHEET_XML,
  NB_XML
}		t_xml_type;

/**
 *	@brief	Parses or counts parsed elements in a XML file
 *
 *	This function parses an XML file and fill a container with parsed values
 *
 *	Each type of XML file have a callback function dedicated.
 *
 *	Container should be NULL, so you can use the function return value
 *	to allocate the right amount of memory dynamically :
 *
 *	@code
 *	t_hiscoreholder *my_hiscores_pointer;
 *	int count;
 *
 *	count = xml_parse("media/hiscores.xml", &xml_hiscore_callback, NULL);
 *	if (count <= 0)
 *	  SDL_LogDebug(XML_LCAT, "No values !!");
 *	else
 *	{
 *	  my_hiscores_pointer = malloc(count * sizeof(t_hiscoreholder));
 *	  if (!my_hiscore_pointer)
 *	  {
 *	    printf("out of memory\n");
 *	    exit(EXIT_FAILURE);
 *	  }
 *	  xml_parse("media/hiscores.xml", &xml_hiscore_callback, my_hiscores_pointer);
 *	  display_hiscores(my_hiscores_pointer);
 *	}
 *	@endcode
 *
 *	@param	path The path to the XML file
 *	@param	callback The XML parsing callback
 *	@param	container A pointer to a container where to save parsed values or NULL
 *	@return	Negative error code or number of counted elements if succeeded
 */
Sint32		xml_parse(char const *path, t_xml_type type, void *container);

#endif /* !CORE_HANDLERS_ */
