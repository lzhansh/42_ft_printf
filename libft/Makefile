# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 14:43:05 by lzhansha          #+#    #+#              #
#    Updated: 2019/06/24 11:51:27 by lzhansha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft*.c
HDRS = libft.h
OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HDRS) -c $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
