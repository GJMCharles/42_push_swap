# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 22:50:27 by grcharle          #+#    #+#              #
#    Updated: 2025/10/28 22:50:29 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
NAME_BONUS	:= checker

RM			:= rm -frv
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
MAKEFLAGS	:= --no-print-directory

LIBFT_SRC	:= ./libft

LDFLAGS		:= -I./includes -I$(LIBFT_SRC)
LDLIBS		:= -L$(LIBFT_SRC) -lft

SOURCES		:= src/main.c \
			src/parsing.c \
			src/errors.c \
			src/stack_utils.c \
			src/ops_swap.c \
			src/ops_push.c \
			src/ops_rotate.c \
			src/ops_revrotate.c \
			src/sort_small.c \
			src/radix.c \
			src/ranks.c \
			src/utils.c

OBJECTS		:= $(patsubst %.c,%.o,$(SOURCES))

all: LIBS $(NAME)

bonus:

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make -C $(LIBFT_SRC) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

clean:
	@make -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# For testing / debuging
# make re && clear && ARG="$(shuf -i 0-100 -n 100 | tr '\n' ' ')"; valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap $ARG | wc -l
# make re && clear && ARG="$(shuf -i 0-500 -n 500 | tr '\n' ' ')"; valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap $ARG | wc -l
