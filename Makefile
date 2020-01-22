# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 11:27:34 by lzhansha          #+#    #+#              #
#    Updated: 2019/11/08 12:36:43 by lzhansha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs
HEADER = includes
DIR_O = obj
LIBFT = libft

SOURCES = ft_printf.c\
		  ft_extra.c\
		  ft_convert.c\
		  ft_check_one.c\
		  ft_check_two.c\
		  ft_flag.c\
		  ft_print_c_s.c\
		  ft_print_digits.c\
		  ft_print_nonprnt.c\
		  ft_print_numb.c\
		  ft_print_ptr.c\
		  ft_print_e.c\
		  ft_print_f.c\
		  ft_print_g.c\

OBJ = $(SOURCES:.c=.o)

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS = $(addprefix $(DIR_O)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
