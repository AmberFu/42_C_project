# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 17:05:04 by pfu               #+#    #+#              #
#    Updated: 2019/08/13 23:55:11 by pfu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGES = -Wall -Wextra -Werror

SRC = \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_memdel.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memalloc.c \
	  ft_strnew.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strlen.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_word_split_count.c \
	  ft_word_malloc.c \
	  ft_itoa.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)
	@echo "RNU: all"

$(NAME): $(OBJ)
	@echo "RUN: ar rc $(NAME) $(OBJ)"
	@ar rc $(NAME) $(OBJ)
	@echo "ranlib $(NAME)"
	@ranlib $(NAME)

%.o: %.c
	@echo "%.o: %.c"
	@echo "gcc $(FLAGES) -c $< -o $@"
	@gcc $(FLAGES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Delete OBJ"

fclean: clean
	@echo "RUN: fclean -> rm -f $(NAME)"
	@rm -f $(NAME) 

re: fclean all
