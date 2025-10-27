# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 23:59:44 by grcharle          #+#    #+#              #
#    Updated: 2025/10/19 23:59:45 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ./libft

LDFLAGS := -I. -I$(LIBFT_SRC)
LDLIBS := -L$(LIBFT_SRC) -lft

SOURCES := \
	main.c \
	utils.c \
	extract_integers.c
# 	push_swap.c \
# 	list_builder.c \
# 	args_validator.c \


OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

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
