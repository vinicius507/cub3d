/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:45:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/19 19:37:55 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	render(t_cub *cub)
{
	raycasting(cub);
	mlx_put_image_to_window(
		cub->screen.mlx,
		cub->screen.window,
		cub->screen.buffer.ptr, 0, 0);
	return (0);
}
