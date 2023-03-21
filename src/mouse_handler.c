/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:04:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/20 22:36:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse(int x, int y, t_cub *cub)
{
	static int	center_x = 640;
	//static int	center_y = 360;

	(void)y;
	if (x > center_x)
	{
		cub->player.angle += 0.2;
		if (cub->player.angle >= 359.0)
			cub->player.angle = 0;
	}
	if (x < center_x)
	{
		cub->player.angle -= 0.2;
		if (cub->player.angle < 0)
			cub->player.angle = 359;
	}
	//mlx_mouse_move(cub->screen.mlx, cub->screen.window, center_x, center_y);
	center_x = x;
	printf("%f\n", cub->player.angle);
	//center_y = y;
	return (0);
}
