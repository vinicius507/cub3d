/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:51:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:47:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

static void	memrcpy(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n--)
		dest[n] = src[n];
}

/**
 * @brief Copies `n` bytes from `src` to `dest`. The memory areas may
 * overlap.
 * @param dest
 * @param src
 * @param n
 * @return A pointer to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (dest > src)
		memrcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
