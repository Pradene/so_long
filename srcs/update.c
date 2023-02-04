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

static void	update_player(t_game *g)
{
	t_player	*pl;

	pl = &g->player;
	change_pos(g, &g->player);
	mlx_put_image_to_window(g->id, g->win, g->floor,
		pl->prev_pos.x, pl->prev_pos.y);
	mlx_put_image_to_window(g->id, g->win, pl->img[0],
		pl->pos.x, pl->pos.y);
	pl->prev_pos.x = pl->pos.x;
	pl->prev_pos.y = pl->pos.y;
}

static void	update_exit(t_game *g)
{
	mlx_put_image_to_window(g->id, g->win, g->exit,
		g->e_pos.x * SIZE, g->e_pos.y * SIZE);
}

int	update(t_game *g)
{
	if (!g->win)
		return (1);
	update_exit(g);
	update_player(g);
	return (0);
}
