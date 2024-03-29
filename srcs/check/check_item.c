/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:34:33 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/05 00:34:43 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_item(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				return (1);
		}
	}
	return (0);
}
