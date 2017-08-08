# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 15:59:39 by mmartins          #+#    #+#              #
#    Updated: 2017/06/01 23:05:39 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAG = -g -Wall -Wextra -Werror

CC = gcc $(CFLAG)

SRC = 	src/main.c \
		src/kill_program.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH =	./libft

LIB		=		-L libft -lft -L mlx -lmlx -framework OpenGL -framework Appkit -framework OpenCL -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJ) $(LIB) -o $(NAME)
	@rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

$(OBJ):
	$(CC) -c $*.c -o $@ -I includes -I libft/includes

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean
