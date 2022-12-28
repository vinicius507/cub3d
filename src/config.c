/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:09:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cub3d.h"

static t_color	get_color(const char *value)
{
	t_color	color;

	color = (uint8_t)(ft_atoi(value) & 0xff) << 16;
	value = ft_strchr(value, ',') + 1;
	color |= (uint8_t)(ft_atoi(value) & 0xff) << 8;
	value = ft_strchr(value, ',') + 1;
	color |= (uint8_t)(ft_atoi(value) & 0xff);
	return (color);
}

t_err	set_config_option(t_config *config, char *option, char *value)
{
	if ((ft_strcmp(option, "NO") == 0))
		config->no = ft_strdup(value);
	else if ((ft_strcmp(option, "SO") == 0))
		config->so = ft_strdup(value);
	else if ((ft_strcmp(option, "WE") == 0))
		config->we = ft_strdup(value);
	else if ((ft_strcmp(option, "EA") == 0))
		config->ea = ft_strdup(value);
	else if ((ft_strcmp(option, "F") == 0))
		config->floor = get_color(value);
	else if ((ft_strcmp(option, "C") == 0))
		config->ceiling = get_color(value);
	else
		return (error_from("Unknown configuration option", (t_err)option));
	return (NULL);
}

void	teardown_config(t_config *config)
{
	if (config->no != NULL)
		free((char *)config->no);
	if (config->so != NULL)
		free((char *)config->so);
	if (config->we != NULL)
		free((char *)config->we);
	if (config->ea != NULL)
		free((char *)config->ea);
}
