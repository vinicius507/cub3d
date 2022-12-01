/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:15:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:17:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_ctype.h>

/**
 * @brief Checks if a character `c` is an ASCII character.
 * @param c
 * @return A non-zero value if it is an ASCII character
 */
int	ft_isascii(int c)
{
	return ((c & ~0x7f) == 0);
}
