/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/13 15:03:06 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static int	in_range(double n, double min, double max)
{
	n = n * 10.0 / 10.0;
	if ((n - min >= 0 && fabs(n - min) >= 0)
		&& (n - max <= 0 && fabs(n - max) >= 0))
		return (1);
	return (0);
}

static int	get_hit_side(t_hit *hit)
{
	double		precision;
	t_point		vertex[4];

	precision = 1. / RAY_PRECISION;
	vertex[0] = (t_point){floor(hit->x), floor(hit->y)};
	vertex[1] = (t_point){vertex[0].x + 1, vertex[0].y};
	vertex[2] = (t_point){vertex[0].x + 1, vertex[0].y + 1};
	vertex[3] = (t_point){vertex[0].x, vertex[0].y + 1};
	if (in_range(hit->x, vertex[3].x, vertex[2].x)
		&& fabs((double)vertex[2].y - hit->y) < precision)
		return (W_NO);
	if (in_range(hit->x, vertex[0].x, vertex[1].x)
		&& fabs((double)vertex[1].y - hit->y) < precision)
		return (W_SO);
	if (in_range(hit->y, vertex[1].y, vertex[2].y)
		&& fabs((double)vertex[1].x - hit->x) < precision)
		return (W_WE);
	if (in_range(hit->y, vertex[0].y, vertex[3].y)
		&& fabs((double)vertex[0].x - hit->x) < precision)
		return (W_EA);
	return (-1);
}

t_hit	raycast(t_cub *cub, double ray_angle)
{
	double	dx;
	double	dy;
	t_ray	ray;
	t_hit	hit;
	char	wall;

	hit = (t_hit){-1, -1, 0, 0};
	wall = '0';
	ray = (t_ray){(cub->player.x), (cub->player.y)};
	dx = cos(radians(ray_angle)) / RAY_PRECISION;
	dy = sin(radians(ray_angle)) / RAY_PRECISION;
	while (wall != '1')
	{
		ray.x += dx;
		ray.y += dy;
		wall = cub->map.rows[(int)floor(ray.y)][(int)floor(ray.x)];
	}
	hit.x = ray.x;
	hit.y = ray.y;
	hit.side = get_hit_side(&hit);
	hit.distance = sqrt(pow(cub->player.x - ray.x, 2)
			+ pow(cub->player.y - ray.y, 2));
	return (hit);
}

void	raycasting(t_cub *cub)
{
	int			x;
	t_hit		hit;
	int			height;
	double		ray_angle;

	x = 0;
	ray_angle = cub->player.angle - 30;
	while (x < SCREEN_WIDTH)
	{
		hit = raycast(cub, ray_angle);
		fisheye_fix(cub, &hit, ray_angle);
		height = floor(SCREEN_HALF_HEIGHT / hit.distance);
		draw(&cub->screen, x, height, &hit);
		ray_angle += (double)cub->player.fov / SCREEN_WIDTH;
		x++;
	}
}
