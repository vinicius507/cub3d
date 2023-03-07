/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:48:56 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/06 22:20:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

t_hitbox	next_vhitbox(int angle, t_player player)
{
	t_hitbox	hitbox;
	int			correction;
	double		tan_angle;

	tan_angle = tan(radians(angle));
	hitbox.delta_x = BOX_SIZE;
	hitbox.delta_y = BOX_SIZE * tan_angle;
	correction = BOX_SIZE;
	if (angle < 90 || angle > 270)
		hitbox.delta_y *= -1;
	else
	{
		correction = -1;
		hitbox.delta_x *= -1;
	}
	hitbox.x = floor(player.x / BOX_SIZE) * (BOX_SIZE) + correction;
	hitbox.y = player.y + (player.x - hitbox.x) * tan_angle;
	return (hitbox);
}

double	distance_correction(int angle, int distance, t_player player)
{
	int		angle_i;
	double	distance_i;

	angle_i = angle - player.angle;
	distance_i = distance * cos(radians(angle_i));
	return (fabs(distance_i));
}

t_hit	v_ray(int angle, t_player player, t_map *world_map)
{
	t_hitbox	hitbox;
	t_fpoint	point;
	t_hit		hit;

	hit.distance = -1;
	hit.side = -1;
	hitbox = next_vhitbox(angle, player);
	point = cast(hitbox, world_map);
	if (point.x == -1 && point.y == -1)
		return (hit);
	hit.distance = fabs(player.x - point.x) / cos(radians(angle));
	hit.side = h_side(point.x);
	hit.x = point.x;
	hit.y = point.y;
	hit.distance = distance_correction(angle, hit.distance, player);
	return (hit);
}

t_hitbox	next_hhitbox(int angle, t_player player)
{
	t_hitbox	hitbox;
	int			correction;
	int			y_direction;
	int			x_direction;

	if (angle < 180)
	{
		correction = -1;
		y_direction = -1;
		x_direction = 1;
	}
	else
	{
		correction = BOX_SIZE;
		y_direction = 1;
		x_direction = -1;
	}
	hitbox.delta_y = BOX_SIZE * y_direction;
	hitbox.delta_x = BOX_SIZE / tan(radians(angle)) * x_direction;
	hitbox.y = floor((double)player.y / BOX_SIZE) * BOX_SIZE + correction;
	hitbox.x = player.x + ((player.y - hitbox.y) / tan(radians(angle)));
	return (hitbox);
}

t_hit	h_ray(int angle, t_player player, t_map *world_map)
{
	t_hitbox	hitbox;
	t_fpoint	point;
	t_hit		hit;

	hit.distance = -1;
	hit.side = -1;
	hitbox = next_hhitbox(angle, player);
	point = cast(hitbox, world_map);
	if (point.x == -1 && point.y == -1)
		return (hit);
	hit.distance = fabs(player.y - point.y) / sin(radians(angle));
	hit.side = v_side(point.y);
	hit.x = point.x;
	hit.y = point.y;
	hit.distance = distance_correction(angle, hit.distance, player);
	return (hit);
}
