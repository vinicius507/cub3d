/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:12:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 13:29:37 by vgoncalv         ###   ########.fr       */
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

int	parse_options(t_cub *cub, char **lines, size_t *lineno)
{
	int		unset;
	char	*key;
	char	*value;

	unset = 6;
	while (lines[*lineno] != NULL && unset > 0)
	{
		if ((is_empty_line(lines[*lineno]) != 0))
			continue ;
		key = option_key(lines[*lineno]);
		if (key == NULL)
			return (1);
		value = option_value(lines[*lineno]);
		if (value == NULL)
		{
			free(key);
			return (1);
		}
		if ((config_set_option(cub, key, value) != 0))
		{
			free(key);
			free(value);
			return (1);
		}
		free(key);
		free(value);
		unset -= 1;
		*lineno += 1;
	}
	return (0);
}

int	parse_map(t_cub *cub, char **lines, size_t *lineno)
{
	(void)cub;
	(void)lines;
	(void)lineno;
	return (0);
}
