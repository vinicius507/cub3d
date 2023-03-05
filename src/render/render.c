/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:45:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/04 21:30:52 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "projection.h"

int	render(t_cub *cub)
{
	background(&cub->screen.buffer, cub->screen.ceiling, cub->screen.floor);
	what_im_doing(&cub->screen, cub->player, &cub->map);
	mlx_put_image_to_window(
		cub->screen.mlx,
		cub->screen.window,
		cub->screen.buffer.ptr, 0, 0);
	return (0);
}
