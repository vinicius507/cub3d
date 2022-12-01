/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:59:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:58:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/ft_io.h>

/**
 * @brief Writes a character on a file descriptor.
 * @param c
 * @param fd
 */
void	ft_putchar_fd(char c, int fd)
{
	(void)write(fd, &c, 1);
}
