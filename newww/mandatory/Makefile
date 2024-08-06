# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 10:05:16 by aamardou          #+#    #+#              #
#    Updated: 2024/08/06 10:05:17 by aamardou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror -Iincludes
MLXFLG	=	-lmlx -framework OpenGL -framework AppKit
LIBFT	=	libs/libft/libft.a
SRCS	=	srcs/cub3D.c \
			srcs/parsing/parsing.c srcs/parsing/parsing_utils.c srcs/parsing/map_parsing.c \
			srcs/parsing/line_parsing.c srcs/parsing/line_parsing_utls.c \
			srcs/utils/initializing.c srcs/utils/setup.c srcs/utils/utils.c srcs/utils/error_handler.c\
			srcs/raycasting/projection.c srcs/raycasting/raycasting.c srcs/raycasting/raycasting_utils.c \

all: $(NAME)

$(LIBFT):
	echo "Compiling libft"
	make -C libs/libft

$(NAME): $(SRCS) $(LIBFT)
	echo "Compiling Cub3D"
	$(CC) $(MLXFLG) $(LIBFT) $(SRCS) -o $(NAME)

clean:
	@make clean -C libs/libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft

re: fclean all

.PHONY: all clean fclean re
