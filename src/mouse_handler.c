/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:04:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/18 20:08:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse(int x, int y, t_cub *cub)
{
	static int	center_x = 640;
	static int	center_y = 360;

	(void)y;
	if (x > center_x)
	{
		cub->player.angle--;
		if (cub->player.angle < 0)
			cub->player.angle = 359;
	}
	if (x < center_x)
	{
		cub->player.angle++;
		if (cub->player.angle == 359)
			cub->player.angle = 0;
	}
	mlx_mouse_move(cub->screen.mlx, cub->screen.window, center_x, center_y);
	return (0);
}
