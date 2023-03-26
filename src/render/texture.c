/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:28:27 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/25 21:54:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	draw_texture(t_screen *screen, t_texture texture)
{
	int		i;
	double	y;
	double	dy;
	t_color	color;
	int		texture_x;

	i = 0;
	y = texture.start.y;
	dy = (double)texture.height * 2 / texture.wall->height;
	texture_x = (int)floor(
			texture.wall->width * (texture.hit->x + texture.hit->y)
			) % texture.wall->width;
	while (i < texture.wall->height)
	{
		color.hex = pixel_get(texture.wall, texture_x, i);
		draw_line(
			&screen->buffer,
			(t_point){texture.start.x, floor(y)},
			(t_point){texture.start.x, floor(y + dy)},
			color.hex);
		y += dy;
		i++;
	}
}

void	draw(t_screen *screen, int x, int height, t_hit *hit)
{
	t_img		*buffer;
	t_texture	texture;

	buffer = &screen->buffer;
	draw_line(
		buffer,
		(t_point){x, 0},
		(t_point){x, SCREEN_HALF_HEIGHT - height},
		screen->ceiling.hex);
	texture.wall = &screen->walls[hit->side];
	texture.height = height;
	texture.hit = hit;
	texture.start = (t_point){x, SCREEN_HALF_HEIGHT - height};
	draw_texture(screen, texture);
	draw_line(
		buffer,
		(t_point){x, SCREEN_HALF_HEIGHT + height},
		(t_point){x, SCREEN_HEIGHT},
		screen->floor.hex);
}

void	draw_line(t_img *img, t_point start, t_point end, int color)
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
	(void)x;
}
