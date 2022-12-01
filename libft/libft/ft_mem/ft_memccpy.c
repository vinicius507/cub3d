/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:19:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Copies up to `n` bytes of from memory area `src` to memory area
 * `dest`, stopping when the character `c` is found.
 * @param dest The destination memory area
 * @param src The source memory area
 * @param c The stopping character
 * @param n The maximum number of bytes to be copied
 * @return A pointer to the copied area
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	distance;

	ptr = ft_memchr(src, c, n);
	if (ptr != NULL)
	{
		distance = (size_t)ptr - (size_t)src + 1;
		return (ft_memcpy(dest, src, distance) + distance);
	}
	ft_memcpy(dest, src, n);
	return (NULL);
}
