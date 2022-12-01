/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:27:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:01:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>

/**
 * @brief Appends a string into another one. It appends up to `size -
 * strlen(dest) - 1` bytes.
 * @param dest The destination string, needs to be allocated
 * @param src The string to be copied
 * @param size The size to be copied
 * @return The copied size of the string
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{	
	size_t	offset;
	size_t	src_size;
	size_t	dest_size;

	dest_size = 0;
	while (dest_size < size && dest[dest_size] != '\0')
		dest_size++;
	src_size = ft_strlen(src);
	if (dest_size < size)
	{
		offset = 0;
		while (dest_size + offset < size - 1 && src[offset] != '\0')
		{
			dest[dest_size + offset] = src[offset];
			offset++;
		}
		dest[dest_size + offset] = '\0';
	}
	return (dest_size + src_size);
}
