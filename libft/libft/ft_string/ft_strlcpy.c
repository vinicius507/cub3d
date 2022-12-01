/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:28:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:02:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>

/**
 * @brief Copies a string. It copies up to `size - 1` bytes.
 * @param dest The destination string
 * @param src The string to be copied
 * @param size: The size to be copied
 * @return The size of the copied string
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	offset;

	if (src == NULL || dest == NULL)
		return (0);
	if (size > 0)
	{
		offset = 0;
		while (offset < size - 1 && src[offset])
		{
			dest[offset] = src[offset];
			offset++;
		}
		dest[offset] = '\0';
	}
	return (ft_strlen(src));
}
