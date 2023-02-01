/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:58:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/20 12:03:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 8

# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif

enum e_gnlstatus
{
	GNLERROR = 1,
	GNLEOF,
};

char	*get_next_line(int fd);

#endif
