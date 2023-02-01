/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:59:32 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/21 13:08:42 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(char **map)
{
	int	line;
	int	i;
	int	size;

	line = 0;
	size = ft_strlen(map[line]) - 1;
	while (map[line])
	{
		i = 0;
		if (line == 0 || map[line + 1] == NULL)
			while (i < size)
				if (map[line][i++] != '1')
					return (0);
		if (line > 0 && map[line + 1] != NULL)
			if (map[line][0] != '1' || map[line][size - 1] != '1')
				return (0);
		line++;
	}
	return (1);
}
