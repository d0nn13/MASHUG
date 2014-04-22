SHELL		=	/bin/bash
CC		=	gcc
MKDIR		=	mkdir -p
RM		=	rm -f
ARCHIVE		=	tar -cjf
SRCPATH		=	src/
LIBPATH		=	
OBJPATH		=	objs/
BINPATH		=	bin/
PACKPATH	=	dist/

SRC		=	$(SRCPATH)core/core.c				\
			$(SRCPATH)core/version.c			\
			$(SRCPATH)core/log.c				\
			$(SRCPATH)core/gfx/display.c			\
			$(SRCPATH)game/client/spaceinvaders.c

OBJ		=	$(SRC:%.c=%.o)

CFLAGS		=	-W -Wall -Werror -pedantic
LDFLAGS		=	-lSDL2
DBGFLAGS	=	-ggdb -DDEBUG
PACKAGE		=	SpaceInvaders-`uname -m`-`uname -s`.tar.gz
BINARY		=	spaceinvaders

%.o:		%.c
		@printf "\x1b[0;37m:: Building $@ from $<\n\x1b[0;0m"
		@$(CC) $(CFLAGS) -c -o $@ $<

all:		debug
.PHONY:		all

debug:		$(OBJ)
		@printf "\x1b[1;33m:: Building Space Invasion (DEBUG). . .\n\x1b[0;0m"
		@$(MKDIR) $(BINPATH)
		@$(CC) $(DBGFLAGS) $(CFLAGS) -o $(BINPATH)$(BINARY)-dbg $(OBJ) $(LDFLAGS)
.PHONY:		debug

release:	$(OBJ)
		@printf "\x1b[1;33m:: Building Space Invasion. . .\n\x1b[0;0m"
		@$(MKDIR) $(BINPATH)
		@$(CC) $(CFLAGS) -o $(BINPATH)$(BINARY) $(OBJ) $(LDFLAGS)
.PHONY:		release

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
		$(MAKE) all
.PHONY:		re
