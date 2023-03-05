/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:35:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/04 20:27:10 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <unistd.h>

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

int	what_im_doing(t_screen *screen, t_player player, t_map *world_map) // Also known as raycast
{
	float direction;
	t_hit	hit;

	float angle_rays = 60 / 1280.0;
	direction = player.angle + 30;
	double projection_distance = 720.0 / tan(radians(30));
	int i = 0;
	while (direction > (player.angle - 30.0))
	{
		hit = raycast(direction, player, world_map);
		int height = floor(64 / hit.distance * projection_distance);
		int j = 360 - (height / 2);
		int x = 0;
		while (x <= height)
		{
			wall_pixel_put(screen, (t_point){i, j}, &hit, height, x);
			j++;
			x++;
		}
		direction -= angle_rays;
		i++;
	}
	return (0);
}
