/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:55:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:43:17 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_mem.h>

/**
 * @brief Sets `n` bytes of memory area `s` to 0.
 * @param s
 * @param n
 * @return A pointer to the start of the zeroed memory area
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
