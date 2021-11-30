# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajana <ajana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 03:08:30 by ajana             #+#    #+#              #
#    Updated: 2021/11/24 15:57:56 by ajana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr_dec.c ft_putnbr_hex.c \
	ft_putstr.c ft_putchar.c ft_strlen.c

SRCS_OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(SRCS_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $<
	ar -rc $(NAME) $@

re: fclean all

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(SRCS_OBJS)

.PHONY: all clean fclaen re bonus
