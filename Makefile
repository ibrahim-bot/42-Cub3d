# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 11:55:03 by ichougra          #+#    #+#              #
#    Updated: 2020/12/18 12:56:22 by ichougra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


CC				=	gcc

NAME			= 	Cub3D

MINILIBX		=	libmlx.a

LIB				=	libftprintf.a

SRC_PATH		=	srcs

SRCS_NAME		= 	main.c ft_loop.c ft_set_color.c ft_move.c\
					ft_init.c ft_init2.c ft_init3.c ft_free.c\
					ft_config_map.c ft_config_map2.c\
					ft_verif.c ft_keys.c ft_verif2.c ft_wall.c\
					ft_sprite_draw.c ft_bmp_conv.c ft_hud.c\
					ft_config_struct.c ft_sprite_lst.c ft_calloc.c\
					ft_bzero.c ft_isdigit.c ft_memcpy.c\
					ft_split.c ft_memset.c ft_strcmp.c ft_strcount_char.c\
					ft_strncmp.c get_next_line.c ft_utils.c error.c

OBJS			= 	${SRCS:.c=.o}

LIBRARIES		=	ft_printf/libftprintf.a minilibx/libmlx.a

CFLAGS 			= 	-Wall -Wextra -Werror -g3

GFLAGS 			=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit\
					-I./includes\

GFLAGS2 		=	 -g3\
					-I./includes\
#-Wall -Wextra -Werror 
SRCS 			= 	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

all:				$(NAME)

%.o: 		%.c ./includes/cube.h ft_printf/libftprintf.a minilibx/libmlx.a
				@$(CC)  $(GFLAGS2) -I ./includes/cube.h -c $< -o $@

$(NAME):	$(MINILIBX) $(LIB) $(OBJS) ./includes/cube.h
				@$(CC) $(OBJS) -L minilibx $(GFLAGS) $(LIBRARIES) -o $(NAME) -lm
				@echo "\033[36m[OK] \033[0m Making Cub3d...\t\033[92m√\033[0m"

$(LIB):
				@make -C ft_printf all

$(MINILIBX):
				@make -C minilibx all

clean:
				@make -C ft_printf clean
				@make -C minilibx clean
				@echo "\033[36m[OK] \033[0m Clean: (minilibx) \033[92m√\033[0m"
				@rm -f $(OBJS)
				@echo "\033[36m[OK] \033[0m Clean: (Cub3d) \033[92m   √\033[0m"

fclean: 	clean
				@make -C ft_printf fclean
				@echo "\033[36m[OK] \033[0m Fclean: (Cub3d) \033[92m  √\033[0m"
				@rm -f $(NAME)

re: 		fclean all

.PHONY: 	all fclean clean re