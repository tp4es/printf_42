# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tide-oli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 17:50:53 by tide-oli          #+#    #+#              #
#    Updated: 2026/02/12 23:54:13 by tide-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
INCLUDE= ft_printf.h

SRC= 	ft_printf.c			\
		options.c			\
		ft_printhex.c		\
		ft_printchar.c		\
		ft_printstring.c	\
		ft_printvoid.c		\
		ft_printnumbers.c	\

OBJ = $(SRC:.c=.o)

CC= cc
CFLAGS = -Wall -Wextra -Werror

RM= rm -f
AR= ar rcs
RN= ranlib

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
