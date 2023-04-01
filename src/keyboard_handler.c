/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/04/01 20:01:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hitted_wall(t_map *world_map, double x, double y)
{
	return (world_map->rows[(int)floor(y)][(int)floor(x)] == '1');
}

void	move(t_cub *cub, double x, double y)
{
	double	x_limit;
	double	y_limit;

	if (x < 0)
		x_limit = x - 0.15;
	else
		x_limit = x + 0.15;
	if (y < 0)
		y_limit = y - 0.15;
	else
		y_limit = y + 0.15;
	if (!hitted_wall(
			&cub->map,
			cub->player.x + x_limit,
			cub->player.y + y_limit))
	{
		cub->player.y += y;
		cub->player.x += x;
	}
}

void	look_left(t_cub *cub)
{
	cub->player.angle -= 0.6;
	if (cub->player.angle == 359)
		cub->player.angle = 0;
}

void	look_right(t_cub *cub)
{
	cub->player.angle += 0.6;
	if (cub->player.angle < 0)
		cub->player.angle = 359;
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
