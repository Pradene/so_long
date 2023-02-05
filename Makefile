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
		check/check_char.c \
		check/check_item.c \
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
		sprites_init.c \
		sprites_destroy.c \
		update.c \

SRCS = ${addprefix srcs/, ${FILES}}
BONUS = ${addprefix bonus/, ${FILES}}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= so_long

OBJS_S = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS_S)
	$(CC) $(OBJS_S) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) 

all: $(NAME)

bo: $(OBJS_B)
	$(CC) $(OBJS_B) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) 

bonus: bo

clean:
	rm -f $(OBJS_S) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean srcs all bo bonus
