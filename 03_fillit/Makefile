# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 19:37:33 by pfu               #+#    #+#              #
#    Updated: 2019/11/12 13:25:05 by pfu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGES = -Wall -Wextra -Werror

SRCDIR = src/

LIBDIR = libft/

SRC = src/*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGES) -o $(NAME) $(SRC) -I $(SRCDIR) -I $(LIBDIR) -L $(LIBDIR) -lft

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
