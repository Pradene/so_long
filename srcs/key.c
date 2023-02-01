/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:51:53 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:55 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key(int keycode, t_game *g)
{
	if (keycode == 97)
		g->player.next_dir = LEFT;
	else if (keycode == 100)
		g->player.next_dir = RIGHT;
	else if (keycode == 115)
		g->player.next_dir = DOWN;
	else if (keycode == 119)
		g->player.next_dir = TOP;
	else if (keycode == 65307)
		quit(g);
	return (0);
}
