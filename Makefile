# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2017/09/11 14:35:26 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SOURCE = gnl.c bonuses.c list_manipulations.c validation.c atoi_base.c main.c visualization.c norm_helper.c
OBJ = $(SOURCE:.c=.o)
HEADER = fdf.h

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc libft/libft.a $(OBJ) -I $(HEADER) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o ${NAME}


.c.o:
	gcc -Wall -Wextra -Werror -c $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
