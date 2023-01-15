/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/15 11:37:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft/ft_mem.h>
#include <libft/ft_string.h>
#include <libft/ft_io/get_next_line.h>

static char	*g_saves[OPEN_MAX] = {};

int	found_linebreak(int fd)
{
	if (g_saves[fd] == NULL)
		return (0);
	return ((ft_strchr(g_saves[fd], '\n') != NULL));
}

int	read_chunk(int fd)
{
	char	*buf;
	char	*save;
	ssize_t	bytes_read;

	buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (buf == NULL)
		return (1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (GNLERROR);
	if (bytes_read == 0)
		return (GNLEOF);
	if (g_saves[fd] == NULL)
		g_saves[fd] = ft_strdup(buf);
	else
	{
		save = ft_strjoin(g_saves[fd], buf);
		free(g_saves[fd]);
		if (save == NULL)
			return (GNLERROR);
		g_saves[fd] = save;
	}
	return (0);
}

char	*get_line(int fd)
{
	char	*line;
	char	*linebreak;

	if (g_saves[fd] == NULL)
		return (NULL);
	linebreak = ft_strchr(g_saves[fd], '\n');
	if (linebreak == NULL || linebreak[1] == '\0')
	{
		line = ft_strdup(g_saves[fd]);
		free(g_saves[fd]);
		g_saves[fd] = NULL;
	}
	else
	{
		line = ft_substr(g_saves[fd], 0, linebreak - g_saves[fd] + 1);
		ft_strlcpy(g_saves[fd], linebreak + 1, (ft_strlen(linebreak + 1) + 1));
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

	if (fd < 0)
		return (NULL);
	while ((found_linebreak(fd) == 0))
	{
		status = read_chunk(fd);
		if (status == GNLERROR)
		{
			if (g_saves[fd] != NULL)
			{
				free(g_saves[fd]);
				g_saves[fd] = NULL;
			}
			return (NULL);
		}
		if (status == GNLEOF)
			break ;
	}
	line = get_line(fd);
	return (line);
}

void	gnl_clear(void)
{
	size_t	fd;

	fd = 0;
	while (fd < OPEN_MAX)
	{
		if (g_saves[fd] != NULL)
		{
			free(g_saves[fd]);
			g_saves[fd] = NULL;
		}
		fd++;
	}
}
