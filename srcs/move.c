/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:46 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:57:50 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move(t_game *g, int x, int y, double f(double))
{
	int	posx;
	int	posy;

	posy = (int)f((double)g->player.pos.y / SIZE) + (y * 8) / SIZE;
	posx = (int)f((double)g->player.pos.x / SIZE) + (x * 8) / SIZE;
	if (g->player.pos.x % SIZE == 0 && g->player.pos.y % SIZE == 0
		&& g->map[posy][posx] != '1')
		g->moves++;
	if (g->map[posy][posx] == 'E' && g->item_left == 0)
		quit(g);
	if (g->map[posy][posx] == 'C')
	{
		g->item_left--;
		g->map[posy][posx] = '0';
		mlx_put_image_to_window(g->id, g->win, g->floor,
			posx * SIZE, posy * SIZE);
	}
	if (g->map[posy][posx] != '1')
	{
		g->player.pos.x += x;
		g->player.pos.y += y;
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
		move(g, -SIZE / 8, 0, &ceil);
	else if (pl->dir == RIGHT)
		move(g, SIZE / 8, 0, &floor);
	else if (pl->dir == TOP)
		move(g, 0, -SIZE / 8, &ceil);
	else if (pl->dir == DOWN)
		move(g, 0, SIZE / 8, &floor);
}
