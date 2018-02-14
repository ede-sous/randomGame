# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 01:59:12 by ede-sous          #+#    #+#              #
#    Updated: 2018/02/14 01:35:49 by adeletan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	randomGame

ifeq (,$(shell command -v SDL2-config 2> /dev/null))
	SDL_EXEC := SDL2-config
else
	SDL_EXEC := sdl2-config
endif

LIBS_SDL	=	`$(SDL_EXEC) --libs` -lSDL2_image -lSDL2_ttf
GCC_FLAGS	=	gcc -Wall -Werror -Wextra

INCLUDES	=	-I./includes `$(SDL_EXEC) --cflags`

SRCS_DIR	=	srcs/

SRCS_FILES	=	main.c \
				initSdl.c \
				randomGame.c \
				createCharacter.c \
				texture.c		\
				playerPhysics.c
				
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

all : checkup $(NAME)

$(NAME): $(OBJS) $(INC) Makefile
	$(GCC_FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS_SDL)

%.o : %.c
	gcc $(INCLUDES) -c -o $@ $<

checkup:
	@if [ "$(shell command -v brew 2> /dev/null)" = "" ]; then echo "brew is not installed - WARNING"; fi
	@if [ "$(shell command -v $(SDL_EXEC) 2> /dev/null)" = "" ]; then echo "SDL2 is not installed - ABORT" && exit 1; fi


clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re: fclean
	@make

.PHONY: re fclean clean checkup %.o %.c $(NAME) all 
