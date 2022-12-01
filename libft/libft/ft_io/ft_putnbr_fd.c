/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:54:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:58:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_io.h>

/**
 * @brief Writes a number on a file descriptor.
 * @param n
 * @param fd
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	*str_n;

	str_n = ft_itoa(n);
	if (str_n == NULL)
		return ;
	ft_putstr_fd(str_n, fd);
}
