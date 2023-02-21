/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:54 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 13:26:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <libft.h>
#include <unistd.h>

char	*option_key(char *line)
{
	char	*space;

	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (ft_strdup(line));
	return (ft_substr(line, 0, space - line));
}

char	*option_value(char *line)
{
	char	*space;

	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (NULL);
	if (*(space + 1) == '\0')
		return (NULL);
	return (ft_strtrim(space + 1, " \r\n\v\t\f"));
}

int	load_texture_option(t_cub *cub, int side, char *path)
{
	t_img	*wall;

	if (side < W_NO || side >= W_COUNT)
		return (1);
	wall = &cub->screen.walls[side];
	wall->ptr = mlx_xpm_file_to_image(
			cub->screen.mlx,
			path,
			&wall->width,
			&wall->height);
	if (wall->ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_TEXTURE_NOT_LOADED, path);
		return (1);
	}
	wall->data = mlx_get_data_addr(
			wall->ptr,
			&wall->bpp,
			&wall->line_len,
			&wall->endianess);
	if (wall->data == NULL)
		return (1);
	return (0);
}

int	load_color_option(t_cub *cub, char key, char *value)
{
	size_t	i;
	int		spec;
	t_color	color;

	i = 0;
	spec = 2;
	color.hex = 0x000000;
	while (value[i] != '\0')
	{
		if (ft_isdigit(value[i] == 0))
			return (1);
		color.rgb[spec] = ft_atoi(&value[i]) & 0xff;
		while (ft_isdigit(value[i]) != 0)
			i++;
		if ((spec > 0 && value[i] != ',') || (spec == 0 && value[i] != '\0'))
			return (1);
		if (value[i] == ',')
			i++;
		spec--;
	}
	if (key == 'C')
		cub->screen.ceiling = color;
	else
		cub->screen.floor = color;
	return (0);
}

int	config_set_option(t_cub *cub, char *key, char *value)
{
	if (key == NULL)
		return (ft_dprintf(STDERR_FILENO, "Error\n"));
	if ((ft_strcmp(key, "NO") == 0))
		return (load_texture_option(cub, W_NO, value));
	if ((ft_strcmp(key, "SO") == 0))
		return (load_texture_option(cub, W_SO, value));
	if ((ft_strcmp(key, "WE") == 0))
		return (load_texture_option(cub, W_WE, value));
	if ((ft_strcmp(key, "EA") == 0))
		return (load_texture_option(cub, W_EA, value));
	if ((ft_strcmp(key, "F") == 0))
		return (load_color_option(cub, *key, value));
	if ((ft_strcmp(key, "C") == 0))
		return (load_color_option(cub, *key, value));
	return (ft_dprintf(STDERR_FILENO, ERR_CFG_UNKNOWN_OPTION, key));
}
