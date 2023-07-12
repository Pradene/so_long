/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:48 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 18:29:28 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_items(t_game *g)
{
	static int	frame = 0;
	int			x;
	int			y;

	frame = (frame + 1) % 8;
	y = -1;
	while (++y * SIZE < g->height)
	{
		x = -1;
		while (++x * SIZE < g->width)
			if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->id, g->win, g->item[frame],
					x * SIZE, y * SIZE);
	}
}

static void	update_player(t_game *g)
{
	static int	frame = 0;
	t_player	*pl;

	pl = &g->player;
	frame = (frame + 1) % 16;
	change_pos(g, &g->player);
	mlx_put_image_to_window(g->id, g->win, g->floor,
		pl->prev_pos.x, pl->prev_pos.y);
	if (!pl->dir)
		mlx_put_image_to_window(g->id, g->win, pl->img[0],
			pl->pos.x, pl->pos.y);
	else
		mlx_put_image_to_window(g->id, g->win,
			pl->img[frame / 4 + (pl->dir - 1) * 4],
			pl->pos.x, pl->pos.y);
	pl->prev_pos.x = pl->pos.x;
	pl->prev_pos.y = pl->pos.y;
}

static void	update_exit(t_game *g)
{
	mlx_put_image_to_window(g->id, g->win, g->exit,
		g->e_pos.x * SIZE, g->e_pos.y * SIZE);
}

static void	update_score(t_game *g)
{
	int		score;
	int		x;
	char	*s;

	score = g->moves;
	s = ft_itoa(score);
	if (!s)
		quit(g);
	x = -1;
	while (g->map[0][++x] != '\n')
		mlx_put_image_to_window(g->id, g->win, g->wall, x * SIZE, 0);
	mlx_string_put(g->id, g->win, 12, SIZE / 2 + 4, 0x000000, "Score ");
	mlx_string_put(g->id, g->win, ft_strlen("Score ") * 6 + 12,
		SIZE / 2 + 4, 0x000000, s);
	free(s);
}

int	update(t_game *g)
{
	if (!g->win)
		return (1);
	update_exit(g);
	update_items(g);
	update_player(g);
	update_score(g);
	usleep(50000);
	return (0);
}
