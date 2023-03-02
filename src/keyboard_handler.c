/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/02 01:19:22 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hitted_wall(t_map *world_map, int x, int y)
{
	return (world_map->rows[x / 64][y / 64] == 1);
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

void	move_up(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 1, 0);
	else if (cub->player.angle < 65)
		move(cub, 1, -1);
	else if (cub->player.angle < 115)
		move(cub, 0, -1);
	else if (cub->player.angle < 155)
		move(cub, -1, -1);
	else if (cub->player.angle < 205)
		move(cub, -1, 0);
	else if (cub->player.angle < 245)
		move(cub, -1, 1);
	else if (cub->player.angle < 295)
		move(cub, 0, 1);
	else if (cub->player.angle < 335)
		move(cub, 1, 1);
	else
		move(cub, 1, 0);
}

void	move_down(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, -1, 0);
	else if (cub->player.angle < 65)
		move(cub, -1, 1);
	else if (cub->player.angle < 115)
		move(cub, 0, 1);
	else if (cub->player.angle < 155)
		move(cub, 1, 1);
	else if (cub->player.angle < 205)
		move(cub, 1, 0);
	else if (cub->player.angle < 245)
		move(cub, 1, -1);
	else if (cub->player.angle < 295)
		move(cub, 0, -1);
	else if (cub->player.angle < 335)
		move(cub, -1, -1);
	else
		move(cub, -1, 0);
}

void	move_left(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 0, -1);
	else if (cub->player.angle < 65)
		move(cub, -1, -1);
	else if (cub->player.angle < 115)
		move(cub, -1, 0);
	else if (cub->player.angle < 155)
		move(cub, -1, 1);
	else if (cub->player.angle < 205)
		move(cub, 1, 0);
	else if (cub->player.angle < 245)
		move(cub, 1, 1);
	else if (cub->player.angle < 295)
		move(cub, 1, 0);
	else if (cub->player.angle < 335)
		move(cub, 1, -1);
	else
		move(cub, 0, -1);
}

void	move_right(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 0, 1);
	else if (cub->player.angle < 65)
		move(cub, 1, 1);
	else if (cub->player.angle < 115)
		move(cub, 1, 0);
	else if (cub->player.angle < 155)
		move(cub, 1, -1);
	else if (cub->player.angle < 205)
		move(cub, -1, 0);
	else if (cub->player.angle < 245)
		move(cub, -1, -1);
	else if (cub->player.angle < 295)
		move(cub, -1, 0);
	else if (cub->player.angle < 335)
		move(cub, -1, 1);
	else
		move(cub, 0, 1);
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
