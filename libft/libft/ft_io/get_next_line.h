/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:58:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 16:05:00 by vgoncalv         ###   ########.fr       */
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
	GNL_ERROR = -1,
	GNL_EOF,
	GNL_NL,
};

#endif
