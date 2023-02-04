/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:58:30 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/21 13:14:29 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_items(char **map)
{
	int	line;
	int	i;
	int	size;
	int	count;

	line = 0;
	count = 0;
	size = ft_strlen(map[line]) - 1;
	while (map[line])
	{
		i = 0;
		while (i < size)
		{
			if (map[line][i] == 'C')
				count++;
			i++;
		}
		line++;
	}
	return (count);
}

int	check_pos(char **map)
{
	int	line;
	int	i;
	int	e;
	int	p;

	line = -1;
	p = 0;
	e = 0;
	while (map[++line])
	{
		i = -1;
		while (++i < ft_strlen(map[line]))
		{
			if (map[line][i] == 'P')
					p++;
			if (map[line][i] == 'E')
					e++;
		}
	}
	if (e != 1 || p != 1)
		return (0);
	return (1);
}
