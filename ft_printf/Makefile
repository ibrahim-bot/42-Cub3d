# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/10 14:33:30 by ichougra     #+#   ##    ##    #+#        #
#    Updated: 2020/01/22 16:54:56 by ichougra    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-I includes

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			display.c\
			printf_utils.c\
			printf_utils2.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_uitoa_base.c\
			ft_print.c\
			ft_parset.c\
			ft_algo.c\
			ft_talgo.c\
			ft_tchek.c\

OBJ	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)	
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36m[OK] \033[0m Making printf...\t\033[92m√\033[0m"

%.o : %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@echo "\033[36m[OK] \033[0m Clean(printf) \033[92m    √\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[36m[OK] \033[0m Fclean(printf) \033[92m   √\033[0m"

re : fclean all

.PHONY: all fclean clean re
