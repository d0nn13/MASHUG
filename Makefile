SHELL		=	/bin/bash
CC		=	gcc
DOXYGEN		=	doxygen
MKDIR		=	mkdir -p
RM		=	rm -f
ARCHIVE		=	tar -cjf
SRCPATH		=	src/
LIBPATH		=	
OBJPATH		=	objs/
BINPATH		=	bin/
PACKPATH	=	dist/

SRC		=	$(SRCPATH)base/math.c				\
			$(SRCPATH)base/memory.c				\
			$(SRCPATH)core/version.c			\
			$(SRCPATH)core/log.c				\
			$(SRCPATH)core/options.c			\
			$(SRCPATH)core/clioptions.c			\
			$(SRCPATH)core/window.c				\
			$(SRCPATH)core/renderer.c			\
			$(SRCPATH)core/graphics.c			\
			$(SRCPATH)core/audio.c				\
			$(SRCPATH)core/handlers/graphic_handler.c	\
			$(SRCPATH)core/handlers/sprite_handler.c	\
			$(SRCPATH)core/handlers/font_handler.c		\
			$(SRCPATH)core/handlers/sound_handler.c		\
			$(SRCPATH)core/spaceinvaders.c			\
			$(SRCPATH)game/common/sprites.c			\
			$(SRCPATH)game/common/fonts.c			\
			$(SRCPATH)game/common/sfx.c			\
			$(SRCPATH)game/mainmenu.c			\
			$(SRCPATH)game/hiscores.c			\
			$(SRCPATH)game/gamecore.c

OBJ		=	$(SRC:%.c=%.o)

CFLAGS		=	`sdl2-config --cflags` -ggdb -W -Wall -std=c99 -pedantic 
LDFLAGS		=	`sdl2-config --libs` -lSDL2_image -lSDL2_ttf
PACKAGE		=	SpaceInvaders-`uname -m`-`uname -s`.tar.gz
BINARY		=	spaceinvaders-dbg

%.o:		%.c
		@printf "\x1b[0;37m:: Building $@ from $<\n\x1b[0;0m"
		@$(CC) $(CFLAGS) -c -o $@ $<

all:		$(BINARY)
.PHONY:		all

$(BINARY):	$(OBJ)
		@printf "\x1b[1;33m:: Building Space Invasion. . .\n\x1b[0;0m"
		@$(MKDIR) $(BINPATH)
		@$(CC) $(CFLAGS) -o $(BINPATH)$(BINARY) $(OBJ) $(LDFLAGS)
.PHONY:		$(BINARY)

dist:		release
		@printf "\x1b[1;35m:: Packing everything. . .\n\x1b[0;0m"
		@$(MKDIR) $(PACKPATH)
		@$(ARCHIVE) $(PACKPATH)$(PACKAGE) $(SRCPATH) $(INCPATH) $(LIBPATH)
		@$(MAKE) clean
.PHONY:		dist

clean:
		@printf "\x1b[1;36m:: Cleaning. . .\n\x1b[0;0m"
		@$(RM) $(OBJ)
.PHONY:		clean

fclean:
		@printf "\x1b[1;31m:: W I P I N G ! ! ! !\n\x1b[0;0m"
		@$(RM) $(OBJ) $(BINPATH)$(BINARY)* $(PACKPATH)$(PACKAGE)
.PHONY:		fclean

re:		fclean
		@$(MAKE) all
.PHONY:		re

doc:
		@$(DOXYGEN)
.PHONY:		doc
