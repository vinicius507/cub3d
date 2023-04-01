/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_switcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:48:12 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/21 00:01:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_cub *cub)
{
	if (cub->player.angle < 25.0)
		move(cub, 0.1, 0);
	else if (cub->player.angle < 65.0)
		move(cub, 0.1, 0.1);
	else if (cub->player.angle < 115.0)
		move(cub, 0, 0.1);
	else if (cub->player.angle < 155.0)
		move(cub, -0.1, 0.1);
	else if (cub->player.angle < 205.0)
		move(cub, -0.1, 0);
	else if (cub->player.angle < 245.0)
		move(cub, -0.1, -0.1);
	else if (cub->player.angle < 295.0)
		move(cub, 0, -0.1);
	else if (cub->player.angle < 335.0)
		move(cub, 0.1, -0.1);
	else
		move(cub, 0.1, 0);
}

void	move_down(t_cub *cub)
{
	if (cub->player.angle < 25.0)
		move(cub, -0.1, 0);
	else if (cub->player.angle < 65.0)
		move(cub, -0.1, -0.1);
	else if (cub->player.angle < 115.0)
		move(cub, 0, -0.1);
	else if (cub->player.angle < 155.0)
		move(cub, 0.1, -0.1);
	else if (cub->player.angle < 205.0)
		move(cub, 0.1, 0);
	else if (cub->player.angle < 245.0)
		move(cub, 0.1, 0.1);
	else if (cub->player.angle < 295.0)
		move(cub, 0, 0.1);
	else if (cub->player.angle < 335.0)
		move(cub, -0.1, 0.1);
	else
		move(cub, -0.1, 0);
}

void	move_left(t_cub *cub)
{
	if (cub->player.angle < 25.0)
		move(cub, 0, -0.1);
	else if (cub->player.angle < 65.0)
		move(cub, 0.1, -0.1);
	else if (cub->player.angle < 115.0)
		move(cub, 0.1, 0);
	else if (cub->player.angle < 155.0)
		move(cub, 0.1, 0.1);
	else if (cub->player.angle < 205.0)
		move(cub, 0, 0.1);
	else if (cub->player.angle < 245.0)
		move(cub, -0.1, 0.1);
	else if (cub->player.angle < 295.0)
		move(cub, -0.1, 0);
	else if (cub->player.angle < 335.0)
		move(cub, -0.1, -0.1);
	else
		move(cub, 0.1, 0);
}

void	move_right(t_cub *cub)
{
	if (cub->player.angle < 25.0)
		move(cub, 0, 0.1);
	else if (cub->player.angle < 65.0)
		move(cub, -0.1, 0.1);
	else if (cub->player.angle < 115.0)
		move(cub, -0.1, 0);
	else if (cub->player.angle < 155.0)
		move(cub, -0.1, -0.1);
	else if (cub->player.angle < 205.0)
		move(cub, 0, -0.1);
	else if (cub->player.angle < 245.0)
		move(cub, 0.1, -0.1);
	else if (cub->player.angle < 295.0)
		move(cub, 0.1, 0);
	else if (cub->player.angle < 335.0)
		move(cub, 0.1, 0.1);
	else
		move(cub, 0, 0.1);
}
