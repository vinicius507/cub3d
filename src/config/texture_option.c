/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:28:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/30 17:59:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <unistd.h>

static int	load_xpm(t_cub *cub, t_img *wall, char *path)
{
	wall->ptr = mlx_xpm_file_to_image(
			cub->screen.mlx,
			path,
			&wall->width,
			&wall->height);
	if (wall->ptr == NULL)
		return (1);
	wall->data = mlx_get_data_addr(
			wall->ptr,
			&wall->bpp,
			&wall->line_len,
			&wall->endianess);
	if (wall->data == NULL)
		return (1);
	return (0);
}

int	load_texture_option(t_cub *cub, char *key, int side, char *path)
{
	t_img	*wall;

	wall = &cub->screen.walls[side];
	if (wall->ptr != NULL)
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_DUPLICATE_KEY, key);
		return (1);
	}
	if ((load_xpm(cub, wall, path) != 0))
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_TEXTURE_NOT_LOADED, path);
		return (1);
	}
	return (0);
}
