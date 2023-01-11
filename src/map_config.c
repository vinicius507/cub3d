/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:51:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:28:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "cub3d.h"

static t_err	parse_config_line(char *line, t_config *config)
{
	char	*key;
	char	*value;
	char	*space;
	t_err	err;

	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (error("configuration option should be in a KEY VALUE format"));
	key = ft_substr(line, 0, space - line);
	if (key == NULL)
		return (error(""));
	value = ft_strtrim(space + 1, " \n\r\t\v\f");
	if (value == NULL)
	{
		free(key);
		return (error(""));
	}
	err = set_config_option(config, key, value);
	free(key);
	free(value);
	return (err);
}

static t_err	parse_map_config(int config_fd, t_config *config)
{
	char	*line;
	int		lineno;
	t_err	err;

	lineno = 0;
	line = get_next_line(config_fd);
	while (line != NULL && ++lineno)
	{
		if ((ft_strcmp(line, "\n") != 0))
		{
			err = parse_config_line(line, config);
			if (err != NULL)
			{
				free(line);
				return (err);
			}
		}
		free(line);
		line = get_next_line(config_fd);
	}
	return (NULL);
}

t_err	load_map_config(const char *filename, t_config *config)
{
	int			fd;
	t_err		err;

	fd = open(filename, O_RDONLY);
	if (fd >= 0)
		err = parse_map_config(fd, config);
	else
		err = error_from("error while loading map configuration",
				strerror(errno));
	close(fd);
	return (err);
}
