/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:39:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/04/13 15:09:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/projection.h"

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

void	move(t_cub *cub, int direction)
{
	t_hit		hit;
	long double	mov_angle;

	mov_angle = cub->player.angle + (direction * 90.0);
	hit = raycast(cub, mov_angle);
	if (hit.distance < MOVE_DISTANCE + PLAYER_BOUNDARY)
		return ;
	cub->player.x += MOVE_DISTANCE * cos(radians(mov_angle));
	cub->player.y += MOVE_DISTANCE * sin(radians(mov_angle));
}

int	handle_keyboard(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		cub_exit(cub);
	else if (keysym == XK_w || keysym == XK_Up)
		move(cub, 0);
	else if (keysym == XK_s || keysym == XK_Down)
		move(cub, 2);
	else if (keysym == XK_a)
		move(cub, 3);
	else if (keysym == XK_d)
		move(cub, 1);
	else if (keysym == XK_Left)
		look_left(cub);
	else if (keysym == XK_Right)
		look_right(cub);
	return (0);
}
