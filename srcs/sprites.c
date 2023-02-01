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

void	init_sprites_item(t_game *g)
{
	init_sprite(g, &g->item[0], "assets/item/item0.xpm");
	if (!g->item[0])
		quit(g);
	init_sprite(g, &g->item[1], "assets/item/item1.xpm");
	if (!g->item[1])
		quit(g);
	init_sprite(g, &g->item[2], "assets/item/item2.xpm");
	if (!g->item[2])
		quit(g);
	init_sprite(g, &g->item[3], "assets/item/item3.xpm");
	if (!g->item[3])
		quit(g);
	init_sprite(g, &g->item[4], "assets/item/item4.xpm");
	if (!g->item[4])
		quit(g);
	init_sprite(g, &g->item[5], "assets/item/item5.xpm");
	if (!g->item[5])
		quit(g);
	init_sprite(g, &g->item[6], "assets/item/item6.xpm");
	if (!g->item[6])
		quit(g);
	init_sprite(g, &g->item[7], "assets/item/item7.xpm");
	if (!g->item[7])
		quit(g);
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
	init_sprite(g, &g->player.img, "assets/player.xpm");
	if (!g->player.img)
		quit(g);
	init_sprites_item(g);
}

void	destroy_sprites(t_game *g)
{
	if (g->wall != NULL)
		mlx_destroy_image(g->id, g->wall);
	if (g->floor != NULL)
		mlx_destroy_image(g->id, g->floor);
	if (g->exit != NULL)
		mlx_destroy_image(g->id, g->exit);
	if (g->player.img != NULL)
		mlx_destroy_image(g->id, g->player.img);
	if (g->item[0] != NULL)
		mlx_destroy_image(g->id, g->item[0]);
	if (g->item[1] != NULL)
		mlx_destroy_image(g->id, g->item[1]);
	if (g->item[2] != NULL)
		mlx_destroy_image(g->id, g->item[2]);
	if (g->item[3] != NULL)
		mlx_destroy_image(g->id, g->item[3]);
	if (g->item[4] != NULL)
		mlx_destroy_image(g->id, g->item[4]);
	if (g->item[5] != NULL)
		mlx_destroy_image(g->id, g->item[5]);
	if (g->item[6] != NULL)
		mlx_destroy_image(g->id, g->item[6]);
	if (g->item[7] != NULL)
		mlx_destroy_image(g->id, g->item[7]);
}
