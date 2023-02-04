/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:52:15 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:53:08 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit(t_game *g)
{
	free_map(g->map);
	destroy_sprites(g);
	mlx_destroy_window(g->id, g->win);
	mlx_destroy_display(g->id);
	free(g->id);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit(EXIT_FAILURE);
	init(&game, argv[1]);
	render(&game);
	mlx_loop_hook(game.id, &update, &game);
	mlx_hook(game.win, 2, 1L << 0, &key, &game);
	mlx_hook(game.win, 17, 0, &quit, &game);
	mlx_loop(game.id);
}
