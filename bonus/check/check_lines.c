/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:06:35 by lpradene          #+#    #+#             */
/*   Updated: 2022/12/21 13:42:18 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_lines(char **map)
{
	int	line;
	int	count;

	line = 0;
	count = ft_strlen(map[line]);
	while (map[++line])
	{
		if (ft_strlen(map[line]) != count)
			return (0);
		count = ft_strlen(map[line]);
	}
	return (1);
}
