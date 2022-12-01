/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:42:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Sets `n` bytes of memory area `s` to the character `c`.
 * @param s
 * @param c
 * @param n
 * @return A pointer to the start of the set memory area
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (s == NULL)
		return (NULL);
	if (n == 0)
		return (s);
	ptr = (unsigned char *)s;
	while (n--)
		ptr[n] = (unsigned char)c;
	return (s);
}
