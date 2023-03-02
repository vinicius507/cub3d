/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/02 00:22:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	rgb(char r, char g, char b)
{
	t_color	color;

	color.rgb[3] = 0x00;
	color.rgb[2] = r & 0xff;
	color.rgb[1] = g & 0xff;
	color.rgb[0] = b & 0xff;
	return (color);
}
