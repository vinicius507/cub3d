/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:26:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:47:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Joins two memory sections.
 * @param m1 A pointer to the first memory section
 * @param m2 A pointer to the second memory section
 * @param size1 The size of the first memory section
 * @param size2 The size of the second memory section
 * @return A pointer to the joined memory
 */
void	*ft_memjoin(const void *m1, const void *m2, size_t size1, size_t size2)
{
	void	*m;

	if (m1 == NULL || m2 == NULL)
		return (NULL);
	m = ft_calloc(size1 + size2, sizeof(char));
	if (m == NULL)
		return (NULL);
	ft_memcpy(m, m1, size1);
	ft_memcpy(m + size1, m2, size2);
	return (m);
}
