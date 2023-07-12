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

static void	destroy_sprites_pl1(t_game *g)
{
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
}

static void	destroy_sprites_pl2(t_game *g)
{
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

void	destroy_sprites(t_game *g)
{
	destroy_sprites_pl1(g);
	destroy_sprites_pl2(g);
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
}
