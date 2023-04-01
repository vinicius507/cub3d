/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:52:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/01 18:09:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <unistd.h>

int	set_player_postition_error(int found)
{
	if (found == 0)
		ft_dprintf(STDERR_FILENO, ERR_CFG_MAP_NO_PLAYER);
	else
		ft_dprintf(STDERR_FILENO, ERR_CFG_MAP_TOO_MANY_PLAYERS, found);
	return (1);
}

void	set_player_angle(t_player *player, char side)
{
	if (side == 'E')
		player->angle = 0;
	else if (side == 'N')
		player->angle = 90;
	else if (side == 'W')
		player->angle = 180;
	else
		player->angle = 270;
	player->fov = 60;
}

void	set_player_coordinates(t_player *player, size_t x, size_t y)
{
	player->x = x;
	player->y = y;
}

int	set_player_position(t_cub *cub)
{
	size_t	x;
	size_t	y;
	t_map	*map;
	int		found;

	y = 0;
	found = 0;
	map = &cub->map;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_strchr("NSWE", map->rows[y][x]) && found++ == 0)
			{
				set_player_coordinates(&cub->player, x, y);
				set_player_angle(&cub->player, map->rows[y][x]);
			}
			x++;
		}
		y++;
	}
	if (found != 1)
		return (set_player_postition_error(found));
	return (0);
}
