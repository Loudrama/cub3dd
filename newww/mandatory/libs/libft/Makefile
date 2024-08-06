# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 03:07:31 by aamardou          #+#    #+#              #
#    Updated: 2024/08/05 06:51:04 by aamardou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_split.c\
ft_memmove.c ft_strchr.c ft_memchr.c ft_strnstr.c ft_atoi.c ft_memcmp.c ft_strncmp.c\
ft_strlcat.c ft_strlcpy.c ft_calloc.c ft_strrchr.c ft_isalnum.c ft_striteri.c \
ft_strdup.c ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line.c

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

.c.o:
			gcc -c $(CFLAGS) $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -rf ${OBJS}

fclean:
			rm -f ${NAME} ${OBJS}

re:			fclean all
