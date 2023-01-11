/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/23 17:24:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/ft_mem.h>
#include <libft/ft_string.h>
#include <libft/ft_io/get_next_line.h>

static int	found_linebreak(char *save)
{
	if (save == NULL)
		return (0);
	return ((ft_strchr(save, '\n') != NULL));
}

int	read_chunk(int fd, char *save)
{
	char	*buf;
	char	*tempsafe;
	ssize_t	bytes_read;

	buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (buf == NULL)
		return (1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (GNLERROR);
	if (bytes_read == 0)
		return (GNLEOF);
	if (save == NULL)
		save = ft_strdup(buf);
	else
	{
		tempsafe = ft_strjoin(save, buf);
		free(save);
		if (tempsafe == NULL)
			return (GNLERROR);
		save = tempsafe;
	}
	return (0);
}

char	*get_line(char *save)
{
	char	*line;
	char	*linebreak;

	if (save == NULL)
		return (NULL);
	linebreak = ft_strchr(save, '\n');
	if (linebreak == NULL || linebreak[1] == '\0')
	{
		line = ft_strdup(save);
		free(save);
		save = NULL;
	}
	else
	{
		line = ft_substr(save, 0, linebreak - save + 1);
		ft_strlcpy(save, linebreak + 1, (ft_strlen(linebreak + 1) + 1));
	}
	return (line);
}

/**
 * @brief Gets the next line from an open file descriptor.
 * @param fd The file descriptor to get the next line from
 * @return The next line of the file
 */
char	*get_next_line(int fd)
{
	int		status;
	char	*line;
	static char	*saves[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	while ((found_linebreak(saves[fd]) == 0))
	{
		status = read_chunk(fd, saves[fd]);
		if (status == GNLERROR)
		{
			if (saves[fd] != NULL)
			{

				free(saves[fd]);
				saves[fd] = NULL;
			}
			return (NULL);
		}
		if (status == GNLEOF)
			break ;
	}
	line = get_line(saves[fd]);
	return (line);
}
