/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:17:17 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 18:17:48 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_sprite(t_game *getgid, t_img **img, char *path)
{
	int	size;

	size = 0;
	*img = mlx_xpm_file_to_image(getgid->id, path,
			&size, &size);
}

void	init_sprites(t_game *g)
{
	init_sprite(g, &g->floor, "assets/floor.xpm");
	if (!g->floor)
		quit(g);
	init_sprite(g, &g->wall, "assets/wall.xpm");
	if (!g->wall)
		quit(g);
	init_sprite(g, &g->exit, "assets/exit.xpm");
	if (!g->exit)
		quit(g);
	init_sprite(g, &g->player.img[0], "assets/player/player_d0.xpm");
	if (!g->player.img[0])
		quit(g);
	init_sprite(g, &g->item[0], "assets/item/item0.xpm");
	if (!g->item[0])
		quit(g);
}

void	destroy_sprites(t_game *g)
{
	if (g->wall != NULL)
		mlx_destroy_image(g->id, g->wall);
	if (g->floor != NULL)
		mlx_destroy_image(g->id, g->floor);
	if (g->exit != NULL)
		mlx_destroy_image(g->id, g->exit);
	if (g->item[0] != NULL)
		mlx_destroy_image(g->id, g->item[0]);
	if (g->player.img[0] != NULL)
		mlx_destroy_image(g->id, g->player.img[0]);
}
