/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static char	**parse_option(char *line)
{
	char	*key;
	char	*value;
	char	**key_value;

	key = option_key(line);
	if (key == NULL)
		return (NULL);
	value = option_value(line);
	if (value == NULL)
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_WRONG_OPTION_VALUE, key);
		free(key);
		return (NULL);
	}
	key_value = ft_calloc(2, sizeof(char *));
	if (key_value == NULL)
	{
		free(key);
		free(value);
		return (NULL);
	}
	key_value[0] = key;
	key_value[1] = value;
	return (key_value);
}

int	parse_options(t_cub *cub, char **lines, size_t *lineno)
{
	int		unset;
	char	**key_value;

	unset = 6;
	while (lines[*lineno] != NULL && unset > 0)
	{
		if ((str_is_whitespace_only(lines[*lineno]) != 0))
			continue ;
		key_value = parse_option(lines[*lineno]);
		if (key_value == NULL)
			return (-1);
		if ((config_set_option(cub, key_value[0], key_value[1]) != 0))
		{
			free(key_value[0]);
			free(key_value[1]);
			free(key_value);
			return (-1);
		}
		free(key_value[0]);
		free(key_value[1]);
		free(key_value);
		unset -= 1;
		*lineno += 1;
	}
	return (unset);
}

int	parse_map(t_cub *cub, char **lines, size_t *lineno)
{
	while ((str_is_whitespace_only(lines[*lineno])))
	{
		if (lines[*lineno] == NULL)
		{
			ft_dprintf(STDERR_FILENO, ERR_CFG_NO_MAP);
			return (1);
		}
		*lineno += 1;
	}
	cub->map = read_map(&lines[*lineno]);
	if (cub->map.rows == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		return (1);
	}
	if ((map_is_valid(&cub->map) == 0))
		return (1);
	if ((set_player_position(cub) != 0))
		return (1);
	return (0);
}
