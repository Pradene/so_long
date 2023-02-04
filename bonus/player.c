/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:58:15 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:58:28 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_player_pos(char **map, t_pos *pos)
{
	int	l;
	int	c;

	l = -1;
	while (map[++l])
	{
		c = -1;
		while (map[l][++c] != '\n')
		{
			if (map[l][c] == 'P')
			{
				pos->x = c * SIZE;
				pos->y = l * SIZE;
				return ;
			}
		}
	}
}

void	init_player(t_game *g)
{
	g->player.dir = NONE;
	g->player.next_dir = NONE;
	init_player_pos(g->map, &g->player.pos);
	g->player.prev_pos.x = g->player.pos.x;
	g->player.prev_pos.y = g->player.pos.y;
}
