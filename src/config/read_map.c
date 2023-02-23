/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:03:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/23 20:06:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static size_t	map_height(char **lines)
{
	size_t	height;

	height = 0;
	while (lines[height] != NULL)
		height++;
	return (height);
}

static size_t	map_max_width(char **lines)
{
	size_t	width;
	size_t	max_width;

	max_width = 0;
	while (*lines != NULL)
	{
		width = ft_strlen(*lines);
		if (width > max_width)
			max_width = width;
		lines++;
	}
	return (max_width);
}

static void	pad_map(t_map *map, char **lines, size_t height, size_t max_width)
{
	size_t	i;
	char	*row;
	size_t	width;

	map->rows = ft_calloc(height + 1, sizeof(char *));
	if (map->rows == NULL)
		return ;
	i = 0;
	while (lines[i] != NULL)
	{
		width = ft_strlen(lines[i]);
		row = ft_calloc(1, max_width + 1);
		ft_strlcpy(row, lines[i], width + 1);
		ft_memset(row + width, ' ', max_width - width);
		map->rows[i] = row;
		i++;
	}
}

t_map	read_map(char **lines)
{
	t_map	map;
	size_t	height;
	size_t	max_width;

	height = map_height(lines);
	max_width = map_max_width(lines);
	pad_map(&map, lines, height, max_width);
	map.height = height;
	map.width = max_width;
	return (map);
}
