/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:18:54 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char	*option_key(char *line)
{
	char	*space;

	space = ft_strchr(line, ' ');
	if (space == NULL || space == line)
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

int	config_set_option(t_cub *cub, char *key, char *value)
{
	if (key == NULL)
		return (ft_dprintf(STDERR_FILENO, "Error\n"));
	if ((ft_strcmp(key, "NO") == 0))
		return (load_texture_option(cub, key, W_NO, value));
	if ((ft_strcmp(key, "SO") == 0))
		return (load_texture_option(cub, key, W_SO, value));
	if ((ft_strcmp(key, "WE") == 0))
		return (load_texture_option(cub, key, W_WE, value));
	if ((ft_strcmp(key, "EA") == 0))
		return (load_texture_option(cub, key, W_EA, value));
	if ((ft_strcmp(key, "F") == 0))
		return (load_color_option(&cub->screen.floor, key, value));
	if ((ft_strcmp(key, "C") == 0))
		return (load_color_option(&cub->screen.ceiling, key, value));
	return (ft_dprintf(STDERR_FILENO, ERR_CFG_UNKNOWN_OPTION, key));
}
