# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 15:59:39 by mmartins          #+#    #+#              #
#    Updated: 2017/08/23 11:15:54 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

NAME = wolf3d

CFLAG = -g -Wall -Wextra -Werror

CC = gcc $(CFLAG)

SRC = 	src/main.c \
		src/init.c \
		src/key_hook.c \
		src/map.c \
		src/raycasting.c \
		src/draw.c \
		src/loop.c \
		src/key_move.c \
		src/minimap.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH =	./libft

LIB		=		-L libft -lft -L mlx -lmlx -framework OpenGL -framework Appkit -framework OpenCL -g

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo "\n$(OKC)$(NAME): compilation success!$(NOC)"

$(OBJ):
	@$(CC) -c $*.c -o $@ -I includes -I libft/includes
	@echo "$(OKC)\c"
	@echo -n ████████
	@echo "$(NOC)\c"

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@echo "$(WAC)$(NAME): removing ./obj/$(NOC)"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "$(WAC)$(NAME): removing executable$(NOC)"

re: fclean all

.PHONY: all clean fclean
