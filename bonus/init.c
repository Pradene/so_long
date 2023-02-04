/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:39:40 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:28 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_items(char **map, int *count)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] != '\n')
			if (map[y][x] == 'C')
				++(*count);
	}
}

static void	get_exit_pos(char **map, int *posx, int *posy)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] != '\n')
		{
			if (map[y][x] == 'E')
			{
				*posx = x;
				*posy = y;
				return ;
			}
		}
	}
}

void	init(t_game *g, char *path)
{
	g->map = init_map(path);
	g->id = mlx_init();
	if (!g->id)
		exit(EXIT_FAILURE);
	g->width = (ft_strlen(g->map[0]) - 1) * SIZE;
	g->height = (ft_strline(g->map)) * SIZE;
	g->win = mlx_new_window(g->id, g->width,
			g->height, "Go Get Coke");
	g->moves = 0;
	g->item_left = 0;
	count_items(g->map, &g->item_left);
	g->e_pos.x = 0;
	g->e_pos.y = 0;
	get_exit_pos(g->map, &g->e_pos.x, &g->e_pos.y);
	init_player(g);
	if (!g->win)
		exit(EXIT_FAILURE);
	init_sprites(g);
}
