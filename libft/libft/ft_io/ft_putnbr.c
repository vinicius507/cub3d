/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:06:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:59:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_io.h>

/**
 * @brief Writes a number on STDOUT.
 * @param n
 */
void	ft_putnbr(int n)
{
	char	*str_n;

	str_n = ft_itoa(n);
	if (str_n == NULL)
		return ;
	ft_putstr(str_n);
}
