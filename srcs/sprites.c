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

void	init_sprites_pl(t_game *g)
{
	init_sprite(g, &g->player.img[0], "assets/player/player_d0.xpm");
	if (!g->player.img[0])
		quit(g);
	init_sprite(g, &g->player.img[1], "assets/player/player_d1.xpm");
	if (!g->player.img[1])
		quit(g);
	init_sprite(g, &g->player.img[2], "assets/player/player_d2.xpm");
	if (!g->player.img[2])
		quit(g);
	init_sprite(g, &g->player.img[3], "assets/player/player_d3.xpm");
	if (!g->player.img[3])
		quit(g);
	init_sprite(g, &g->player.img[4], "assets/player/player_r0.xpm");
	if (!g->player.img[4])
		quit(g);
	init_sprite(g, &g->player.img[5], "assets/player/player_r1.xpm");
	if (!g->player.img[5])
		quit(g);
	init_sprite(g, &g->player.img[6], "assets/player/player_r2.xpm");
	if (!g->player.img[6])
		quit(g);
	init_sprite(g, &g->player.img[7], "assets/player/player_r3.xpm");
	if (!g->player.img[7])
		quit(g);
	init_sprite(g, &g->player.img[8], "assets/player/player_u0.xpm");
	if (!g->player.img[8])
		quit(g);
	init_sprite(g, &g->player.img[9], "assets/player/player_u1.xpm");
	if (!g->player.img[9])
		quit(g);
	init_sprite(g, &g->player.img[10], "assets/player/player_u2.xpm");
	if (!g->player.img[10])
		quit(g);
	init_sprite(g, &g->player.img[11], "assets/player/player_u3.xpm");
	if (!g->player.img[11])
		quit(g);
	init_sprite(g, &g->player.img[12], "assets/player/player_l0.xpm");
	if (!g->player.img[12])
		quit(g);
	init_sprite(g, &g->player.img[13], "assets/player/player_l1.xpm");
	if (!g->player.img[13])
		quit(g);
	init_sprite(g, &g->player.img[14], "assets/player/player_l2.xpm");
	if (!g->player.img[14])
		quit(g);
	init_sprite(g, &g->player.img[15], "assets/player/player_l3.xpm");
	if (!g->player.img[15])
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
	init_sprites_pl(g);
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
	if (g->player.img[0] != NULL)
		mlx_destroy_image(g->id, g->player.img[0]);
	if (g->player.img[1] != NULL)
		mlx_destroy_image(g->id, g->player.img[1]);
	if (g->player.img[2] != NULL)
		mlx_destroy_image(g->id, g->player.img[2]);
	if (g->player.img[3] != NULL)
		mlx_destroy_image(g->id, g->player.img[3]);
	if (g->player.img[4] != NULL)
		mlx_destroy_image(g->id, g->player.img[4]);
	if (g->player.img[5] != NULL)
		mlx_destroy_image(g->id, g->player.img[5]);
	if (g->player.img[6] != NULL)
		mlx_destroy_image(g->id, g->player.img[6]);
	if (g->player.img[7] != NULL)
		mlx_destroy_image(g->id, g->player.img[7]);
	if (g->player.img[8] != NULL)
		mlx_destroy_image(g->id, g->player.img[8]);
	if (g->player.img[9] != NULL)
		mlx_destroy_image(g->id, g->player.img[9]);
	if (g->player.img[10] != NULL)
		mlx_destroy_image(g->id, g->player.img[10]);
	if (g->player.img[11] != NULL)
		mlx_destroy_image(g->id, g->player.img[11]);
	if (g->player.img[12] != NULL)
		mlx_destroy_image(g->id, g->player.img[12]);
	if (g->player.img[13] != NULL)
		mlx_destroy_image(g->id, g->player.img[13]);
	if (g->player.img[14] != NULL)
		mlx_destroy_image(g->id, g->player.img[14]);
	if (g->player.img[15] != NULL)
		mlx_destroy_image(g->id, g->player.img[15]);
}
