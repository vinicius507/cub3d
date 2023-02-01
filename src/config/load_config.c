/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:41:59 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/01 20:17:17 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "../cub3d.h"
#include "config.h"
#include "libft/ft_io/get_next_line.h"

static int	parse_option_line(char *line, t_config *config)
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
	if ((config_set_option(config, key, value) == 0))
		is_option_set = 1;
	free(key);
	free(value);
	return (!is_option_set);
}

static int	read_config(int config_fd, t_config *config)
{
	int		is_invalid_line;
	char	*line;
	int		lineno;

	lineno = 0;
	line = get_next_line(config_fd);
	while (line != NULL && ++lineno)
	{
		is_invalid_line = 0;
		if ((config_should_read_map(config) == 0))
		{
			if ((ft_strcmp(line, "\n") != 0))
				is_invalid_line = parse_option_line(line, config);
		}
		else if ((ft_strcmp(line, "\n") == 0))
			is_invalid_line = config->map_lines != NULL;
		else
			is_invalid_line = config_add_map_line(config, line);
		free(line);
		if (is_invalid_line != 0)
			return (1);
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
