/*
** handlers.h for MASHUG in /Users/ahamad_s/dev/ETNA/Projets/TCM-DEVC/MASHUG
**
** Made by AHAMADA Samir
** Login   <ahamad_s@etna-alternance.net>
**
** Started on  Tue Jun 24 22:56:13 2014 AHAMADA Samir
** Last update Wed Jul 23 13:25:48 2014 ENNEBATI Yassine
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
# include "graphics.h"
# include "audio.h"

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
SDL_Surface	*get_text_surface(const char *text,
				  const TTF_Font *f,
				  const SDL_Color *c);

/**
 *	@brief	Draws some text at a given origin point, font and color.
 *
 *	@param	text The string to be drawn on the surface
 *	@param	orig A SDL_Point that defines the x and y coordinates of
 *		the text to be drawn
 *	@param	f A poiner to the font to render the text with
 *	@param	c The color to render the text in
 */
void		draw_text(const char *text,
			  const SDL_Point *orig,
			  const TTF_Font *f,
			  const SDL_Color *c);

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
t_texture	*make_texture(const SDL_Renderer *r, Sint32 a, Sint32 w, Sint32 h);

/**
 *	@brief	Create a texture from an existing surface.
 *
 *	@param	r The rendering context
 *	@param	s The structure containing pixel data used to fill the texture
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_texture_from_surface(const SDL_Renderer *r,
					   const SDL_Surface *s);

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


/**
 * ==================== S P R I T E S ====================
 */
typedef struct	s_spriteholder
{
  char		*name;
  SDL_Rect	rect;
}		t_spriteholder;

/**
 *	@brief	XML Spritesheet parsing callback
 *	
 *	Pass a reference to this function to 'xml_parse()' function to parse a Spritesheet XML file
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8	xml_spritesheet_callback(xmlNodePtr node, void *container);

/**
 *	@brief	XML Animation parsing callback
 *	
 *	Pass a reference to this function to 'xml_parse()' function to parse an Animation XML file
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8	xml_animation_callback(xmlNodePtr node, void *container);

/**
 *	@brief	Allocates a new scaled sprite from a sprites sheet file.
 *
 *	@param	file The file name of the sprites sheet containing the desired sprite
 *	@param	zone The zone in the sprites sheet to take
 *	@param	size The desired sprite size
 *	@return	A pointer to a newly heap allocated texture
 */
t_texture	*make_sprite(const char *file,
			     const SDL_Rect *zone,
			     const SDL_Rect *size);

/**
 *	@brief	Draws a sprite at a given zone in the texture.
 *
 *	This function scales the sprite to 'zone' dimensions.
 *	Passing NULL to 'zone' implies scaling to fit texture size
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	zone The zone to fill with the desired sprite
 */
void		draw_sprite(const t_texture *s, const SDL_Rect *zone);

/**
 *	@brief	Draws a sprite at a given point in the texture without applying scaling.
 *
 *	@param	s The desired sprite in t_sprite enumeration
 *	@param	orig A SDL_Point that defines the x and y coordinates of the sprite to be drawn
 */
void		draw_sprite_raw(const t_texture *s, const SDL_Point *orig);


/*
** ==================== H I S C O R E S ====================
*/
# define HISCORE_NICKNAME_LENGTH	16

/**
 *	@brief	Hiscore holder structure
 *	@todo	Use proper date type for "date" member
 */
typedef struct	s_hiscoreholder
{
  char		nickname[HISCORE_NICKNAME_LENGTH];
  Uint32	score;
  Uint32	date;
}		t_hiscoreholder;

/**
 *	@brief	XML Hiscore parsing callback
 *	
 *	Pass a reference to this function to 'xml_parse()' function to parse a Hiscore XML file
 *	You should NOT call this function yourself!
 *
 *	@return	Number of counted elements
 */
Uint8		xml_hiscore_callback(xmlNodePtr, void *);

/**
 *	@brief	Game filter setter
 *
 *	Use this function if you need to retrieve Hiscores of a specific game
 *
 *	@param	name Name of the 'game' XML element to filter
 */
void		xml_hiscore_set_game_filter(const char *name);


/*
** ==================== X M L ====================
*/
/**
 *	@brief	XML Callback signature
 */
typedef	Uint8	(*t_xmlcallback)(xmlNodePtr, void *);

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
 *	@return	Number of counted elements
 */
Uint8		xml_parse(const char *path, t_xmlcallback callback, void *container);

#endif /* !CORE_HANDLERS_ */
