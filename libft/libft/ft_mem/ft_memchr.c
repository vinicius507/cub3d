/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:15:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Scans a memory area for a byte `c`.
 * @param s A pointer to the memory area. It is interpreted as an `unsigned
 * char *`
 * @param c The target byte. Is is interpreted as an `unsigned char `.
 * @param n The size of the memory area to be scanned
 * @return A pointer to the byte, if found, else, `NULL`.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			offset;

	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	offset = 0;
	while (offset < n)
	{
		if (ptr[offset] == (unsigned char)c)
			return (&ptr[offset]);
	}
	return (NULL);
}
