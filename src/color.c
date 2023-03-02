/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 12:03:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	rgb(char r, char g, char b)
{
	t_color	color;

	color.rgb[0] = 0x00;
	color.rgb[1] = r & 0xff;
	color.rgb[2] = g & 0xff;
	color.rgb[3] = b & 0xff;
	return (color);
}
