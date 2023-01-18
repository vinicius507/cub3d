/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/18 08:13:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "config.h"

int	config_set_option(t_config *config, char *option, char *value)
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
		config->floor = ft_strdup(value);
	else if ((ft_strcmp(option, "C") == 0))
		config->ceiling = ft_strdup(value);
	else
		return (1);
	return (0);
}

int	config_should_read_map(t_config *config)
{
	if (config->map_lines != NULL)
		return (1);
	if (config->no != NULL
		&& config->so != NULL
		&& config->we != NULL
		&& config->ea != NULL
		&& config->ceiling != NULL
		&& config->floor != NULL)
		return (1);
	return (0);
}

int	config_add_map_line(t_config *config, char *line)
{
	char	*map_lines;

	if (config->map_lines == NULL)
		config->map_lines = ft_strdup(line);
	else
	{
		ft_asprintf(&map_lines, "%s%s", config->map_lines, line);
		free(config->map_lines);
		config->map_lines = map_lines;
	}
	if (config->map_lines == NULL)
		return (1);
	return (0);
}

void	config_teardown(t_config *config)
{
	if (config->no != NULL)
		free((char *)config->no);
	if (config->so != NULL)
		free((char *)config->so);
	if (config->we != NULL)
		free((char *)config->we);
	if (config->ea != NULL)
		free((char *)config->ea);
	if (config->floor != NULL)
		free((char *)config->floor);
	if (config->ceiling != NULL)
		free((char *)config->ceiling);
	if (config->map_lines != NULL)
		free((char *)config->map_lines);
}
