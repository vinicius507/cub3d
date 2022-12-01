/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:39:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:47:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Returns the absolute value of an integer `n`.
 * @param n
 * @return The `unsigned int` value representing the absolute
 * value of the integer `n`.
 */
uint	ft_abs(int n)
{
	unsigned int	u_n;

	if (n > 0)
		u_n = n;
	else
		u_n = n * -1;
	return (u_n);
}
