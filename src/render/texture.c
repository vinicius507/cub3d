/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:40:48 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/02 00:49:23 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	wall_pixel_put(t_screen *screen, t_point px, t_hit *hit, int height, int wall_y)
{
	int		color;
	t_img	*wall;
	double	texture_x;

	if (hit->side == W_NO|| hit->side == W_SO)
		texture_x = hit->x % 64;
	else if (hit->side == W_WE || hit->side == W_EA)
		texture_x = hit->y % 64;
	wall = &screen->walls[hit->side];
	color = pixel_get(
			wall,
			texture_x,
			floor(((double)wall->height / height) * wall_y));
	pixel_put(&screen->buffer, px.x, px.y, color);
}

int	h_side(int x_coordinate)
{
	if ((x_coordinate % BOX_SIZE) > (BOX_SIZE / 2))
		return (W_EA);
	return (W_WE);
}

int	v_side(int y_coordinate)
{
	if ((y_coordinate % BOX_SIZE) > (BOX_SIZE / 2))
		return (W_SO);
	return (W_NO);
}

int	side_corretion(int angle)
{
	if (angle > 315)
		return (W_WE);
	if (angle > 225)
		return (W_NO);
	if (angle > 135)
		return (W_EA);
	if (angle > 45)
		return (W_SO);
	return (W_WE);
}
