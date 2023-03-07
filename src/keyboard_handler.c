/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/06 23:48:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hitted_wall(t_map *world_map, int x, int y)
{
	return (world_map->rows[y / 64][x / 64] == '1');
}

void	move(t_cub *cub, int x, int y)
{
	int	x_limit;
	int	y_limit;

	if (x < 0)
		x_limit = x - 15;
	else
		x_limit = x + 15;
	if (y < 0)
		y_limit = y - 15;
	else
		y_limit = y + 15;
	if (!hitted_wall(
			&cub->map,
			cub->player.x + x_limit,
			cub->player.y + y_limit))
	{
		cub->player.y += y;
		cub->player.x += x;
	}
}

int	handle_keyboard(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		cub_exit(cub);
	else if (keysym == XK_w)
		move_up(cub);
	else if (keysym == XK_s)
		move_down(cub);
	else if (keysym == XK_a)
		move_left(cub);
	else if (keysym == XK_d)
		move_right(cub);
	return (0);
}
