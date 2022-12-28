/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/28 12:24:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cub3d.h"

static t_err	set_color_option(t_color *color, const char *value)
{
	int	n;
	int	spec;
	int	commas;

	n = 0;
	*color = 0;
	commas = 0;
	while (value[n] != '\0')
	{
		spec = ft_atoi(&value[n]);
		if (spec < 0 || spec > 255)
			return (error(
					"a color RGB value should be a number in the range 0-255"));
		*color |= (spec & 0xff);
		*color = *color << 8;
		while (value[n] != '\0' && (ft_isdigit(value[n]) != 0))
			n++;
		if (commas < 2 && value[n] != ',')
			return (error(
					"a color value should be in the format REG,GREEN,BLUE"));
		if (value[n] == ',')
			commas++;
		n++;
	}
	return (NULL);
}

t_err	set_config_option(t_config *config, char *option, char *value)
{
	t_err	err;

	err = NULL;
	if ((ft_strcmp(option, "NO") == 0))
		config->no = ft_strdup(value);
	else if ((ft_strcmp(option, "SO") == 0))
		config->so = ft_strdup(value);
	else if ((ft_strcmp(option, "WE") == 0))
		config->we = ft_strdup(value);
	else if ((ft_strcmp(option, "EA") == 0))
		config->ea = ft_strdup(value);
	else if ((ft_strcmp(option, "F") == 0))
		err = set_color_option(&config->floor, value);
	else if ((ft_strcmp(option, "C") == 0))
		err = set_color_option(&config->ceiling, value);
	else
		return (error_from("Unknown configuration option", (t_err)option));
	return (err);
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
