/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:55:11 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/05 01:55:13 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
