/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:48:12 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/06 23:48:25 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 1, 0);
	else if (cub->player.angle < 65)
		move(cub, 1, -1);
	else if (cub->player.angle < 115)
		move(cub, 0, -1);
	else if (cub->player.angle < 155)
		move(cub, -1, -1);
	else if (cub->player.angle < 205)
		move(cub, -1, 0);
	else if (cub->player.angle < 245)
		move(cub, -1, 1);
	else if (cub->player.angle < 295)
		move(cub, 0, 1);
	else if (cub->player.angle < 335)
		move(cub, 1, 1);
	else
		move(cub, 1, 0);
}

void	move_down(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, -1, 0);
	else if (cub->player.angle < 65)
		move(cub, -1, 1);
	else if (cub->player.angle < 115)
		move(cub, 0, 1);
	else if (cub->player.angle < 155)
		move(cub, 1, 1);
	else if (cub->player.angle < 205)
		move(cub, 1, 0);
	else if (cub->player.angle < 245)
		move(cub, 1, -1);
	else if (cub->player.angle < 295)
		move(cub, 0, -1);
	else if (cub->player.angle < 335)
		move(cub, -1, -1);
	else
		move(cub, -1, 0);
}

void	move_left(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 0, -1);
	else if (cub->player.angle < 65)
		move(cub, -1, -1);
	else if (cub->player.angle < 115)
		move(cub, -1, 0);
	else if (cub->player.angle < 155)
		move(cub, -1, 1);
	else if (cub->player.angle < 205)
		move(cub, 0, 1);
	else if (cub->player.angle < 245)
		move(cub, 1, 1);
	else if (cub->player.angle < 295)
		move(cub, 1, 0);
	else if (cub->player.angle < 335)
		move(cub, 1, -1);
	else
		move(cub, 0, -1);
}

void	move_right(t_cub *cub)
{
	if (cub->player.angle < 25)
		move(cub, 0, 1);
	else if (cub->player.angle < 65)
		move(cub, 1, 1);
	else if (cub->player.angle < 115)
		move(cub, 1, 0);
	else if (cub->player.angle < 155)
		move(cub, 1, -1);
	else if (cub->player.angle < 205)
		move(cub, 0, -1);
	else if (cub->player.angle < 245)
		move(cub, -1, -1);
	else if (cub->player.angle < 295)
		move(cub, -1, 0);
	else if (cub->player.angle < 335)
		move(cub, -1, 1);
	else
		move(cub, 0, 1);
}
