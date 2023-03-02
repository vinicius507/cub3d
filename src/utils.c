/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:01:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/22 16:17:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str_array(char **config)
{
	size_t	i;

	if (config == NULL)
		return ;
	i = 0;
	while (config[i] != NULL)
		free(config[i++]);
	free(config);
}

int	str_is_whitespace_only(char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " ");
	if (trimmed == NULL || trimmed[0] == '\0')
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}
