/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:27:22 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/13 16:38:15 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	malloc_map(t_env *e)
{
	int y;

	y = 0;
	if (!(e->map = (int **)malloc(sizeof(int**) * MAP_H)))
		return (0);
	while (y < MAP_H)
	{
		if (!(e->map[y] = (int *)malloc(sizeof(int*) * MAP_W)))
			return (0);
		y++;
	}
	return (1);
}

int	get_map(t_env *e)
{
	int		fd;
	char	*line;
	int		y;
	int		x;
	int		x_i;

	y = 0;
	fd = open("map", O_RDONLY);
	if (fd < 1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		x_i = 0;
		while (x < MAP_W)
		{
			e->map[y][x] = ft_atoi(&line[x_i]);
			x++;
			x_i += 2;
		}
		y++;
	}
	free(line);
	line = NULL;
	return (1);
}
