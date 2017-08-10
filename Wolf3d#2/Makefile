# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 15:59:39 by mmartins          #+#    #+#              #
#    Updated: 2017/08/10 17:17:44 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

NAME = wolf3d

CFLAG = -g -Wall -Wextra -Werror

CC = gcc $(CFLAG)

SRC = 	src/main.c \
		src/init.c \
		src/key_hook.c \
		src/map.c \
		src/raycasting.c \
		src/draw.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH =	./libft

LIB		=		-L libft -lft -L mlx -lmlx -framework OpenGL -framework Appkit -framework OpenCL -g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${_BOLD}${_GREEN}Compilation...${_END}"
	@echo "${_BOLD}${_GREEN}Wait...${_END}"
	@make -C $(LIBFT_PATH)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@echo "${_BOLD}${_GREEN}Program [OK]...${_END}"

$(OBJ):
	@$(CC) -c $*.c -o $@ -I includes -I libft/includes

clean:
	@echo "${_BOLD}${_GREEN}Deleting Objects...${_END}"
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@echo "${_BOLD}${_GREEN}Cleaning [OK]${_END}"

fclean: clean
	@echo "${_BOLD}${_GREEN}Deleting program...${_END}"
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "${_BOLD}${_GREEN}FCleaning [OK]${_END}"

re: fclean all

.PHONY: all clean fclean
