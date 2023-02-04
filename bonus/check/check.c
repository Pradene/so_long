/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:06:22 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/29 21:24:31 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	get_pos(char **map)
{
	t_pos	pos;
	int		line;
	int		i;

	line = -1;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'P')
			{
				pos.x = i;
				pos.y = line;
			}
		}
	}
	return (pos);
}

int	check(char **map)
{
	if (!check_lines(map))
		return (write(2, "Error\nMap isn't rectangular\n", 29), 0);
	else if (!check_pos(map))
		return (write(2, "Error\nMap have multiple exits or strating points\n",
				50), 0);
	else if (!check_walls(map))
		return (write(2, "Error\nMap isn't surrounded by walls\n", 37), 0);
	else if (!check_item(map))
		return (write(2, "Error\nMap doesn't have items\n", 30), 0);
	else if (!check_char(map))
		return (write(2, "Error\nMap contains other char\n", 31), 0);
	else if (!check_path(map, get_pos(map).x, get_pos(map).y))
		return (write(2, "Error\nMap isn't finishable\n", 28), 0);
	return (1);
}
