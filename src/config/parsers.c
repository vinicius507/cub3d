/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 16:01:07 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <unistd.h>

static int	is_empty_line(char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n\r\f\v\t");
	if (trimmed == NULL || trimmed[0] == '\0')
		return (1);
	return (0);
}

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
		if ((is_empty_line(lines[*lineno]) != 0))
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
	(void)cub;
	(void)lines;
	(void)lineno;
	return (0);
}

int	parse_config(t_cub *cub, char **lines)
{
	int		unset;
	size_t	lineno;

	lineno = 0;
	unset = parse_options(cub, lines, &lineno);
	if (unset == -1)
	{
		ft_dprintf(
			STDERR_FILENO,
			"Error\nfatal: config parse error\n");
		return (-1);
	}
	else if (unset > 0)
	{
		ft_dprintf(STDERR_FILENO, ERR_CFG_UNSET_OPTIONS);
		return (-1);
	}
	return (parse_map(cub, lines, &lineno));
}
