/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/19 19:33:57 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double	radians(double degree)
{
	return (degree * M_PI / 180);
}

static int	in_range(double n, double min, double max)
{
	n = n * 10.0 / 10.0;
	if (max - min < 0.5)
		printf("n: %.2f, [%.2f, %2.f]\r", n, min, max);
	if ((n - min >= 0 && fabs(n - min) >= 0)
		&& (n - max <= 0 && fabs(n - max) >= 0))
		return (1);
	return (0);
}

// TODO: make this work
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

static t_hit	raycast(t_cub *cub, double ray_angle)
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
	hit.distance = hit.distance * cos(radians(ray_angle - cub->player.angle));
	return (hit);
}

static void	draw_line(t_img *img, t_point start, t_point end, int color)
{
	int	x;
	int	y;

	if (start.x < 0)
		x = 0;
	else if (start.x >= SCREEN_WIDTH)
		x = SCREEN_WIDTH - 1;
	else
		x = start.x;
	if (start.y < 0)
		y = 0;
	else if (start.y > SCREEN_HEIGHT)
		y = SCREEN_HEIGHT - 1;
	else
		y = start.y;
	while (y < end.y && y < SCREEN_HEIGHT)
	{
		pixel_put(img, start.x, y, color);
		y++;
	}
}

static void	draw_texture(t_screen *screen, t_img *wall, t_point start, t_hit *hit, int height)
{
	int		i;
	double	y;
	double	dy;
	t_color	color;
	int		texture_x;

	i = 0;
	y = start.y;
	dy = (double)height * 2 / wall->height;
	texture_x = (int)floor(wall->width * (hit->x + hit->y)) % wall->width;
	while (i < wall->height)
	{
		color.hex = pixel_get(wall, texture_x, i);
		draw_line(
			&screen->buffer,
			(t_point){start.x, floor(y)},
			(t_point){start.x, floor(y + dy)},
			color.hex);
		y += dy;
		i++;
	}
}

static void	draw(t_screen *screen, int x, int height, t_hit *hit)
{
	t_img	*buffer;

	buffer = &screen->buffer;
	draw_line(
		buffer,
		(t_point){x, 0},
		(t_point){x, SCREEN_HALF_HEIGHT - height},
		rgb(0, 0, 0));
	draw_texture(
		screen,
		&screen->walls[hit->side],
		(t_point){x, SCREEN_HALF_HEIGHT - height},
		hit,
		height);
	draw_line(
		buffer,
		(t_point){x, SCREEN_HALF_HEIGHT + height},
		(t_point){x, SCREEN_HEIGHT},
		rgb(200, 200, 200));
}

void	raycasting(t_cub *cub)
{
	int			x;
	t_hit		hit;
	int			height;
	double		ray_angle;

	x = 0;
	ray_angle = cub->player.angle;
	while (x < SCREEN_WIDTH)
	{
		hit = raycast(cub, ray_angle);
		height = floor(SCREEN_HALF_HEIGHT / hit.distance);
		draw(&cub->screen, x, height, &hit);
		ray_angle += (double)cub->player.fov / SCREEN_WIDTH;
		x++;
	}
}
