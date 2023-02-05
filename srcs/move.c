/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:46 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/05 00:34:14 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_move(int n)
{
	char	*s;

	write(1, "Score: ", 7);
	s = ft_itoa(n);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	free(s);
}

static void	move(t_game *g, int x, int y)
{
	int		posx;
	int		posy;

	posx = g->player.pos.x / SIZE;
	posy = g->player.pos.y / SIZE;
	if (g->map[posy + y / SIZE][posx + x / SIZE] != '1')
		g->moves++;
	if (g->map[posy + y / SIZE][posx + x / SIZE] == 'E' && g->item_left == 0)
		quit(g);
	if (g->map[posy + y / SIZE][posx + x / SIZE] == 'C')
	{
		g->item_left--;
		g->map[posy + y / SIZE][posx + x / SIZE] = '0';
		mlx_put_image_to_window(g->id, g->win, g->floor,
			g->player.pos.x, g->player.pos.y);
	}
	if (g->map[posy + y / SIZE][posx + x / SIZE] != '1')
	{
		g->player.pos.x += x;
		g->player.pos.y += y;
		print_move(g->moves);
	}
}

static void	reset_dir(t_dir *dir, t_dir *next_dir)
{
	*dir = *next_dir;
	*next_dir = NONE;
}

void	change_pos(t_game *g, t_player *pl)
{
	if (pl->next_dir != NONE
		&& (pl->pos.x % SIZE == 0 && pl->pos.y % SIZE == 0))
		reset_dir(&pl->dir, &pl->next_dir);
	if (pl->dir == LEFT)
		move(g, -SIZE, 0);
	else if (pl->dir == RIGHT)
		move(g, SIZE, 0);
	else if (pl->dir == TOP)
		move(g, 0, -SIZE);
	else if (pl->dir == DOWN)
		move(g, 0, SIZE);
	pl->dir = NONE;
}
