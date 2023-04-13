/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye_effect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:57:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/13 15:00:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	fisheye_fix(t_cub *cub, t_hit *hit, double ray_angle)
{
	hit->distance = hit->distance * cos(radians(ray_angle - cub->player.angle));
}
