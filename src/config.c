/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/15 12:07:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "cub3d.h"

static int	set_config_option(t_config *config, char *option, char *value)
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

static int	parse_config_line(char *line, t_config *config)
{
	char	*key;
	char	*value;
	char	*space;
	int		is_option_set;

	is_option_set = 0;
	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (1);
	key = ft_substr(line, 0, space - line);
	if (key == NULL)
		return (1);
	value = ft_strtrim(space + 1, " \n\r\t\v\f");
	if (value == NULL)
	{
		free(key);
		return (1);
	}
	if ((set_config_option(config, key, value) == 0))
		is_option_set = 1;
	free(key);
	free(value);
	return (!is_option_set);
}

static int	read_config(int config_fd, t_config *config)
{
	char	*line;
	int		lineno;

	lineno = 0;
	line = get_next_line(config_fd);
	while (line != NULL && ++lineno)
	{
		if ((ft_strcmp(line, "\n") != 0))
		{
			if ((parse_config_line(line, config) != 0))
			{
				free(line);
				return (1);
			}
		}
		free(line);
		line = get_next_line(config_fd);
	}
	return (0);
}

int	load_config(const char *filename, t_config *config)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errmsg(strerror(errno));
		return (1);
	}
	if ((read_config(fd, config) != 0))
	{
		errmsg("Could not load map config. Please check your config.");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
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
	if (config->floor != NULL)
		free((char *)config->floor);
	if (config->ceiling != NULL)
		free((char *)config->ceiling);
}
