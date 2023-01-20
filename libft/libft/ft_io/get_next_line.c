/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/01 20:16:39 by vgoncalv         ###   ########.fr       */
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

static int	read_chunk(int fd, char **save)
{
	char	*temp;
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE + 1];

	ft_bzero(buf, BUFFER_SIZE + 1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (GNLERROR);
	if (bytes_read == 0)
		return (GNLEOF);
	if (*save == NULL)
		*save = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*save, buf);
		free(*save);
		*save = temp;
		if (*save == NULL)
			return (GNLERROR);
	}
	return (0);
}

char	*get_line(char **save)
{
	char	*temp;
	char	*line;
	char	*linebreak;
	size_t	line_size;

	if (*save == NULL)
		return (NULL);
	temp = NULL;
	linebreak = ft_strchr(*save, '\n');
	line_size = ft_strlen(*save);
	if (linebreak != NULL && linebreak[1] != '\0')
		line_size = line_size - ft_strlen(linebreak + 1);
	line = ft_substr(*save, 0, line_size);
	if ((ft_strlen(*save + line_size) > 0))
		temp = ft_strdup(*save + line_size);
	free(*save);
	*save = NULL;
	if (temp != NULL)
		*save = temp;
	return (line);
}

/**
 * @brief Gets the next line from an open file descriptor.
 * @param fd The file descriptor to get the next line from
 * @return The next line of the file
 */
char	*get_next_line(int fd)
{
	int			status;
	char		*line;
	static char	*saves[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	while ((found_linebreak(saves[fd]) == 0))
	{
		status = read_chunk(fd, &(saves[fd]));
		if (status == GNLERROR)
			return (NULL);
		if (status == GNLEOF)
			break ;
	}
	line = get_line(&(saves[fd]));
	return (line);
}
