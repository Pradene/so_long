# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpradene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:33:43 by lpradene          #+#    #+#              #
#    Updated: 2022/12/30 22:26:27 by lpradene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= gnl/get_next_line.c \
		check/check_lines.c \
		check/check_path.c \
		check/check_pos.c \
		check/check_walls.c \
		check/check.c \
		utils/itoa.c \
		utils/memcpy.c \
		utils/strchr.c \
		utils/strdup.c \
		utils/strlen.c \
		utils/strline.c \
		init.c \
		key.c \
		main.c \
		map.c \
		move.c \
		player.c \
		render.c \
		sprites.c \
		update.c \

SRCS = ${addprefix srcs/, ${FILES}}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= so_long

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
