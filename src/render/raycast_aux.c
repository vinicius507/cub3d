/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:48:56 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/02 01:27:59 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

t_point cast(t_hitbox init_hitbox, t_map *world_map)
{
	t_hitbox	hitbox;
	t_point		point;
	int			box_y;
	int			box_x;

	hitbox = init_hitbox;
	point.y = -1;
	point.x = -1;
	while (NOT_HIT)
	{
		box_y = hitbox.y / BOX_SIZE;
		box_x = hitbox.x / BOX_SIZE;
		if (box_x < 0 || box_x > (int)world_map->width - 1)
			return (point);
		if (box_y < 0 || box_y > (int)world_map->height - 1)
			return (point);
		if (world_map->rows[box_x][box_y] == 1)
			break ;
		hitbox.y += hitbox.delta_y;
		hitbox.x += hitbox.delta_x;
	}
	point.y = hitbox.y;
	point.x = hitbox.x;
	return (point);
}

t_hitbox	next_vhitbox (int angle, t_player player)
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

t_hit	v_ray(int angle, t_player player, t_map *world_map)
{
	t_hitbox	hitbox;
	t_point		point;
	t_hit		hit;

	hit.distance = -1;
	hit.side = -1;
	hitbox = next_vhitbox(angle, player);
	point = cast(hitbox, world_map);
	if (point.x == -1 && point.y == -1)
		return (hit);
	hit.distance = abs(player.x - point.x) / cos(radians(angle));
	hit.side = h_side(point.x);
	hit.x = point.x;
	hit.y = point.y;
	int b_angle = angle - player.angle; // Turn into function
	hit.distance = hit.distance * cos(radians(b_angle));
	hit.distance = abs(hit.distance);
	return (hit);
}

t_hitbox	next_hhitbox (int angle, t_player player) // Needs work
{
	t_hitbox	hitbox;
	int			correction;
	int			y_direction;
	int			x_direction;

	if (angle < 180) // ray facing up
	{
		correction = -1;
		y_direction = -1;
		x_direction = 1;
	}
	else // ray facing down
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
	t_point		point;
	t_hit		hit;

	hit.distance = -1;
	hit.side = -1;
	hitbox = next_hhitbox(angle, player);
	point = cast(hitbox, world_map);
	if (point.x == -1 && point.y == -1)
		return (hit);
	hit.distance = abs(player.y - point.y) / sin(radians(angle));
	hit.side = v_side(point.y);
	hit.x = point.x;
	hit.y = point.y;
	int b_angle = angle - player.angle; // Turn into function
	hit.distance = hit.distance * cos(radians(b_angle));
	hit.distance = abs(hit.distance);
	return (hit);
}
