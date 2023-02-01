/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:42:04 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/21 16:01:31 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	search_items(char **map)
{
	int	i;
	int	line;

	line = 0;
	while (map[++line + 1])
	{
		i = 0;
		while (++i < ft_strlen(map[line]))
		{
			if (map[line][i] == 'C')
				return (0);
		}
	}
	return (1);
}

static int	safe(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P' ||
		map[y][x] == 'C' || map[y][x] == 'E')
		return (1);
	return (0);
}

int	check_path(char **map, int x, int y)
{
	if (search_items(map))
		return (1);
	if (safe(map, x, y))
	{
		map[y][x] = 'X';
		if (check_path(map, x, y - 1))
			return (1);
		if (check_path(map, x - 1, y))
			return (1);
		if (check_path(map, x, y + 1))
			return (1);
		if (check_path(map, x + 1, y))
			return (1);
		return (0);
	}
	return (0);
}
