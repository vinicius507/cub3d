/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:32:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:47:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Compares the first `n` bytest of two memory areas.
 * @param s1
 * @param s2
 * @param n The number of bytes to be compared
 * @return For a non-zero value, it is the difference between the first pair
 * of bytes that differ in `s1` and `s2`
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			offset;

	offset = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (offset < n)
	{
		if (ptr1[offset] != ptr2[offset])
			return (ptr1[offset] - ptr2[offset]);
	}
	return (0);
}
