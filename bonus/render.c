/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:58:50 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:59:52 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put(t_game *g, t_img *img, int x, int y)
{
	mlx_put_image_to_window(g->id, g->win, img, x, y);
}

int	render(t_game *g)
{
	int		x;
	int		y;

	if (!g->win)
		return (1);
	y = -1;
	while (++y * SIZE < g->height)
	{
		x = -1;
		while (++x * SIZE < g->width)
		{
			if (g->map[y][x] == 'P')
				put(g, g->player.img[0], g->player.pos.x, g->player.pos.y);
			else if (g->map[y][x] == 'C')
				put(g, g->item[0], x * SIZE, y * SIZE);
			else if (g->map[y][x] == '1')
				put(g, g->wall, x * SIZE, y * SIZE);
			else if (g->map[y][x] == 'E')
				put(g, g->exit, x * SIZE, y * SIZE);
			else
				put(g, g->floor, x * SIZE, y * SIZE);
		}
	}
	return (0);
}
