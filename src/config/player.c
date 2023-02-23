/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:52:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/23 20:13:15 by vgoncalv         ###   ########.fr       */
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
				cub->player.x = (double)(x + 1) / 2;
				cub->player.y = (double)(y + 1) / 2;
			}
			x++;
		}
		y++;
	}
	if (found != 1)
		return (set_player_postition_error(found));
	return (0);
}
