SHELL		=	/bin/bash
CC		=	gcc
DOXYGEN		=	doxygen
MKDIR		=	mkdir -p
RM		=	rm -fr
ARCHIVE		=	tar -cjf
SRCPATH		=	src/
LIBPATH		=
OBJPATH		=	objs/
BINPATH		=	bin/
PACKPATH	=	dist/

SRC		=	$(SRCPATH)base/math.c					\
			$(SRCPATH)base/memory.c					\
			$(SRCPATH)base/list.c					\
			$(SRCPATH)core/version.c				\
			$(SRCPATH)core/log.c					\
			$(SRCPATH)core/options.c				\
			$(SRCPATH)core/clioptions.c				\
			$(SRCPATH)core/video_debug.c				\
			$(SRCPATH)core/window.c					\
			$(SRCPATH)core/renderer.c				\
			$(SRCPATH)core/graphics.c				\
			$(SRCPATH)core/audio.c					\
			$(SRCPATH)core/input.c					\
			$(SRCPATH)core/launcher.c				\
			$(SRCPATH)core/handlers/graphic_handler.c		\
			$(SRCPATH)core/handlers/sprite_handler.c		\
			$(SRCPATH)core/handlers/font_handler.c			\
			$(SRCPATH)core/handlers/sound_handler.c			\
			$(SRCPATH)core/handlers/xml_handler.c			\
			$(SRCPATH)core/handlers/xml_hiscore_handler.c		\
			$(SRCPATH)core/handlers/xml_spritesheet_handler.c	\
			$(SRCPATH)core/helpers/factory_helpers.c		\
			$(SRCPATH)core/helpers/input_helpers.c			\
			$(SRCPATH)core/helpers/file_helpers.c			\
			$(SRCPATH)core/mashug.c					\
			$(SRCPATH)games/mainmenu.c				\
			$(SRCPATH)games/input_test.c				\
			$(SRCPATH)games/common/fonts.c				\
			$(SRCPATH)games/common/sfx.c				\
			$(SRCPATH)games/common/common.c				\
			$(SRCPATH)games/spaceinvaders/spaceinvaders.c		\
			$(SRCPATH)games/spaceinvaders/spacemenu.c		\
			$(SRCPATH)games/spaceinvaders/spacehiscores.c		\
			$(SRCPATH)games/spaceinvaders/spacespritesheet.c	\
			$(SRCPATH)games/spaceinvaders/spacecore.c		\
			$(SRCPATH)games/spaceinvaders/objects/ship.c		\
			$(SRCPATH)games/spaceinvaders/objects/ship_callback.c	\
			$(SRCPATH)games/spaceinvaders/objects/rocket.c		\
			$(SRCPATH)games/spaceinvaders/objects/rocket_callback.c	\
			$(SRCPATH)games/spaceinvaders/objects/alien.c		\
			$(SRCPATH)games/spaceinvaders/objects/alien_callback.c	\
			$(SRCPATH)games/spaceinvaders/objects/block.c		\
			$(SRCPATH)games/spaceinvaders/objects/block_callback.c

OBJ		=	$(SRC:%.c=%.o)

CFLAGS		+=	`sdl2-config --cflags` `xml2-config --cflags` -W -Wall -Wextra -Wfatal-errors -std=c89 -pedantic
LDFLAGS		=	`sdl2-config --libs` `xml2-config --libs` -lSDL2_image -lSDL2_ttf
PACKAGE		=	mashug-`uname -m`-`uname -s`.tar.gz
BINARY		=	mashug-dbg

%.o:		%.c
		@printf "\x1b[0;37m:: Building $@ from $<\n\x1b[0;0m"
		@$(CC) $(CFLAGS) -c -o $@ $<

all:		$(BINARY)
.PHONY:		all

$(BINARY):	$(OBJ)
		@printf "\x1b[1;33m:: Building application. . .\n\x1b[0;0m"
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

printcmd:
		@echo $(CC) $(CFLAGS) " <source> " $(LDFLAGS)
.PHONY:		test
