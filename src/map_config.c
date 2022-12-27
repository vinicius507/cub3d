/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:51:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 15:07:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <cub3d.h>

static char	*get_config_key(char *line)
{
	char	*space;
	char	*key;

	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (NULL);
	key = ft_substr(line, 0, space - line);
	return (key);
}

static char	*get_config_value(char *line)
{
	char	*space;
	char	*value;

	space = ft_strchr(line, ' ');
	if (space == NULL)
		return (NULL);
	value = ft_strtrim(space + 1, " \n\r\t\v\f");
	return (value);
}

static int	parse_map_config(int config_fd, t_config *config)
{
	char	*line;
	char	*key;
	char	*value;
	int		ret;

	line = get_next_line(config_fd);
	while (line != NULL)
	{
		value = NULL;
		key = get_config_key(line);
		if (key != NULL)
		{
			value = get_config_value(line);
			ret = set_config_option(config, key, value);
			free(key);
		}
		free(line);
		if (ret == 1)
			return (1);
		line = get_next_line(config_fd);
	}
	return (0);
}

int	load_map_config(const char *filename, t_config *config)
{
	int	fd;
	int	parse_result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (1);
	}
	parse_result = parse_map_config(fd, config);
	gnl_clear();
	close(fd);
	return (parse_result);
}
