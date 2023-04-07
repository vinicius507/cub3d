/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/04/07 20:55:06 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hitted_wall(t_map *world_map, t_player player, double x, double y)
{
	double	x_limit;
	double	y_limit;
	int		x_end;
	int		y_end;

	if (x < 0)
		x_limit = x - 0.1;
	else
		x_limit = x + 0.1;
	if (y < 0)
		y_limit = y - 0.1;
	else
		y_limit = y + 0.1;
	x_end = (int)floor(player.x + x_limit);
	y_end = (int)floor(player.y + y_limit);
	if (world_map->rows[y_end][x_end] == '1')
		return (1);
	return (0);
}

void	move(t_cub *cub, double x, double y)
{
	if (!hitted_wall(&cub->map, cub->player, x, y))
	{
		cub->player.y += y;
		cub->player.x += x;
	}
}

int	handle_keyboard(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		cub_exit(cub);
	else if (keysym == XK_w || keysym == XK_Up)
		move_up(cub);
	else if (keysym == XK_s || keysym == XK_Down)
		move_down(cub);
	else if (keysym == XK_a)
		move_left(cub);
	else if (keysym == XK_d)
		move_right(cub);
	else if (keysym == XK_Left)
		look_left(cub);
	else if (keysym == XK_Right)
		look_right(cub);
	return (0);
}
