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

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ./libft
FTPRINTF_SRC := ./ftprintf

LDFLAGS := -I. -I$(FTPRINTF_SRC) -I$(LIBFT_SRC)
LDLIBS := \
	-L$(LIBFT_SRC) -lft \
	-L$(FTPRINTF_SRC) -lftprintf

SOURCES := push_swap.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make -C $(LIBFT_SRC) all
	@make -C $(FTPRINTF_SRC) all

$(NAME): $(OBJECTS)

clean:
	@make -C $(LIBFT_SRC) clean
	@make -C $(FTPRINTF_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_SRC) fclean
	@make -C $(FTPRINTF_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
