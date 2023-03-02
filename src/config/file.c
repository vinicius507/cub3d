/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:04:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 12:54:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <libft.h>

char	**read_config_file(int fd)
{
	char	*line;
	char	*temp;
	char	*content;
	char	**lines;

	content = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (content == NULL)
			temp = ft_strdup(line);
		else
			temp = ft_strjoin(content, line);
		free(line);
		if (content != NULL)
			free(content);
		content = temp;
		if (content == NULL)
			break ;
		line = get_next_line(fd);
	}
	lines = ft_split(content, '\n');
	free(content);
	return (lines);
}
