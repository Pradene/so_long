/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:24 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:54:26 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	line;

	line = -1;
	while (map[++line])
		free(map[line]);
	free(map);
}

int	count_lines(char *path)
{
	int		fd;
	int		readc;
	int		count;
	char	buf[2];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	readc = 1;
	count = 0;
	while (readc)
	{
		readc = read(fd, buf, 1);
		buf[readc] = '\0';
		if (*buf == '\n')
			count++;
	}
	close(fd);
	return (count);
}

char	**read_map(char *path)
{
	int		fd;
	int		size;
	int		line;
	char	**map;

	size = count_lines(path);
	if (!size)
		return (0);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = -1;
	while (++line <= size)
		map[line] = get_next_line(fd);
	close(fd);
	return (map);
}

char	**init_map(char *path)
{
	char	**map;

	map = read_map(path);
	if (!map)
		exit(EXIT_FAILURE);
	if (!check(map))
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	free_map(map);
	map = read_map(path);
	return (map);
}
