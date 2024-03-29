/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:52:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/14 17:39:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

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
		player->angle = 0.1;
	else if (side == 'N')
		player->angle = 270.1;
	else if (side == 'W')
		player->angle = 180.1;
	else
		player->angle = 90.1;
	player->fov = 60;
}

void	set_player_coordinates(t_player *player, size_t x, size_t y)
{
	player->x = x + 0.5;
	player->y = y + 0.5;
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
