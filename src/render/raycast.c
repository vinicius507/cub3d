/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:35:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/06 23:35:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <unistd.h>

t_fpoint	cast(t_hitbox init_hitbox, t_map *world_map)
{
	t_hitbox	hitbox;
	t_fpoint	point;
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
		if (world_map->rows[box_y][box_x] == '1')
			break ;
		hitbox.y += hitbox.delta_y;
		hitbox.x += hitbox.delta_x;
	}
	point.y = hitbox.y;
	point.x = hitbox.x;
	return (point);
}

t_hit	raycast(int direction, t_player player, t_map *world_map)
{
	t_hit	horizontal;
	t_hit	vertical;

	if (direction < 0)
		direction += 359;
	if (direction > 359)
		direction -= 359;
	horizontal.distance = -1;
	vertical.distance = -1;
	if (direction != 0 && direction != 180)
		horizontal = h_ray(direction, player, world_map);
	if (direction != 90 && direction != 270)
		vertical = v_ray(direction, player, world_map);
	if (horizontal.distance == OUT_OF_LIMITS)
		return (vertical);
	if (vertical.distance == OUT_OF_LIMITS)
		return (horizontal);
	if (vertical.distance < horizontal.distance)
		return (vertical);
	if (vertical.distance == horizontal.distance)
	{
		vertical.side = side_corretion(direction);
		return (vertical);
	}
	return (horizontal);
}

int	what_im_doing(t_screen *screen, t_player player, t_map *world_map)
{
	float	direction;
	int		wall_x;
	int		height;
	t_hit	hit;

	direction = player.angle + 30;
	wall_x = 0;
	while (direction > (player.angle - 30.0))
	{
		hit = raycast(direction, player, world_map);
		height = floor(64 / hit.distance * screen->projection_distance);
		wall_pixel_put(screen, wall_x, &hit, height);
		direction -= screen->angle_rays;
		wall_x++;
	}
	return (0);
}
