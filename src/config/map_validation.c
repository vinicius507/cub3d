/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:07:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:21 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	get_tile(char c)
{
	if (c == ' ')
		return (TL_VOID);
	if (c == '0')
		return (TL_FLOOR);
	if (c == '1')
		return (TL_WALL);
	if (ft_strchr("NSWE", c) != NULL)
		return (TL_PLAYER);
	return (0);
}

int	get_expected(int tile)
{
	if (tile == TL_VOID)
		return (TL_WALL | TL_VOID);
	if (tile == TL_FLOOR)
		return (TL_FLOOR | TL_PLAYER | TL_WALL);
	if (tile == TL_WALL)
		return (TL_VOID | TL_FLOOR | TL_PLAYER | TL_WALL);
	if (tile == TL_PLAYER)
		return (TL_FLOOR | TL_WALL);
	return (0);
}

int	expect(t_map *map, ssize_t x, ssize_t y, int expected)
{
	int	tile;
	int	is_expected;

	if (x < 0 || y < 0 || (size_t)x >= map->width || (size_t)y >= map->height)
		tile = TL_VOID;
	else
		tile = get_tile(map->rows[y][x]);
	is_expected = tile & expected;
	if (is_expected == 0)
		ft_dprintf(STDERR_FILENO, ERR_CFG_INVALID_MAP);
	return (is_expected);
}

int	check_neighbors(t_map *map, ssize_t x, ssize_t y, int expected)
{
	if ((expect(map, x + 1, y, expected) == 0))
		return (0);
	if ((expect(map, x, y + 1, expected) == 0))
		return (0);
	if ((expect(map, x + 1, y + 1, expected) == 0))
		return (0);
	if ((expect(map, x - 1, y, expected) == 0))
		return (0);
	if ((expect(map, x, y - 1, expected) == 0))
		return (0);
	if ((expect(map, x - 1, y - 1, expected) == 0))
		return (0);
	if ((expect(map, x + 1, y - 1, expected) == 0))
		return (0);
	if ((expect(map, x - 1, y + 1, expected) == 0))
		return (0);
	return (1);
}

int	map_is_valid(t_map *map)
{
	ssize_t	x;
	ssize_t	y;
	int		tile;
	int		expected;

	y = 0;
	while ((size_t)y < map->height)
	{
		x = 0;
		while ((size_t)x < map->width)
		{
			tile = get_tile(map->rows[y][x]);
			expected = get_expected(tile);
			if ((check_neighbors(map, x, y, expected) == 0))
				return (0);
			tile = map->rows[y][x];
			x++;
		}
		y++;
	}
	return (1);
}
